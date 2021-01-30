#include "../includes/sound.h"


void LoadSound(){
	MLV_init_audio();
	stir_a = MLV_load_sound("media/stir_a.wave");
	stir_e = MLV_load_sound("media/stir_e.wave");
	boom = MLV_load_sound("media/explosion.wave");
	menu = MLV_load_music("media/menu.mp3");
	bckg = MLV_load_music("media/background.wave");
}

void FreeSound(){
	MLV_stop_all_sounds();
	MLV_free_sound(stir_a);
	MLV_free_sound(stir_e);
	MLV_free_sound(boom);
	MLV_free_music(bckg);
	MLV_free_audio();
}