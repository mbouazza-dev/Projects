#ifndef __SHOOT__
#define __SHOOT__
#include "player.h"
#include "foe.h"
#include "sound.h"
#include <assert.h>
#include <math.h>

#define COORD_Y_DEPART_TIR 10
#define PLAYER_SHOOT_SPEED 30
#define CLASSIC_SHOOT_SPEED 15


typedef enum
{
	LAZER,
	MISSILE,
	BOMBE,
}TypeShoot;

typedef struct shoot{
	Position p;
	char team;
	TypeShoot type;
	int speed;
	int damage;
	struct shoot *next;
	double coeff;
	double ordonne_origine;
	double angle;
}Shoot,*ShootList;

/**
 * Initialise a Shoot struct
 * @param shoot a Shoot**, pos Position, team char, type TypeShoot, speed int
 * @return 0: if error, else 1
 */
int InitShoot (Shoot ** shoot, Position pos, char team, TypeShoot type,int speed);

/**
 * Print every information from the shoot struct
 * @param shoot Shoot*
 * @return none
 */
void PrintShoot (ShootList shoot);

/**
 * Add a shoot to a shoot list
 * @param tir1 ShootList*, tir2 ShootList*
 * @return none
 */
void AddShoot (ShootList* tir1, ShootList* tir2);

/**
 * Extract a shoot from a shoot list
 * @param shootList ShootList*, shoot ShootList
 * @return extracted ShootList
 */
ShootList ExtractShoot (ShootList * shootList, ShootList shoot);

/**
 * Free a shoot from a shoot list
 * @param shootList ShootList*, shoot ShootList
 * @return none
 */
void FreeShoot(ShootList * shootList, ShootList shoot);

/**
 * Test if 2 shots are equals
 * @param Shoot tir1, Shoot tir2
 * @return 0: if shoots are equals, 1: if shoots aren't equals
 */
int EqualsShoot (Shoot tir1, Shoot tir2);

/**
 * Make the player shoot
 * @param 
 * @return 0: if error else 1
 */
int Shoot_a(Ship vs, ShootList* shootList, MLV_Keyboard_button key_sym,MLV_Button_state state);

/**
 * 
 * @param ListFoe* foe, Ship* vs, ShootList* shootList
 * @return none
 */
int ColisionDetection(ListFoe* foe, Ship* vs, ShootList* shootList);

/**
 * Detect Colision between a shoot and a ship
 * @param ShootList shoot, Ship vs
 * @return none
 */
int collisionShipShoot(ShootList shoot, Ship vs);

/**
 * Make the ennemy shoot
 * @param ListFoe listFoe, ShootList* shootList, Ship joueur, int height
 * @return 0 if error else 1
 */
int Shoot_e(ListFoe listFoe, ShootList* shootList, Ship joueur, int height);

/**
 * Make all the player ship shots moving
 * @param ShootList* shootList
 * @return 0 if error else 1
 */
int ShootIncrementation(ShootList* shootList);

/**
 * Make all the enemys ships shots moving
 * @param Shoot * shoot
 * @return 0 if error else 1
 */
int FoeShootIncrementation (Shoot * shoot);

/**
 * Calculate an angle
 * @param Position pos_joueur, Position pos_ennemie
 * @return angle
 */
double GiveAngle(Position pos_joueur, Position pos_ennemie );

/**
 * Calculate an equation with an angle
 * @param double* coeff, double* ordonne_origine, double* angle, Position pos_joueur, Position pos_ennemie 
 * @return none
 */
void GiveEquation(double* coeff, double* ordonne_origine, double* angle, Position pos_joueur, Position pos_ennemie );
#endif