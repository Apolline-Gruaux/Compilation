#include "verification.h"

void next_analyse(node_t n, void f()){
	for (int i = 0 ; i < n->nops ; i++){
		if (n->opr[i]){
			f(n->opr[i]);
        }
    }
}

void type_rec(node_t n, node_type type){
	int i;

	switch(n->nature){

		case NODE_INTVAL:
		if (type != TYPE_INT){
			fprintf(stderr, "Error line %d: Variable of type other than TYPE INT has been initialized with an expression of type TYPE INT.\n", n->lineno);
			exit(-1);
		}
		break;

		case NODE_BOOLVAL:
		if (type != TYPE_BOOL){
			fprintf(stderr, "Error line %d: Variable of type other than TYPE BOOL has been initialized with an expression of type TYPE BOOL.\n", n->lineno);
			exit(-1);
		}
		break;

		case NODE_IDENT:
		n->type = type;
		break;

		default:
		for (i = 0 ; i < n->nops ; i++){
			if (n->opr[i]){
				type_rec(n->opr[i], type);
			}
		}
		break;
	}
}

void analyse_block(node_t n){
	push_context();
	next_analyse(n, analyse);
	pop_context();
}

void analyse_glob(node_t n){
	if (trace > 4){
		printf("Analyse %s\n", node_nature2string(n->nature));
	}
	switch(n->nature){

		case NODE_PLUS:
		case NODE_MINUS:
		case NODE_MUL:
		case NODE_DIV:
		case NODE_MOD:
		case NODE_LT:
		case NODE_GT:
		case NODE_LE:
		case NODE_GE:
		case NODE_EQ:
		case NODE_NE:
		case NODE_AND:
		case NODE_OR:
		case NODE_BAND:
		case NODE_BOR:
		case NODE_BXOR:
		case NODE_SRL:
		case NODE_SRA:
		case NODE_SLL:
		case NODE_NOT:
		case NODE_BNOT:
		case NODE_AFFECT:
		fprintf(stderr, "Error line %d: Global variables initialized without a constant value.\n", n->opr[0]->lineno);
		exit(-1);
		break;

		case NODE_DECLS:
		next_analyse(n, analyse_glob);
		type_rec(n->opr[1], n->opr[0]->type);
		break;

		case NODE_DECL:
		n->opr[0]->offset = env_add_element(n->opr[0]->ident, n, 4);
		if (n->opr[0]->offset == -1){
			fprintf(stderr, "Error line %d: Variable has been defined multiple times.\n", n->lineno);
			exit(-1);
		}
		next_analyse(n, analyse_glob);
		break;

		case NODE_INTVAL:
		n->type = TYPE_INT;
		break;

		case NODE_BOOLVAL:
		n->type = TYPE_BOOL;
		break;

		default:
		next_analyse(n, analyse_glob);
		break;
	}
}

void analyse_func(node_t n){
	reset_env_current_offset();
	reset_temporary_max_offset();

	if (n->opr[0]->type != TYPE_VOID){
		fprintf(stderr, "Error line %d: %s Type must be VOID.\n", n->opr[0]->lineno, node_type2string(n->opr[0]->type));
		exit(-1);
	}

	if (strcmp(n->opr[1]->ident,"main")){
		fprintf(stderr, "Error line %d: Function name '%s' must be 'main'.\n", n->opr[1]->lineno, n->opr[1]->ident);
		exit(-1);
	}

	analyse(n->opr[2]);
	n->offset = get_env_current_offset();
	n->stack_size = n->offset + get_temporary_max_offset();

	if (trace > 3){
		printf("temporary_curr_offset %d == 0\n", get_temporary_curr_offset());
		printf("current_reg %d == 8\n", get_current_reg());
		printf("max_temporary_offset = %d\n", get_temporary_max_offset());
	}
}

void analyse_print(node_t n){
	node_t node;

	switch (n->nature){

		case NODE_STRINGVAL:
		n->offset = add_string(n->str);
		n->type = TYPE_STRING;
		break;

		case NODE_IDENT:
		node = get_decl_node(n->ident);
		if (node){
			n->decl_node = node->opr[0];
			n->type = node->opr[0]->type;
		}
		else {
			fprintf(stderr, "Error line %d: Variable '%s' has not been declared.\n", n->lineno, n->ident);
			exit(-1);
		}
		break;

		default:
		next_analyse(n, analyse_print);
		break;
	}
}

void analyse(node_t n){
	if (trace > 4){
		printf("Analyse of %s\n", node_nature2string(n->nature));
	}

	if (trace > 3){
		printf("Current_reg %d\n", get_current_reg());
	}

	node_t node;

	switch(n->nature){

		case NODE_BLOCK:
	 	analyse_block(n);
	 	break;

		case NODE_DECLS:
		next_analyse(n, analyse);
		type_rec(n->opr[1], n->opr[0]->type);
		break;

		case NODE_DECL:
		n->opr[0]->offset = env_add_element(n->opr[0]->ident, n, 4);
		next_analyse(n, analyse);
		break;

		case NODE_PRINT:
		analyse_print(n->opr[0]);
		break;

		case NODE_IDENT:
		node = get_decl_node(n->ident);
		if (node){
			n->decl_node = node->opr[0];
			n->type = node->opr[0]->type;
		}
		else {
			fprintf(stderr, "Error line %d: Variable '%s' has not been declared.\n", n->lineno, n->ident);
			exit(-1);
		}
		break;

		case NODE_STRINGVAL:
		fprintf(stderr, "Error line %d: Strings are not authorized to appear in expressions.\n", n->lineno);
		exit(-1);
		break;

		case NODE_INTVAL:
		n->type = TYPE_INT;
		break;

		case NODE_BOOLVAL:
		n->type = TYPE_BOOL;
		break;

		case NODE_LT:
		case NODE_GT:
		case NODE_LE:
		case NODE_GE:						// meme verif

		case NODE_NOT:

		case NODE_AFFECT:

		case NODE_PLUS:
		case NODE_MINUS:
		case NODE_MUL:
		case NODE_DIV:
		case NODE_MOD:
		case NODE_BAND:
		case NODE_BOR:
		case NODE_BXOR:
		case NODE_SLL:
		case NODE_SRA:
		case NODE_SRL:						// meme verif

		case NODE_NE:
		case NODE_EQ:						// meme verif

		case NODE_AND:
		case NODE_OR:						// meme verif

		case NODE_UMINUS:
		case NODE_BNOT:						// meme verif

		case NODE_IF:
		case NODE_WHILE:					// meme verif

		case NODE_FOR:
		case NODE_DOWHILE:					// meme verif
		break;

		default:
		next_analyse(n, analyse);
		break;
	}
}
