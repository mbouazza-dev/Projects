#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <assert.h>
#include <math.h>
#include "affichage.h"
#include "ville.h"


void dessiner_repere(int nb_villes){
    int i;

    MLV_draw_line(TAILLE_X / 2, 0, TAILLE_X / 2, TAILLE_Y, MLV_COLOR_RED);
    MLV_draw_line(0, TAILLE_Y / 2, TAILLE_X, TAILLE_Y / 2, MLV_COLOR_RED);

    for (i = 0; i < TAILLE_X; i += 50){
        MLV_draw_text((TAILLE_X / 2) + i, TAILLE_Y / 2, "%d", MLV_COLOR_BLACK, i / nb_villes);
    }
    for (i = -TAILLE_X / 2; i < 0; i += 50){
        MLV_draw_text((TAILLE_X / 2) + i, TAILLE_Y / 2, "%d", MLV_COLOR_BLACK, i / nb_villes);
    }
    for (i = 0; i < TAILLE_Y; i += 50){
        MLV_draw_text(TAILLE_X / 2, (TAILLE_Y / 2) + i, "%d", MLV_COLOR_BLACK, -(i / nb_villes));
    }
    for (i = -TAILLE_X / 2; i < 0; i += 50){
        MLV_draw_text(TAILLE_X / 2, (TAILLE_Y / 2) + i, "%d", MLV_COLOR_BLACK, -(i / nb_villes));
    }
}


void dessiner_ville(Ville tab[], int nb_villes){
    int i;
    MLV_Image* premier;
    MLV_Image* dernier;

    premier = MLV_load_image("images/premier.png");
    dernier = MLV_load_image("images/dernier.png");

    MLV_resize_image_with_proportions(premier, 30, 30);
    MLV_resize_image_with_proportions(dernier, 25, 25);

    assert(tab != NULL);
    assert(nb_villes > 1);

    for (i = 0; i < nb_villes; i++){
        if (i == 0){
            MLV_draw_image(premier, ((TAILLE_X / 2) + tab[i].x * nb_villes) - 15, ((TAILLE_Y / 2) + (-tab[i].y) * nb_villes) - 15);
            MLV_draw_text(((TAILLE_X / 2) + tab[i].x * nb_villes) + 15, ((TAILLE_Y / 2) + (-tab[i].y) * nb_villes) + 15, "%s", MLV_COLOR_BLACK, tab[i].nom);
        }
        else if (i == nb_villes - 1){
            MLV_draw_image(dernier, ((TAILLE_X / 2) + tab[i].x * nb_villes) - 15, ((TAILLE_Y / 2) + (-tab[i].y) * nb_villes) - 15);
            MLV_draw_text(((TAILLE_X / 2) + tab[i].x * nb_villes) + 15, ((TAILLE_Y / 2) + (-tab[i].y) * nb_villes) + 15, "%s", MLV_COLOR_BLACK, tab[i].nom);
        }
        else{
            MLV_draw_circle(((TAILLE_X / 2) + tab[i].x * nb_villes), ((TAILLE_Y / 2) + (-tab[i].y) * nb_villes), 5, MLV_COLOR_GREEN);
            MLV_draw_filled_circle(((TAILLE_X / 2) + tab[i].x * nb_villes), ((TAILLE_Y / 2) + (-tab[i].y) * nb_villes), 5, MLV_COLOR_GREEN);
            MLV_draw_text(((TAILLE_X / 2) + tab[i].x * nb_villes) + 5, ((TAILLE_Y / 2) + (-tab[i].y) * nb_villes) + 5, "%s", MLV_COLOR_BLACK, tab[i].nom);
        }
    }
}


void trace_chemin(Population pop , int taille){
    int i, x1, y1, x2, y2;
    for (i = 0 ; i < taille - 1 ; i++){
        x1 = (TAILLE_X / 2) + pop.tab[0].chemin[i].x * taille;
        x2 = (TAILLE_X / 2) + pop.tab[0].chemin[i + 1].x * taille;;
        y1 = (TAILLE_Y / 2) + (-pop.tab[0].chemin[i].y) * taille;
        y2 = (TAILLE_Y / 2) + (-pop.tab[0].chemin[i + 1].y) * taille;
        MLV_draw_line(x1, y1, x2, y2, MLV_COLOR_RED);
    }
    MLV_draw_adapted_text_box(TAILLE_X - (TAILLE_X / 4), TAILLE_Y - (TAILLE_Y / 4), "Distance: %.2f", 9, MLV_COLOR_GREEN, MLV_COLOR_GREEN, MLV_COLOR_BLACK, MLV_TEXT_CENTER, sqrt(pop.tab[0].distance));
}
