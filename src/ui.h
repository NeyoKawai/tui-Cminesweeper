#pragma once

#include "game.h"
#include <ncurses.h>
void init_ui(void);
void shutdown_ui(void);
void draw_board(Cell board[HEIGHT][WIDTH], Game *game);
int get_input(void);
