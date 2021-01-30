#include "../includes/foe.h"



int InitFoe (ListFoe *enemy, ListFoe listEnemy, foeType type, int width){ 

	*enemy = (Foe*) malloc( sizeof(Foe) );
	if (NULL != *enemy){
		Position pos_ennemy;
		pos_ennemy.x = MLV_get_random_integer(0+WITDH_BOSS,width-WITDH_BOSS);
		pos_ennemy.y = COORDINATE_Y_FOE_START;
		if(!FoeDetection(pos_ennemy,listEnemy,type)){
			if (type == BOSS){
				InitShip (&(*enemy)->ship, pos_ennemy, RADIUS_BOSS, 100);
				(*enemy)->direction = RIGHT;
				(*enemy)->ship.speed = BOSS_SPEED;
			}
			else if (type == FAST){
				InitShip (&(*enemy)->ship, pos_ennemy, RADIUS_FAST, 1);
				(*enemy)->direction = DOWN;
				(*enemy)->ship.speed = FAST_SPEED;			
			}
			else if (type == CLASSIC){
				InitShip (&(*enemy)->ship, pos_ennemy, RADIUS, 3);
				(*enemy)->direction = DOWN;
				(*enemy)->ship.speed = CLASSIC_SPEED;
			}
			(*enemy)->next = NULL;
			(*enemy)->type = type;
			return 1;
		}
	} 
	free(*enemy);
	*enemy = NULL;
	return 0;
}

int FoeDetection(Position posShip,ListFoe enemy,foeType type){

	if(enemy == NULL){
		return 0;
	}

	for (enemy;enemy != NULL; enemy = enemy->next ){	
		if(type == BOSS){
			if(Distance(posShip,enemy->ship.p) <(2*RADIUS_BOSS)){
				return 1;
			}
		}
		else{
			if(Distance(posShip,enemy->ship.p) < ( 2* RADIUS)){
				return 1;
			}
		}
	}
	return 0;
}



void PrintFoe (Foe enemy){
	printf("[%d ",enemy.type);
	PrintShip (enemy.ship);
	printf("] ");
	
}

void PrintFoeList (ListFoe listFoe){
	ListFoe tmp ;
	assert(listFoe != NULL);
	printf("{");
	for (tmp = listFoe; tmp != NULL; tmp = tmp->next){
		PrintFoe (*tmp);
	}
	printf("}\n");
}

void AddFoe(ListFoe* source, ListFoe * dest){
	
	ListFoe  tmp ;
	assert (dest != NULL);
	if (*source == NULL){
		*source = *dest;
		return;
	}
	
	for (tmp = *source; tmp->next != NULL; tmp = tmp->next){

	}
	tmp->next = *dest;
	return;
}

int EqualsFoe (Foe foe1, Foe foe2){
	return foe1.type == foe2.type  && EqualsShip (foe1.ship, foe2.ship);
}


ListFoe ExtractFoe (ListFoe * listFoe, ListFoe foe){
	
	ListFoe tmp, tmp2;	
	assert (NULL != *listFoe);
	assert (NULL != foe);
	if (EqualsFoe (*(*listFoe),*foe)) {
		tmp = *listFoe;
		*listFoe = (*listFoe)->next;
		tmp->next = NULL;
		return tmp;
	}
	for (tmp = *listFoe; tmp->next != NULL; tmp = tmp->next){
		if (EqualsFoe (*(tmp->next),*foe)) {
			tmp2 = tmp->next;
			tmp->next = tmp2->next;
			tmp2->next = NULL;
			return tmp2;	
		}
	}
	return NULL;

}

void FreeFoe (ListFoe * listFoe, ListFoe foe){
	ListFoe tmp ;
	assert(*listFoe != NULL);
	assert(foe != NULL);

	tmp = ExtractFoe (listFoe,foe);
	free(tmp);
	tmp = NULL;
}

void FreeListFoe (ListFoe * listFoe){
	FreeListFoe(&((*listFoe)->next));
	free(*listFoe);

}

void MoveFoe(ListFoe* foe, int width){
	ListFoe tmp;
	for (tmp = *foe; tmp != NULL; tmp = tmp->next){
		if (tmp->type == 2){
			if ( (tmp->direction == LEFT) &&  tmp->ship.p.x < 0 )
				tmp->direction = RIGHT;
			if ( (tmp->direction == LEFT) )
				tmp->ship.p.x -= tmp->ship.speed;;
			if ( (tmp->direction == RIGHT) &&  tmp->ship.p.x+WITDH_BOSS > width )
				tmp->direction = LEFT;
			if ( (tmp->direction == RIGHT) )
				tmp->ship.p.x += tmp->ship.speed;;
		}
		else{
			tmp->ship.p.y += tmp->ship.speed;
		}
	}
}


void InitWave(int foeNumber, ListFoe* foeList, foeType type, int width){

	int i;

	for (i = 0; i < foeNumber; ++i)
	{
		ListFoe foe = NULL;
		do{

			InitFoe(&foe,*foeList, type, width);
		}
		while(foe == NULL);
		AddFoe(foeList, &foe);
	
	}

}

int GenerateWave(ListFoe* foeList, int width){
	int type;
	int nb;
	type = MLV_get_random_integer(0,3);
	switch(type){
		case 0:
			nb = MLV_get_random_integer(5,10);
			InitWave(nb, foeList, CLASSIC, width);
			break;
		case 1:
			nb = MLV_get_random_integer(2,7);
			InitWave(nb, foeList, FAST, width);
			break;
		case 2:
			nb = MLV_get_random_integer(1,3);
			InitWave(nb, foeList, BOSS, width);
			break;
	}
	return 1;
}