/* Auteurs: Bouazza Mehdi */
/* Créé le 20-02-19 */
/* Modifié le 2-03-18 */

#include <MLV/MLV_all.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef struct fenetre{
    int hauteur;
    int largeur;
}Fenetre;

typedef struct image{
    int type;
    int couleur;
    struct image* no;
    struct image* ne;
    struct image* so;
    struct image* se;
}Image, *Arbre;

/* Prennd en argument un entier (taille) et le nom d'une image (nom_image) et l'affiche en haut à gauche de la fenetre au format (taille x taille) */
void affiche_modele(int taille, char *nom_image){
    MLV_Image *image;

    image = MLV_load_image(nom_image);
    MLV_resize_image_with_proportions(image, taille, taille);
    MLV_draw_image(image, 0,0);
}

void affiche_image_redim(char* mon_image, int x, int y, int largeur){
    MLV_Image* image;
    int image_width, image_height;
    image = MLV_load_image(mon_image);

    MLV_draw_filled_rectangle(x, y, largeur, largeur, MLV_COLOR_WHITE);
    MLV_resize_image_with_proportions(image, largeur, largeur);
    MLV_get_image_size(image, &image_width, &image_height);
    MLV_draw_image(image, (largeur - image_width) / 2, (largeur - image_height) / 2);
}

/*	Alloue la place pour un Arbre et le renvoi */
Arbre AlloueImage(){
    Arbre tmp;
    tmp = (Image *)malloc(sizeof(Image)); /*allocation de la place nécessaire*/
    if (tmp != NULL){ 
        tmp -> couleur = -1;
        tmp -> type = 0;
        tmp -> no = NULL;
        tmp -> ne = NULL;
        tmp -> so = NULL;
        tmp -> se = NULL;
    }
    return tmp;
}

/*	Prend en argument trois entiers (x, y et taille) et renvoi 1 si la nuance de gris des pixels entre  
	(x, y) et (x + taille, y + taille) est homogène, renvoie 0 sinon */
int verifie_pixel(int x, int y, int taille){
    int i = 0;
    int j = 0;

    int couleur1;
    int couleur2;

    MLV_get_pixel(x, y, &couleur2, NULL, NULL, NULL);

    for (i = 0; i < taille; i++){
        for (j = 0; j < taille; j++){
            MLV_get_pixel(x + i, y + j, &couleur1, NULL, NULL, NULL);
            if (couleur1 != couleur2)
                return 0;
            couleur2 = couleur1;
        }
    }

    return 1;
}

/*   Prend en argument trois entiers et convertit l'image en noir et blanc*/
void convertit_image(int x, int y, int taille){
    int i = 0;
    int j = 0;

    int couleur1;

    for (i = 0; i < taille; i++){
        for (j = 0; j < taille; j++){
            MLV_get_pixel(x + i, y + j, &couleur1, NULL, NULL, NULL);
            
            MLV_draw_pixel(i, j, MLV_rgba(couleur1, couleur1, couleur1, 255));
        }
    }
}

/*	Prend en argument un poiinteur sur un Arbre (image) et trois entiers (debut_x, debut_y, fin) et créé l'arbre
	(image) correspondant à la zone de pixels comprise entre (debut_x, debut_y) et (debut_x + fin, debut_y + fin) */
Arbre* cree_arbre(Arbre* image, int debut_x, int debut_y, int fin){
    if((*image) == NULL)
        (*image) = AlloueImage();

    if (verifie_pixel(debut_x, debut_y, fin) == 1){
        (*image) -> type = 1;
        MLV_get_pixel(debut_x, debut_y, &((*image) -> couleur), NULL, NULL, NULL);
        return NULL;
    }

    else{
        cree_arbre(&(*image) -> no, debut_x, debut_y, (fin / 2));
        cree_arbre(&(*image) -> ne, debut_x + (fin / 2), debut_y, (fin / 2)); 
        cree_arbre(&(*image) -> so, debut_x, debut_y + (fin / 2), (fin / 2));
        cree_arbre(&(*image) -> se, debut_x + (fin / 2), debut_y + (fin / 2), (fin / 2));
        return &(*image);
    }  
}

/*	Prend en argument un pointeur sur un arbre (image), l'adresse d'un entier (num_noeud), un entier (palier) et un
	pointeur sur un arbre (noeud_recup) et fait pointer (noeud_recup) vers le (num_noeud)ème noeud du (palier)ème
	palier de l'arbre (image) */
void recupere_noeud(Arbre* image, int* num_noeud, int palier, Arbre* noeud_recup){
    if (palier == -1){
    	if (*num_noeud == 0)
	        *noeud_recup = *image;
        *num_noeud -= 1;
        return;
    }
    if (*image == NULL)
        return;
    if (*num_noeud < 0)
    	return;

    recupere_noeud(&(*image) -> no, &(*num_noeud), palier - 1, &(*noeud_recup));
    recupere_noeud(&(*image) -> ne, &(*num_noeud), palier - 1, &(*noeud_recup));
    recupere_noeud(&(*image) -> so, &(*num_noeud), palier - 1, &(*noeud_recup));
    recupere_noeud(&(*image) -> se, &(*num_noeud), palier - 1, &(*noeud_recup));
    return;
}

/*	Prend en argument 4 pointeurs sur des Arbre (par1, par2, fils1, fils2) et deux entiers (val1, val2) correspondants aux
	numero des pointeurs (fils1, fils2) sur leurs paliers respectifs, et échange les pointeurs (fils1, fils2) chez les parents
	(par1, par2) */
void echange_fils(Arbre* par1, Arbre* par2, Arbre* fils1, Arbre* fils2, int val1, int val2){
    int num_fils1 = val1 % 4;
    int num_fils2 = val2 % 4;

    switch(num_fils1){
        case 0: (*par1) -> no = *fils2;
        	break;
       	case 1: (*par1) -> ne = *fils2; 
       	    break;
        case 2: (*par1) -> so = *fils2;
            break;
        case 3: (*par1) -> se = *fils2; 
            break;
    }
    switch(num_fils2){
        case 0: (*par2) -> no = *fils1; 
            break;
        case 1: (*par2) -> ne = *fils1; 
            break; 
        case 2: (*par2) -> so = *fils1; 
            break; 
        case 3: (*par2) -> se = *fils1; 
            break;
    }
}

/*	Prend en argument un pointeur sur un Arbre (image) et un entier (type) définissant le palier des pointeurs
	qui seront ensuite mélangés */
void melange_noeuds(Arbre *image, int type){
    assert(type == 4 || type == 16 || type == 64);
    int val1, val2;
    int val1_par, val2_par;
    int copie_val1, copie_val2;
    Arbre par1;
    Arbre par2;
    Arbre fils1;
    Arbre fils2;
    int i = 0;

    for (i = 0 ; i < type ; i++ ){
    	par1 = NULL;
		par2 = NULL;
		fils1 = NULL;
		fils2 = NULL;
		
	    do{
	        val1 = rand() % (type - 1);
	        val2 = rand() % (type -1);
	    }while(val2 == val1);

	    val1_par = val1 / 4;
	    val2_par = val2 / 4;
	    copie_val2 = val2;
	    copie_val1 = val1;

	    recupere_noeud(&(*image), &val1, (log(type) / log(4)) - 1, &fils1);
	    recupere_noeud(&(*image), &val2, (log(type) / log(4)) - 1, &fils2);
	    recupere_noeud(&(*image), &val1_par, (log(type) / log(4)) - 2, &par1);
	    recupere_noeud(&(*image), &val2_par, (log(type) / log(4)) - 2, &par2);
	    echange_fils(&par1, &par2, &fils1, &fils2, copie_val1, copie_val2);
	}
}

/*	Prend en argument 4 entiers (x, y, largeur, couleur) et rempli de pixels de couleur (couleur) la zone
	située entre (x, y) et (x + largeur, y + largeur) */
void dessine_pixel(int x, int y, int largeur, int couleur){
    int i = 0;
    int j = 0;
    for(i = 0; i < largeur ; i++){
        for(j = 0; j < largeur; j++){
            MLV_draw_pixel(x + i, y + j, MLV_rgba(couleur, couleur, couleur, 255));
        }
    }
}

/*	Prend en argument un arbre (image) et 3 entiers (x, y, largeur) et affiche l'arbre (image) dans la zone
	située entre (x, y) et (x + largeur, y + largeur) */
void affiche_arbre(Arbre image, int x, int y, int largeur){
    if (image -> no == NULL){
        dessine_pixel(x, y, largeur, image -> couleur);
        return;
    }
    affiche_arbre(image -> no, x, y, (largeur / 2));
    affiche_arbre(image -> ne, x + (largeur / 2), y, (largeur / 2)); 
    affiche_arbre(image -> so, x, y + (largeur / 2), (largeur / 2));
    affiche_arbre(image -> se, x + (largeur / 2), y + (largeur / 2), (largeur / 2));
}

/*	Prend en argument un pointeur sur un arbre (image), 6 entiers (palier, debut_x, debut_y, x, y, fin), deux 
	pointeurs sur entiers (compte, num_noeud) et un pointeur sur arbre (ma_case) et fait pointer (num_noeud) sur 
	le numero de la case présente graphiquement aux coordonnées (x, y) et (ma_case) sur celle_ci */
void recherche_case(Arbre* image, int palier, int debut_x, int debut_y, int x, int y, int fin, int *compte, int *num_noeud, Arbre* ma_case){
    if (palier == -1){
        if (debut_x <= x && debut_x + fin >= x && debut_y <= y && debut_y + fin >= y){
            *num_noeud = *compte;
            *ma_case = *image;
        }
        *compte += 1;
        return;
    }
    if (*image == NULL)
        return;
    if (*ma_case != NULL)
        return;

    recherche_case(&(*image) -> no, palier - 1, debut_x, debut_y, x, y, (fin / 2), &(*compte), &(*num_noeud), &(*ma_case));
    recherche_case(&(*image) -> ne, palier - 1, debut_x + (fin / 2), debut_y, x, y, (fin / 2), &(*compte), &(*num_noeud), &(*ma_case)); 
    recherche_case(&(*image) -> so, palier - 1, debut_x, debut_y + (fin / 2), x, y, (fin / 2), &(*compte), &(*num_noeud), &(*ma_case));
    recherche_case(&(*image) -> se, palier - 1, debut_x + (fin / 2), debut_y + (fin / 2), x, y, (fin / 2), &(*compte), &(*num_noeud), &(*ma_case));
    return;
}

/*	Prend en argument 2 arbres (modele, image) et renvoi 0 si les arbres sont les mêmes, 1 sinon */
int compare(Arbre modele, Arbre image){
    if(modele == NULL || image == NULL)
        return 0;
    return (modele -> couleur != image -> couleur) || compare(modele -> no, image -> no) || compare(modele -> ne, image -> ne) || compare(modele -> so, image -> so) || compare(modele -> se, image -> se);
}

/*	Prend en argument 2 arbres (modele, image) et 5 entiers (decoupage, x, y, largeur, largeur_fenetre) et affiche
	en blanc les cases qui diffèrent entre (image) et (modele) */
void affiche_aide(Arbre modele, Arbre image, int decoupage, int x, int y, int largeur, int largeur_fenetre){
    if (image -> no == NULL){
        if(modele -> type != image -> type || (modele -> type == image -> type && modele -> couleur != image -> couleur)){
            MLV_draw_filled_rectangle((largeur_fenetre - 512) + ((x / (512/decoupage)) * (512/decoupage)), (y / (512/decoupage)) * (512/decoupage), 512 / decoupage, 512 / decoupage, MLV_COLOR_WHITE);
            return;
        }
    }

    if (modele -> no == NULL)
        return;
        
    affiche_aide(modele -> no, image -> no, decoupage, x, y, (largeur / 2), largeur_fenetre);
    affiche_aide(modele -> ne, image -> ne, decoupage, x + (largeur / 2), y, (largeur / 2), largeur_fenetre); 
    affiche_aide(modele -> so, image -> so, decoupage, x, y + (largeur / 2), (largeur / 2), largeur_fenetre);
    affiche_aide(modele -> se, image -> se, decoupage, x + (largeur / 2), y + (largeur / 2), (largeur / 2), largeur_fenetre);
}

/*	 Prend en argument 2 arbres (modele, image) un entier (decoupage) et une Fenetre (fenetre) et fais clignoter les cases qui 
	diffèrents entre (modete) et (image) 3 fois */
void clignote_aide(Arbre modele, Arbre image, int decoupage, Fenetre fenetre){
    int i = 0;

    for(i = 0; i < 3; i++){
        affiche_aide(modele, image, decoupage, 0, 0, 512, fenetre.largeur);
        MLV_actualise_window(); 
        MLV_wait_milliseconds(200);
        affiche_arbre(image, fenetre.largeur - 512, 0, 512);
        MLV_actualise_window(); 
        MLV_wait_milliseconds(200);
    }
}

/*	Prend en argument un pointeur sur arbre (image) un arbre (modele) 3 entiers (decoupage, taille, type) et une fenetre (fenetre_jeu)
	et attend deux clics de l'utilisateurs pour échanger les case correspondantes */ 
int echange_jeu(Arbre *image, Arbre modele, int decoupage, int taille, int type, Fenetre fenetre_jeu){
    int ax = 0, ay = 0; 
    int bx = 0, by = 0;
    int compt_a = 0, compt_b = 0;
    int noued_a, noued_b;
    int palier = (log(type) / log(4)) - 1;
    int par_a, par_b;
    Arbre ma_case_a = NULL, ma_case_b = NULL;
    Arbre par1 = NULL, par2 = NULL;

    do{
        do{
            MLV_wait_mouse(&ax, &ay);
            if(ax >= 540 && ax <= 740 && ay >= 300 && ay <= 340)
                return 0;
            if (ax >= 1280 - 3 * (512/4) && ax <= (1280 - 3 * (512/4)) + ((512/4) * 2) && ay >= 550 && ay <= 590){
                clignote_aide(modele, *image, decoupage, fenetre_jeu);
                return 1;
            }

        }while(ax < fenetre_jeu.largeur - taille || ay > taille);

        do{
            MLV_wait_mouse(&bx, &by); 
        }while(bx < fenetre_jeu.largeur - taille || by > taille);  
    }while(ax == bx && ay == by);

    ax = ax - (fenetre_jeu.largeur - taille);
    bx = bx - (fenetre_jeu.largeur - taille);
    
    recherche_case(&(*image), palier, 0, 0, ax, ay, taille, &compt_a, &noued_a, &ma_case_a);
    recherche_case(&(*image), palier, 0, 0, bx, by, taille, &compt_b, &noued_b, &ma_case_b);
    par_a = noued_a / 4;
    par_b = noued_b / 4;
    recupere_noeud(&(*image), &par_a, palier - 1, &par1);
    recupere_noeud(&(*image), &par_b, palier - 1, &par2);

    echange_fils(&par1, &par2, &ma_case_a, &ma_case_b, noued_a, noued_b);
    return 1;
}

/*	Affiche le menu pour charger une image, un quadtree, ou quitter */
void affiche_menu_image(){
	MLV_draw_text_box(540, 100, 200, 40, "Charger une image", 9, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_rgba(51, 204, 255, 255), MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_draw_text_box(540, 150, 200, 40, "Charger un quadtree", 9, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_rgba(51, 204, 255, 255), MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_draw_text_box(540, 300, 200, 40, "Quitter", 9, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_rgba(51, 204, 255, 255), MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}

/*	Affiche le menu pour découper le puzzle en 16 ou 64 pièces */
void affiche_menu_decoupage(){
    MLV_draw_text_box(540, 200, 200, 40, "Puzzle 16 pieces", 9, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_rgba(51, 204, 255, 255), MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(540, 250, 200, 40, "Puzzle 64 pieces", 9, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_rgba(51, 204, 255, 255), MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}

/*	Prend en argument un entier (score) et l'affiche */
void affiche_score(long score){
	char chaine_score[11];
	sprintf(chaine_score, "Score : %ld", score);
	MLV_draw_text_box(540, 400, 200, 40, chaine_score, 9, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_rgba(51, 204, 255, 255), MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}

/*	Prend en argument un entier (score) et affiche la phase de fin de partie avec le score */
void affiche_fin(int score){
	char chaine_score[19];
	sprintf(chaine_score, "Fini en %d coups !", score);
	MLV_draw_text_box(540, 400, 200, 40, chaine_score, 9, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_rgba(51, 204, 255, 255), MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}

void change_chaine(char* chaine){
    chaine[strlen(chaine) - 4] = '.';
    chaine[strlen(chaine) - 3] = 'q';
    chaine[strlen(chaine) - 2] = 'u';
    chaine[strlen(chaine) - 1] = 'a';
    chaine[strlen(chaine)] = 'd';
}

/*	Affiche le bouton aide */
void affiche_bouton_aide(){
    MLV_draw_text_box(1280 - 3 * (512/4), 550, (512/4) * 2, 40, "aide", 9, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_rgba(51, 204, 255, 255), MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}

/*	Attend un clique du joueur et renvoi le numero du bouton sur lequel il a cliqué, 0 sinon */
int bouton_clique(){
	int ax, ay;
	MLV_wait_mouse(&ax, &ay);

	if(ax >= 540 && ax <= 740 && ay >= 100 && ay <= 140)
		return 1;
	if(ax >= 540 && ax <= 740 && ay >= 150 && ay <= 190)
		return 2;
	if(ax >= 540 && ax <= 740 && ay >= 200 && ay <= 240)
		return 3;
	if(ax >= 540 && ax <= 740 && ay >= 250 && ay <= 290)
		return 4;
	if(ax >= 540 && ax <= 740 && ay >= 300 && ay <= 340)
		return 5;

	return 0;
}

/*	Prend en argument une arbre (image) et un fichier (fichier) et écrit dans (fichier) la suite de chiffres correspondants à un 
	parcours préfixe de l'arbre (image) */
void ecriture_arbre_fichier(Arbre image, FILE* fichier){
    if (image == NULL)
        return;
    if (fichier == NULL)
        return;
    if (image -> type == 1){
        fprintf(fichier, "%d %d ", image -> type,  image -> couleur);
        return;
    }
    if (image -> type == 0)
        fprintf(fichier, "%d ", image -> type);

    ecriture_arbre_fichier(image -> no, &(*fichier));
    ecriture_arbre_fichier(image -> ne, &(*fichier));
    ecriture_arbre_fichier(image -> so, &(*fichier));
    ecriture_arbre_fichier(image -> se, &(*fichier));
    return;
}

/*	 Prend en argument un arbre (image) et un fichier (fichier) et construit l'arbre (image) en fonction de la suite
	de nombre contenue dans (fichier) */
void recupere_image_arbre(Arbre *image, FILE* fichier){
    int noeud;
    int gris_noeud;
    if((*image) == NULL)
        (*image) = AlloueImage();

    fscanf(fichier,"%d ", &noeud);

    if (noeud == 1){
        (*image) -> type = 1;
        fscanf(fichier,"%d ", &gris_noeud);
        (*image) -> couleur = gris_noeud;
        return;
    }
    if (noeud == 0)
        (*image) -> type = 0;

    recupere_image_arbre(&(*image) -> no, fichier);
    recupere_image_arbre(&(*image) -> ne, fichier); 
    recupere_image_arbre(&(*image) -> so, fichier);
    recupere_image_arbre(&(*image) -> se, fichier);
    return;
}

int main(void){
    srand(time(NULL));
    int fin_jeu = 1;
    int bouton = 0;
    int decoupage = 16;
    int echange = 0;
    Fenetre fenetre_jeu;
    Arbre modele = NULL;
    Arbre image = NULL;
    char *charge_img;
    long compteur = 0;


    int taille = 512;
    fenetre_jeu.largeur = 1280;
    fenetre_jeu.hauteur = 720;

    MLV_create_window("quadtree", "quadtree", fenetre_jeu.largeur, fenetre_jeu.hauteur);

    while (bouton != 5){
        fin_jeu = 1;
        decoupage = 16;
        echange = 0;
        compteur = 0;
        affiche_menu_image();
        MLV_actualise_window();
        
        while(bouton == 0 || bouton == 3 || bouton == 4){
            bouton = bouton_clique();
        }

        if(bouton == 2){
            MLV_wait_input_box(490, 600, 300, 40, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_rgba(51, 204, 255, 255), "QUADTREE.quad: ", &charge_img);
            FILE *fichier = fopen(charge_img, "r");
            recupere_image_arbre(&modele, fichier);
            fclose(fichier);
            FILE *fichier_2 = fopen(charge_img, "r");
            recupere_image_arbre(&image, fichier_2);
            fclose(fichier_2);
            affiche_arbre(image, 0, 0, 512);
        }

        if(bouton == 1){
            MLV_wait_input_box(490, 600, 300, 40, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_rgba(51, 204, 255, 255), "IMAGE.jpg: ", &charge_img);
            affiche_image_redim(charge_img, 0, 0, 512);
            convertit_image(0, 0, 512);
            cree_arbre(&modele, 0, 0, 512);
            cree_arbre(&image, 0, 0, 512);
            change_chaine(charge_img);
            FILE *fichier_ecriture = fopen(charge_img, "w");
            ecriture_arbre_fichier(modele, fichier_ecriture);
            fclose(fichier_ecriture);
        }

        if(bouton == 5)
            return 0;

        affiche_menu_decoupage();
        MLV_actualise_window();

        while(bouton == 0 || bouton == 1 || bouton == 2){
            bouton = bouton_clique();
        }

        if(bouton == 3)
            decoupage = 16;

        if(bouton == 4)
            decoupage = 64;

        if(bouton == 5)
            return 0;

        melange_noeuds(&image, decoupage);
        affiche_arbre(image, fenetre_jeu.largeur - taille, 0, 512);
        affiche_bouton_aide();
        affiche_score(compteur);
        MLV_actualise_window();

        while(fin_jeu == 1){
            echange = echange_jeu(&image, modele, decoupage, 512, decoupage, fenetre_jeu);
            compteur += 1;
            affiche_arbre(image, fenetre_jeu.largeur - taille, 0, 512);
            affiche_score(compteur);
            MLV_actualise_window(); 
            if (echange == 0)
                return 0;
            fin_jeu = compare(modele, image); 
        }

        affiche_fin(compteur);
        MLV_actualise_window(); 
        MLV_clear_window(MLV_COLOR_BLACK);
        bouton = bouton_clique(); 
    }

    return 0;
}
