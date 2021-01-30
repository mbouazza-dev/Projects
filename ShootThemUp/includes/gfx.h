#ifndef __GFX__
#define __GFX__

#define NB_STARS 100
#define MAX_IMAGE 1000
#define OFFSET_X_TIR 10
#define OFFSET_Y_TIR 30
#define POS_X_PLAYER_LIFEBAR 20
#define POS_Y_PLAYER_LIFEBAR 35
#define POS_X_BOSS_LIFEBAR 20
#define POS_Y_BOSS_LIFEBAR 70

#include <MLV/MLV_all.h>
#include <stdarg.h>
#include "player.h"
#include "shoot.h"
#include "foe.h"



 
typedef struct parameter {
	const char* window_name;
	const char* icone_name;
}Parameter;


typedef struct grid {
	unsigned int width;
	unsigned int height;
}Grid;

typedef struct star {
	int x;
	int y;
	int radius;
}Star;

typedef enum 
{
	PERMANENT,
	TEMPORARY,
}TypeAnimation;

typedef struct anim{
	Position p;
	int frame_counter;
	int nb_image;
	TypeAnimation typeAnimation;
	MLV_Image** tab_image;
}Animation;

typedef struct 
{
	Animation *array;
	int animationNumber;
	int maxLength;
}AnimationArray;

typedef struct 
{
	Parameter parameter;
	Grid window;
	AnimationArray animationArray;
	Star starTab[NB_STARS];
	ShootList shootList;
	ListFoe foeList;
	Ship player;
	int score;
}GameState;


MLV_Image* ship_a;
MLV_Image* ship_e;
MLV_Image* ship_f;
MLV_Image* ship_b;
MLV_Image* shoot_image_a;
MLV_Image* shoot_image_e;
MLV_Image* shoot_image_boss;
MLV_Image* explosion[6];
MLV_Image* background;
MLV_Image* heart;
MLV_Image* point;
MLV_Image* howtoplay;

MLV_Font* interface;
MLV_Font* menu_font;


void GameStateInit(GameState *state);

/**
 * Initialise the gameState
 * @param GameState *state
 * @return none
 */
void InitGrid(Grid* grid,int width, int height);
/**
 * Initialise the window grid
 * @param Grid* grid,int width, int height
 * @return none
 */

void InitStarsTab(GameState* state);
/**
 * Initialise the stars tab for the background
 * @param GameState *state
 * @return none
 */

void DrawShoot (GameState* state);
/**
 * Draw the shots
 * @param GameState *state
 * @return none
 */

void DrawBackground(GameState* state);
/**
 * Draw the stars background
 * @param GameState *state
 * @return none
 */

void DrawShip(GameState* state);
/**
 * Draw a ship
 * @param GameState *state
 * @return none
 */

void DrawFoe(GameState* state);
/**
 * Draw all the enemy ships
 * @param GameState* state, Bonus bonus
 * @return none
 */

void DrawWindow (GameState* state, Bonus bonus);
/**
 * Draw all elements on the window
 * @param GameState* state, Bonus bonus
 * @return none
 */

void DrawBonus(Bonus bonus);
/**
 * Draw the bonus
 * @param Bonus bonus
 * @return none
 */

void DrawAnimation (GameState* state);
/**
 * Draw an animation
 * @param GameState* state
 * @return none
 */

void LoadImages ();
/**
 * Load all the files related to the used images
 * @param
 * @return none
 */

int DrawExplosion(int x, int y);
/**
 * Draw the explosion animation
 * @param int x, int y
 * @return none
 */

void DrawFrameAnimation (Animation* animation);
/**
 * Draw the framed animation
 * @param Animation* animation
 * @return none
 */

void DrawLifebar(Ship ship, char c);
/**
 * Draw the ship life bar
 * @param Ship ship, char c
 * @return none
 */

void DrawHowToPlay();
/**
 * Draw the how to play menu
 * @param
 * @return none
 */

void InitAnimation(Animation* animation_image, Position position_image, int nb_image_animation,TypeAnimation typeAnimation,MLV_Image* tab_image[]);
/**
 * Initialise an animation
 * @param Animation* animation_image, Position position_image, int nb_image_animation,TypeAnimation typeAnimation,MLV_Image* tab_image[]
 * @return none
 */

void FreeAnimation (Animation * animation);
/**
 * Free an animation
 * @param Animation * animation
 * @return none
 */

void FillAnimation (Animation* animation, ...);
/**
 * Fill an animation
 * @param Animation* animation, ...
 * @return none
 */

static int IsFinishAnimation(Animation animation);
/**
 * Check if an animation is finished or not
 * @param Animation animation
 * @return none
 */

int IsActivAnimation(Animation animation);
/**
 * Chek if an animation is activ or not
 * @param Animation animation
 * @return none
 */

void UpComptFrame(Animation *animation);
/**
 * 
 * @param Animation *animation
 * @return none
 */

void SetInactivAnimation(Animation *animation);
/**
 * Set an animation to inactiv
 * @param Animation *animation
 * @return none
 */

void RollBackAnimation(Animation *animation);
/**
 * Rewind an animation
 * @param Animation *animation
 * @return none
 */

void AddAnimation(GameState *state,Position position_collision, int nb_image_animation,TypeAnimation typeAnimation,MLV_Image* tab_image[] );
/**
 * Add an animation to an animation array
 * @param GameState *state,Position position_collision, int nb_image_animation,TypeAnimation typeAnimation,MLV_Image* tab_image[]
 * @return none
 */

int InitAnimationArray(AnimationArray* animationArray);
/**
 * Initialise an animation array
 * @param AnimationArray* animationArray
 * @return none
 */

int ResizeAnimationArray (AnimationArray * animationArray);
/**
 * Resize an animation array
 * @param AnimationArray* animationArray
 * @return none
 */

void CollisionShoot(GameState* state, Bonus* bonus);
/**
 * 
 * @param GameState* state, Bonus* bonus
 * @return none
 */

void CollisionShip(GameState* state);
/**
 * 
 * @param GameState* state
 * @return none
 */

int DetectCollisionShoot(ShootList shoot, Ship ship);
/**
 * 
 * @param ShootList shoot, Ship ship
 * @return none
 */

int DetectCollisionShip(Ship vaisseauPlayer, Ship vaisseauFoe);
/**
 * 
 * @param Ship vaisseauPlayer, Ship vaisseauFoe
 * @return none
 */

void LoadFont();
/**
 * Load all the files related to text font
 * @param 
 * @return none
 */

void DrawInterface(GameState *state);
/**
 * Draw the score on the window
 * @param GameState *state
 * @return none
 */

void DrawInterfaceBar(GameState *state);
/**
 * Detect Colision between a shoot and a ship
 * @param GameState *state
 * @return none
 */

void GetScore(GameState *state, TypeAnimation type);
/**
 * get the score frome the gameState
 * @param GameState *state, TypeAnimation type
 * @return none
 */

void DrawScore(GameState *state);
/**
 * Draw the score on the window
 * @param GameState *state
 * @return none
 */

void FreeImages();
/**
 * Free all the images
 * @param
 * @return none
 */

#endif