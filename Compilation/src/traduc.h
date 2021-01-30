/* traduc.h */

#include "symbTab.h"

void traduc_header();
void traduc_var_local(int pos);
void traduc_var_global(int pos);
void traduc_intLiteral(Node *op);
void traduc_fonction(Node *a);
void traduc_operation(Node *op);
void traduc_assign();
void traduc_main();
void traduc_print(Node *node);
void traduc_footer();
void traduc_into_asm(Node *arbre);
void traduc_instr(Node *instr);
void traduc_suite_instr(Node *suite_instr);
void traduc_fct(Node *fct);
void traduc_boucle_while(Node *node);
void traduc_valueOf();
