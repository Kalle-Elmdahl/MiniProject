#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"

int snakex = 0;
int snakey = 0;

struct Snake player1;
struct Apple apple;

void game_init() {
    dxsnake = 1;
    dysnake = 1;
    new_apple();
    player1 = initialize_snake();
}

void game_update() {        
    draw_rect(DISPLAY_WIDTH - 1 - 23, 0, 23, DISPLAY_HEIGHT);
    draw_image(DISPLAY_WIDTH - 1 - 16, 1, 9, 16, &lever_down[0][0]);
    draw_text(DISPLAY_WIDTH - 21, 3, "Exit");
    player1 = update_snake(player1);
    display_snake(player1);
    display_apple();


    // Borders
    draw_rect(0, 0, DISPLAY_WIDTH - 24, 1);
    draw_rect(0, 1, 1, DISPLAY_HEIGHT - 2);
    draw_rect(0, DISPLAY_HEIGHT - 1, DISPLAY_WIDTH - 24, 1);
    
    snakex = (snakex + dxsnake) % 128;
    snakey = (snakey + dysnake) % 32;

    pixels[snakey][snakex] = 1;
}