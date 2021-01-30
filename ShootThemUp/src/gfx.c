#include <MLV/MLV_all.h>
#include "../includes/gfx.h"

void GameStateInit(GameState *state){
	state->parameter.window_name = "Project Stars";
	state->parameter.icone_name = "Project Stars";
	InitGrid(&(state->window),MLV_get_desktop_width (),MLV_get_desktop_height ());
	state->score = 0;
	InitAnimationArray(&(state->animationArray));
	InitStarsTab(state);
	state->shootList =NULL;
	state->foeList=NULL;
	Position positionPlayer;
	positionPlayer.x = COORDINATE_X_START;
	positionPlayer.y = COORDINATE_Y_START;
	InitShip (&(state->player), positionPlayer, RADIUS, BASE_HP);
}

void InitGrid(Grid* grid,int width, int height){
	grid->width = width;
	grid->height = height;
}

void InitStarsTab(GameState* state){
	int index;

	for (index = 0; index<NB_STARS; index++){
		state->starTab[index].x = MLV_get_random_integer(0, state->window.width);
		state->starTab[index].y = MLV_get_random_integer(0, state->window.height);

		switch(MLV_get_random_boolean()) {
			case 0 :
				state->starTab[index].radius = 1;
				break;
			case 1 :
				state->starTab[index].radius = 2;
				break;
		}
	}
}

void DrawBackground(GameState* state){
	int index;
	
	for (index = 0; index<NB_STARS; index++){
		if (state->starTab[index].radius == 1)
			state->starTab[index].y = (state->starTab[index].y) + 1;
			else
				state->starTab[index].y = (state->starTab[index].y) + 3;
			if ( (state->starTab[index].y)>state->window.height ){
					state->starTab[index].y = 0;
			}
			MLV_draw_filled_circle(state->starTab[index].x, state->starTab[index].y, state->starTab[index].radius, MLV_COLOR_ANTIQUE_WHITE);
	}
}



void DrawShoot (GameState * state){
	ShootList tmp = state->shootList ;
	while (tmp != NULL ){

		if (tmp->p.y + 5 > state->window.height){
			ShootList tmp_free = tmp;
			tmp = tmp->next;
			FreeShoot(&(state->shootList), tmp_free);
		}
		else{
			if (tmp->team == 'a'){
				MLV_draw_image(shoot_image_a, tmp->p.x-OFFSET_X_TIR, tmp->p.y-OFFSET_Y_TIR);	
			}
			else{
				if(tmp->angle != 90){
					MLV_Image * shoot_image_boss = MLV_load_image("media/Shoot_e.png");
					MLV_rotate_image (shoot_image_boss, -tmp->angle);
					MLV_draw_image(shoot_image_boss, tmp->p.x-OFFSET_X_TIR, tmp->p.y-OFFSET_Y_TIR);
					free(shoot_image_boss);

				}
				else{
					MLV_draw_image(shoot_image_e, tmp->p.x-OFFSET_X_TIR, tmp->p.y-OFFSET_Y_TIR);
			}	}
			tmp = tmp->next;
		}
	}
}

void LoadImages (){
	ship_a = MLV_load_image("media/ship_a.png");	
	ship_e = MLV_load_image("media/ship_e.png");
	ship_f = MLV_load_image("media/ship_f.png");
	ship_b = MLV_load_image("media/ship_b.png");
	background =  MLV_load_image("media/background.jpeg");
	shoot_image_a = MLV_load_image("media/Shoot_a.png");
	shoot_image_e = MLV_load_image("media/Shoot_e.png");
	MLV_rotate_image (shoot_image_e, 90);
	explosion[0] = MLV_load_image("media/exp1.png");       
	explosion[1] = MLV_load_image("media/exp2.png");  
	explosion[2] = MLV_load_image("media/exp3.png");  
	explosion[3] = MLV_load_image("media/exp4.png");  
	explosion[4] = MLV_load_image("media/exp5.png");  
	explosion[5] = MLV_load_image("media/exp6.png"); 	
 	heart = MLV_load_image("media/heart.png");
 	point = MLV_load_image("media/point.png");
 	howtoplay = MLV_load_image("media/howtoplay.jpeg");
}

void DrawShip(GameState* state){
	if (state->player.p.x<state->window.width && state->player.p.y<state->window.height){
		MLV_resize_image_with_proportions(ship_a, 70, 70);
		MLV_draw_image(ship_a, state->player.p.x-WITDH_SP, state->player.p.y-HEIGHT_SP);
		DrawLifebar(state->player, 'A');
	}
}

void DrawHitbox(int x, int y, int radius){
	MLV_draw_filled_circle(x,y,radius,MLV_COLOR_GREEN);
}

void DrawBonus(Bonus bonus){
	if (bonus.type == 'h'){
		MLV_resize_image_with_proportions(heart, 25, 25);
		MLV_draw_image(heart, bonus.cord.x, bonus.cord.y);
	}
	else if (bonus.type == 'p'){
		MLV_resize_image_with_proportions(point, 25, 25);
		MLV_draw_image(point, bonus.cord.x, bonus.cord.y);
	}
}


void DrawHowToPlay(){
	MLV_clear_window(MLV_COLOR_BLACK);
	MLV_draw_image(howtoplay, 0, 0);
	MLV_actualise_window();
}


void DrawFoe(GameState* state){
	ListFoe tmp;
	for (tmp = state->foeList ; tmp != NULL ; tmp = tmp->next){
		if (tmp->ship.p.x<state->window.width && abs(tmp->ship.p.y)<state->window.height){
			switch(tmp->type){
				case CLASSIC:
					MLV_resize_image_with_proportions(ship_e, 70, 70);
					MLV_draw_image(ship_e, tmp->ship.p.x-WITDH_SP, tmp->ship.p.y-HEIGHT_SP);

					break;
				case FAST:
					MLV_resize_image_with_proportions(ship_f, 50, 50);
					MLV_draw_image(ship_f, tmp->ship.p.x-WITDH_FAST, tmp->ship.p.y-HEIGHT_FAST);

					break;
				case BOSS:
					MLV_resize_image_with_proportions(ship_b, 150, 150);
					MLV_draw_image(ship_b, tmp->ship.p.x-WITDH_BOSS, tmp->ship.p.y-HEIGHT_BOSS);
					DrawLifebar(tmp->ship, 'B');

					break;
			}
		}
	}
}

void DrawWindow (GameState* state, Bonus bonus){
	int i=0;
	MLV_clear_window(MLV_COLOR_BLACK);
	DrawBackground(state);
	DrawShip(state);
	DrawShoot (state);
	DrawFoe(state);
	DrawBonus(bonus);
	DrawScore(state);
	DrawAnimation (state);
	MLV_actualise_window();
}

int InitAnimationArray(AnimationArray* animationArray){
	animationArray->maxLength = 50;
	Animation * test;
	test = (Animation*)malloc(sizeof(Animation)*50);
	if(NULL != test){
		for (int i = 0; i < animationArray->maxLength; ++i)
		{
			test[i].p.x = test[i].p.y = -1;
		}
		animationArray->array = test;
		animationArray->animationNumber = 0;

		return 1;
	}
	return 0;
}


int ResizeAnimationArray (AnimationArray * animationArray){
	Animation * test;
	animationArray->maxLength *= 2;
	test = (Animation*)realloc(animationArray->array,sizeof(Animation)*animationArray->maxLength);
	if(NULL != test){
		animationArray->array = test;
		for (int i = animationArray->animationNumber+1; i < animationArray->maxLength; ++i)
		{
			test[i].p.x = test[i].p.y = -1;
		}
		return 1;
	}
	return 0;
}

void InitAnimation(Animation* animation_image, Position position_image, int nb_image_animation,TypeAnimation typeAnimation,MLV_Image* tab_image[]){

	animation_image->p = position_image;
	animation_image->frame_counter = 0;
	animation_image->nb_image = nb_image_animation;
	animation_image->typeAnimation = typeAnimation;
	animation_image->tab_image =  tab_image;
}

void DrawFrameAnimation (Animation* animation){

	MLV_draw_image(animation->tab_image[animation->frame_counter],animation->p.x, animation->p.y);
	
	if(animation->frame_counter < animation->nb_image-1){
		UpComptFrame(animation);
		if(IsFinishAnimation(*animation)){
			SetInactivAnimation(animation);
		}
	
		else if(animation->frame_counter == animation->nb_image-1 && animation->typeAnimation == PERMANENT){
			RollBackAnimation(animation);
		}
	}
}

void UpComptFrame(Animation *animation){
	animation->frame_counter ++;	
}

void RollBackAnimation(Animation *animation){	
	animation->frame_counter = 0;
}

void SetInactivAnimation(Animation *animation){
	if(IsFinishAnimation(*animation)){
		animation->p.x =animation->p.y = -1;
	}
}

void DrawAnimation (GameState* state){
	int i;
	for (i = 0; i <state->animationArray.maxLength ; ++i)
	{
		if (IsActivAnimation(state->animationArray.array[i])){
			DrawFrameAnimation(&(state->animationArray.array[i]));
		}
		
	}
}

int IsActivAnimation(Animation animation){
	return animation.p.x != -1 && animation.p.y != -1; 
}

static int IsFinishAnimation(Animation animation){
	return animation.frame_counter == (animation.nb_image-1) && animation.typeAnimation == TEMPORARY;
}

int isFullArrayAnimation(AnimationArray animationArray){
	return animationArray.animationNumber == animationArray.maxLength-1;
}

void AddAnimation(GameState *state,Position position_collision, int nb_image_animation,TypeAnimation typeAnimation,MLV_Image* tab_image[] ){
	Animation animation;
	InitAnimation(&animation, position_collision,nb_image_animation,typeAnimation,tab_image);
	state->animationArray.array[state->animationArray.animationNumber] = animation;
	state->animationArray.animationNumber ++;
	if (isFullArrayAnimation(state->animationArray))
	{
		ResizeAnimationArray(&(state->animationArray));
	}
}

void PrintAnimationArray(AnimationArray animationArray){
	int i;
	for (i = 0; i < animationArray.maxLength; ++i)
	{
		printf("coordonnée: (%d,%d) frame: (%d)\n",animationArray.array[i].p.x,animationArray.array[i].p.y,animationArray.array[i].frame_counter );	
	}
}

void CollisionShoot(GameState* state, Bonus* bonus){
	ShootList tmpShootFree, shootList = state->shootList;
	ListFoe foeList = state->foeList ;

	for (shootList = state->shootList; shootList != NULL; shootList = shootList->next){
		for (foeList = state->foeList; foeList != NULL; foeList = foeList->next){
			if(DetectCollisionShoot(shootList, foeList->ship) && shootList->team == 'a'){
				LoseHealth(&(foeList->ship),shootList->damage);

				if(foeList->type == BOSS){
					Position pos_animation; 
					pos_animation.x = shootList->p.x;
					pos_animation.y = shootList->p.y - 30;
					AddAnimation(state,pos_animation, 6, TEMPORARY,explosion);
				}
				else{
					AddAnimation(state,shootList->p, 6, TEMPORARY,explosion);
				}
				MLV_play_sound(boom, 0.02);
				FreeShoot(&(state->shootList), shootList);
				if (IsDead(foeList->ship)){
					GetScore(state, foeList->type);
					if (MLV_get_random_integer(1,10) == 1)
						GenerateBonus(bonus, foeList->ship.p.x, foeList->ship.p.y);
					
					FreeFoe(&(state->foeList), foeList);
				}
				break;
			}
			if(DetectCollisionShoot(shootList, state->player) && shootList->team == 'e'){
				LoseHealth(&(state->player),shootList->damage);
				AddAnimation(state,shootList->p, 6, TEMPORARY,explosion);
				FreeShoot(&(state->shootList), shootList);
				if (IsDead(state->player)){
				}
				break;
			}
		}
	}
}
		
	

void CollisionShip(GameState* state){

	ListFoe tmpFoe;
	for (tmpFoe = state->foeList ; NULL != tmpFoe ; tmpFoe = tmpFoe->next)
	{
		if(DetectCollisionShip(state->player, tmpFoe->ship)){
			if(tmpFoe->type != BOSS){
				GetScore(state, tmpFoe->type);
				state->player.hp -= 10;
				FreeFoe((&state->foeList),tmpFoe);
			}
			else{
				state->player.hp = 0;
			}
		}
	}
}

int DetectCollisionShoot(ShootList shoot, Ship ship){
	return Distance(shoot->p, ship.p) < ship.hitbox.radius;
}

int DetectCollisionShip(Ship vaisseauPlayer, Ship vaisseauFoe){
	return Distance(vaisseauPlayer.p, vaisseauFoe.p) < vaisseauPlayer.hitbox.radius+vaisseauFoe.hitbox.radius;
}

void DrawLifebar(Ship ship, char type){

	int largeurLifeBar ;
	if('A' == type){
		largeurLifeBar = ship.hp * 0.8; 
		MLV_draw_rectangle(ship.p.x-POS_X_PLAYER_LIFEBAR-WITDH_SP+15, ship.p.y+POS_Y_PLAYER_LIFEBAR-WITDH_SP+25, 100*0.8, 5, MLV_COLOR_GREEN);
		MLV_draw_filled_rectangle(ship.p.x-POS_X_PLAYER_LIFEBAR-WITDH_SP+15, ship.p.y+POS_Y_PLAYER_LIFEBAR-WITDH_SP+25, largeurLifeBar, 3, MLV_COLOR_GREEN);

	}
	else{
		largeurLifeBar = ship.hp * 0.4;
		MLV_draw_filled_rectangle(ship.p.x-POS_X_BOSS_LIFEBAR, ship.p.y-POS_Y_BOSS_LIFEBAR, largeurLifeBar, 5, MLV_COLOR_RED);
	}
}


void LoadFont(){
	interface = MLV_load_font("font/Pixeled.ttf", 10);
}

void DrawScore(GameState *state){
	char score[10];
	sprintf(score, "%d", state->score);
	MLV_draw_text_with_font(state->window.width - 150,state->window.height - 100,"SCORE",interface,MLV_COLOR_WHITE );
	MLV_draw_text_with_font(state->window.width - 70,state->window.height - 100,score,interface,MLV_COLOR_WHITE );
}


void GetScore(GameState *state, TypeAnimation type){
	switch(type){
		case CLASSIC: state->score += 100;break;
		case FAST: state->score += 500;break;
		case BOSS: state->score += 1500;break;
	}
}

void FreeImages(){
	MLV_free_image(ship_a);
	MLV_free_image(ship_e);
	MLV_free_image(ship_f);
	MLV_free_image(ship_b);
	MLV_free_image(shoot_image_a);
	MLV_free_image(shoot_image_e);
	MLV_free_image(shoot_image_boss);
	MLV_free_image(explosion[0]);
	MLV_free_image(explosion[1]);
	MLV_free_image(explosion[2]);
	MLV_free_image(explosion[3]);
	MLV_free_image(explosion[4]);
	MLV_free_image(explosion[5]);
	MLV_free_image(background);
	MLV_free_image(heart);
	MLV_free_image(point);
	MLV_free_image(howtoplay);
}