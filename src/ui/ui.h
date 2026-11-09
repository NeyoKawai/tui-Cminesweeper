#pragma once
// I SEE NO REASONS TO MAKE SECOND .h FILE
#include "../game.h"
#include <curses.h>
void init_ui(void);
void shutdown_ui(void);
void draw_board(Cell board[HEIGHT][WIDTH], Game *game);
int get_input(void);
