#ifndef GOL_GAME_OF_LIFE_H
#define GOL_GAME_OF_LIFE_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HEIGHT 20
#define WIDTH 80
#define SYMBOL_BORT '='
#define SYMBOL_BORT_SIDE 'N'
#define SYMBOL_DEATH ' '
#define SYMBOL_LIVE '#'
#define SYMBOL_K_LIVE 'L'
#define SYMBOL_K_DEATH 'D'

#define PAUSE ' '
#define CURSOR_UP 'w'
#define CURSOR_UP_UPPER 'W'
#define CURSOR_DOWN 's'
#define CURSOR_DOWN_UPPER 'S'
#define CURSOR_LEFT 'a'
#define CURSOR_LEFT_UPPER 'A'
#define CURSOR_RIGHT 'd'
#define CURSOR_RIGHT_UPPER 'D'
#define CURSOR_SWITCH 'f'
#define CURSOR_SWITCH_UPPER 'F'
#define ENTER_LIFE 'e'
#define ENTER_LIFE_UPPER 'E'
#define DELETE_LIFE 'q'
#define DELETE_LIFE_UPPER 'Q'
#define EXIT 27

#define END_OF_COORDINATES '\n'

bool allocate(int ***matrix, int n, int m);
int enterFileCoordinates(int **a, int n, int m);
int changeSpeedGameScanf();
int check_life(int **matrix, int n, int m, int row, int column);
int countAlive(int **matrix, int n, int m);
int update(int ***matrix, int n, int m);

void enterHumanCoordinates(int **a, int n, int m);
void changeSpeedGame(char speedMode, int *speedGame);
void printwField(int **A, int N, int M, int k_x, int k_y);
void printfField(int **A, int N, int M);
void cursorControl(char command, bool *Cursor, int *k_x, int *k_y,
                   int **field);
void zeroMatrix(int **a, int n, int m);
void drawGreeting();
void drawLiveDeath();
void drawGameOver();
void drawInfinity();
void drawManual();
void gameControl(char command, bool *Pause, bool *Exit, bool *isCursor,
                 int *speedGame, int *k_x, int *k_y, int **field);

#endif //GOL_GAME_OF_LIFE_H
