#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <MLV/MLV_all.h>
#include "visite.h"
#include "mutation.h"

void calculeDistance(Visite* visit, const int taille){
    int i;

    assert(taille > 0);
    assert(NULL != visit);

    visit->distance = 0;
    for(i = 1 ; i < taille ; i++){
        visit->distance += ((visit->chemin[i].x - visit->chemin[i - 1].x) * (visit->chemin[i].x - visit->chemin[i - 1].x)) + ((visit->chemin[i].y - visit->chemin[i - 1].y) * (visit->chemin[i].y - visit->chemin[i - 1].y));
    }
}

Visite generer_visite(Ville tab[], int nb_villes){
    int i, j, n;
    int k = 0;
    Visite visite_alea;
    Ville copie[50];

    assert(NULL != tab);
    assert(nb_villes > 0);
    
    for(i = 0 ; i < nb_villes ; i++)
        copie[i] = tab[i];   
    while(nb_villes > 0){
        n = rand() % nb_villes + 1;
        j = 0;
        i = 0;
        while(i < n){
            if(copie[j].x == -10)
                j++;
            else{
                i++;
                j++;
            }
        }
        visite_alea.chemin[k]= tab[j - 1]; 
        copie[j - 1].x = -10;
        nb_villes -= 1;
        k++;
    }
    return visite_alea;
}

void echange(Ville *v1, Ville *v2){
    Ville tmp;

    strcpy(tmp.nom, v1->nom);
    tmp.x = v1->x;
    tmp.y = v1->y;
    strcpy(v1->nom, v2->nom);
    v1->x = v2->x;
    v1->y = v2->y;
    strcpy(v2->nom, tmp.nom);
    v2->x = tmp.x;
    v2->y = tmp.y;
}

Visite generer_visite_2(Ville tab[], int nb_villes){
    int i, j;
    Visite visite_alea;

    assert(NULL != tab);
    assert(nb_villes> 0);
    
    for (i = 0 ; i < nb_villes * nb_villes ; i++){
        j = rand() % nb_villes;
        echange(&tab[j], &tab[j + 1]);
    }

    i = 0;
    for (i = 0 ; i < nb_villes ; i++){
        visite_alea.chemin[i] = tab[i];
    }
    calculeDistance(&visite_alea, nb_villes);

    return visite_alea;
}

void nouvelle_population(Population* pop, Ville *villes, int alpha, int beta, int gamma, int nb_villes){
    int i;
    Visite *copie;

    assert(NULL != villes->nom);
    assert(alpha + beta + gamma == K);

    copie = (Visite*)malloc(beta * sizeof(Visite));
    if (NULL == copie)
        exit(EXIT_FAILURE);

    for (i = 0 ; i < beta ; i++)
        copie[i] = pop->tab[i];
    
    for (i = 0 ; i < beta ; i++)
        pop->tab[alpha + i] = copie[i];
    
    for (i = 0 ; i < gamma ; i++){
        pop->tab[alpha + beta + i] = generer_visite(villes, nb_villes);
        calculeDistance(&(pop->tab[alpha + beta + i]), nb_villes);
    }
}

void affiche_visite(Visite *visites, int nb_villes){
    int i;
    int j;

    assert(visites != NULL);

    for (i = 0 ; i < nb_villes * nb_villes ; i++){
        printf("visite n°%d: ", i + 1);
        for (j = 0; j < nb_villes; j++){
            printf("%s ", visites[i].chemin[j].nom);
        }
        printf(" %d \n", visites[i].distance);
    }
}

int cmpdist(const void* a, const void* b){
    Visite* v1 = (Visite*)a;
    Visite* v2 = (Visite*)b;

    assert(a != NULL);
    assert(b != NULL);
    
    return v1->distance - v2->distance;
}


void nouvelle_populationM(Population *pop, const int alpha, const int taille){
    int i;

    assert(taille > 0);

    for (i = 0 ; i < alpha ; i++){
        mutation(pop->tab[i], taille);
        calculeDistance(&(pop->tab[i]), taille);
    }
}