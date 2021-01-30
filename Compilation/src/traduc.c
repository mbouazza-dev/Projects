#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "traduc.h"

FILE* fichier;

static const char *StringFromKind[] = {
  "Program",
  "VarDeclList",
  "IntLiteral",
  "CharLiteral",
  "Identifier",
  "VarDec",
  "FunDeclList",
  "FunDec",
  "ParamList",
  "Param",
  "Pointeur",
  "Body",
  "Char",
  "Int",
  "EnTeteFonct",
  "Void",
  "SuiteInstr",
  "Instr",
  "LValue",
  "Assign",
  "Return",
  "Expr",
  "Or",
  "And",
  "Add",
  "Sub",
  "ReadE",
  "ReadC",
  "Print",
  "Condition",
  "ConditionTrue",
  "Else",
  "WhileBoucle",
  "Equal",
  "NotEqual",
  "Greater",
  "Less",
  "GreaterOrEqual",
  "LessOrEqual",
  "Multiply",
  "Div",
  "Mod",
  "Not",
  "Adress",
  "ArgList",
  "ListExpr"
  /* and all other node labels */
  /* The list must coincide with the enum in abstract-tree.h */
  /* To avoid listing them twice, see https://stackoverflow.com/a/10966395 */
};

extern int nb_var_globales; /*from symbTab.c*/

void traduc_header(){
	fichier = fopen("test.asm", "w");
	if(fichier == NULL){
		exit(EXIT_FAILURE);
	}
	rewind(fichier);
	fprintf(fichier, "global _start				;\n");
	fprintf(fichier, "extern printf				;\n");
	fprintf(fichier, "section .bss				;\n");
	fprintf(fichier, "__static:					;\n");
	fprintf(fichier, "	resb %d					;\n", 8*nb_var_globales);
	fprintf(fichier, "section .data				;\n");
	fprintf(fichier, "__format_int:				;\n");
	fprintf(fichier, "	db \"%%d\", 10, 0			;\n");
	fprintf(fichier, "section .text				;\n");
	fprintf(fichier, "_start:						;\n");
	fprintf(fichier, "	call main				;\n");
	fprintf(fichier, "	mov rax, 60				;\n");
	fprintf(fichier, "	mov rdi, 0				;\n");
	fprintf(fichier, "	syscall					;\n");
	fclose(fichier);
}

void traduc_assign(){
	fprintf(fichier, "	pop rbx					;\n");
	fprintf(fichier, "	pop rax					;\n");
	fprintf(fichier, "	mov qword [rax], rbx	;\n");
}

void traduc_print(Node *node){
	if(strcmp(StringFromKind[node->kind], "Identifier") == 0){
		if(node->portee == GLOBALE){
			traduc_var_global(node->pos);
		}
		else{
			traduc_var_local(node->pos);
		}
		traduc_valueOf();
	}	
	fprintf(fichier, "	mov rdi, __format_int	;\n");
	fprintf(fichier, "	pop rsi					;\n");
	fprintf(fichier, "	xor rax, rax			;\n");
	fprintf(fichier, "	call printf				;\n");
}

void traduc_intLiteral(Node *op){
	fprintf(fichier, "	push %d 					;\n", op->u.integer);
}

void traduc_var_local(int pos){
	fprintf(fichier, "	lea rax, [rbp - %d]      ;\n", 8*pos);
	fprintf(fichier, "	push rax     			;\n");
}

void traduc_var_global(int pos){
	fprintf(fichier, "	lea rax, [__static + %d] ;\n", 8*pos);
	fprintf(fichier, "	push rax     			;\n");
}


void traduc_operation(Node *op){
	if(strcmp(StringFromKind[op->kind], "CharLiteral") == 0){
		fprintf(fichier, "	char					;\n");
	}
	if(strcmp(StringFromKind[op->kind], "Add") == 0){
		fprintf(fichier, "	pop rbx					;\n");
		fprintf(fichier, "	pop rax					;\n");
		fprintf(fichier, "	add rax, rbx			;\n");
		fprintf(fichier, "	push rax				;\n");
		traduc_operation(op->firstChild);
		traduc_operation(op->firstChild->nextSibling);
	}
	else if(strcmp(StringFromKind[op->kind], "Sub") == 0){
		fprintf(fichier, "	pop rbx					;\n");
		fprintf(fichier, "	pop rax					;\n");
		fprintf(fichier, "	sub rax, rbx			;\n");
		fprintf(fichier, "	push rax				;\n");
		traduc_operation(op->firstChild);
		traduc_operation(op->firstChild->nextSibling);

	}
	else if(strcmp(StringFromKind[op->kind], "Multiply") == 0){
		fprintf(fichier, "	pop rbx					;\n");
		fprintf(fichier, "	pop rax					;\n");
		fprintf(fichier, "	imul rax, rbx			;\n");
		fprintf(fichier, "	push rax				;\n");
		traduc_operation(op->firstChild);
		traduc_operation(op->firstChild->nextSibling);
	}
	else if(strcmp(StringFromKind[op->kind], "Div") == 0){
		fprintf(fichier, "	pop rbx					;\n");
		fprintf(fichier, "	pop rax					;\n");
		fprintf(fichier, "	idiv rbx				;\n");
		fprintf(fichier, "	push rax				;\n");
		traduc_operation(op->firstChild);
		traduc_operation(op->firstChild->nextSibling);
	}
	else if(strcmp(StringFromKind[op->kind], "Mod") == 0){
		fprintf(fichier, "	pop rbx					;\n");
		fprintf(fichier, "	pop rax					;\n");
		fprintf(fichier, "	idiv rbx				;\n");
		fprintf(fichier, "	push rdx				;\n");
		fprintf(fichier, "	push rax				;\n");
		traduc_operation(op->firstChild);
		traduc_operation(op->firstChild->nextSibling);
	}
	else if(strcmp(StringFromKind[op->kind], "Identifier") == 0){
		if(op->portee == GLOBALE){
			traduc_var_global(op->pos);
		}
		else{
			traduc_var_local(op->pos);
		}
		traduc_valueOf();
	}
	else if(strcmp(StringFromKind[op->kind], "IntLiteral") == 0){
		fprintf(fichier, "	push %d 				;\n", op->u.integer);
	}
}

void traduc_main(){
	fichier = fopen("test.asm", "a");
	if(fichier == NULL){
		exit(EXIT_FAILURE);
	}
	fprintf(fichier, "main:                    	;\n");
	fprintf(fichier, "\tmov rbp, rsp			;\n");
	fprintf(fichier, "\tsub rsp, 8				;\n");
	fclose(fichier);
}

void traduc_footer(){
	fprintf(fichier, "	add rsp, 8     		;\n");
	fprintf(fichier, "	mov rsp, rbp     		;\n");
	fprintf(fichier, "	ret     				;\n");
}

void traduc_instr(Node *instr){
	if(instr == NULL){
		return;
	}
	if(strcmp(StringFromKind[instr->kind], "Return") == 0){
		traduc_footer();
	}
	else if(strcmp(StringFromKind[instr->kind], "Print") == 0){
		traduc_print(instr->firstChild);
	}
	else if(strcmp(StringFromKind[instr->kind], "Assign") == 0){
		traduc_instr(instr->firstChild);
		traduc_instr(instr->firstChild->nextSibling);
		traduc_assign();
	}
	else if(strcmp(StringFromKind[instr->kind], "IntLiteral") == 0){
		traduc_intLiteral(instr);
	}
	else if(strcmp(StringFromKind[instr->kind], "Identifier") == 0){
		if(instr->portee == GLOBALE){
			traduc_var_global(instr->pos);
		}
		else{
			traduc_var_local(instr->pos);
		}
	}
	else{
		traduc_operation(instr);
	}
}

void traduc_suite_instr(Node *suite_instr){
	fichier = fopen("test.asm", "a");
	while(suite_instr->firstChild != NULL){
		traduc_instr(suite_instr->firstChild->firstChild);
		suite_instr->firstChild = suite_instr->firstChild->nextSibling;
	}
	fclose(fichier);
}

void traduc_fct(Node *fct){
	if(strcmp(fct->firstChild->firstChild->u.identifier, "main") == 0){
		traduc_main();
	}
	else{
		fichier = fopen("test.asm", "a");
		fprintf(fichier, "%s:                    	;\n", fct->firstChild->firstChild->u.identifier);
		fclose(fichier);
	}
	traduc_suite_instr(fct->firstChild->nextSibling->firstChild->nextSibling);
}

void traduc_into_asm(Node *arbre){
	traduc_header();
	while(arbre->firstChild->nextSibling->firstChild != NULL){
		traduc_fct(arbre->firstChild->nextSibling->firstChild);
		arbre->firstChild->nextSibling->firstChild = arbre->firstChild->nextSibling->firstChild->nextSibling;
	}
}

void traduc_valueOf(){
	fprintf(fichier, "	pop rax					;\n");
	fprintf(fichier, "	push qword [rax]		;\n");
}