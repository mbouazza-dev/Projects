#ifndef __MUTATION__
#define __MUTATION__

/*Representation d'une mutation*/

typedef struct mut{
    int j;
    int i;
    int l;
}Mutation;

/* Fonction qui remplis une structure a partir de 3 valeurs aléatoire. */
/* Paramètres: Un entier 'nb_villes'. */
/* Renvoie une structure Mutation. */

Mutation generation(int nb_villes);

/* Fonction qui remplis une structure a partir de 3 valeurs aléatoire. */
/* Paramètres: Un entier 'nb_villes'. */
/* Renvoie une structure Mutation. */

void mutation(Visite visites, int nb_villes);

#endif
