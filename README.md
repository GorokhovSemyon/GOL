# GOL (Game Of Life)
This is a logic game in which life arises and dies according to certain laws - [GOL](https://ru.wikipedia.org/wiki/%D0%98%D0%B3%D1%80%D0%B0_%C2%AB%D0%96%D0%B8%D0%B7%D0%BD%D1%8C%C2%BB) on C language for terminal Linux.

## Libraries for dynamic version
- [`ncurses`](https://en.wikipedia.org/wiki/Ncurses) - for real-time mode 
- [`unistd`](https://en.wikipedia.org/wiki/Unistd.h) - for the necessary console output presets
- [`stdio`](https://www.tutorialspoint.com/c_standard_library/stdio_h.htm) - for other primitive actions (e.g. printf())

## Compilation
Go to the GOL folder and enter in the terminal:
```
$ make
```
Run dynamic version GOL in the terminal:
```
$ ./GOL
```
## Gameplay
### General
Coordinates can be entered both manually and by reading from a file, for which it is necessary to correctly specify the file name.

### During the game
You can use the special "Creator mod" to add ('e') or remove ('q') life, to enter this mode you must press 'f' (both lowercase and uppercase commands are supported).

### Gif from original "Game of Life"
![GIF](https://github.com/GorokhovSemyon/GOL/blob/develop/materials/Gospers_glider_gun.gif)
