#ifndef __AFFICHAGE__
#define __AFFICHAGE__
#include "ville.h"
#include "visite.h"
#define TAILLE_X 1366
#define TAILLE_Y 768

/* Fonction qui dessine le repère orthormé de la carte.*/
/* Paramètres: nombre de villes. */

void dessiner_repere(int nb_villes);

/* Fonction qui affiche la position de chaque ville.*/
/* Paramètres: Un tableau de structures de type Ville et un entier 'nb_villes' correspondant au nombre de villes. */

void dessiner_ville(Ville tab[], int nb_villes);

/* Fonction qui affiche le trajet d'une visite.*/
/* Paramètres: Une structure de type Population et un entier 'nb_villes' correspondant au nombre de villes. */

void trace_chemin(Population pop , int nb_villes);

#endif
