#include "game_of_life.h"
#include "drawings.h"

int main() {
    bool Exit = false;
    bool AllDeath = false;
    bool Pause = false;
    bool Movement = true;
    bool Cursor = false;
    char choice = ' ';
    int SPEED_GAME = 100000;
    int k_x = -1;
    int k_y = -1;
    int **field = NULL;
    FILE *file = NULL;
    drawGreeting();
    printf("Do you want to enter the coordinates of the first life yourself? (y/n)\n");
    scanf("%c", &choice);
    if (allocate(&field, HEIGHT, WIDTH) == false)
        return 0;
    if (choice == 'y' || choice == 'Y') {
        printf("Do you know any secret combinations?) Enter them in the format\n"
               "<X1> <Y2>\n"
               ".........\n"
               "<Xn> <Yn>.\n");
        enterHumanCoordinates(field, HEIGHT, WIDTH);
        SPEED_GAME = changeSpeedGameScanf();
    } else if (choice == 'n' || choice == 'N') {
        printf("Enter the file name to see the beauty!\n");
        inputCoordinatesFromFile(field, HEIGHT, WIDTH);
    } else {
        free(field);
        return 0;
    }
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
    if (file != NULL)
        fclose(file);
    return 0;
}
