#pragma once

#include "stdbool.h"

#define WIDTH 20
#define HEIGHT 20
#define MINES 40

typedef struct {
  bool has_mine;
  bool revealed;
  bool flagged;
  int adjacent_mines;
} Cell;

void generate_board(Cell board[HEIGHT][WIDTH], int first_x, int first_y);
void init_board(Cell board[HEIGHT][WIDTH]);
int count_adjacant_mines(Cell board[HEIGHT][WIDTH], int x, int y);
void calculate_board_numbers(Cell board[HEIGHT][WIDTH]);
