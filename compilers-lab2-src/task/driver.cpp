#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

#include "CoolLexer.h"
#include "Parser.h"


int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "usage: coolc <source>\n";
        std::exit(EXIT_FAILURE);
    }
    std::ifstream ifs(argv[1]);
    if (ifs.fail()) {
        std::cerr << "Error opening file `" << argv[1] << "`\n";
        std::exit(EXIT_FAILURE);
    }

    CoolLexer* lexer = new CoolLexer(ifs, std::cout);
    for (int token = lexer->yylex(); token; token = lexer->yylex()) {
        if (token == TOKEN_STRING) {
            std::cout << "Token: " << token << " '" << *lexer->yylval.string_val << "'\n";
        }
        else
            std::cout << "Token: " << token << " '" << lexer->YYText() << "'\n";
    }

    return 0;
}

