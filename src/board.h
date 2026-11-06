#pragma once

#include "stdbool.h"

#define WIDTH 10
#define HEIGHT 10

typedef struct {
  bool has_mine;
  bool revealed;
  bool flagged;
  int adjacent_mines;
} Cell;

void init_board(Cell board[HEIGHT][WIDTH]);
