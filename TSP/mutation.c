#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <MLV/MLV_all.h>
#include "visite.h"
#include "mutation.h"

Mutation generation(int nb_villes){
    Mutation gen;

    do{
        
        gen.l = MLV_get_random_integer(1, nb_villes / 2);
        gen.i = MLV_get_random_integer(1, nb_villes / 2);
        gen.j = MLV_get_random_integer(nb_villes / 2, nb_villes);
        
    }while((gen.i + gen.l >= gen.j) || ((gen.l + gen.j > nb_villes + 1) && (gen.i == gen.j)));

    return gen;
}

void mutation(Visite visites, int nb_villes){
    Mutation gen;
    Ville tmp;
    int cmp = 0;

    assert(nb_villes > 0);

    gen = generation(nb_villes);
    while(cmp < gen.l){
       tmp = visites.chemin[gen.i + cmp - 1];
        visites.chemin[gen.i + cmp - 1] = visites.chemin[gen.j + cmp - 1];
        visites.chemin[gen.j + cmp - 1] = tmp;
        cmp++;
    }
}