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
PONCTUATION     [ !#$%&'()*+,-./:;<=>?@[]^_`{|}~]
AUTRE           [\"]
CHAINE_CAR      {LETTRE}|{CHIFFRE}|{PONCTUATION}
IDF             {LETTRE}({LETTRE}|{CHIIFRE}|_)*
ENTIER          {CHIFFRE}+
CHAINE          "({CHAINE_CAR}|\"|\n)*"
COMMENTAIRE     //([graph:])*\n

%%

"void"          return TOK_VOID;






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
                char tmp[] = strdup(yytext);
                char* p = tmp;
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




