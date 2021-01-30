#ifndef __MENU__
#define __MENU__
#include <MLV/MLV_all.h>
#include "gfx.h"
#include "sound.h"

#define X_PLAY 220
#define X_QUIT 220
#define X_HOWTOPLAY 110
#define Y_PLAY 480
#define Y_QUIT 570
#define Y_HOWTOPLAY 390

#define WIDTH_PLAY 170
#define WIDTH_QUIT 170
#define WIDTH_HOWTOPLAY 450
#define HEIGHT_PLAY 70
#define HEIGHT_QUIT 70
#define HEIGHT_HOWTOPLAY 70

/**
 * Display Menu with multiple options
 * @param none
 * @return value of the DrawTitle function
 */
int DrawMenu();

/**
 * Display the background menu's image
 * @param none
 * @return none
 */
void DrawBckg();

/**
 * Display every menu's options
 * @param none
 * @return 1: if player select the PLAY option, 2: if the player select the HOW TO PLAY option, 3: if the player select the QUIT option
 */
int DrawTitle();
#endif