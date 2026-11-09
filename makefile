
CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -O2
LDLIBS = -lncurses

TARGET = minesweeper
SRC_DIR = src

SOURCES = $(wildcard $(SRC_DIR)/*.c)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET) $(LDLIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

