#ifndef GOL_GAME_OF_LIFE_H
#define GOL_GAME_OF_LIFE_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// настройка поля
#define HEIGHT 20
#define WIDTH 80
#define SYMBOL_BORT '='
#define SYMBOL_BORT_SIDE 'N'
#define SYMBOL_DEATH ' '
#define SYMBOL_LIVE '#'
#define SYMBOL_K_LIVE 'L'
#define SYMBOL_K_DEATH 'D'

// настройки управления игрой
#define PAUSE ' '
#define CURSOR_UP 'w'
#define CURSOR_DOWN 's'
#define CURSOR_LEFT 'a'
#define CURSOR_RIGHT 'd'
#define CURSOR_SWITCH 'f'
#define ENTER_LIFE 'e'
#define DELETE_LIFE 'q'
#define EXIT 27

// настройки ручного ввода
#define BETWEEN_XY ' '
#define END_OF_COORDINATES '\n'

bool allocate(int ***matrix, int n, int m);
int enterHumanCoordinates(int **a, int n, int m);
int enterFileCoordinates(int **a, int n, int m);
int changeSpeedGameScanf();
int check_life(int **matrix, int n, int m, int row, int column);
int countAlive(int **matrix, int n, int m);
int update(int ***matrix, int n, int m);

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
