#ifndef __FOE__
#define __FOE__
#include "player.h"
#include <assert.h>
#define COORDINATE_Y_BOSS_STATION 100
#define COORDINATE_Y_FOE_START 0
#define WITDH_FAST 25
#define HEIGHT_FAST 27
#define HEIGHT_BOSS 75
#define WITDH_BOSS 62
#define CLASSIC_SPEED 2
#define FAST_SPEED 10
#define BOSS_SPEED 13


typedef enum
{
	CLASSIC,
	FAST,
	BOSS,
}foeType;

typedef enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}direction;

typedef struct foe
{
	Ship ship;
	foeType type;
	int direction;
	struct foe* next;
}Foe,*ListFoe;

/**
 * Print every information from the foe struct
 * @param foe an Foe of your choice
 * @return none
 */
void PrintFoe (Foe foe);

/**
 * A test function
 * @param p an integer **of your choice**
 * @return 0: if zero, 1: if positive, -1: if negative
 */
int FoeDetection(Position pos,ListFoe enemy,foeType type);

/**
 * Initialise an foe ship
 * @param enemy an ListFoe pointer type, listEnemy an *Foe, type an foeType, withd an int
 * @return 0: if something gone wrong, 1: if ok
 */
int InitFoe (ListFoe *enemy, ListFoe listEnemy, foeType type, int width);

/**
 * Add an foe ship to a list of foes
 * @param source an ListFoe pointer type, dest an ListFoe pointer type
 * @return none
 */
void AddFoe(ListFoe* source, ListFoe * dest);

/**
 * Print every foe's from an foes list
 * @param listFoe an Foe*
 * @return none
 */
void PrintFoeList (ListFoe listFoe);

/**
 * Test if 2 foes are equals
 * @param foe1 an Foe, foe2 an Foe
 * @return 0: if foes are equals, 1: if foes aren't equals
 */
int EqualsFoe (Foe foe1, Foe foe2);

/**
 * Extract an foe from an foes list
 * @param listFoe an ListFoe pointer type, foe an Foe*
 * @return Extracted Foe*
 */
ListFoe ExtractFoe (ListFoe * listFoe, ListFoe foe);

/**
 * Free an foe
 * @param listFoe an ListFoe pointer type, foe an *Foe
 * @return none
 */
void FreeFoe (ListFoe * listFoe, ListFoe foe);

/**
 * Free an entier foes list
 * @param listFoe an ListFoe pointer type
 * @return none
 */
void FreeListFoe (ListFoe * listFoe);

/**
 * Move every entity of an foes list
 * @param foe an ListFoe pointer type, witdh an int
 * @return none
 */
void MoveFoe(ListFoe* foe, int width);

/**
 * Initialise an entier wave of foes
 * @param foeNumber an int, foeList an ListFoe pointer type, type an foeType, witdh an int
 * @return none
 */
void InitWave(int foeNumber, ListFoe* foeList, foeType type, int width);

/**
 * Fill a foes wave list
 * @param foeList an ListFoe poijnter type, witdh an int
 * @return 0: if classic enemy wave, 1: if fast enemy wave, 2: if boss enemy wave
 */
int GenerateWave(ListFoe* foeList, int width);

#endif