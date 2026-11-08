#include "ui.h"
#include <ncurses.h>

void init_ui(void) {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);

  if (has_colors()) {
    start_color();
    use_default_colors();

    init_pair(1, COLOR_WHITE, COLOR_BLUE); // Closed
    init_pair(2, COLOR_RED, -1);           // Mine
    init_pair(3, COLOR_CYAN, -1);          // 1
    init_pair(4, COLOR_GREEN, -1);         // 2
    init_pair(5, COLOR_YELLOW, -1);        // 3
    init_pair(6, COLOR_MAGENTA, -1);       // 4+
    init_pair(7, COLOR_RED, -1);           // Flag
    init_pair(8, COLOR_WHITE, -1);         // Default
  }
}

void shutdown_ui(void) { endwin(); }

void draw_board(Cell board[HEIGHT][WIDTH], Game *game) {
  erase();

  int start_y = (LINES - HEIGHT) / 2;
  int start_x = (COLS - WIDTH * 3) / 2;

  if (LINES < HEIGHT + 6 || COLS < WIDTH * 3 + 4) {
    mvprintw(0, 0, "Terminal too small!");
    refresh();
    return;
  }

  mvprintw(1, start_x, "MINESWEEPER");
  mvprintw(2, start_x, "Flags: %d / %d", game->flags_placed, MINES);

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      Cell *cell = &board[y][x];

      int screen_y = start_y + y;
      int screen_x = start_x + x * 3;

      bool selected = (x == game->cursor_x && y == game->cursor_y);

      if (selected)
        attron(A_REVERSE);

      if (cell->flagged && !cell->revealed) {
        attron(COLOR_PAIR(7));
        mvaddstr(screen_y, screen_x, " F ");
        attroff(COLOR_PAIR(7));
      } else if (!cell->revealed) {
        attron(COLOR_PAIR(1));
        mvaddstr(screen_y, screen_x, "###");
        attroff(COLOR_PAIR(1));
      } else if (cell->has_mine) {
        attron(COLOR_PAIR(2));
        mvaddstr(screen_y, screen_x, " * ");
        attroff(COLOR_PAIR(2));
      } else if (cell->adjacent_mines == 0) {
        mvaddstr(screen_y, screen_x, "   ");
      } else {
        int color = 6;

        if (cell->adjacent_mines == 1)
          color = 3;
        else if (cell->adjacent_mines == 2)
          color = 4;
        else if (cell->adjacent_mines == 3)
          color = 5;

        attron(COLOR_PAIR(color));
        mvprintw(screen_y, screen_x, " %d ", cell->adjacent_mines);
        attroff(COLOR_PAIR(color));
      }

      if (selected)
        attroff(A_REVERSE);
    }
  }

  int footer_y = start_y + HEIGHT + 1;

  if (game->game_over)
    mvprintw(footer_y, start_x, "GAME OVER! Press Q to quit.");
  else if (game->game_won)
    mvprintw(footer_y, start_x, "YOU WON! Press Q to quit.");
  else
    mvprintw(footer_y, start_x,
             "WASD / Arrows: Move | Z: Reveal | X: Flag | Q: Quit");

  refresh();
}

int get_input(void) { return getch(); }
