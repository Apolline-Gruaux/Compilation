#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"
#include "common.h"
#include "registers.h"
#include "mips_inst.h"

extern char * outfile;
extern int trace;
extern int registers;
extern bool syntaxicAnalysis;
extern bool verificationAnalysis;

void next_analyse(node_t n, void func());
void type_rec(node_t n, node_type type);
void analyse_block(node_t n);
void analyse_glob(node_t n);
void analyse_func(node_t n);
void analyse_print(node_t n);
void analyse(node_t n);
