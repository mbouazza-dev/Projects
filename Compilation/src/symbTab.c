/* symbTab.c */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "symbTab.h"
extern int lineno;       /* from lexer */


Symbole *tab;
int nb_symb = 0;
char param_type[10][10];
int erreurs = 0;
int nb_var_globales = 0;

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



void verif_var_func(Node *arbre){
	Node *node_instr = arbre->firstChild;

	while(node_instr != NULL){
		verif_instr(node_instr);
		node_instr = node_instr->nextSibling;
	}
}

int verif_instr(Node *arbre){
	if(arbre == NULL){
		return 0;
	}
	if(arbre->firstChild == NULL){
		if(strcmp("Identifier", StringFromKind[arbre->kind]) == 0){
			if(!rechercher_symbole(arbre->u.identifier)){
				erreurs++;
			}
		}
		return 1;
	}
	if(arbre->firstChild->nextSibling == NULL){
		return verif_instr(arbre->firstChild);
	}
	return verif_instr(arbre->firstChild) && verif_instr(arbre->firstChild->nextSibling);
}

int rechercher_symbole(char *nom){
	int i;

	for(i = 0; i < nb_symb; i++){
		if(strcmp(nom, tab[i].ident) == 0){
			return 1;
		}
	}
	afficher_erreur_variable(NON_DEC, nom, "");
	return 0;	
}

int est_nv_symbole(char *nom, char *type){
	int i;

	for(i = 0; i < nb_symb; i++){
		if(strcmp(nom, tab[i].ident) == 0){
			if(strcmp(type, tab[i].type) == 0){
				afficher_erreur_variable(ERREUR_REDEC, nom, type);
				erreurs++;
				return ERREUR_REDEC;
			}
			else{
				erreurs++;
				afficher_erreur_variable(ERREUR_CONFLIT, nom, type);
				return ERREUR_CONFLIT;
			}
		}
	}
	return 1;
}

int addVar(char *nom, char *type, int portee){
	int nv_symb;

	if(tab == NULL){
		tab = (Symbole*)malloc(sizeof(Symbole));
		if(tab == NULL){
			exit(EXIT_FAILURE);
		}
	}
	if(portee == GLOBALE){
		nv_symb = est_nv_symbole(nom, type);
		if(!nv_symb){
			return -1;
		}
	}
	tab = (Symbole*)realloc(tab, sizeof(Symbole) * (nb_symb + 1));
	strcpy(tab[nb_symb].ident, nom);
	tab[nb_symb].variable = 1;
	tab[nb_symb].portee = portee;
	strcpy(tab[nb_symb].type, type);
	sprintf(tab[nb_symb].adresse, "%p", &tab[nb_symb].ident);
	nb_symb++;	
	if(portee == GLOBALE){
		nb_var_globales++;
	}
	return nb_symb;
}

void addFunc(char *nom, char *type, int nb_param){
	if(tab == NULL){
		tab = (Symbole*)malloc(sizeof(Symbole));
		if(tab == NULL){
			exit(EXIT_FAILURE);
		}
	}
	else{
		tab = (Symbole*)realloc(tab, sizeof(Symbole) * (nb_symb + 1));
	}
	strcpy(tab[nb_symb].ident, nom);
	tab[nb_symb].nb_param = nb_param;
	add_type_param_function(tab[nb_symb].param_type);
	strcpy(tab[nb_symb].type, type);
	sprintf(tab[nb_symb].adresse, "%p", &tab[nb_symb].ident);
	nb_symb++;
}

void add_type_param_function(char param[10][10]){
	int i;

	i = 0;
	while(strcmp(param_type[i], "") != 0){
		strcpy(param[i], param_type[i]);
		i++;
	}
}

int func_params(Node *arbre, int i){
	if(arbre == NULL){
		return 0;
	}
	strcpy(param_type[i], StringFromKind[arbre->kind]);
	if(est_pointeur(arbre->firstChild->kind)){
		strcat(param_type[i], "*");
	}
	return 1 + func_params(arbre->nextSibling, i + 1);
}

int est_pointeur(Kind kind){
	return (strcmp("Pointeur", StringFromKind[kind]) == 0);
}

void construire_tab_var(Node *arbre, int portee){
	char type[10];
	char pointeur[15];
	Node *noeud_type = arbre->firstChild;

	while(noeud_type != NULL){
		strcpy(type, StringFromKind[noeud_type->kind]);
		strcpy(pointeur, type);
		strcat(pointeur, "*");
		if(est_pointeur(noeud_type->firstChild->firstChild->kind)){
			addVar(noeud_type->firstChild->firstChild->firstChild->u.identifier, pointeur, portee);
		}
		else{
			if(portee == GLOBALE){
				noeud_type->firstChild->firstChild->portee = GLOBALE;
				noeud_type->firstChild->firstChild->pos = nb_var_globales;
			}
			else{
				noeud_type->firstChild->firstChild->portee = LOCALE;
			}
			addVar(noeud_type->firstChild->firstChild->u.identifier, type, portee);
		}
		Node *sibling = noeud_type->firstChild->nextSibling;
		while(sibling != NULL){
			if(est_pointeur(sibling->firstChild->kind)){
				addVar(sibling->firstChild->firstChild->u.identifier, pointeur, portee);
			}
			else{
				if(portee == GLOBALE){
					sibling->firstChild->portee = GLOBALE;
					sibling->firstChild->pos = nb_var_globales;
				}
				else{
					sibling->firstChild->portee = LOCALE;
				}
				addVar(sibling->firstChild->u.identifier, type, portee);
			}
			sibling = sibling->nextSibling;
		}
		noeud_type = noeud_type->nextSibling;
	}
}

void construire_tab_func(Node *arbre){
	char type[10];
	char pointeur[15];
	int nb_param;
	int erreur_local;
	Node *noeud_fct = arbre->firstChild;

	while(noeud_fct != NULL){
		if(est_pointeur(noeud_fct->firstChild->firstChild->kind)){
			strcpy(type, StringFromKind[noeud_fct->firstChild->kind]);
			strcpy(pointeur, type);
			strcat(pointeur, "*");
			nb_param = func_params(noeud_fct->firstChild->firstChild->nextSibling->nextSibling->firstChild, FIRST_PARAM);
			addFunc(noeud_fct->firstChild->firstChild->nextSibling->u.identifier, pointeur, nb_param);
			construire_tab_var(noeud_fct->firstChild->nextSibling->firstChild, LOCALE);		
		}
		else{
			if(strcmp("Int", StringFromKind[noeud_fct->firstChild->kind])){
				strcpy(type, StringFromKind[noeud_fct->firstChild->kind]);
			}
			else if (strcmp("Char", StringFromKind[noeud_fct->firstChild->kind])){
				strcpy(type, StringFromKind[noeud_fct->firstChild->kind]);
			}
			else if (strcmp("Void", StringFromKind[noeud_fct->firstChild->kind])){
				strcpy(type, StringFromKind[noeud_fct->firstChild->kind]);
			}
			else{
				return;
			}
			nb_param = func_params(noeud_fct->firstChild->firstChild->nextSibling->firstChild, FIRST_PARAM);
			addFunc(noeud_fct->firstChild->firstChild->u.identifier, type, nb_param);
			construire_tab_param(noeud_fct->firstChild->firstChild->nextSibling);
			erreur_local = verif_var_local_func(noeud_fct->firstChild->nextSibling->firstChild->firstChild, noeud_fct->firstChild->firstChild->nextSibling);
			if(erreur_local == 0){
				construire_tab_var(noeud_fct->firstChild->nextSibling->firstChild, LOCALE);
			}
			else{
				erreurs += erreur_local; 
			}
			if(noeud_fct->firstChild->nextSibling->firstChild->nextSibling != NULL){
				verif_var_func(noeud_fct->firstChild->nextSibling->firstChild->nextSibling);
			}		
		}
		noeud_fct = noeud_fct->nextSibling;
	}
}

void construire_tab(Node *arbre){
    construire_tab_var(arbre->firstChild, GLOBALE);
    construire_tab_func(arbre->firstChild->nextSibling);
    /*Typage fonction*/
    Node *global_var = NULL;
    if(arbre->firstChild->firstChild != NULL){
    	global_var = arbre->firstChild->firstChild;
    }
    Node *fct = arbre->firstChild->nextSibling->firstChild;
    while(fct != NULL){
    	typage_fct(fct, global_var);
    	if(control_return_func(fct) == -1){
    		erreurs++;
    	}
    	fct = fct->nextSibling;
    }
}

void afficher_param(char param[10][10], int nb_param){
	int i;

	for(i = 0; i < nb_param; i++){
		printf("%s ", param[i]);
	}
}

void afficher_symbole(Symbole symb){
	printf("%s", symb.ident);
	printf("	%s", symb.type);
	if(symb.variable){
		switch(symb.portee){
			case GLOBALE: printf("		Globale 	"); break;
			case LOCALE: printf("		Locale 		"); break;
			case PARAMETRE: printf("		Parametre 	");
		}
		printf("	variable		%s\n", symb.adresse);
	}
	else{
		printf("					fonction		%s 			%d 			", symb.adresse, symb.nb_param);
		afficher_param(symb.param_type, symb.nb_param);
	}
}

void afficher_tab(){
	int i;

	printf("Table des symboles:\nNom	Type		Portée (Variable)	Catégorie		Adresse			Nb Param (Fonction)		Type Param(s) (Fonction)\n");
	for(i = 0; i < nb_symb; i++){
		afficher_symbole(tab[i]);
		printf("\n");
	}
}

void afficher_erreur_variable(int erreur, char *nom, const char *type){
	switch(erreur){
		case ERREUR_REDEC: 
			printf("Erreur: Redéclaration d'une variable %s de type %s\n", nom, type);
			break;
		case ERREUR_CONFLIT:
			printf("Erreur Conflit: Variable %s d'un autre type déjà existant\n", nom);
			break;
		case NON_DEC:
			printf("Erreur: %s non déclarée\n", nom);
			break;
		case CONFLIT_PARAM:
			printf("Erreur Conflit: Une autre variable de nom %s est déclarée dans les paramètres\n", nom);
			break;
	}
}

void free_tab(){
	free(tab);
}

void construire_tab_param(Node *arbre){
	char type[10];
	char pointeur[15];
	Node *noeud_type = arbre->firstChild;
	while(noeud_type != NULL){
		strcpy(type, StringFromKind[noeud_type->kind]);;
		if(est_pointeur(noeud_type->firstChild->kind)){
			strcpy(pointeur, type);
			strcat(pointeur, "*");
			addVar(noeud_type->firstChild->firstChild->u.identifier, pointeur, PARAMETRE);
		}
		else{
			addVar(noeud_type->firstChild->u.identifier, type, PARAMETRE);
		}
		noeud_type = noeud_type->nextSibling;
	}
}

int symb_local_present(char *nom, const char *type, char tab[10][10], char tab_type[10][5]){
	int i;
	for(i = 0; strcmp(tab[i], "") != 0; i++){
		if(strcmp(nom, tab[i]) == 0){
			if(strcmp(type, tab_type[i]) == 0){
				afficher_erreur_variable(ERREUR_REDEC, nom, type);
			}
			else{
				afficher_erreur_variable(ERREUR_CONFLIT, nom, "");
			}
			return 1;
		}
	}
	return 0;
}

int verif_var_local_func(Node *arbre, Node *params){
	char tab[10][10];
	char tab_type[10][5];
	int i, nb_erreur;
	i = 0;
	nb_erreur = 0;
	while(arbre != NULL){
		if(varLocal_in_param_func(params->firstChild, arbre->firstChild->firstChild->u.identifier)){
			afficher_erreur_variable(CONFLIT_PARAM, arbre->firstChild->firstChild->u.identifier, "");
			nb_erreur++;
		}
		else{
			if (symb_local_present(arbre->firstChild->firstChild->u.identifier, StringFromKind[arbre->kind], tab, tab_type)){
				nb_erreur++;
			}
		}
		strcpy(tab[i], arbre->firstChild->firstChild->u.identifier);
		strcpy(tab_type[i], StringFromKind[arbre->kind]);
		i++;
		arbre = arbre->nextSibling;
	}
	return nb_erreur;
}

int varLocal_in_param_func(Node *arbre, char *nom){
	while(arbre != NULL){
		if(strcmp(nom, arbre->firstChild->u.identifier) == 0){
			return 1;
		}
		arbre = arbre->nextSibling;
	}
	return 0;
}

int search_identifier_in_varLocal(Node *id, Node *local){
	while(local != NULL){
		Node* var = local->firstChild;
		while(var != NULL){
			if(strcmp(var->firstChild->u.identifier, id->u.identifier) == 0){
				if(strcmp(StringFromKind[local->kind], "Int") == 0){
					id->type = TYPE_INT;
				}
				else{
					id->type = TYPE_CHAR;
				}
				id->portee = var->firstChild->portee;
				return 1;
			}
			var = var->nextSibling;
		}
		local = local->nextSibling;
	}
	return 0;
}

int search_identifier_in_params(Node *id, Node *param){
	while(param != NULL){
		if(strcmp(param->firstChild->u.identifier, id->u.identifier) == 0){
			if(strcmp(StringFromKind[param->kind], "Int") == 0){
				id->type = TYPE_INT;
			}
			else{
				id->type = TYPE_CHAR;
			}
			id->portee = param->firstChild->portee;
			return 1;
		}
		param = param->nextSibling;
	}
	return 0;
}

int search_identifier_in_global(Node *id, Node *global){
	while(global != NULL){
		Node *var_dec = global->firstChild;
		while(var_dec != NULL){
			if(strcmp(var_dec->firstChild->u.identifier, id->u.identifier) == 0){
				if(strcmp(StringFromKind[global->kind], "Int") == 0){
					id->type = TYPE_INT;
				}
				else{
					id->type = TYPE_CHAR;
				}
				id->pos = var_dec->firstChild->pos;
				id->portee = var_dec->firstChild->portee;
				return 1;
			}
			var_dec = var_dec->nextSibling;
		}
		global = global->nextSibling;
	}
	return 0;
}


int operators(Node *node, Node *global, Node *param, Node *local){
	if(strcmp(StringFromKind[node->kind], "Add") == 0){
		return operators(node->firstChild, global, param, local) && operators(node->firstChild->nextSibling, global, param, local);
	}
	if(strcmp(StringFromKind[node->kind], "Sub") == 0){
		return operators(node->firstChild, global, param, local) && operators(node->firstChild->nextSibling, global, param, local);
	}
	if(strcmp(StringFromKind[node->kind], "Multiply") == 0){
		return operators(node->firstChild, global, param, local) && operators(node->firstChild->nextSibling, global, param, local);
	}
	if(strcmp(StringFromKind[node->kind], "Div") == 0){
		return operators(node->firstChild, global, param, local) && operators(node->firstChild->nextSibling, global, param, local);
	}
	if(strcmp(StringFromKind[node->kind], "Add") == 0 || strcmp(StringFromKind[node->kind], "Or") == 0){
		return bool_op(node, global, param, local);
	}
	if(strcmp(StringFromKind[node->kind], "IntLiteral") == 0){
		node->type = TYPE_INT;
		return TYPE_INT;
	}
	if(search_identifier_in_varLocal(node, local) == 1){
		return 1;
	}
	if(search_identifier_in_params(node, param) == 1){
		return 2;
	}
	if(search_identifier_in_global(node, global) == 1){
		return 3;
	}
	if(strcmp(StringFromKind[node->kind], "CharLiteral") == 0){
		node->type = TYPE_CHAR;
		return TYPE_CHAR;
	}
	return 0;
}

int bool_op(Node *node, Node *global, Node *param, Node *local){
	if(strcmp(StringFromKind[node->kind], "And") == 0){
		return bool_op(node->firstChild, global, param, local) && bool_op(node->firstChild->nextSibling, global, param, local);
	}
	if(strcmp(StringFromKind[node->kind], "OR") == 0){
		return bool_op(node->firstChild, global, param, local) && bool_op(node->firstChild->nextSibling, global, param, local);
	}
	if(strcmp(StringFromKind[node->kind], "IntLiteral") == 0){
		node->type = TYPE_INT;
		return TYPE_INT;
	}
	return 0;
}

void typage_instr(Node *global, Node *suite_instr, Node *param, Node *local){
	Node *instr = suite_instr->firstChild;
	while(instr != NULL){
		if(strcmp(StringFromKind[instr->firstChild->kind], "Return") == 0){
			if(val_instr(instr->firstChild->firstChild, global, param, local) == 0){
				erreurs++;
			}
		}
		if(strcmp(StringFromKind[instr->firstChild->kind], "Assign") == 0){
			if(val_instr(instr->firstChild->firstChild->nextSibling, global, param, local) == 0){
				erreurs++;
			}
			else{
				if(!verif_assign(instr->firstChild->firstChild->nextSibling)){
					erreurs++;
				}
				else{
					search_identifier_in_varLocal(instr->firstChild->firstChild, local);
					search_identifier_in_params(instr->firstChild->firstChild, param);
					search_identifier_in_global(instr->firstChild->firstChild, global);
					if(!compare_type_lval_rval(instr->firstChild->firstChild, instr->firstChild->firstChild->nextSibling)){
						erreurs++;
					}
				}
			}
		}
		if(strcmp(StringFromKind[instr->firstChild->kind], "WhileBoucle") == 0){
			/*Typage boucle (non fait)*/
		}
		instr = instr->nextSibling;
	}
}

void typage_fct(Node *fct, Node *global){
	Node *params = fct->firstChild->firstChild->nextSibling;
	Node *locals = fct->firstChild->nextSibling->firstChild;
	Node *suite_instr = fct->firstChild->nextSibling->firstChild->nextSibling;
	typage_instr(global, suite_instr, params->firstChild, locals->firstChild);
}

int control_return_func(Node *fct){
	char fct_type[8];
	Node *ret = fct->firstChild->nextSibling->firstChild->nextSibling->firstChild->firstChild;
	strcpy(fct_type, StringFromKind[fct->firstChild->kind]);
	if((strcmp(StringFromKind[ret->kind], "Return") == 0) && (strcmp(fct_type, "Void") == 0)){
		return -1;
	}
	if((strcmp(StringFromKind[ret->kind], "Return") != 0) && (strcmp(fct_type, "Void") != 0)){
		return -1;
	}
	if(strcmp(fct_type, "Int") == 0 && (strcmp(StringFromKind[ret->firstChild->kind], "Identifier") == 0 || strcmp(StringFromKind[ret->firstChild->kind], "CharLiteral") == 0 || strcmp(StringFromKind[ret->firstChild->kind], "IntLiteral") == 0)){
		if((strcmp(StringFromKind[ret->firstChild->kind], "Identifier") == 0) && ret->firstChild->type == TYPE_INT){
			return 1;
		}
		if((strcmp(StringFromKind[ret->firstChild->kind], "Identifier") == 0) && ret->firstChild->type == TYPE_CHAR){
			return -1;
		}
		if(strcmp(StringFromKind[ret->firstChild->kind], "CharLiteral") == 0){
			return -1;
		}
		if(strcmp(StringFromKind[ret->firstChild->kind], "IntLiteral") == 0){
			return 1;
		}
	}
	if(strcmp(fct_type, "Char") == 0 && (strcmp(StringFromKind[ret->firstChild->kind], "Identifier") == 0 || strcmp(StringFromKind[ret->firstChild->kind], "CharLiteral") == 0 || strcmp(StringFromKind[ret->firstChild->kind], "IntLiteral") == 0)){
		if((strcmp(StringFromKind[ret->firstChild->kind], "Identifier") == 0) && ret->firstChild->type == TYPE_CHAR){
			return 1;
		}
		if(strcmp(StringFromKind[ret->firstChild->kind], "CharLiteral") == 0){
			return 1;
		}
		if(strcmp(StringFromKind[ret->firstChild->kind], "IntLiteral") == 0){
			return -1;
		}
		return -1;
	}

	int val = verif_ret(ret->firstChild, fct_type);
	if(!val){
		return -1;
	}
	return 1;
}

int verif_ret(Node *op, char fct_type[8]){
	if(strcmp(StringFromKind[op->kind], "Add") == 0){
		return verif_ret(op->firstChild, fct_type) && verif_ret(op->firstChild->nextSibling, fct_type);
	}
	if(strcmp(StringFromKind[op->kind], "Sub") == 0){
		return verif_ret(op->firstChild, fct_type) && verif_ret(op->firstChild->nextSibling, fct_type);
	}
	if(strcmp(StringFromKind[op->kind], "Multiply") == 0){
		return verif_ret(op->firstChild, fct_type) && verif_ret(op->firstChild->nextSibling, fct_type);
	}
	if(strcmp(StringFromKind[op->kind], "Div") == 0){
		return verif_ret(op->firstChild, fct_type) && verif_ret(op->firstChild->nextSibling, fct_type);
	}
	if(strcmp(fct_type, "Int") == 0){
		if(op->type == TYPE_INT){
			return 1;
		}
		if(strcmp(StringFromKind[op->kind], "IntLiteral") == 0){
			return 1;
		}
		if(op->type == TYPE_CHAR){
			return 0;
		}
	}
	if(strcmp(fct_type, "Char") == 0){
		return 1;
	}
	return 0;
}

int verif_assign(Node *assign){
	if(strcmp(StringFromKind[assign->kind], "Add") == 0){
		return verif_assign(assign->firstChild) && verif_assign(assign->firstChild->nextSibling);
	}
	if(strcmp(StringFromKind[assign->kind], "Sub") == 0){
		return verif_assign(assign->firstChild) && verif_assign(assign->firstChild->nextSibling);
	}
	if(strcmp(StringFromKind[assign->kind], "Multiply") == 0){
		return verif_assign(assign->firstChild) && verif_assign(assign->firstChild->nextSibling);
	}
	if(strcmp(StringFromKind[assign->kind], "Div") == 0){
		return verif_assign(assign->firstChild) && verif_assign(assign->firstChild->nextSibling);
	}
	if(assign->type == TYPE_INT){
		return 1;
	}
	if(strcmp(StringFromKind[assign->kind], "IntLiteral") == 0){
		assign->type = TYPE_INT;
		return 1;
	}
	if(assign->type == TYPE_CHAR){
		return 1;
	}
	if(strcmp(StringFromKind[assign->kind], "CharLiteral") == 0){
		assign->type = TYPE_CHAR;
		return 1;
	}
	return 0;
}

int compare_type_lval_rval(Node *lval, Node *rval){
	if(lval->type == TYPE_INT){
		if(rval->type == TYPE_CHAR){
			return 0;
		}
		if((strcmp(StringFromKind[rval->kind], "Add") == 0) || strcmp(StringFromKind[rval->kind], "Sub") == 0 || strcmp(StringFromKind[rval->kind], "Multiply") == 0 || strcmp(StringFromKind[rval->kind], "Div") == 0){
			return lval->type && compare_type_lval_rval(lval, rval->firstChild) && compare_type_lval_rval(lval, rval->firstChild->nextSibling);
		}
		return 1;
	}
	if(lval->type == TYPE_CHAR){
		if(strcmp(StringFromKind[rval->kind], "Div") == 0){
			return 0;
		}
		return 1;
	}
	return lval->type && rval->type;
}

int val_instr(Node *node, Node *global, Node *param, Node *local){
	if(strcmp(StringFromKind[node->kind], "IntLiteral") == 0){
		return 1;
	}
	if(strcmp(StringFromKind[node->kind], "CharLiteral") == 0){
		return 1;
	}
	if(strcmp(StringFromKind[node->kind], "Sub") == 0){
		if(strcmp(StringFromKind[node->firstChild->kind], "IntLiteral") == 0 && node->firstChild->nextSibling == NULL){
			return 2;
		}
		if(strcmp(StringFromKind[node->firstChild->kind], "CharLiteral") == 0 && node->firstChild->nextSibling == NULL){
			return 0;
		}
		if(strcmp(StringFromKind[node->firstChild->kind], "Identifier") == 0 && node->firstChild->nextSibling == NULL){
			if(search_identifier_in_varLocal(node->firstChild, local) || search_identifier_in_params(node->firstChild, param) || search_identifier_in_global(node->firstChild, global)){
				if(node->firstChild->type == TYPE_CHAR){
					return 0;
				}
				else{
					return 2;
				}
			}
		}
	}
	if(strcmp(StringFromKind[node->kind], "Identifier") == 0 && node->nextSibling == NULL){
			if(search_identifier_in_varLocal(node, local) || search_identifier_in_params(node, param) || search_identifier_in_global(node, global)){
				if(node->type == TYPE_CHAR){
					return 0;
				}
				else{
					return 2;
				}
			}
	}
	return operators(node, global, param, local);
}