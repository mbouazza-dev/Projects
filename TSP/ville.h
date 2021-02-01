#ifndef __VILLE__
#define __VILLE__
#define N 50

/*Representation d'une ville*/

typedef struct{
    char nom[N];
    int x;
    int y;
}Ville;

/* Fonction qui remplit un tableau de villes. */
/* Paramètres: Un tableau de structures de type Ville, un entier 'nb_villes' et un fichier. */
/* Renvoie 0 si le tableau s'est bien rempli. */

int recupererVille(Ville *villes, int nb_villes, FILE* fichier);

#endif