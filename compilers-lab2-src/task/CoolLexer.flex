%{
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

#include "Parser.h"
#include "CoolLexer.h"

#undef YY_DECL
#define YY_DECL int CoolLexer::yylex()

YYSTYPE yylval;

%}

typeid            [A-Z]{alpha_num}*
objectid          [a-z]{alpha_num}*
dashcomment       --.*\n
white_space       [ \t]*
digit             [0-9]
alpha             [A-Za-z_]
alpha_num         ({alpha}|{digit})
integer           {digit}+
error_integer (\b[0-9]+[.][0-9]*[fFlL]?|[.][0-9]|[0-9][eE][1-9])

%x COMMENT
%x STRING

%option warn batch noyywrap c++
%option yylineno
%option yyclass="CoolLexer"

%%
"(*" {
    comment_level++;
    BEGIN(COMMENT);
}
<COMMENT>"(*" {comment_level++;}
<COMMENT>.          { /* skip*/ }
<COMMENT>\n         { lineno++; }
<COMMENT><<EOF>>    Error("EOF in comment");
<COMMENT>"*)" {
    comment_level--;
    if(comment_level == 0)
        BEGIN(INITIAL);
}
{dashcomment} { lineno++; }

\" {
    string_buffer.clear();
    string_buffer += '"';
    BEGIN(STRING);
}
<STRING>\\\n { 
    lineno++; 
    string_buffer += '\n';
}
<STRING>\\ {
    string_buffer += '\\';
}
<STRING>[^\"\n\\]+  { string_buffer.append(yytext, yyleng); }
<STRING>\n          Error("Line string");
<STRING><<EOF>>     Error("EOF in string");    
<STRING>\" {
    string_buffer += '"';
    BEGIN(INITIAL);
    yylval.string_val = new std::string(string_buffer);
    return TOKEN_STRING;
}

class                return TOKEN_KW_PROG;
not                  return TOKEN_KW_NOT;
isvoid               return TOKEN_KW_ISVOID;
if                   return TOKEN_KW_IF;
then                 return TOKEN_KW_THEN;
else                 return TOKEN_KW_ELSE;
fi                   return TOKEN_KW_FI;
while                return TOKEN_KW_WHILE;
loop                 return TOKEN_KW_LOOP;
pool                 return TOKEN_KW_POOL;
in                   return TOKEN_KW_IN;
let                  return TOKEN_KW_LET;
case                 return TOKEN_KW_CASE;
of                   return TOKEN_KW_OF;
esac                 return TOKEN_KW_ESAC;
new                  return TOKEN_KW_NEW;
inherits             return TOKEN_KW_INHERITS;
false                return TOKEN_BOOL_FALSE;
true                 return TOKEN_BOOL_TRUE;

"<="|"=<"            return TOKEN_LEQ;
"<"                  return TOKEN_NEQ;
"="                  return TOKEN_EQ;
"<-"                 return TOKEN_ASSIGN;

{integer}            return TOKEN_INTEGER;
{objectid}           return TOKEN_OBJECTID;
{typeid}             return TOKEN_TYPEID;
{error_integer}      Error("Float");

[@~.+\-*/{}:;,()]     return yytext[0];

{white_space}        { /* skip spaces */ }
\n                   lineno++;

.                    Error("unrecognized character");
%%

void CoolLexer::Error(const char* msg) const
{
    std::cerr << "Lexer error (line " << lineno + 1 << "): " << msg << ": lexeme '" << YYText() << "'\n";
    std::exit(YY_EXIT_FAILURE);
}
