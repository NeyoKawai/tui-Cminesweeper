#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "src/board.h"

void print_board(Cell board[HEIGHT][WIDTH]) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (board[y][x].has_mine) {
        printf("* ");
      } else {
        printf("%d ", board[y][x].adjacent_mines);
      }
    }
    printf("\n");
  }
}

int main(void) {
  Cell board[HEIGHT][WIDTH];

  srand(time(NULL));

  init_board(board);
  generate_board(board, 0, 0);
  calculate_board_numbers(board);

  print_board(board);

  return 0;
}
