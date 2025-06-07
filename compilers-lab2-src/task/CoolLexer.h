#ifndef COOLLEXER_H
#define COOLLEXER_H

#include <iostream>
#include <fstream>

#undef yyFlexLexer
#include <FlexLexer.h>

struct YYSTYPE {
    std::string* string_val;
};

class CoolLexer : public yyFlexLexer {
public:
    CoolLexer(std::istream& arg_yyin, std::ostream& arg_yyout) :
        yyFlexLexer{arg_yyin, arg_yyout}, out{arg_yyout}, lineno{0}, comment_level{0} {}
    virtual int yylex();
    std::string string_buffer;
    YYSTYPE yylval;

private:
    void Error(const char* msg) const;

    std::ostream& out;
    int lineno;
    int comment_level;
};

#endif
