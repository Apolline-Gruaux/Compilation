%{
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "defs.h"
#include "common.h"

#include "y.tab.h"

void yyerror(char *);
int yyparse(node_t * program_root);
int fileno(FILE * stream);
void analyse_tree(node_t root);


char * infile = NULL;
char * outfile = NULL;
bool stop_after_syntax = false;
bool stop_after_verif = false;
/* A completer */

#if YYDEBUG
extern int yydebug;
#endif


%}

%option yylineno


LETTRE          [a-zA-Z]
CHIFFRE         [0-9]
IDF             {LETTRE}({LETTRE}|{CHIFFRE}|_)*

TOUT            [\x20-\x7E]
CHIFFRE_NON_NUL [1-9]
PONCTUATION     [!#$%&'()*+,-./:;<=>?@[]_`{|}~ ]
SIGNE			"-"|""



ENTIER_HEXA      {SIGNE}"0x"({CHIFFRE}|[a-fA-F])*
ENTIER          {SIGNE}({CHIFFRE}+|{ENTIER_HEXA})

CHAINE_CAR      [\x20-\x21]|[\x23-\x5B]|[\x5D-\x7E]
CHAINE          "({CHAINE_CAR}|\"|\n)*"
COMMENTAIRE     "//"({TOUT})*\n
/* //({CHAINE_CAR}|{AUTRE})*\n */
/* ^ */

%%

"void"          return TOK_VOID;

"int"			return TOK_INT;
"for"			return TOK_FOR;
"if"			return TOK_IF;
"else"			return TOK_ELSE;
"while"			return TOK_WHILE;
"do"			return TOK_DO;
"print"			return TOK_PRINT;
"bool"			return TOK_BOOL;
"true"			return TOK_TRUE;
"false"			return TOK_FALSE;
"="				return TOK_AFFECT;
"+"				return TOK_PLUS;
"-"				return TOK_MINUS;
"*"				return TOK_MUL;
"/"				return TOK_DIV;
"=="			return TOK_EQ;
"!="			return TOK_NE;
"&"				return TOK_BAND;
"|"				return TOK_BOR;
"&&"			return TOK_AND;
"||"			return TOK_OR;
"%"				return TOK_MOD;
"!"				return TOK_NOT;
"~"				return TOK_BNOT;
"^"				return TOK_BXOR;
";"				return TOK_SEMICOL;
","				return TOK_COMMA;
"("				return TOK_LPAR;
")"				return TOK_RPAR;
"{"				return TOK_LACC;
"}"				return TOK_RACC;
">>"			return TOK_SRA;
">>>"			return TOK_SRL;
"<<"			return TOK_SLL;
">"				return TOK_GT;
"<"				return TOK_LT;
">="			return TOK_GE;
"<="			return TOK_LE;


{IDF} {
                yylval.strval = strdup(yytext);
                return TOK_IDENT;
}

{ENTIER} {
                /* A completer : affecter yylval.intval et faire des verifications */   
                yylval.intval = atoi(yytext);             
                return TOK_INTVAL;
}

{CHAINE} {
                /* A completer : affecter yylval.strval */
                char* p = strdup(yytext);
                p++;
                p[strlen(p)-1] = 0;
                yylval.strval = p;
                return TOK_STRING;
}

{COMMENTAIRE} {
}


[ \t\n]+

. {
    fprintf(stderr, "Error line %d: Lexical error\n", yylineno);
    exit(1);
}


%%

int yywrap(void) {
    return 1;
}


int main(int argc, char ** argv) {
    /* A completer */
    node_t program_root;
    parse_args(argc, argv);
    #if YYDEBUG
    yydebug = 1;
    #endif
    

    yyin = fopen(infile, "r");
    yyparse(&program_root);
    fclose(yyin);
    analyse_tree(program_root);
    yylex_destroy();
    return 0;
}




