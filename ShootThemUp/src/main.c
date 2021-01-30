#define _XOPEN_SOURCE 700
#define BILLION 1000000000

#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <time.h>
#include <sys/time.h>   
#include <sys/resource.h>  
#include "../includes/gfx.h"
#include "../includes/player.h"
#include "../includes/shoot.h"
#include "../includes/foe.h"
#include "../includes/menu.h"
#include "../includes/sound.h"

int main(int argc, char const *argv[])
{
	int accum = 0;
	struct timespec new, last;
	int frame = 0;
	MLV_Keyboard_button key_sym;
	MLV_Button_state state;
	Bonus bonus;
	
	GameState gameState;

	GameStateInit(&gameState);
	InitBonus(&bonus);
	MLV_create_window(gameState.parameter.window_name, gameState.parameter.icone_name, gameState.window.width, gameState.window.height);
	LoadImages();
	LoadFont();
	LoadSound();

	InitWave(20, &(gameState.foeList), CLASSIC, gameState.window.width);

	switch(DrawMenu()){
		case 1:
			break;
		case 2:
			DrawHowToPlay();
			MLV_wait_keyboard_or_mouse(NULL,NULL,NULL,NULL,NULL); 	
			break;
		case 3:
			exit(1);
			break;
		default:
			break;
	}
	MLV_actualise_window();
	MLV_play_music(bckg, 0.3, -1);
	 while (!IsDead(gameState.player)){
	 	frame += 1;
		/* Get the time in nanosecond at the frame begining */
		clock_gettime(CLOCK_REALTIME, &last);
		/* Display of the current frame */
		/* THIS FUNCTION CALL A SINGLE TIME MLV_actualize_window */
		DrawWindow(&gameState, bonus);

		/* We get here at most one keyboard event each frame */
		MLV_get_event(&key_sym, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &state);
		
		/* Event resolution here.... */

		/* Moves of the entities on the board */
		MoveFoe(&(gameState.foeList), gameState.window.width);
		MoveShip(&(gameState.player), gameState.window.width, gameState.window.height, &bonus, &(gameState.score));
		Shoot_a(gameState.player, &(gameState.shootList), key_sym, state);
		if (frame%40 == 0)
			Shoot_e(gameState.foeList, &(gameState.shootList),gameState.player, gameState.window.height);
		if (frame%230 == 0)
			GenerateWave(&(gameState.foeList), gameState.window.width);
		ShootIncrementation(&(gameState.shootList));
        /* Collision resolutions */
		CollisionShoot(&gameState, &bonus);
		CollisionShip(&gameState);

        state = MLV_RELEASED;

		/* Get the time in nanosecond at the frame ending */
		clock_gettime(CLOCK_REALTIME, &new);
		/* We compute here the time spent for the current frame */
		accum = (new.tv_sec-last.tv_sec)+((new.tv_nsec-last.tv_nsec)/BILLION);

		/* We force here to wait if the frame was too short */
		if (accum < (1.0/48.0)){
			MLV_wait_milliseconds((int)(((1.0/48.0) - accum)*1000));
		}
		
	}
	MLV_free_font(interface);
	MLV_free_font(menu_font);
	FreeSound();
	FreeImages();
	MLV_free_window();
	return 0;
}