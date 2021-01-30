#ifndef __SOUND__
#define __SOUND__

#include <MLV/MLV_all.h>

MLV_Sound* stir_a;
MLV_Sound* stir_e;
MLV_Sound* boom;
MLV_Music* menu;
MLV_Music* bckg;

/**
 * Load every sound related files
 * @param none
 * @return none
 */
void LoadSound();

/**
 * Free every sound related variable
 * @param none
 * @return none
 */
void FreeSound();

#endif