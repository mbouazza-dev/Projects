#ifndef __VISITE__
#define __VISITE__
#define K 128
#include "ville.h"

/*Representation d'une visite*/

typedef struct{
    Ville chemin[K];
    int distance; 
}Visite;

/*Representation d'une population*/

typedef struct population{
    Visite tab[K];
}Population;

/* Fonction qui calcule la longueur totale d'une visite. */
/* Paramètres: Un entier 'nb_villes' et un tableau de structure de type Ville. */
/* Renvoie la longueur totale d'une visite. */

void calculeDistance(Visite* visit, const int taille);

/* Fonction qui affiche les K visites. */
/* Paramètres: Un tableau de structure de type Visite et un entier 'nb_villes'. */

void affiche_visite(Visite visites[K], int nb_villes);

/* Fonction qui génère une visite. */
/* Paramètres: Un tableau de structures de type Ville, un entier 'nb_villes', un tableau de structures de type Visite et un entier 'indice' pour génèrer la visite à l'indice donné. */

Visite generer_visite(Ville tab[], int nb_villes);

/* Fonction qui compare deux distances. */
/* Paramètres: Deux pointeurs génériques 'a' et 'b'. */
/* Renvoie la différence des deux distances. */

int cmpdist(const void* a, const void* b);

/* Fonction qui remplis une structure de type Population en fonction de parametres permettant d'ameliorer les distances parcouru*/
/* Paramètres: Un pointeur sur une structure de type Population, un pointeur sur une structure de type Ville, 3 entiers Alpha, Beta, Gamma, et le nombre de villes*/

void nouvelle_population(Population* pop, Ville *villes, int alpha, int beta, int gamma, int nb_villes);

/* Fonction operant les Alpha permutation d'une population entrée en paramètre*/
/* Paramètres: Une structure de type Population, un entier Alpha, et le nombre de villes*/

void nouvelle_populationM(Population *pop, const int alpha, const int taille);

/* Fonction echangeant deux structures de type Ville données en paramètres*/

void echange(Ville *v1, Ville *v2);

/* Fonction qui génère une visite en utilisant l'algorithme de Glouton (non uniforme) */
/* Paramètres: Un tableau de structures de type Ville et un entier 'nb_villes'*/

Visite generer_visite_2(Ville tab[], int nb_villes);

#endif