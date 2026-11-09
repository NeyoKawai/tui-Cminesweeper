#include "board.h"
#include <stdlib.h>

void generate_board(Cell board[HEIGHT][WIDTH], int first_x, int first_y) {

  int placed = 0;

  while (placed < MINES) {
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;

    // Safe first click + surrounding cells
    if (abs(x - first_x) <= 1 && abs(y - first_y) <= 1) {
      continue;
    }

    if (board[y][x].has_mine) {
      continue;
    }

    board[y][x].has_mine = true;
    placed++;
  }
}
void init_board(Cell board[HEIGHT][WIDTH]) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      board[y][x].has_mine = false;
      board[y][x].flagged = false;
      board[y][x].revealed = false;
      board[y][x].adjacent_mines = 0;
    }
  }
}
int count_adjacent_mines(Cell board[HEIGHT][WIDTH], int x, int y) {
  int count = 0;
  for (int dy = -1; dy <= 1; dy++) {
    for (int dx = -1; dx <= 1; dx++) {
      if (dx == 0 && dy == 0) {
        continue;
      }
      int nx = x + dx;
      int ny = y + dy;

      if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT &&
          board[ny][nx].has_mine) {
        count++;
      }
    }
  }
  return count;
}
void calculate_board_numbers(Cell board[HEIGHT][WIDTH]) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      board[y][x].adjacent_mines = count_adjacent_mines(board, x, y);
    }
  }
}
