/* symbTab.h */

#include "abstract-tree.h"


/* Structure représentant un symbole dans la table des symboles*/
typedef struct {
	int portee;
	char ident[20];
	int variable;
	char type[20];
	char adresse[20];
	int nb_param;
	char param_type[10][10];
	int lineno;
}Symbole;


#define GLOBALE 1
#define LOCALE 2
#define PARAMETRE 3
#define FIRST_PARAM 0
#define ERREUR_REDEC -1
#define ERREUR_CONFLIT -2
#define NON_DEC -3
#define CONFLIT_PARAM -4
#define TYPE_INT 4
#define TYPE_CHAR 5

extern Symbole *tab;
extern int nb_symb;
extern char param_type[10][10];
extern int erreurs;
extern int nb_var_globales;


/*Vérifie si les variables d'une fonction ont été déclarées*/
void verif_var_func(Node *arbre);

/*Parcours d'un arbre de racine instruction (Fonction utilisée dans la fonction ci-dessus)*/
int verif_instr(Node *arbre);

/*Recherche dans la table des symboles si une variable avec le nom en paramètre existe déjà*/
/*Renvoie 1 si oui, sinon renvoie 0*/
int rechercher_symbole(char *nom);

/*Vérifie si le symbole qu'on souhaite ajouter avec un nom et un type est bien un nouveau symbole*/
/*Rnvoie 1 si c'est un nouveau symbole, sinon renvoie un entier négatif qui diffère selon le cas*/
int est_nv_symbole(char *nom, char *type);

/*Permet l'ajout d'une nouvelle variable.
Renvoie le nombre de symbole ajouté dans la table, sinon renvoie -1 si le symbole est déjà
présent (on y appelle la fonction ci-dessus)*/
int addVar(char *nom, char *type, int portee);

/*Permet l'ajout d'une nouvelle fonction*/
void addFunc(char *nom, char *type, int nb_param);

/*Permet l'ajout des types des paramètres d'une fonction*/
void add_type_param_function(char param_type[10][10]);

/*Renvoie le nombre de paramètre(s) d'une fonction*/
int func_params(Node *arbre, int i);

/*Vérifie si une variable ou fonction est un pointeur*/
/*Renvoie 1 si c'est le cas, sinon renvoie 0*/
int est_pointeur(Kind kind);

/*Construit la table des symboles pour les variables*/
void construire_tab_var(Node *arbre, int portee);

/*Construit la table des symboles pour les fonctions.
On y appelle également la fonction précédente pour les variables locales déclarées*/
void construire_tab_func(Node *arbre);

/*Construit la table des symboles entière à l'aide des deux fonctions précédentes*/
void construire_tab(Node *arbre);

/*Affiche un symbole*/
void afficher_symbole(Symbole symb);

/*Affiche la table des symboles*/
void afficher_tab();

/*Affiche les erreurs concernant les variables*/
void afficher_erreur_variable(int erreur, char *nom, const char *type);

/*Ajout des paramètres d'une fonction dans la table des symboles*/
void construire_tab_param(Node *arbre);

/*Libération de la mémoire de la table des symboles*/
void free_tab();

/*Verification d'éventuelles erreurs au niveau des variables locales d'une fonction*/
int verif_var_local_func(Node *arbre, Node *params);

/*Verification si le nom d'un symbole en paramètre est présent dans le tableau en paramètre*/
int symb_local_present(char *nom, const char *type, char tab[10][10], char tab_type[10][5]);

/*Vérifie si une variable déclarée localement n'est pas déjà présente dans les paramètres de la fonction*/
int varLocal_in_param_func(Node *arbre, char *nom);


int operators(Node *op, Node *global, Node *param, Node *local);

/*Recherche si la variable renvoyée par une fonction est une variable locale de la fonction*/
int search_identifier_in_varLocal(Node *id, Node *local);

/*Recherche si la variable renvoyée par une fonction est un paramètre de la fonction*/
int search_identifier_in_params(Node *id, Node *param);

/*Recherche si la variable renvoyée par une fonction est une variable globale*/
int search_identifier_in_global(Node *id, Node *global);

void typage_instr(Node *global, Node *suite_instr, Node *params, Node *locals);

void typage_fct(Node *fct, Node *global);

int control_return_func(Node *fct);

int verif_ret(Node *op, char fct_type[8]);

int verif_assign(Node *assign);

int compare_type_lval_rval(Node *lval, Node *rval);

int val_instr(Node *node, Node *global, Node *param, Node *local);

int bool_op(Node *node, Node *global, Node *param, Node *local);