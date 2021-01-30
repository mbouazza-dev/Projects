#include "../includes/player.h"
#include "../includes/gfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void InitShip (Ship* vs, Position coordinate, int radius, int hp){
	vs->p = coordinate; 
	vs->hitbox.radius = radius;
	vs->hp = hp;
	vs->speed = PLAYER_SPEED;
}

void PrintShip (Ship vs){
	printf("Position : (%d,%d); ", vs.p.x, vs.p.y);
}

void MoveShip(Ship * vs, int width, int height, Bonus* bonus, int* score){
	
	assert(vs != NULL);
	if ( MLV_get_keyboard_state( MLV_KEYBOARD_UP ) == MLV_PRESSED && ValidMove(vs->p.x, vs->p.y - vs->speed, width, height
		) ){
		vs->p.y = vs->p.y-vs->speed;
		ObtainedBonus(vs, bonus, score);
	}
	if (MLV_get_keyboard_state( MLV_KEYBOARD_DOWN ) == MLV_PRESSED && ValidMove(vs->p.x, vs->p.y + vs->speed, width, height
		) ){
		vs->p.y = vs->p.y+vs->speed;
		ObtainedBonus(vs, bonus, score);
	}
	if (MLV_get_keyboard_state( MLV_KEYBOARD_LEFT ) == MLV_PRESSED && ValidMove(vs->p.x - vs->speed, vs->p.y, width, height
		) ){
		vs->p.x = vs->p.x-vs->speed;
		ObtainedBonus(vs, bonus, score);
	}
	if (MLV_get_keyboard_state( MLV_KEYBOARD_RIGHT ) == MLV_PRESSED && ValidMove(vs->p.x + vs->speed, vs->p.y, width, height
		) ){
		vs->p.x = vs->p.x+vs->speed;
		ObtainedBonus(vs, bonus, score);
	}
}

int EqualsShip (Ship vs1, Ship vs2){
	return vs1.p.x == vs2.p.x && vs1.p.y == vs2.p.y && vs1.hitbox.radius == vs2.hitbox.radius;
}

int ValidMove(int x, int y, int width, int height){
		return 0 < (x - WITDH_SP) && (x + WITDH_SP) < width && 0 < (y - HEIGHT_SP) && (y + HEIGHT_SP + 80 ) < height ;	
}

void LoseHealth(Ship * vs, int abrupt_damage){
	vs->hp -= abrupt_damage;
}

int Distance(Position a, Position b){
	return sqrt( (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
}

int IsDead(Ship vs){
	return vs.hp <= 0;
}

void InitBonus(Bonus* bonus){
	bonus->cord.x = -1000;
	bonus->cord.y = -1000;
	bonus->type = 'n';
}

void GenerateBonus(Bonus* bonus, int x, int y){
	bonus->cord.x = x;
	bonus->cord.y = y;
	if (MLV_get_random_boolean() == 0)
		bonus->type = 'h';
	else{
		bonus->type = 'p';
	}
}

int ObtainedBonus(Ship* vs, Bonus* bonus, int* score){
	if ( Distance(bonus->cord, vs->p)<16 ){
		if (bonus->type == 'h'){
			vs->hp += 15;
			bonus->cord.x = -1000;
			bonus->cord.y = -1000;
			bonus->type = 'n';
			return 0;
		}
		if (bonus->type == 'p'){
			*score += 150;
			bonus->cord.x = -1000;
			bonus->cord.y = -1000;
			bonus->type = 'n';
			return 0;
		}
	}
	return 1;
}