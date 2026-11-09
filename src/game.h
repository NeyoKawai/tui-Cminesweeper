#pragma once

#include "board.h"
#include <stdbool.h>

typedef struct {
  int cursor_x;
  int cursor_y;

  int flags_placed;

  bool game_over;
  bool game_won;
  bool board_generated;
} Game;

void init_game(Game *game);

void reveal_cell(Game *game, Cell board[HEIGHT][WIDTH], int x, int y);

void toggle_flag(Game *game, Cell board[HEIGHT][WIDTH], int x, int y);

void flood_fill(Cell board[HEIGHT][WIDTH], int x, int y);

bool check_win(Cell board[HEIGHT][WIDTH]);
