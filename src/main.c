#include "game_of_life.h"
#include "drawings.h"

int main(int argc, char **argv) {
    bool Exit = false;
    bool AllDeath = false;
    bool Pause = false;
    bool Movement = true;
    bool Cursor = false;
    int SPEED_GAME = 100000;
    int k_x = -1;
    int k_y = -1;
    int **field = NULL;
    FILE *file = NULL;
    drawGreeting();
    allocate(&field, HEIGHT, WIDTH);
    if (*(argv[1]) == '1' || *(argv[1]) == '0') {
        if (*(argv[1]) == '1') {
            enterFileCoordinates(field, HEIGHT, WIDTH);
            file = freopen("/dev/tty", "r", stdin);
        } else {
            enterHumanCoordinates(field, HEIGHT, WIDTH);
            SPEED_GAME = changeSpeedGameScanf();
        }
    } else
        return 0;
    initscr();
    noecho();
    nodelay(stdscr, true);
    printwField(field, HEIGHT, WIDTH, k_x, k_y);
    while (!Exit && !AllDeath && Movement) {
        usleep(SPEED_GAME);
        refresh();
        clear();
        if (!Pause)
            Movement = update(&field, HEIGHT, WIDTH);
        printwField(field, HEIGHT, WIDTH, k_x, k_y);
        drawManual();
        gameControl(getch(), &Pause, &Exit, &Cursor, &SPEED_GAME, &k_x, &k_y,
                    field);
        if (!countAlive(field, HEIGHT, WIDTH))
            AllDeath = true;
    }
    endwin();
    printfField(field, HEIGHT, WIDTH);
    if (Exit)
        drawGameOver();
    if (AllDeath)
        drawLiveDeath();
    if (!Movement)
        drawInfinity();
    free(field);
    fclose(file);
    return 0;
}
