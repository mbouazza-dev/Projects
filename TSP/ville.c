#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ville.h"

int recupererVille(Ville *villes, int nb_villes, FILE* fichier){
    char ligne[BUFSIZ];
    int i;

    assert(villes != NULL);
    assert(fichier != NULL);

    for (i = 0; i < nb_villes; i++){
        fgets(ligne, BUFSIZ, fichier);
  
        if (sscanf(ligne,"%s%d%d", villes[i].nom, &villes[i].x, &villes[i].y) == 3){
            continue;
        }

    }

    return 0;
}