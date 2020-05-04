/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "grammar.y"

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

#line 40 "grammar.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int32_t intval;
    char * strval;
    node_t ptr;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 70 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(node_t *  program_root)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(node_t *  program_root, const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(program_root, msg)
#endif

extern int YYPARSE_DECL();

#define TOK_VOID 257
#define TOK_INT 258
#define TOK_INTVAL 259
#define TOK_BOOL 260
#define TOK_TRUE 261
#define TOK_FALSE 262
#define TOK_IDENT 263
#define TOK_IF 264
#define TOK_ELSE 265
#define TOK_WHILE 266
#define TOK_FOR 267
#define TOK_PRINT 268
#define TOK_AFFECT 269
#define TOK_GE 270
#define TOK_LE 271
#define TOK_GT 272
#define TOK_LT 273
#define TOK_EQ 274
#define TOK_NE 275
#define TOK_PLUS 276
#define TOK_MINUS 277
#define TOK_MUL 278
#define TOK_DIV 279
#define TOK_MOD 280
#define TOK_UMINUS 281
#define TOK_SEMICOL 282
#define TOK_COMMA 283
#define TOK_LPAR 284
#define TOK_RPAR 285
#define TOK_LACC 286
#define TOK_RACC 287
#define TOK_STRING 288
#define TOK_DO 289
#define TOK_THEN 290
#define TOK_OR 291
#define TOK_AND 292
#define TOK_BOR 293
#define TOK_BXOR 294
#define TOK_BAND 295
#define TOK_SRL 296
#define TOK_SRA 297
#define TOK_SLL 298
#define TOK_NOT 299
#define TOK_BNOT 300
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    2,    2,    8,    1,    1,    3,    4,    5,
    5,    5,    6,    6,    7,    7,    9,    9,   10,   10,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   12,
   13,   13,   13,   13,   13,   13,   13,   13,   13,   13,
   13,   13,   13,   13,   13,   13,   13,   13,   13,   13,
   13,   13,   13,   13,   13,   13,   13,   13,   14,   14,
   15,   15,
};
static const YYINT yylen[] = {                            2,
    2,    1,    1,    2,    5,    1,    0,    3,    1,    1,
    1,    1,    1,    3,    1,    3,    1,    0,    1,    2,
    2,    7,    5,    5,    9,    7,    1,    1,    5,    4,
    3,    3,    3,    3,    3,    3,    3,    2,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    2,    2,    3,    3,    1,    1,    1,    1,    3,    1,
    1,    1,
};
static const YYINT yydefred[] = {                         0,
   12,   10,   11,    0,    0,    3,    0,    2,    4,    1,
    9,    0,    0,   13,    0,    0,    8,    0,   55,   56,
   57,    0,    0,    0,    0,    0,    0,    0,    0,   14,
   38,    0,   51,   52,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    5,   53,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   31,   32,   35,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   28,    0,    0,    0,   19,   27,
    0,    0,    0,    0,    0,    0,   30,   20,   21,    0,
    0,    0,   62,   61,    0,   60,    0,    0,    0,    0,
    0,    0,    0,    0,   24,    0,   59,   29,    0,    0,
    0,    0,   22,    0,   26,    0,   25,
};
static const YYINT yydgoto[] = {                          4,
   78,    5,    6,   26,    7,   13,   14,    8,   87,   88,
   89,   90,   91,  105,  106,
};
static const YYINT yysindex[] = {                      -243,
    0,    0,    0,    0, -243,    0, -244,    0,    0,    0,
    0, -266, -223,    0, -176, -239,    0, -244,    0,    0,
    0, -176, -176, -176, -176, -214,  198, -225, -212,    0,
    0,  -34,    0,    0, -176, -176, -176, -176, -176, -176,
 -176, -176, -176, -176, -176, -176, -176, -176, -176, -176,
 -176, -176, -176, -176, -243,    0,    0,  198,  -98,  -98,
  -98,  -98,  463,  463, -274, -274,    0,    0,    0,  285,
  296,  412,  423,  452, -127, -127, -127,  -94, -243, -244,
 -220, -218, -215, -213,    0,  -94, -205,  -94,    0,    0,
   -5, -176, -176, -176, -247, -178,    0,    0,    0,   24,
   53,   82,    0,    0, -272,    0, -187,  -94,  -94, -176,
 -247, -169, -176, -146,    0,  111,    0,    0,  140,  -94,
 -176, -161,    0,  169,    0,  -94,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -191,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -63, -183,    0, -191,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -219,    0,    0, -125,  481,  507,
  533,  559,  564,  586,  227,  256,    0,    0,    0, -229,
  -89, -189, -165,  320,  325,  354,  383, -156, -152,    0,
    0,    0,    0,    0,    0,    0,    0, -154,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -123,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,   67,   -3,   -6,   -4,    0,  124,  141,    0,    0,
  -36,  127,  -15,    0,   45,
};
#define YYTABLESIZE 881
static const YYINT yytable[] = {                         27,
   12,    9,   15,   44,   45,   46,   31,   32,   33,   34,
  111,   29,  112,    1,    2,   11,    3,   16,   11,   58,
   59,   60,   61,   62,   63,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   73,   74,   75,   76,   77,    7,
  103,    7,    7,    7,    7,   28,    7,    7,    7,   96,
   80,   98,   44,   44,   35,   44,   15,    7,   17,   18,
   55,   44,    7,   92,    7,   93,    7,    7,   94,    7,
   95,  114,  115,   29,   80,    9,  100,  101,  102,    7,
    7,   97,   19,  123,   20,   21,   11,  107,  104,  127,
   15,   15,   46,   46,  116,   46,  113,  119,   16,   16,
   22,   46,   46,   46,  104,  124,    6,   23,    6,    6,
    6,    6,  118,    6,    6,    6,   47,   47,  120,   47,
  125,   79,   24,   25,    6,   47,   47,   47,   47,    6,
   18,    6,   17,    6,    6,   23,    6,   23,   23,   23,
   23,   30,   23,   23,   23,   10,    6,    6,   42,   43,
   44,   45,   46,   23,   56,  117,   54,   54,   23,   54,
   23,    0,   23,   23,   19,   23,   20,   21,   11,   81,
    0,   82,   83,   84,    0,   23,   23,   42,   43,   44,
   45,   46,   22,    0,    0,    0,    0,   85,    0,   23,
    0,   55,   43,   43,   86,   43,    0,   52,   53,   54,
    0,   43,   43,    0,   24,   25,   58,   58,   58,   58,
   58,   58,   58,   58,   58,   58,   58,    0,   58,   58,
    0,   58,    0,    0,    0,    0,    0,   58,   58,   58,
   58,   58,   58,   58,   58,   36,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,    0,    0,    0,    0,
   57,    0,    0,    0,    0,    0,   47,   48,   49,   50,
   51,   52,   53,   54,   36,   37,   38,   39,   40,   41,
   42,   43,   44,   45,   46,    0,   99,    0,    0,    0,
    0,    0,    0,    0,    0,   47,   48,   49,   50,   51,
   52,   53,   54,   36,   37,   38,   39,   40,   41,   42,
   43,   44,   45,   46,    0,    0,    0,    0,  108,    0,
    0,    0,    0,    0,   47,   48,   49,   50,   51,   52,
   53,   54,   36,   37,   38,   39,   40,   41,   42,   43,
   44,   45,   46,    0,    0,    0,    0,  109,    0,    0,
    0,    0,    0,   47,   48,   49,   50,   51,   52,   53,
   54,   36,   37,   38,   39,   40,   41,   42,   43,   44,
   45,   46,    0,  110,    0,    0,    0,    0,    0,    0,
    0,    0,   47,   48,   49,   50,   51,   52,   53,   54,
   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,
   46,    0,  121,    0,    0,    0,    0,    0,    0,    0,
    0,   47,   48,   49,   50,   51,   52,   53,   54,   36,
   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,
    0,    0,    0,    0,  122,    0,    0,    0,    0,    0,
   47,   48,   49,   50,   51,   52,   53,   54,   36,   37,
   38,   39,   40,   41,   42,   43,   44,   45,   46,    0,
    0,    0,    0,  126,    0,    0,    0,    0,    0,   47,
   48,   49,   50,   51,   52,   53,   54,   36,   37,   38,
   39,   40,   41,   42,   43,   44,   45,   46,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   47,   48,
   49,   50,   51,   52,   53,   54,   33,   33,   33,   33,
   33,   33,   33,   33,    0,    0,    0,    0,   33,   33,
    0,   33,    0,    0,    0,    0,    0,   33,   33,   33,
   33,   33,   33,   33,   33,   34,   34,   34,   34,   34,
   34,   34,   34,    0,    0,    0,    0,   34,   34,    0,
   34,    0,    0,    0,    0,    0,   34,   34,   34,   34,
   34,   34,   34,   34,   36,   37,   38,   39,   40,   41,
   42,   43,   44,   45,   46,   36,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   48,   49,   50,   51,
   52,   53,   54,    0,    0,    0,    0,    0,   49,   50,
   51,   52,   53,   54,   48,   48,   48,   48,   48,   48,
    0,   45,   45,    0,   45,    0,   48,   48,    0,   48,
   45,   45,   45,   45,   45,   48,   48,   48,   48,   48,
   48,   48,   48,   49,   49,   49,   49,   49,   49,    0,
    0,    0,    0,    0,    0,   49,   49,    0,   49,    0,
    0,    0,    0,    0,   49,   49,   49,   49,   49,   49,
   49,   49,   50,   50,   50,   50,   50,   50,    0,    0,
    0,    0,    0,    0,   50,   50,    0,   50,    0,    0,
    0,    0,    0,   50,   50,   50,   50,   50,   50,   50,
   50,   36,   37,   38,   39,   40,   41,   42,   43,   44,
   45,   46,   36,   37,   38,   39,   40,   41,   42,   43,
   44,   45,   46,    0,    0,   50,   51,   52,   53,   54,
    0,    0,    0,    0,    0,    0,    0,   51,   52,   53,
   54,   36,   37,   38,   39,   40,   41,   42,   43,   44,
   45,   46,   36,   37,   38,   39,    0,    0,   42,   43,
   44,   45,   46,    0,    0,    0,    0,   52,   53,   54,
   39,   39,   39,   39,   39,   39,    0,    0,   52,   53,
   54,    0,   39,   39,    0,   39,    0,    0,    0,    0,
    0,   39,   39,   39,   39,   39,   40,   40,   40,   40,
   40,   40,    0,    0,    0,    0,    0,    0,   40,   40,
    0,   40,    0,    0,    0,    0,    0,   40,   40,   40,
   40,   40,   37,   37,   37,   37,   37,   37,    0,    0,
    0,    0,    0,    0,   37,   37,    0,   37,    0,    0,
    0,    0,    0,   37,   37,   37,   37,   37,   36,   36,
   36,   36,   36,   36,    0,    0,    0,   41,   41,    0,
   36,   36,    0,   36,    0,   41,   41,    0,   41,   36,
   36,   36,   36,   36,   41,   41,   41,   41,   41,   42,
   42,    0,    0,    0,    0,    0,    0,   42,   42,    0,
   42,    0,    0,    0,    0,    0,   42,   42,   42,   42,
   42,
};
static const YYINT yycheck[] = {                         15,
    7,    5,  269,  278,  279,  280,   22,   23,   24,   25,
  283,   18,  285,  257,  258,  263,  260,  284,  263,   35,
   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,
   46,   47,   48,   49,   50,   51,   52,   53,   54,  259,
  288,  261,  262,  263,  264,  285,  266,  267,  268,   86,
   55,   88,  282,  283,  269,  285,  269,  277,  282,  283,
  286,  291,  282,  284,  284,  284,  286,  287,  284,  289,
  284,  108,  109,   80,   79,   79,   92,   93,   94,  299,
  300,  287,  259,  120,  261,  262,  263,  266,   95,  126,
  282,  283,  282,  283,  110,  285,  284,  113,  282,  283,
  277,  291,  292,  293,  111,  121,  259,  284,  261,  262,
  263,  264,  282,  266,  267,  268,  282,  283,  265,  285,
  282,   55,  299,  300,  277,  291,  292,  293,  294,  282,
  287,  284,  287,  286,  287,  259,  289,  261,  262,  263,
  264,   18,  266,  267,  268,    5,  299,  300,  276,  277,
  278,  279,  280,  277,   28,  111,  282,  283,  282,  285,
  284,   -1,  286,  287,  259,  289,  261,  262,  263,  264,
   -1,  266,  267,  268,   -1,  299,  300,  276,  277,  278,
  279,  280,  277,   -1,   -1,   -1,   -1,  282,   -1,  284,
   -1,  286,  282,  283,  289,  285,   -1,  296,  297,  298,
   -1,  291,  292,   -1,  299,  300,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,  282,  283,
   -1,  285,   -1,   -1,   -1,   -1,   -1,  291,  292,  293,
  294,  295,  296,  297,  298,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  280,   -1,   -1,   -1,   -1,
  285,   -1,   -1,   -1,   -1,   -1,  291,  292,  293,  294,
  295,  296,  297,  298,  270,  271,  272,  273,  274,  275,
  276,  277,  278,  279,  280,   -1,  282,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  291,  292,  293,  294,  295,
  296,  297,  298,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,   -1,   -1,   -1,   -1,  285,   -1,
   -1,   -1,   -1,   -1,  291,  292,  293,  294,  295,  296,
  297,  298,  270,  271,  272,  273,  274,  275,  276,  277,
  278,  279,  280,   -1,   -1,   -1,   -1,  285,   -1,   -1,
   -1,   -1,   -1,  291,  292,  293,  294,  295,  296,  297,
  298,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,   -1,  282,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  291,  292,  293,  294,  295,  296,  297,  298,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
  280,   -1,  282,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  291,  292,  293,  294,  295,  296,  297,  298,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
   -1,   -1,   -1,   -1,  285,   -1,   -1,   -1,   -1,   -1,
  291,  292,  293,  294,  295,  296,  297,  298,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  280,   -1,
   -1,   -1,   -1,  285,   -1,   -1,   -1,   -1,   -1,  291,
  292,  293,  294,  295,  296,  297,  298,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  291,  292,
  293,  294,  295,  296,  297,  298,  270,  271,  272,  273,
  274,  275,  276,  277,   -1,   -1,   -1,   -1,  282,  283,
   -1,  285,   -1,   -1,   -1,   -1,   -1,  291,  292,  293,
  294,  295,  296,  297,  298,  270,  271,  272,  273,  274,
  275,  276,  277,   -1,   -1,   -1,   -1,  282,  283,   -1,
  285,   -1,   -1,   -1,   -1,   -1,  291,  292,  293,  294,
  295,  296,  297,  298,  270,  271,  272,  273,  274,  275,
  276,  277,  278,  279,  280,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  280,  292,  293,  294,  295,
  296,  297,  298,   -1,   -1,   -1,   -1,   -1,  293,  294,
  295,  296,  297,  298,  270,  271,  272,  273,  274,  275,
   -1,  282,  283,   -1,  285,   -1,  282,  283,   -1,  285,
  291,  292,  293,  294,  295,  291,  292,  293,  294,  295,
  296,  297,  298,  270,  271,  272,  273,  274,  275,   -1,
   -1,   -1,   -1,   -1,   -1,  282,  283,   -1,  285,   -1,
   -1,   -1,   -1,   -1,  291,  292,  293,  294,  295,  296,
  297,  298,  270,  271,  272,  273,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,  282,  283,   -1,  285,   -1,   -1,
   -1,   -1,   -1,  291,  292,  293,  294,  295,  296,  297,
  298,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  270,  271,  272,  273,  274,  275,  276,  277,
  278,  279,  280,   -1,   -1,  294,  295,  296,  297,  298,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  295,  296,  297,
  298,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  270,  271,  272,  273,   -1,   -1,  276,  277,
  278,  279,  280,   -1,   -1,   -1,   -1,  296,  297,  298,
  270,  271,  272,  273,  274,  275,   -1,   -1,  296,  297,
  298,   -1,  282,  283,   -1,  285,   -1,   -1,   -1,   -1,
   -1,  291,  292,  293,  294,  295,  270,  271,  272,  273,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,
   -1,  285,   -1,   -1,   -1,   -1,   -1,  291,  292,  293,
  294,  295,  270,  271,  272,  273,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,  282,  283,   -1,  285,   -1,   -1,
   -1,   -1,   -1,  291,  292,  293,  294,  295,  270,  271,
  272,  273,  274,  275,   -1,   -1,   -1,  274,  275,   -1,
  282,  283,   -1,  285,   -1,  282,  283,   -1,  285,  291,
  292,  293,  294,  295,  291,  292,  293,  294,  295,  274,
  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,   -1,
  285,   -1,   -1,   -1,   -1,   -1,  291,  292,  293,  294,
  295,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 300
#define YYUNDFTOKEN 318
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TOK_VOID","TOK_INT","TOK_INTVAL",
"TOK_BOOL","TOK_TRUE","TOK_FALSE","TOK_IDENT","TOK_IF","TOK_ELSE","TOK_WHILE",
"TOK_FOR","TOK_PRINT","TOK_AFFECT","TOK_GE","TOK_LE","TOK_GT","TOK_LT","TOK_EQ",
"TOK_NE","TOK_PLUS","TOK_MINUS","TOK_MUL","TOK_DIV","TOK_MOD","TOK_UMINUS",
"TOK_SEMICOL","TOK_COMMA","TOK_LPAR","TOK_RPAR","TOK_LACC","TOK_RACC",
"TOK_STRING","TOK_DO","TOK_THEN","TOK_OR","TOK_AND","TOK_BOR","TOK_BXOR",
"TOK_BAND","TOK_SRL","TOK_SRA","TOK_SLL","TOK_NOT","TOK_BNOT",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : listdeclnonnull maindecl",
"program : maindecl",
"listdeclnonnull : vardecl",
"listdeclnonnull : listdeclnonnull vardecl",
"maindecl : type ident TOK_LPAR TOK_RPAR block",
"listdecl : listdeclnonnull",
"listdecl :",
"vardecl : type listtypedecl TOK_SEMICOL",
"ident : TOK_IDENT",
"type : TOK_INT",
"type : TOK_BOOL",
"type : TOK_VOID",
"listtypedecl : decl",
"listtypedecl : listtypedecl TOK_COMMA decl",
"decl : ident",
"decl : ident TOK_AFFECT expr",
"listinst : listinstnonnull",
"listinst :",
"listinstnonnull : inst",
"listinstnonnull : listinstnonnull inst",
"inst : expr TOK_SEMICOL",
"inst : TOK_IF TOK_LPAR expr TOK_RPAR inst TOK_ELSE inst",
"inst : TOK_IF TOK_LPAR expr TOK_RPAR inst",
"inst : TOK_WHILE TOK_LPAR expr TOK_RPAR inst",
"inst : TOK_FOR TOK_LPAR expr TOK_SEMICOL expr TOK_SEMICOL expr TOK_RPAR inst",
"inst : TOK_DO inst TOK_WHILE TOK_LPAR expr TOK_RPAR TOK_SEMICOL",
"inst : block",
"inst : TOK_SEMICOL",
"inst : TOK_PRINT TOK_LPAR listparamprint TOK_RPAR TOK_SEMICOL",
"block : TOK_LACC listdecl listinst TOK_RACC",
"expr : expr TOK_MUL expr",
"expr : expr TOK_DIV expr",
"expr : expr TOK_PLUS expr",
"expr : expr TOK_MINUS expr",
"expr : expr TOK_MOD expr",
"expr : expr TOK_LT expr",
"expr : expr TOK_GT expr",
"expr : TOK_MINUS expr",
"expr : expr TOK_GE expr",
"expr : expr TOK_LE expr",
"expr : expr TOK_EQ expr",
"expr : expr TOK_NE expr",
"expr : expr TOK_AND expr",
"expr : expr TOK_OR expr",
"expr : expr TOK_BAND expr",
"expr : expr TOK_BOR expr",
"expr : expr TOK_BXOR expr",
"expr : expr TOK_SRL expr",
"expr : expr TOK_SRA expr",
"expr : expr TOK_SLL expr",
"expr : TOK_NOT expr",
"expr : TOK_BNOT expr",
"expr : TOK_LPAR expr TOK_RPAR",
"expr : ident TOK_AFFECT expr",
"expr : TOK_INTVAL",
"expr : TOK_TRUE",
"expr : TOK_FALSE",
"expr : ident",
"listparamprint : listparamprint TOK_COMMA paramprint",
"listparamprint : paramprint",
"paramprint : ident",
"paramprint : TOK_STRING",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 385 "grammar.y"


/* A completer et/ou remplacer avec d'autres fonctions */
node_t make_node(node_nature nature, int nops, ...) {
    va_list ap;
    node_t node = new_node();
    if(node == NULL)
    {
        yyerror(&node, NO_MEMORY);
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
            node->value = yylval.intval;
            break;
        
        case(NODE_STRINGVAL):
            node->str = yylval.strval;
            break;
        
        case(NODE_TYPE):
            va_start(ap, nops);
            node->type = va_arg(ap, node_type);
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
                node->opr[i] = va_arg(ap, node_t);
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

#line 637 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 88 "grammar.y"
	{
            yyval.ptr = make_node(NODE_PROGRAM, 2, yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr);
            *program_root = yyval.ptr;
        }
break;
case 2:
#line 93 "grammar.y"
	{
            yyval.ptr = make_node(NODE_PROGRAM, 2, NULL, yystack.l_mark[0].ptr);
            *program_root = yyval.ptr;
        }
break;
case 3:
#line 101 "grammar.y"
	{
            yyval.ptr = yystack.l_mark[0].ptr;
        }
break;
case 4:
#line 105 "grammar.y"
	{
            yyval.ptr = make_node(NODE_DECLS, 2, yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr);
        }
break;
case 5:
#line 112 "grammar.y"
	{
            yyval.ptr = make_node(NODE_FUNC, 3, yystack.l_mark[-4].ptr, yystack.l_mark[-3].ptr, yystack.l_mark[0].ptr);
        }
break;
case 6:
#line 119 "grammar.y"
	{
            yyval.ptr =yystack.l_mark[0].ptr;
        }
break;
case 7:
#line 123 "grammar.y"
	{
            yyval.ptr = NULL;
        }
break;
case 8:
#line 130 "grammar.y"
	{
            yyval.ptr = make_node(NODE_DECLS, 2, yystack.l_mark[-2].ptr, yystack.l_mark[-1].ptr);
        }
break;
case 9:
#line 137 "grammar.y"
	{
            yyval.ptr = make_node(NODE_IDENT, 0);
        }
break;
case 10:
#line 144 "grammar.y"
	{
            yyval.ptr = make_node(NODE_TYPE, 1, TYPE_INT);
        }
break;
case 11:
#line 148 "grammar.y"
	{
            yyval.ptr = make_node(NODE_TYPE, 1, TYPE_BOOL);
        }
break;
case 12:
#line 152 "grammar.y"
	{
            yyval.ptr = make_node(NODE_TYPE, 1, TYPE_VOID);
        }
break;
case 13:
#line 159 "grammar.y"
	{
            yyval.ptr = yystack.l_mark[0].ptr;
        }
break;
case 14:
#line 163 "grammar.y"
	{
            yyval.ptr = make_node(NODE_LIST, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 15:
#line 170 "grammar.y"
	{
            yyval.ptr = make_node(NODE_LIST, 2, yystack.l_mark[0].ptr, NULL);
        }
break;
case 16:
#line 174 "grammar.y"
	{
            yyval.ptr = make_node(NODE_LIST, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 17:
#line 181 "grammar.y"
	{
            yyval.ptr = yystack.l_mark[0].ptr;
        }
break;
case 18:
#line 185 "grammar.y"
	{
            yyval.ptr = NULL;
        }
break;
case 19:
#line 192 "grammar.y"
	{
            yyval.ptr = yystack.l_mark[0].ptr;
        }
break;
case 20:
#line 196 "grammar.y"
	{
            yyval.ptr = make_node(NODE_LIST, 2, yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr);
        }
break;
case 21:
#line 203 "grammar.y"
	{
			yyval.ptr = yystack.l_mark[-1].ptr;
		}
break;
case 22:
#line 207 "grammar.y"
	{
			yyval.ptr = make_node(NODE_IF, 3, yystack.l_mark[-4].ptr, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 23:
#line 211 "grammar.y"
	{
			yyval.ptr = make_node(NODE_IF, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 24:
#line 215 "grammar.y"
	{
			yyval.ptr = make_node(NODE_WHILE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 25:
#line 219 "grammar.y"
	{
			yyval.ptr = make_node(NODE_FOR, 4, yystack.l_mark[-6].ptr, yystack.l_mark[-4].ptr, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 26:
#line 223 "grammar.y"
	{
			yyval.ptr = make_node(NODE_DOWHILE, 2, yystack.l_mark[-5].ptr, yystack.l_mark[-2].ptr);
		}
break;
case 27:
#line 227 "grammar.y"
	{
			yyval.ptr = yystack.l_mark[0].ptr;
		}
break;
case 28:
#line 231 "grammar.y"
	{
			yyval.ptr = NULL;
		}
break;
case 29:
#line 235 "grammar.y"
	{
			yyval.ptr = make_node(NODE_PRINT, 1, yystack.l_mark[-2].ptr);
		}
break;
case 30:
#line 242 "grammar.y"
	{
            yyval.ptr = make_node(NODE_BLOCK, 2, yystack.l_mark[-2].ptr, yystack.l_mark[-1].ptr);
        }
break;
case 31:
#line 249 "grammar.y"
	{
            yyval.ptr = make_node(NODE_MUL, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 32:
#line 253 "grammar.y"
	{
            yyval.ptr = make_node(NODE_DIV, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 33:
#line 257 "grammar.y"
	{
            yyval.ptr = make_node(NODE_PLUS, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 34:
#line 261 "grammar.y"
	{
            yyval.ptr = make_node(NODE_MINUS, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 35:
#line 265 "grammar.y"
	{
            yyval.ptr = make_node(NODE_MOD, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 36:
#line 269 "grammar.y"
	{
            yyval.ptr = make_node(NODE_LT, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 37:
#line 273 "grammar.y"
	{
            yyval.ptr = make_node(NODE_GT, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 38:
#line 277 "grammar.y"
	{
            yyval.ptr = make_node(NODE_UMINUS, 1, yystack.l_mark[0].ptr);
        }
break;
case 39:
#line 281 "grammar.y"
	{
            yyval.ptr = make_node(NODE_GE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 40:
#line 285 "grammar.y"
	{
            yyval.ptr = make_node(NODE_LE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 41:
#line 289 "grammar.y"
	{
            yyval.ptr = make_node(NODE_EQ, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 42:
#line 293 "grammar.y"
	{
            yyval.ptr = make_node(NODE_NE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 43:
#line 297 "grammar.y"
	{
            yyval.ptr = make_node(NODE_AND, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 44:
#line 301 "grammar.y"
	{
            yyval.ptr = make_node(NODE_OR, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 45:
#line 305 "grammar.y"
	{
            yyval.ptr = make_node(NODE_BAND, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 46:
#line 309 "grammar.y"
	{
            yyval.ptr = make_node(NODE_BOR, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 47:
#line 313 "grammar.y"
	{
            yyval.ptr = make_node(NODE_BXOR, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 48:
#line 317 "grammar.y"
	{
            yyval.ptr = make_node(NODE_SRL, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 49:
#line 321 "grammar.y"
	{
            yyval.ptr = make_node(NODE_SRA, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 50:
#line 325 "grammar.y"
	{
            yyval.ptr = make_node(NODE_SLL, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 51:
#line 329 "grammar.y"
	{
            yyval.ptr = make_node(NODE_NOT, 1, yystack.l_mark[0].ptr);
        }
break;
case 52:
#line 333 "grammar.y"
	{
            yyval.ptr = make_node(NODE_BNOT, 1, yystack.l_mark[0].ptr);
        }
break;
case 53:
#line 337 "grammar.y"
	{
            yyval.ptr = yystack.l_mark[-1].ptr;
        }
break;
case 54:
#line 341 "grammar.y"
	{
            yyval.ptr = make_node(NODE_AFFECT, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 55:
#line 345 "grammar.y"
	{
            yyval.ptr = make_node(NODE_INTVAL, 0);
        }
break;
case 56:
#line 349 "grammar.y"
	{
            yyval.ptr = make_node(NODE_BOOLVAL, 1, 1);
        }
break;
case 57:
#line 353 "grammar.y"
	{
            yyval.ptr = make_node(NODE_BOOLVAL, 1, 0);
        }
break;
case 58:
#line 357 "grammar.y"
	{
            yyval.ptr = yystack.l_mark[0].ptr;
        }
break;
case 59:
#line 365 "grammar.y"
	{
            yyval.ptr = make_node(NODE_LIST, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        }
break;
case 60:
#line 369 "grammar.y"
	{
            yyval.ptr = yystack.l_mark[0].ptr;
        }
break;
case 61:
#line 376 "grammar.y"
	{
            yyval.ptr = yystack.l_mark[0].ptr;
        }
break;
case 62:
#line 380 "grammar.y"
	{
            yyval.ptr = make_node(NODE_STRINGVAL, 0);
        }
break;
#line 1213 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
