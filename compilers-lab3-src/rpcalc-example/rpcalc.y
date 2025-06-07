%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
%}

%define api.value.type {double}
%token NUM
%left '-' '+'
%left '*' '/'
%precedence NEG 
%right '^' 

%%

input:
    | input line
;

line:
    '\n'
    | exp '\n' { printf("%.10g\n", $1); }
;

exp:
    NUM                  { $$ = $1; }
    | exp '+' exp        { $$ = $1 + $3; }
    | exp '-' exp        { $$ = $1 - $3; }
    | exp '*' exp        { $$ = $1 * $3; }
    | exp '/' exp        { $$ = $1 / $3; }
    | '-' exp %prec NEG  { $$ = -$2; }
    | exp '^' exp        { $$ = pow($1, $3); }
    | '(' exp ')'        { $$ = $2; }
;

%%
#include <ctype.h>

int yylex()
{
    int c = getchar();
    while (c == ' ' || c == '\t') {
        c = getchar();
    }

    /* Process floating point numbers */
    if (c == '.' || isdigit(c)) {
        ungetc(c, stdin);
        if (scanf("%lf", &yylval) != 1)
            abort();
        return NUM;
    } else if (c == EOF) {
        return YYEOF;
    }
    /* Single char token */
    return c;
}

int main(void)
{
    return yyparse();
}
