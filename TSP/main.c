/*Auteurs: AMINE Angelica & BOUAZZA Mehdi Groupe 2*/
/*Date de création: 04/04/2019*/
/*Dernière modification: 12/05/2019*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <MLV/MLV_all.h>
#include <time.h>
#include <assert.h>

#include "ville.h"
#include "visite.h"
#include "utilitaire.h"
#include "affichage.h"

int main(int argc, char* argv[]){
    FILE* fichier;
    int nb_villes;
    int alpha;
    int beta;
    int gamma;
    int i;
    int j;  
    Ville tab[30];
    Population population;
    MLV_Keyboard_button sym;
    MLV_Event event;

    srand(time(NULL));

    if (argv[1] == NULL)
        fichier = fopen("CARTE.pvc", "r");
    else{
        fichier = fopen(argv[1], "r");
        if (NULL == fichier){
            printf("Fichier inexistant !\n");
            return 1;
        }
    }

    nb_villes = compte_ville(fichier);

    recupererVille(tab, nb_villes, fichier);
    
    alpha = rand() % (nb_villes * nb_villes);
    beta = rand() % ((nb_villes * nb_villes) - alpha);
    gamma = (nb_villes * nb_villes) - (alpha + beta);

    for (i = 0 ; i < K ; i++){
        population.tab[i] = generer_visite(tab, nb_villes);
        calculeDistance(&(population.tab[i]), nb_villes);
    }

    do{
            printf("\nDonner un alpha, un béta et un gamma (le tout doit faire %d):\n", K);
            scanf("%d", &alpha);
            scanf("%d", &beta);
            scanf("%d", &gamma);
    }while(alpha + beta + gamma != K);  
        
        MLV_create_window("PVC", "PVC", TAILLE_X, TAILLE_Y);
        
    do{
            event = MLV_get_event( 
            &sym, NULL, NULL, 
            NULL, NULL, NULL, 
            NULL, NULL, NULL);
            
            if(event == MLV_KEY){
                if(sym == MLV_KEYBOARD_SPACE)
                    break;
            }
            nouvelle_population(&population, tab, alpha, beta, gamma, nb_villes);
            nouvelle_populationM(&population, alpha, nb_villes);
            qsort(population.tab, sizeof(population.tab) / sizeof(population.tab[0]), sizeof(Visite), cmpdist);
            MLV_clear_window(MLV_COLOR_WHITE);
            dessiner_ville(population.tab[0].chemin, nb_villes);
            dessiner_repere(nb_villes);
            trace_chemin(population, nb_villes);
            MLV_actualise_window();
    }while(1);


        for(j = 0 ; j < K ; j++)
            printf("v%d : %.6f\n", j + 1, sqrt(population.tab[j].distance));

        MLV_wait_seconds(10);
        MLV_free_window();      
        fclose(fichier);

    return 0;
}