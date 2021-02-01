#include <stdio.h>
#include <assert.h>
#include "utilitaire.h"

int compte_ville(FILE* fichier){
    int nb_lignes;
    char c;

    assert(fichier != NULL);

    nb_lignes = 0;
    
    while ((c = getc(fichier)) != EOF){
        if (c == '\n')
            ++nb_lignes;
    }

    rewind(fichier);

    return nb_lignes;
}