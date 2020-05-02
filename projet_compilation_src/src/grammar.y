%{
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

#include "defs.h"
#include "common.h"
#include "mips_inst.h"

#include "registers.h"

/* Global variables */

#define NO_MEMORY "ERROR : OUT OF MEMORY"

/* A completer */
extern bool stop_after_syntax;
extern bool stop_after_verif;
extern char * infile;
extern char * outfile;

/* prototypes */
int yylex(void);
extern int yylineno;

void yyerror(node_t * program_root, char * s);
void analyse_tree(node_t root);
node_t make_node(node_nature nature, int nops, ...);
node_t new_node();
/* A completer */

%}

%parse-param { node_t * program_root }

%union {
    int32_t intval;
    char * strval;
    node_t ptr;
};


/* Definir les token ici avec leur associativite, dans le bon ordre */

%token TOK_VOID		TOK_INT		TOK_INTVAL	TOK_BOOL	TOK_TRUE    TOK_FALSE

%token TOK_IDENT	TOK_IF		TOK_ELSE	TOK_WHILE	TOK_FOR		TOK_PRINT

%token TOK_AFFECT	TOK_GE		TOK_LE		TOK_GT		TOK_LT		TOK_EQ

%token TOK_NE		TOK_PLUS	TOK_MINUS	TOK_MUL		TOK_DIV		TOK_MOD

%token TOK_UMINUS	TOK_SEMICOL	TOK_COMMA	TOK_LPAR	TOK_RPAR	TOK_LACC

%token TOK_RACC		TOK_STRING	TOK_DO

%nonassoc TOK_THEN
%nonassoc TOK_ELSE

%right TOK_AFFECT

%left TOK_OR
%left TOK_AND
%left TOK_BOR
%left TOK_BXOR
%left TOK_BAND
%left TOK_EQ		TOK_NE
%left TOK_GT		TOK_LT			TOK_GE			TOK_LE
%left TOK_SRL		TOK_SRA			TOK_SLL
%left TOK_PLUS		TOK_MINUS
%left TOK_MUL		TOK_DIV			TOK_MOD
%left TOK_UMINUS	TOK_NOT			TOK_BNOT

%type <intval>	TOK_INTVAL
%type <strval>	TOK_IDENT		TOK_STRING
%type <ptr>		program		listdecl			listdeclnonnull		vardecl		ident		type				listtypedecl	decl	maindecl
%type <ptr>		listinst	listinstnonnull		inst				block		expr		listparamprint		paramprint

%%

/* Regles ici */
program:
        listdeclnonnull maindecl
        {
            $$ = make_node(NODE_PROGRAM, 2, $1, $2);
            *program_root = $$;
        }
        | maindecl
        {
            $$ = make_node(NODE_PROGRAM, 2, NULL, $1);
            *program_root = $$;
        }
        ;

listdeclnonnull:
        vardecl
        {
            $$ = $1;
        }
        | listdeclnonnull vardecl
        {
            $$ = make_node(NODE_DECLS, 2, $1, $2);
        }
        ;

maindecl:
        type ident TOK_LPAR TOK_RPAR block
        {
            $$ = make_node(NODE_FUNC, 3, $1, $2, $5);
        }
        ;

listdecl:
        listdeclnonnull
        {
            $$ =$1;
        }
        |
        {
            $$ = NULL;
        }
		;

vardecl:
        type listtypedecl TOK_SEMICOL
        {
            $$ = make_node(NODE_DECLS, 2, $1, $2);
        }
		;

ident: 
		TOK_IDENT
        {
            $$ = make_node(NODE_IDENT, 0);
        }
		;

type: 
		TOK_INT
        {
            $$ = make_node(NODE_TYPE, 1, TYPE_INT);
        }
        | TOK_BOOL
        {
            $$ = make_node(NODE_TYPE, 1, TYPE_BOOL);
        }
        | TOK_VOID{
            $$ = make_node(NODE_TYPE, 1, TYPE_VOID);
        }
		;

listtypedecl: 
		decl
        | listtypedecl TOK_COMMA decl
		;

decl: 
		ident
        | ident TOK_AFFECT expr
		;

listinst: 
		listinstnonnull
        |
		;

lisinstnonull:
		inst
        | listinstnonnull inst
		;

inst: 
		expr TOK_MUL expr
        | expr TOK_DIV expr
        | expr TOK_PLUS expr
        | expr TOK_MINUS expr
        | expr TOK_MOD expr
        | expr TOK_LT expr
        | expr TOK_GT expr
        | TOK_MINUS expr %prec TOK_UMINUS
        | expr TOK_GE expr
		;

block: 
		TOK_LACC listdecl listinst TOK_RACC
        {
            $$ = make_node(NODE_BLOCK, 2, $2, $3);
        }
		;

expr: 
        expr TOK_MUL expr
        | expr TOK_DIV expr
        | expr TOK_PLUS expr
        | expr TOK_MINUS expr
        | expr TOK_MOD expr
        | expr TOK_LT expr
        | expr TOK_GT expr
        | TOK_MINUS expr %prec TOK_UMINUS
        | expr TOK_GE expr
        | expr TOK_LE expr
        | expr TOK_EQ expr
        | expr TOK_NE expr
        | expr TOK_AND expr
        | expr TOK_OR expr
        | expr TOK_BAND expr
        | expr TOK_BOR expr
        | expr TOK_BXOR expr
        | expr TOK_SRL expr
        | expr TOK_SRA expr
        | expr TOK_SLL expr
        | TOK_NOT expr
        {
            $$ = make_node(NODE_NOT, 1, $2);
        }
        | TOK_BNOT expr
        {
            $$ = make_node(NODE_BNOT, 1, $2);
        }
        | TOK_LPAR expr TOK_RPAR
        {
            $$ = $2;
        }
        | ident TOK_AFFECT expr
        {
            $$ = make_node(NODE_AFFECT, 2, $1, $3);
        }
        | TOK_INTVAL
        {
            $$ = make_node(NODE_INTVAL, 0);
        }
        | TOK_TRUE
        {
            $$ = make_node(NODE_BOOLVAL, 1, 1);
        }
        | TOK_FALSE
        {
            $$ = make_node(NODE_BOOLVAL, 1, 0);
        }
        | ident
        {
            $$ = $1;
        }

		;

listparamprint : 
		listparamprint TOK_COMMA paramprint
        {
            $$ = make_node(NODE_LIST, 2, $1, $3);
        }
        | paramprint
        {
            $$ = $1;
        }
		;

paramprint : 
		ident
        {
            $$ = $1;
        }
        | TOK_STRING
        {
            $$ = make_node(NODE_STRINGVAL, 0);
        }
		;

%%

/* A completer et/ou remplacer avec d'autres fonctions */
node_t make_node(node_nature nature, int nops, ...) {
    va_list ap;
    node_t node = new_node();
    if(node == NULL)
    {
        yyerror(&node, NO_MEMORY)
    }
    node->lineno = yylineno;
    node->nature = nature;

    switch(nature){

        case(NODE_BOOLVAL):
            va_start(ap, nops);
            node->value = va_arg(ap, int64_t);
            va_end(ap);
            break;
        
        case(NODE_IDENT):
            node->ident = yylval.strval;
            break;
        
        case(NODE_INTVAL):
            node->intval = yylval.intval;
            break;
        
        case(NODE_STRINGVAL):
            node->str = yylval.strval;
            break;
        
        case(NODE_TYPE):
            va_start(ap, nops);
            node->type = va_arg(ap, NODE_TYPE);
            va_end(ap);
            break;

        default:
            node->nops = nops;
            node->opr = malloc(nops * sizeof(node_t));
            if(node->opr == NULL)
            {
                yyerror(&node, NO_MEMORY);
            }

            va_start(ap, nops);
            for(int i = 0; i < nops; i++)
            {
                node->opr[i] = va_args(ap, node_t);
            }
            va_end(ap);

            break;

    }

    return node;
}



node_t new_node(){
    node_t node = malloc(sizeof(node_t));
    node->type = TYPE_NONE;
    node->nature = NONE;
    node->opr = NULL;
    node->decl_node = NULL;
    node->ident = NULL;
    node->str = NULL;
    node->global_decl = false;
    node->value = 0;
    node->offset = 0;
    node->lineno = 0;
    node->stack_size = 0;
    node->nops = 0;
    node->node_num = 0;

    return node;
}



/* A completer */
void analyse_tree(node_t root) {
    if (!stop_after_syntax) {
        // Appeler la passe 1

        if (!stop_after_verif) {
            create_program(); 
            // Appeler la passe 2

            dump_mips_program(outfile);
            free_program();
        }
        free_global_strings();
    }
}



void yyerror(node_t * program_root, char * s) {
    fprintf(stderr, "Error line %d: %s\n", yylineno, s);
    exit(1);
}

