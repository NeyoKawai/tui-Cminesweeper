# TUI Minesweeper (Linux and Windows)

A simple terminal-based Minesweeper game written in C using **ncurses**.

## Features
- Terminal-based interface powered by ncurses
- Safe first click
- Recursive flood fill
- Keyboard controls (I'll let u bind them in updates)
- Colored numbers and cursor highlighting

## Planned Features
- Better UI (STILL TUI)
- Customizable board dimensions and mine count
- Configurable keyboard bindings
- Custom color themes
- Game statistics and best times
- Daily challenges and streaks
- Persistent settings

## Requirements
- GCC
- GNU Make
- ncurses
- At least an IBM PC from 1980
### Prerequisites

#### WINDOWS VISTA/XP/7/10/11
just pray your cmd can work with this thing
and ofc pray that my makefile would work for u

### Select your Linux distribution to install the required dependencies (`gcc`, `make`, `ncurses`):

#### Arch Linux
```bash
sudo pacman -S gcc make ncurses
```

#### Debian / Ubuntu / Linux Mint
```bash
sudo apt update && sudo apt install gcc make libncurses-dev
```

#### Fedora / RHEL / CentOS
```bash
sudo dnf install gcc make ncurses-devel
```

#### OpenSUSE
```bash
sudo zypper install gcc make ncurses-devel
```
## Build

Clone the repository:

```bash
git clone https://github.com/NeyoKawai/cli-Cminesweeper.git
cd cli-Cminesweeper
```

Compile:

```bash
make
```

Run:

```bash
make run
```

Clean build files:

```bash
make clean
```

## Controls

| Key | Action |
|---|---|
| W / ↑ | Move up |
| A / ← | Move left |
| S / ↓ | Move down |
| D / → | Move right |
| Z | Reveal cell |
| X | Toggle flag |
| Q | Quit |

## Project Structure

```text
src/
├── main.c
├── board.c
├── board.h
├── game.c
├── game.h
├── ui.c
└── ui.h

Makefile
LICENSE
README.md
```
```

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

---

Made by [NeyoKawai](https://github.com/NeyoKawai)
