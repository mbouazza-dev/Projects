#include "../includes/menu.h"


int DrawMenu(){
	MLV_play_music(menu, 0.05, -1);
	DrawBckg();
	return DrawTitle();
}

void DrawBckg(){
	MLV_draw_image(background,0, 0);
}

int DrawTitle(){
	int x, y;
	menu_font = MLV_load_font("font/Pixeled.ttf", 35);
	MLV_draw_text_with_font(100, 100, "PLAY", menu_font, MLV_COLOR_WHITE);
	MLV_draw_text_with_font(100, 300, "HOW TO PLAY", menu_font, MLV_COLOR_WHITE);
	MLV_draw_text_with_font(100, 500, "QUIT", menu_font, MLV_COLOR_WHITE);
	MLV_get_mouse_position(&x,&y);
	while (1){
		if (x > 100 && x < 245 && y > 135 && y < 180){
			MLV_draw_text_with_font(100, 100, "PLAY", menu_font, MLV_COLOR_RED);
			if ( MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED	){
				MLV_free_music(menu);
				return 1;
			}
		}
		else if (x > 100 && x < 460 && y > 335 && y < 380){
			MLV_draw_text_with_font(100, 300, "HOW TO PLAY", menu_font, MLV_COLOR_RED);
			if ( MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED	){
				MLV_free_music(menu);
				return 2;
			}

		}
		else if (x > 100 && x < 230 && y > 530 && y < 580){
			MLV_draw_text_with_font(100, 500, "QUIT", menu_font, MLV_COLOR_RED);
			if ( MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED	){
				MLV_free_music(menu);
				return 3;
			}
		}
		else {
			MLV_draw_text_with_font(100, 100, "PLAY", menu_font, MLV_COLOR_WHITE);
			MLV_draw_text_with_font(100, 300, "HOW TO PLAY", menu_font, MLV_COLOR_WHITE);
			MLV_draw_text_with_font(100, 500, "QUIT", menu_font, MLV_COLOR_WHITE);
		}
		MLV_get_mouse_position(&x,&y);
		MLV_actualise_window();
	}
}