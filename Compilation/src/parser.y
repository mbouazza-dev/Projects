%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "traduc.h"
int yyparse();
int yylex();
int yyerror(char *s);
extern int lineno;
extern int c;
extern char linebuf[500];
Node *arbre;
%}

%union {
    Node *node;
    char id[100];
    char type[100];
    int num;
    char caractere;
    char comp[100];
    char addsub;
    char cond_logical[100];
    char condition[100];
    char print[100];
    char read[100];
    char boucle[100];
}


%type <node> Prog DeclVars Declarateurs DeclFoncts DeclFonct EnTeteFonct Corps ListTypVar Parametres SuiteInstr Instr LValue Arguments ListExp Exp TB FB M E T F
%token <num> NUM
%token <caractere> CHARACTER
%token <id> IDENT
%token <type> TYPE 
%token <comp> EQ ORDER 
%token <cond_logical> OR AND
%token <addsub> ADDSUB
%token <return> RETURN
%token <condition> IF
%token <print> PRINT
%token <read> READC READE 
%token <void> VOID 
%token <boucle> WHILE
%nonassoc else_priority
%nonassoc ELSE

%%
Prog:  DeclVars DeclFoncts {
                                $$ = makeNode(Program);
                                Node *tmp = makeNode(VarDeclList);
                                Node *tmp2 = makeNode(FunDeclList);
                                addChild($$, tmp);
                                addChild(tmp, $1);
                                addChild($$, tmp2);
                                addChild(tmp2, $2);
                                /*printTree($$);*/
                                arbre = $$; 
                            }
    ;
DeclVars:
       DeclVars TYPE Declarateurs ';' {
                                        if(strcmp($2, "int") == 0){
                                            $$ = makeNode(Int);
                                        }
                                        else{
                                            $$ = makeNode(Char);
                                        }
                                        addSibling($$, $1);
                                        addChild($$, $3);
                                    }
    | {$$ = NULL;} ;
Declarateurs:
       Declarateurs ',' IDENT {
                                $$ = makeNode(VarDec);
                                addSibling($$, $1);
                                Node *node = makeNode(Identifier);
                                strcpy(node->u.identifier, $3);
                                addChild($$, node);
                            }
    |  Declarateurs ',' '*' IDENT {
                                    $$ = makeNode(VarDec);
                                    addSibling($$, $1);
                                    Node *node = makeNode(Pointeur);
                                    addChild($$, node);
                                    Node *node_id = makeNode(Identifier);
                                    strcpy(node_id->u.identifier, $4);
                                    addChild(node, node_id);
                                }
    |  IDENT {
                $$ = makeNode(VarDec);
                Node *node = makeNode(Identifier);
                strcpy(node->u.identifier, $1);
                addChild($$, node);
            }
    |  '*' IDENT {
                    $$ = makeNode(VarDec);
                    Node *node = makeNode(Pointeur);
                    addChild($$, node);
                    Node *node_id = makeNode(Identifier);
                    strcpy(node_id->u.identifier, $2);
                    addChild(node, node_id);
                }
    ;
DeclFoncts:
       DeclFoncts DeclFonct {
                                $$ = makeNode(FunDec);
                                addSibling($$, $1);
                                addChild($$, $2);
                            }
    |  DeclFonct {
                    $$ = makeNode(FunDec);
                    addChild($$, $1);
                }
    ;
DeclFonct:
       EnTeteFonct Corps {
                            $$ = $1;
                            addSibling($$, $2);
                        }
    ;
EnTeteFonct:
       TYPE IDENT '(' Parametres ')' {
                                        if(strcmp($1, "int") == 0){
                                            $$ = makeNode(Int);
                                        }
                                        else{
                                            $$ = makeNode(Char);
                                        }
                                        Node *node = makeNode(Identifier);
                                        strcpy(node->u.identifier, $2);
                                        addChild($$, node);
                                        addChild($$, $4);
                                    }
    |  TYPE '*' IDENT '(' Parametres ')' {
                                            if(strcmp($1, "int") == 0){
                                                $$ = makeNode(Int);
                                            }
                                            else{
                                                $$ = makeNode(Char);
                                            }
                                            Node *node = makeNode(Pointeur);
                                            addChild($$, node); 
                                            Node *node_id = makeNode(Identifier);
                                            strcpy(node_id->u.identifier, $3);
                                            addChild($$, node_id);
                                            addChild($$, $5);
                                    }
    |  VOID IDENT '(' Parametres ')' {
                                        $$ = makeNode(Void);
                                        Node *node_id = makeNode(Identifier);
                                        strcpy(node_id->u.identifier, $2);
                                        addChild($$, node_id);
                                        addChild($$, $4);
                                    }
    ;
Parametres:
       VOID {
                $$ = makeNode(ParamList);
            }
    |  ListTypVar {
                    $$ = makeNode(ParamList);
                    addChild($$, $1);
                    }
    ;
ListTypVar:
       ListTypVar ',' TYPE IDENT {
                                    if(strcmp($3, "int") == 0){
                                        $$ = makeNode(Int);
                                    }
                                    else{
                                        $$ = makeNode(Char);
                                    }
                                    addSibling($$, $1);
                                    Node *node_id = makeNode(Identifier);
                                    strcpy(node_id->u.identifier, $4);
                                    addChild($$, node_id);                               
                                }
    |  ListTypVar ',' TYPE '*' IDENT {
                                        if(strcmp($3, "int") == 0){
                                            $$ = makeNode(Int);
                                        }
                                        else{
                                            $$ = makeNode(Char);
                                        }
                                        addSibling($$, $1);
                                        Node *node = makeNode(Pointeur);
                                        addChild($$, node);
                                        Node *node_id = makeNode(Identifier);
                                        strcpy(node_id->u.identifier, $5);
                                        addChild(node, node_id);
                                    }
    |  TYPE IDENT   {
                        if(strcmp($1, "int") == 0){
                            $$ = makeNode(Int);
                        }
                        else{
                            $$ = makeNode(Char);
                        }
                        Node *node_id = makeNode(Identifier);
                        strcpy(node_id->u.identifier, $2);
                        addChild($$, node_id);                    
                    }
    |  TYPE '*' IDENT {
                        if(strcmp($1, "int") == 0){
                            $$ = makeNode(Int);
                        }
                        else{
                            $$ = makeNode(Char);
                        }
                        Node *node = makeNode(Pointeur);
                        addChild($$, node); 
                        Node *node_id = makeNode(Identifier);
                        strcpy(node_id->u.identifier, $3);
                        addChild(node, node_id);                     
                    }
    ;
Corps: '{' DeclVars SuiteInstr '}' {
                                        $$ = makeNode(Body);
                                        Node *tmp = makeNode(VarDeclList);
                                        Node *tmp2 = makeNode(SuiteInstr);
                                        addChild($$, tmp);
                                        addChild(tmp, $2);
                                        addChild($$, tmp2);
                                        addChild(tmp2, $3);                                  
                                    }
    ;
SuiteInstr:
       SuiteInstr Instr {
                            $$ = makeNode(Instr);
                            addSibling($$, $1);
                            addChild($$, $2);
                        }
    | {$$ = NULL;} ;
Instr:
       LValue '=' Exp ';' {
                            $$ = makeNode(Assign);
                            addChild($$, $1);
                            addChild($$, $3);
                          }
    |  READE '(' IDENT ')' ';' {
                                $$ = makeNode(ReadE);
                                Node *node_id = makeNode(Identifier);
                                strcpy(node_id->u.identifier, $3);
                                addChild($$, node_id);                                
                                }
    |  READC '(' IDENT ')' ';' {
                                $$ = makeNode(ReadC);
                                Node *node_id = makeNode(Identifier);
                                strcpy(node_id->u.identifier, $3);
                                addChild($$, node_id);
                                }
    |  PRINT '(' Exp ')' ';' {
                                $$ = makeNode(Print);
                                addChild($$, $3);
                            }
    |  IF '(' Exp ')' Instr      %prec else_priority {
                                                        $$ = makeNode(Condition);
                                                        addChild($$, $3);
                                                        Node *node = makeNode(ConditionTrue);
                                                        addChild($$, node);
                                                        addChild(node, $5);
                                                    }
    |  IF '(' Exp ')' Instr ELSE Instr {
                                            $$ = makeNode(Condition);
                                            addChild($$, $3);
                                            Node *node_if = makeNode(ConditionTrue);
                                            addChild($$, node_if);
                                            addChild(node_if, $5);
                                            Node *node_else = makeNode(Else);
                                            addChild($$, node_else);
                                            addChild(node_else, $7);
                                        }
    |  WHILE '(' Exp ')' Instr {
                                    $$ = makeNode(WhileBoucle);
                                    Node *node = makeNode(Condition);
                                    addChild($$, node);
                                    addChild(node, $3);
                                    Node *node_true = makeNode(ConditionTrue);
                                    addChild($$, node_true);
                                    addChild(node_true, $5);
                                }
    |  IDENT '(' Arguments  ')' ';' {
                                        $$ = makeNode(Identifier);
                                        strcpy($$->u.identifier, $1);
                                        Node *node = makeNode(ArgList);                                        
                                        addChild(node, $3);
                                    }
    |  RETURN Exp ';' {
                            $$ = makeNode(Return);
                            addChild($$, $2);
                          }
    |  RETURN ';'   {
                        $$ = makeNode(Return);
                    }
    |  '{' SuiteInstr '}' {
                            $$ = $2;
                          }
    |  ';' {$$ = NULL;} 
    ;
Exp :  Exp OR TB { 
                    $$ = makeNode(Or);
                    addChild($$, $1);
                    addChild($$, $3);
                }
    |  TB {
            $$ = $1;
        }
    ;
TB  :  TB AND FB { 
                    $$ = makeNode(And);
                    addChild($$, $1);
                    addChild($$, $3);
                }
    |  FB {
            $$ = $1;
            }
    ;
FB  :  FB EQ M {
                    if(strcmp($2, "==") == 0){
                        $$ = makeNode(Equal);
                    }
                    else{
                        $$ = makeNode(NotEqual);
                    }
                    addChild($$, $1);
                    addChild($$, $3);   
                }
    |  M {
            $$ = $1;
        }
    ;
M   :  M ORDER E {
                    if(strcmp($2, "<") == 0){
                        $$ = makeNode(Less);
                    }
                    else if (strcmp($2, "<=") == 0){
                        $$ = makeNode(LessOrEqual);
                    }
                    else if (strcmp($2, ">") == 0){
                        $$ = makeNode(Greater);
                    }
                    else{
                        $$ = makeNode(GreaterOrEqual);
                    }
                    addChild($$, $1);
                    addChild($$, $3);   
                }
    |  E {
            $$ = $1;
        }
    ;
E   :  E ADDSUB T {
                    if($2 == '+'){
                        $$ = makeNode(Add);
                    }
                    else{
                        $$ = makeNode(Sub);
                    }
                    addChild($$, $1);
                    addChild($$, $3);
                }
    |  T {
            $$ = $1;
        }
    ;    
T   :  T '*' F {
                    $$ = makeNode(Multiply);
                    addChild($$, $1);
                    addChild($$, $3);
                }
    |  T '/' F {
                    $$ = makeNode(Div);
                    addChild($$, $1);
                    addChild($$, $3);
                }
    |  T '%' F {
                    $$ = makeNode(Mod);
                    addChild($$, $1);
                    addChild($$, $3);
                }
    |  F {
            $$ = $1;
        }
    ;
F   :  ADDSUB F {
                    if($1 == '+'){
                        $$ = makeNode(Add);
                    }
                    else{
                        $$ = makeNode(Sub);
                    }
                    addChild($$, $2);   
                }
    |  '!' F {
                $$ = makeNode(Not);
                addChild($$, $2);
            }
    |  '&' IDENT {
                    $$ = makeNode(Adress);
                    Node *node_id = makeNode(Identifier);
                    strcpy(node_id->u.identifier, $2);
                    addChild($$, node_id);
                }
    |  '(' Exp ')' {
                        $$ = $2;
                    }
    |  NUM {
                $$ = makeNode(IntLiteral);
                $$->u.integer = $1;
            }
    |  CHARACTER {
                    $$ = makeNode(CharLiteral);
                    $$->u.character = $1;
                }
    |  LValue {
                $$ = $1;
                }
    |  IDENT '(' Arguments  ')' {
                                        $$ = makeNode(Identifier);
                                        strcpy($$->u.identifier, $1);
                                        addChild($$, $3);
                                }
    |  '*' IDENT '(' Arguments  ')' {
                                        $$ = makeNode(Pointeur); 
                                        Node *node_id = makeNode(Identifier);
                                        strcpy(node_id->u.identifier, $2);
                                        addChild($$, node_id);
                                        addChild(node_id, $4);
                                    }
    ;
LValue:
       IDENT {
                $$ = makeNode(Identifier);
                strcpy($$->u.identifier, $1);
            }
    |  '*' IDENT {
                    $$ = makeNode(Pointeur);
                    Node *node = makeNode(Identifier);
                    strcpy(node->u.identifier, $2);
                    addChild($$, node);
                }
    ;
Arguments:
       ListExp {
                $$ = makeNode(ListExpr);
                addChild($$, $1);
                }
    | {$$ = NULL;} ;
ListExp:
       ListExp ',' Exp {
                            $$ = makeNode(Expr);
                            addSibling($$, $1);
                            addChild($$, $3);
                        }
    |  Exp {
                $$ = makeNode(Expr);
                addChild($$, $1);
            }
    ;
%%

int yyerror(char *s){
	int i;
    if(linebuf != NULL){
	  	fprintf(stderr, "%s near line %d at:\n %s \n", s, lineno, linebuf);
        for (i = 0; i < c - 1; i++){
            printf(" ");
        }
        printf("^\n");
    }
    return 1;
}

int main(int argc, char** argv) {
    if(yyparse() == 0){
        construire_tab(arbre);
        if(erreurs > 0){
            printf("%d erreur(s) détecté(s) dans le programme\n", erreurs);
            return -1;
        }
        else{
            /*afficher_tab();*/
            traduc_into_asm(arbre); /*traduc de l'arbre en fichier asm si celui-ci est correcte*/
        }
        free_tab();
    }
    else if(yyparse() == 1){
        return 1;
    }
    return 0;
}