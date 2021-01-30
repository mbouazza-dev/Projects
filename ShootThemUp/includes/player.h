#ifndef __PLAYER__
#define __PLAYER__

#include <MLV/MLV_all.h>

#define COORDINATE_X_START 500
#define COORDINATE_Y_START 600
#define RADIUS 20
#define RADIUS_BOSS 70
#define RADIUS_FAST 20	
#define WITDH_SP 36
#define HEIGHT_SP 27
#define BASE_HP 100
#define PLAYER_SPEED 10


typedef struct hitbox {
	int radius;
}Hitbox;

typedef struct position
{
	int x,y ;
}Position;

typedef struct ship{
	Position p;
	int hp;
	int speed;
	Hitbox hitbox;
}Ship;

typedef struct bonus
{
	Position cord;
	char type;
}Bonus;

/**
 * Initialise a ship struct
 * @param vs a *Ship, coordinate a Position struct, radius an int, hp an int
 * @return none
 */
void InitShip (Ship* vs, Position coordinate, int radius, int hp);

/**
 * Print every information from the ship struct
 * @param vs a Ship
 * @return none
 */
void PrintShip (Ship vs);

/**
 * Move a Ship entity
 * @param vs a Ship*, witdh an int, height an int, bonus a Bonus*, score an int*
 * @return none
 */
void MoveShip(Ship * vs, int width, int height, Bonus* bonus, int* score);

/**
 * Check if a move is valid (inside the game window)
 * @param x,y,witdh and height all int
 * @return 0: if move is valid
 */
int ValidMove(int x, int y, int width, int height);

/**
 * Check if 2 ships are equals
 * @param vs1, vs2 all Ship
 * @return 0: if ships are equals, 1: if ships are not equals
 */
int EqualsShip (Ship vs1, Ship vs2);

/**
 * Calculate distance between 2 objects compared to their positions
 * @param a and b both Position
 * @return distance
 */
int Distance(Position a, Position b);

/**
 * Check if is a ship is dead or not
 * @param vs a Ship
 * @return 0: if the ship is dead, 1: if the ship is not dead
 */
int IsDead(Ship vs);

/**
 * Take health from a ship
 * @param vs a SHip*, abrupt_damage an int
 * @return none
 */
void LoseHealth(Ship * vs, int abrupt_damage);

/**
 * Initialise a bonus
 * @param bonus a Bonus*
 * @return none
 */
void InitBonus(Bonus* bonus);

/**
 * Fill bonus struct variable
 * @param bonus a Bonus* and x and y both int
 * @return none
 */
void GenerateBonus(Bonus* bonus, int x, int y);

/**
 * Check if the player did take the bonus or not
 * @param vs a Ship*, bonus an Bonus*, score an int*
 * @return 0: if the player took the bonus, 1: if the player didn't take the bonus
 */
int ObtainedBonus(Ship* vs, Bonus* bonus, int* score);
#endif