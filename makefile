PLATFORM ?= linux

CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -O2

SRC = src/main.c src/board.c src/game.c
BUILD_DIR = build

.PHONY: all clean linux windows run

all: $(PLATFORM)

# =========================
# Linux
# =========================

linux: $(BUILD_DIR)/minesweeper

$(BUILD_DIR)/minesweeper: $(SRC) src/ui/ui.c
	mkdir -p $(BUILD_DIR)
	gcc $(CFLAGS) $(SRC) src/ui/ui.c -lncurses -o $@

run: linux
	./$(BUILD_DIR)/minesweeper

# =========================
# Windows
# =========================

WIN_CC = x86_64-w64-mingw32-gcc
WIN_AR = x86_64-w64-mingw32-ar
WIN_CFLAGS = $(CFLAGS) -DPDC_WIDE -IPDCurses
PDCURSES_DIR = PDCurses/wincon
PDCURSES_LIB = $(PDCURSES_DIR)/pdcurses.a

windows: $(BUILD_DIR)/minesweeper.exe

$(PDCURSES_LIB):
	$(MAKE) -C $(PDCURSES_DIR) \
		CC=$(WIN_CC) \
		AR=$(WIN_AR) \
		CFLAGS="-O2 -DPDC_WIDE -I.."

$(BUILD_DIR)/minesweeper.exe: $(SRC) src/ui/ui_pdcurses.c $(PDCURSES_LIB)
	mkdir -p $(BUILD_DIR)
	$(WIN_CC) $(WIN_CFLAGS) \
		$(SRC) src/ui/ui_pdcurses.c \
		$(PDCURSES_LIB) \
		-o $@

clean:
	rm -rf $(BUILD_DIR)
