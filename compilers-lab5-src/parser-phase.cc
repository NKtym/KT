#include "cool-parse.h"
#include "cool-tree.h"
#include "utilities.h"
#include <cstdio>
#include <functional>
#include <string>
#include <unistd.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::FILE *token_file = stdin;
extern Classes parse_results;
extern Program ast_root;

extern int curr_lineno;
const char *curr_filename = "<stdin>";
extern int parse_errors;

extern int yy_flex_debug;
extern int cool_yydebug;
int lex_verbose = 0;
extern int cool_yyparse();

namespace analyzer {
using StrSet = std::unordered_set<std::string>;
using StrToStr = std::unordered_map<std::string, std::string>;
std::unordered_map<
    std::string,
    std::unordered_map<std::string,
                       std::pair<std::string, std::vector<std::string>>>>
    methods;
std::unordered_map<std::string, std::unordered_map<std::string, std::string>>
    attrs;
StrToStr hierarchy;
int err_count = 0;
const StrSet builtin_classes = {"Object", "Int", "Bool", "String", "IO"};

void semantics_error(const std::string &msg) {
  std::cerr << "- semantic error: " << msg << std::endl;
  err_count++;
}

bool detect_cycle(const StrToStr &hierarchy) {
  StrSet visited, visiting;
  std::function<bool(const std::string &)> dfs = [&](const std::string &c) {
    if (visited.count(c))
      return false;
    if (visiting.count(c))
      return true;
    visiting.insert(c);
    auto it = hierarchy.find(c);
    if (it != hierarchy.end()) {
      if (dfs(it->second))
        return true;
    }
    visiting.erase(c);
    visited.insert(c);
    return false;
  };

  for (const auto &p : hierarchy) {
    if (!builtin_classes.count(p.second) && hierarchy.count(p.second) == 0) {
      semantics_error("parent of class '" + p.first + "' ('" + p.second +
                      "') doesn't exist");
    }
    if (dfs(p.first))
      return true;
  }
  return false;
}

void check_expr(Expression expr, const StrSet &class_attrs,
                std::vector<StrSet> &scopes, const std::string &current_class) {
  ExprVisitor ev;
  expr->accept(ev);
  if (!ev.id_name.empty()) {
    const std::string &v = ev.id_name;
    if (v != "self") {
      bool found = false;
      for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        if (it->count(v)) {
          found = true;
          break;
        }
      }
      auto check_attr = [&](const std::string &cls, const std::string &attr) {
        std::string current = cls;
        while (current != "") {
          if (attrs[current].count(attr))
            return true;
          current = hierarchy.count(current) ? hierarchy[current] : "";
        }
        return false;
      };
      if (!found && !check_attr(current_class, v)) {
        semantics_error("undeclared identifier '" + v + "'");
      }
    }
    ev.id_name.clear();
  }
  if (!ev.let_id.empty()) {
    check_expr(ev.let_init, class_attrs, scopes, current_class);
    scopes.emplace_back();
    if (!scopes.back().insert(ev.let_id).second) {
      semantics_error("variable '" + ev.let_id +
                      "' already declared in this scope");
    }
    check_expr(ev.let_body, class_attrs, scopes, current_class);
    scopes.pop_back();
    ev.let_id.clear();
    return;
  }
  if (ev.block_body) {
    for (int i = ev.block_body->first(); ev.block_body->more(i);
         i = ev.block_body->next(i)) {
      check_expr(ev.block_body->nth(i), class_attrs, scopes, current_class);
    }
    ev.block_body = nullptr;
    return;
  }
  if (ev.recv || ev.args) {
    if (dynamic_cast<int_const_class *>(ev.recv)) {
      semantics_error(std::string("Dispatch to undefined method '") +
                      ev.disp_name->get_string() + "' on type Int");
      return;
    }
    if (ev.recv)
      check_expr(ev.recv, class_attrs, scopes, current_class);
    for (int i = ev.args->first(); ev.args->more(i); i = ev.args->next(i)) {
      check_expr(ev.args->nth(i), class_attrs, scopes, current_class);
    }
    ev.recv = nullptr;
    ev.args = nullptr;
    return;
  }
  if (ev.plus_e1) {
    if (dynamic_cast<int_const_class *>(ev.plus_e1) &&
        dynamic_cast<string_const_class *>(ev.plus_e2)) {
      semantics_error("Incompatible types for '+': Int and String");
      return;
    }
    check_expr(ev.plus_e1, class_attrs, scopes, current_class);
    check_expr(ev.plus_e2, class_attrs, scopes, current_class);
    ev.plus_e1 = ev.plus_e2 = nullptr;
    return;
  }
}

std::string expr_type(Expression expr, const std::string &current_class) {
  ExprVisitor ev;
  expr->accept(ev);
  if (dynamic_cast<new__class *>(expr)) {
    NewVisitor nv;
    expr->accept(nv);
    std::string type = nv.type_name->get_string();
    if (!builtin_classes.count(type) && hierarchy.count(type) == 0) {
      semantics_error("new with undefined class " + type);
    }
    return type;
  }
  if (ev.plus_e1) {
    auto t1 = expr_type(ev.plus_e1, current_class);
    auto t2 = expr_type(ev.plus_e2, current_class);
    if (t1 != "Int" || t2 != "Int")
      semantics_error("Incompatible types for '+': " + t1 + " and " + t2);
    return "Int";
  }
  if (ev.recv) {
    auto recv_t = expr_type(ev.recv, current_class);
    std::string cls = recv_t;
    while (cls != "Object") {
      auto it = methods[cls].find(ev.disp_name->get_string());
      if (it != methods[cls].end()) {
        auto &sig = it->second;
        std::vector<std::string> ats;
        if (ev.args)
          for (int j = ev.args->first(); ev.args->more(j); j = ev.args->next(j))
            ats.push_back(expr_type(ev.args->nth(j), current_class));
        if (ats.size() != sig.second.size())
          semantics_error(std::string("Wrong number of args in dispatch to '") +
                          ev.disp_name->get_string() + "'");
        else
          for (size_t m = 0; m < ats.size(); m++)
            if (ats[m] != sig.second[m])
              semantics_error("Type mismatch in arg " + std::to_string(m) +
                              " of '" + ev.disp_name->get_string() + "'");
        return sig.first;
      }
      cls = hierarchy[cls];
    }
    semantics_error(std::string("Dispatch to undefined method '") +
                    ev.disp_name->get_string() + "' on type " + recv_t);
    return "";
  }
  if (dynamic_cast<int_const_class *>(expr))
    return "Int";
  if (dynamic_cast<string_const_class *>(expr))
    return "String";
  if (dynamic_cast<bool_const_class *>(expr))
    return "Bool";
  if (!ev.id_name.empty()) {
    if (ev.id_name == "self")
      return current_class;
    if (attrs[current_class].count(ev.id_name))
      return attrs[current_class][ev.id_name];
    return "";
  }
  if (dynamic_cast<new__class *>(expr)) {
    NewVisitor nv;
    expr->accept(nv);
    return nv.type_name->get_string();
  }
  return "";
}
void check_classes(Classes classes, StrSet &class_names, StrToStr &hierarchy) {
  class_names.insert(builtin_classes.begin(), builtin_classes.end());
  methods["IO"]["out_string"] = {"IO", {"String"}};
  methods["IO"]["in_string"] = {"String", {}};
  methods["Object"]["abort"] = {"Object", {}};
  methods["Object"]["type_name"] = {"String", {}};
  methods["Object"]["copy"] = {"SELF_TYPE", {}};
  for (int i = classes->first(); classes->more(i); i = classes->next(i)) {
    class__class *cls = dynamic_cast<class__class *>(classes->nth(i));
    NameVisitor nv;
    cls->accept(nv);
    std::string class_name = nv.name;
    if (!class_names.insert(class_name).second) {
      semantics_error("class '" + class_name + "' already exists!");
    }
    ParentVisitor pv;
    cls->accept(pv);
    std::string parent_name = pv.name;
    hierarchy[class_name] = parent_name;
    FeaturesVisitor fv;
    cls->accept(fv);
    Features feats = fv.features;
    for (int j = feats->first(); feats->more(j); j = feats->next(j)) {
      Feature f = feats->nth(j);
      NameVisitor fnv;
      f->accept(fnv);
      const std::string feat_name = fnv.name;
      if (f->get_feature_type() == "attr_class") {
        TypeVisitor tv;
        f->accept(tv);
        attrs[class_name][feat_name] = tv.type;
      }
      if (f->get_feature_type() == "method_class") {
        TypeVisitor rtv;
        f->accept(rtv);
        FormalsVisitor fmv;
        f->accept(fmv);
        std::vector<std::string> param_types;
        for (int k = fmv.formals->first(); fmv.formals->more(k);
             k = fmv.formals->next(k)) {
          TypeVisitor ptv;
          fmv.formals->nth(k)->accept(ptv);
          param_types.push_back(ptv.type);
        }
        methods[class_name][feat_name] = {rtv.type, param_types};
      }
    }

    std::string current = class_name;
    while (current != "Object") {
      if (hierarchy.count(current)) {
        current = hierarchy[current];
        for (const auto &[name, sig] : methods[current]) {
          if (methods[class_name].count(name) == 0) {
            methods[class_name][name] = sig;
          }
        }
      } else {
        break;
      }
    }
    StrSet feature_names;
    StrSet class_attrs;
    for (int j = feats->first(); feats->more(j); j = feats->next(j)) {
      Feature f = feats->nth(j);
      NameVisitor fnv;
      f->accept(fnv);
      std::string feat_name = fnv.name;
      if (!feature_names.insert(feat_name).second) {
        semantics_error("Feature '" + feat_name + "' in '" + class_name +
                        "' already exists");
      }
      if (f->get_feature_type() == "attr_class") {
        class_attrs.insert(feat_name);
      }
      if (f->get_feature_type() == "method_class") {
        FormalsVisitor fmv;
        f->accept(fmv);
        Formals formals = fmv.formals;
        StrSet formal_names;
        for (int k = formals->first(); formals->more(k); k = formals->next(k)) {
          NameVisitor pnv;
          formals->nth(k)->accept(pnv);
          std::string pname = pnv.name;
          if (!formal_names.insert(pname).second) {
            semantics_error("Formal '" + pname + "' in method '" + feat_name +
                            "' already exists");
          }
        }
      }
    }
    for (int j = feats->first(); feats->more(j); j = feats->next(j)) {
      Feature f = feats->nth(j);
      if (f->get_feature_type() == "method_class") {
        FormalsVisitor fmv;
        f->accept(fmv);
        std::vector<StrSet> scopes;
        StrSet param_scope;
        for (int k = fmv.formals->first(); fmv.formals->more(k);
             k = fmv.formals->next(k)) {
          NameVisitor pnv;
          fmv.formals->nth(k)->accept(pnv);
          param_scope.insert(pnv.name);
        }
        scopes.push_back(param_scope);
        class__class *dummy;
        ExprVisitor ev;
        f->accept(ev);
        Expression body = ev.method_body;
        check_expr(body, class_attrs, scopes, class_name);
        expr_type(body, class_name);
      }
    }
  }
  if (class_names.count("Main") == 0) {
    semantics_error("Start point - class 'Main' doesn't exist");
  } else {
    class__class *main_cls = nullptr;
    for (int i = classes->first(); classes->more(i); i = classes->next(i)) {
      class__class *c = dynamic_cast<class__class *>(classes->nth(i));
      NameVisitor nv2;
      c->accept(nv2);
      if (nv2.name == "Main") {
        main_cls = c;
        break;
      }
    }
    if (main_cls) {
      FeaturesVisitor mv;
      main_cls->accept(mv);
      bool has_main = false;
      for (int j = mv.features->first(); mv.features->more(j);
           j = mv.features->next(j)) {
        NameVisitor fnv;
        mv.features->nth(j)->accept(fnv);
        if (fnv.name == "main") {
          has_main = true;
          break;
        }
      }
      if (!has_main) {
        semantics_error("Method 'main' in 'Main' class does not exist");
      }
    }
  }
}
}; // namespace analyzer

int main(int argc, char **argv) {
  yy_flex_debug = 0;
  cool_yydebug = 0;
  lex_verbose = 0;
  analyzer::hierarchy["Int"] = "Object";
  analyzer::hierarchy["Bool"] = "Object";
  analyzer::hierarchy["String"] = "Object";
  analyzer::hierarchy["IO"] = "Object";
  for (int i = 1; i < argc; i++) {
    token_file = std::fopen(argv[i], "r");
    if (token_file == NULL) {
      std::cerr << "Error: can not open file " << argv[i] << std::endl;
      std::exit(1);
    }
    curr_lineno = 1;
    cool_yyparse();
    if (parse_errors != 0) {
      std::cerr << "Error: parse errors\n";
      std::exit(1);
    }
    if (!ast_root) {
      std::cerr << "Error: AST is null after parsing\n";
      std::exit(1);
    }
    ast_root->dump_with_types(std::cerr, 0);
    std::fclose(token_file);
    analyzer::StrSet class_names{"Object"};
    analyzer::StrToStr hierarchy;
    analyzer::check_classes(parse_results, class_names, hierarchy);
    if (analyzer::detect_cycle(hierarchy)) {
      analyzer::semantics_error(
          "loop detected in classes inheritance hierarchy");
    }
  }
  std::cerr << "Detected " << analyzer::err_count << " semantic errors\n";
  return analyzer::err_count;
}
