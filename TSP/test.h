#ifndef __TEST__
#define __TEST__

#include "ville.h"
#include "visite.h"

/* Fonction qui test les valeurs de retour de la fonction Generateur.*/
/* Paramètre: Aucun. */
/* Renvoie 1 si les test se sont bien passé, 0 sinon*/

int test_generateur(void);

/* Fonction qui test les valeurs de retour de la fonction de comparaison entre 2 longueurs.*/
/* Paramètre: Aucun. */
/* Renvoie 1 si les test se sont bien passé, 0 sinon*/

int test_compare(void);

/* Fonction qui réalise la mutation sur une permutation d'entiers. */

void mutation_int(int *tab, Mutation gen);

/* Fonction qui test les valeurs de retour de la fonction de mutation.*/
/* Paramètre: Aucun. */
/* Renvoie 1 si les test se sont bien passé, 0 sinon*/

int test_mutation(void);

int test(void);
    
#endif
