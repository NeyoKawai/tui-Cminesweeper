#include "game.h"

void init_game(Game *game) {
  game->cursor_x = WIDTH / 2;
  game->cursor_y = HEIGHT / 2;
  game->flags_placed = 0;
  game->game_over = false;
  game->game_won = false;
  game->board_generated = false;
}

void reveal_cell(Game *game, Cell board[HEIGHT][WIDTH], int x, int y) {
  if (game->game_over || game->game_won)
    return;

  if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
    return;

  Cell *cell = &board[y][x];

  if (cell->revealed || cell->flagged)
    return;

  if (!game->board_generated) {
    generate_board(board, x, y);
    calculate_board_numbers(board);
    game->board_generated = true;
  }

  if (cell->has_mine) {
    cell->revealed = true;
    game->game_over = true;
    return;
  }

  flood_fill(board, x, y);

  if (check_win(board))
    game->game_won = true;
}
void toggle_flag(Game *game, Cell board[HEIGHT][WIDTH], int x, int y) {
  if (game->game_over || game->game_won)
    return;

  if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
    return;

  if (board[y][x].revealed)
    return;

  board[y][x].flagged = !board[y][x].flagged;

  if (board[y][x].flagged)
    game->flags_placed++;
  else
    game->flags_placed--;
}
void flood_fill(Cell board[HEIGHT][WIDTH], int x, int y) {
  if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
    return;

  Cell *cell = &board[y][x];

  if (cell->revealed || cell->flagged || cell->has_mine)
    return;

  cell->revealed = true;

  if (cell->adjacent_mines != 0)
    return;

  for (int dy = -1; dy <= 1; dy++) {
    for (int dx = -1; dx <= 1; dx++) {
      if (dx == 0 && dy == 0)
        continue;
      flood_fill(board, x + dx, y + dy);
    }
  }
}
bool check_win(Cell board[HEIGHT][WIDTH]) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (!board[y][x].revealed && !board[y][x].has_mine) {
        return false;
      }
    }
  }
  return true;
}
