#include "../includes/shoot.h"


int InitShoot (Shoot ** shoot, Position pos, char team, TypeShoot type,int speed){

	*shoot = (Shoot*)malloc(sizeof(Shoot));
	if ((*shoot) != NULL){
		(*shoot)->p.x = pos.x + 35;
		(*shoot)->p.y = pos.y - 10;
		(*shoot)->next = NULL;
		(*shoot)->team = team;
		(*shoot)->type = type;
		(*shoot)->speed = speed;
		(*shoot)->angle = 90;
		switch (type){
			case LAZER: (*shoot)->damage = 5;break;
			case MISSILE: (*shoot)->damage = 15;break;
			case BOMBE: (*shoot)->damage = 40;break;
		}
		

		return 1;

	}
	return 0;

}

int EqualsShoot (Shoot tir1, Shoot tir2){

	return tir1.p.x == tir2.p.x && tir1.p.y == tir2.p.y;
}

void PrintShoot (ShootList shoot){
	
	ShootList tmp ;
	assert(shoot != NULL);
	
	for (tmp = shoot; tmp != NULL; tmp = tmp->next){
		printf("{(%d,%d);",tmp->p.x,tmp->p.y);
	}
	printf("}\n");
}

void AddShoot (ShootList* source, ShootList * dest){

	Shoot * tmp ;
	assert(dest != NULL);
	if (*source == NULL){
		*source = *dest;
		return;
	}
	
	for (tmp = *source; tmp->next != NULL; tmp = tmp->next){

	}
	tmp->next = *dest;
	return;
}

ShootList ExtractShoot (ShootList * shootList, ShootList shoot){
	
	ShootList tmp, tmp2;	
	assert (NULL != *shootList);
	assert (NULL != shoot);
	if (EqualsShoot (*(*shootList),*shoot)) {
		tmp = *shootList;
		*shootList = (*shootList)->next;
		tmp->next = NULL;
		return tmp;
	}
	for (tmp = *shootList; tmp->next != NULL; tmp = tmp->next){
		if (EqualsShoot (*(tmp->next),*shoot)) {
			tmp2 = tmp->next;
			tmp->next = tmp2->next;
			tmp2->next = NULL;
			return tmp2;	
		}
	}
	return NULL;

}


void FreeShoot(ShootList * shootList, ShootList shoot){

	ShootList tmp ;
	assert(*shootList != NULL);
	assert(shoot != NULL);

	tmp = ExtractShoot (shootList,shoot);
	free(tmp);
	tmp = NULL;
}

int ColisionDetection(ListFoe* foe, Ship* vs, ShootList* shootList){
	ShootList tmp1;
	ListFoe tmp2;
	for (tmp1 = *shootList; tmp1 != NULL; tmp1 = tmp1->next){
		for (tmp2 = *foe; tmp2 != NULL; tmp2 = tmp2->next){

			if(collisionShipShoot(tmp1, tmp2->ship) && tmp1->team == 'a'){
				tmp2->ship.hp -= 1;
				FreeShoot(shootList, tmp1);
				if (tmp2->ship.hp < 1){
					FreeFoe(foe, tmp2);
				}
			}
			if(collisionShipShoot(tmp1, *vs) && tmp1->team == 'e'){
				vs->hp -= 1;
				FreeShoot(shootList, tmp1);
				if (vs->hp < 1){
					FreeFoe(foe, tmp2);
				}
			}
		}
	}
}

int collisionShipShoot(ShootList shoot, Ship vs){
	return Distance(shoot->p, vs.p) < vs.hitbox.radius;
}

int Shoot_a(Ship vs, ShootList* shootList, MLV_Keyboard_button key_sym,MLV_Button_state state){
    ShootList shoot = NULL;   
    if ( key_sym == MLV_KEYBOARD_w && state == MLV_PRESSED && InitShoot (&shoot, vs.p, 'a', LAZER,PLAYER_SHOOT_SPEED)){
        shoot->p.x = vs.p.x;
        shoot->p.y = vs.p.y;
        AddShoot (shootList, &shoot);
        MLV_play_sound(stir_a, 0.02);
        return 1;
     }
    return 0;
}

int Shoot_e(ListFoe listFoe, ShootList* shootList, Ship joueur, int height){
    ShootList shoot;
    ShootList l_tir;
    ListFoe tmp;
    for (tmp = listFoe; tmp != NULL; tmp = tmp->next){
    	if (tmp->ship.p.y < height){
    		MLV_play_sound(stir_e, 0.02);
			switch(tmp->type){
				case CLASSIC:{
					if(InitShoot (&shoot, tmp->ship.p, 'e', LAZER, CLASSIC_SHOOT_SPEED)){
						shoot->p.x = tmp->ship.p.x;
						shoot->p.y = tmp->ship.p.y+COORD_Y_DEPART_TIR;
		            	AddShoot (shootList, &shoot);
						break;
					}
					else
						return 0;
				}
				case FAST:{
					if(InitShoot (&shoot, tmp->ship.p, 'e', LAZER, CLASSIC_SHOOT_SPEED)){
						shoot->p.x = tmp->ship.p.x + (WITDH_SP/2);
						shoot->p.y = tmp->ship.p.y + (HEIGHT_BOSS);
		           	 	AddShoot (shootList, &shoot);
						break;
					}
					else 
						return 0;
				}
				case BOSS:{
					if(InitShoot (&shoot, tmp->ship.p, 'e', MISSILE, CLASSIC_SHOOT_SPEED)){
						shoot->p.x = tmp->ship.p.x + (WITDH_BOSS/2);
		           		shoot->p.y = tmp->ship.p.y + (HEIGHT_BOSS);
		           		GiveEquation(&(shoot->coeff), &(shoot->ordonne_origine), &(shoot->angle),joueur.p, shoot->p );
		            	AddShoot (shootList, &shoot);
						break;
					}
					else
						return 0;
				}
				
	    	}
	    }
    }
    return 1;
}

double GiveAngle(Position pos_joueur, Position pos_ennemie ){
	if(pos_joueur.x - pos_ennemie.x != 0){  
		double tan = (double)(pos_joueur.y - pos_ennemie.y)/(double)(pos_joueur.x - pos_ennemie.x);
		return atan(tan);
	}
	return 90;
}

void GiveEquation(double* coeff, double* ordonne_origine, double* angle, Position pos_joueur, Position pos_ennemie ){
	*angle = (GiveAngle(pos_joueur,pos_ennemie)* (double)180)/M_PI;
	*coeff = (double)(pos_joueur.y - pos_ennemie.y)/(double)(pos_joueur.x - pos_ennemie.x);
	*ordonne_origine = (double)pos_ennemie.y - (*coeff) * (double)pos_ennemie.x;

}

int ShootIncrementation(ShootList* shootList){
	ShootList tmp;
	for (tmp = *shootList; tmp != NULL; tmp = tmp->next){
		if(!FoeShootIncrementation (tmp)){
			tmp->p.y -= tmp->speed;	
		}
	}
}

int FoeShootIncrementation (Shoot * shoot){
	
	if(shoot->team == 'e'){

		if(0 < shoot->angle)

			if( shoot->angle < 25){
				shoot->p.x += 2 * shoot->speed ;
				shoot->p.y = shoot->coeff * (double)shoot->p.x + shoot->ordonne_origine ;
			}

			else if( shoot->angle < 45){
				shoot->p.x += shoot->speed ;
				shoot->p.y = shoot->coeff * (double)shoot->p.x + shoot->ordonne_origine ;
			}
			else{
				shoot->p.y += shoot->speed ;
				if( shoot->angle != 90)
					shoot->p.x = ((double)shoot->p.y - shoot->ordonne_origine) / shoot->coeff ;
			}
		
		else{

			if( shoot->angle > -20){
				shoot->p.x -= 2 * shoot->speed ;
				shoot->p.y = shoot->coeff * (double)shoot->p.x + shoot->ordonne_origine ;
			}

			else if(shoot->angle > -45){
				shoot->p.x -= shoot->speed ;
				shoot->p.y = shoot->coeff * (double)shoot->p.x + shoot->ordonne_origine ;
			}
			else{
				shoot->p.y += shoot->speed ;
				if( shoot->angle != -90)
					shoot->p.x = ((double)shoot->p.y - shoot->ordonne_origine) / shoot->coeff ;
				
			}
		}
	return 1;
	}
	return 0;

}