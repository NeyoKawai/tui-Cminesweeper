#include <stdlib.h>
#include <time.h>

#include "board.h"
#include "game.h"
#include "ui/ui.h"

int main(void) {
  Cell board[HEIGHT][WIDTH];
  Game game;

  srand(time(NULL));

  init_board(board);
  init_game(&game);
  init_ui();

  int running = 1;

  while (running) {
    draw_board(board, &game);

    int key = get_input();

    switch (key) {
    case 'w':
    case 'W':
    case KEY_UP:
      if (game.cursor_y > 0)
        game.cursor_y--;
      break;

    case 's':
    case 'S':
    case KEY_DOWN:
      if (game.cursor_y < HEIGHT - 1)
        game.cursor_y++;
      break;

    case 'a':
    case 'A':
    case KEY_LEFT:
      if (game.cursor_x > 0)
        game.cursor_x--;
      break;

    case 'd':
    case 'D':
    case KEY_RIGHT:
      if (game.cursor_x < WIDTH - 1)
        game.cursor_x++;
      break;

    case 'z':
    case 'Z':
      reveal_cell(&game, board, game.cursor_x, game.cursor_y);
      break;

    case 'x':
    case 'X':
      toggle_flag(&game, board, game.cursor_x, game.cursor_y);
      break;

    case 'q':
    case 'Q':
      running = 0;
      break;
    }
  }
  shutdown_ui();
  return 0;
}
