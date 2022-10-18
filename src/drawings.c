#include "drawings.h"
#include "game_of_life.h"

void drawGreeting() {
    printf("====================================================================="
           "=============\n");
    printf("                                                                     "
           "             \n");
    printf("                              Amazing "
           "start screen of            \n");
    printf("                                                                "
           "                 \n");
    printf("                                                                       "
           "                  \n");
    printf("                # # # # # # # #   # # # # # # # #   #                "
           "                  \n");
    printf("                #                 #             #   #   "
           "                        \n");
    printf("                #                 #             #   #          "
           "             \n");
    printf("                #                 #             #   #         "
           "             \n");
    printf("                #                 #             #   #         "
           "             \n");
    printf("                #     # # # # #   #             #   #        "
           "             \n");
    printf("                #             #   #             #   #        "
           "             \n");
    printf("                #             #   #             #   #          "
           "             \n");
    printf("                # # # # # # # #   # # # # # # # #   # # # # # # # #"
           "             \n");
    printf("                                                                        "
           "             \n");
    printf("                                                                     "
           "             \n");
    printf("                            To end the game "
           "click 'ESC'     \n");
    printf("                                                                     "
           "             \n");
    printf("====================================================================="
           "=============\n");
}

void drawGameOver() {
    printf("====================================================================="
           "=============\n");
    printf("                                                                     "
           "             \n");
    printf("                                                                     "
           "             \n");
    printf("                                                                     "
           "             \n");
    printf("                                                                     "
           "             \n");
    printf("                                   See you!)     "
           "             \n");
    printf("                                                                     "
           "             \n");
    printf("                                                                     "
           "             \n");
    printf("                                                                     "
           "             \n");
    printf("                                                                     "
           "             \n");
    printf("====================================================================="
           "=============\n");
}

void drawLiveDeath() {
    printf("====================================================================="
           "=============\n");
    printf("                                                                     "
           "             \n");
    printf("           _===========_                                              "
           "             \n");
    printf("         _/             \\_                                          "
           "             \n");
    printf("        /                 \\                                         "
           "             \n");
    printf("       /    \\ /     \\ /    \\           You have become a pirate!    "
           "             \n");
    printf("      |      x       x      |    Oh, mistake, your life is in the past :(     "
           "             \n");
    printf("      |     / \\     / \\     |     To roll back time try restarting. "
           "             \n");
    printf("       \\                   /              Be more cheerful :)       "
           "             \n");
    printf("        \\_               _/                                         "
           "             \n");
    printf("          \\__ |  |  | __/                                          "
           "             \n");
    printf("             \\|  |  |/                                             "
           "             \n");
    printf("              |__|__|                                              "
           "             \n");
    printf("                                                                     "
           "             \n");
    printf("====================================================================="
           "=============\n");
}

void drawInfinity() {
    printf("====================================================================="
           "=============\n");
    printf("                                                                     "
           "             \n");
    printf("                                                     "
           "             \n");
    printf("                                                               "
           "             \n");
    printf("                            Congratulations! "
           "             \n");
    printf("                                                                 "
           "             \n");
    printf("                 Harmony reigned in your binary world! :)                  "
           "             \n");
    printf("                                                               "
           "             \n");
    printf("                                                  "
           "             \n");
    printf("                                                                     "
           "             \n");
    printf("====================================================================="
           "=============\n");
}

void drawManual() {
    printw("====================================================================="
           "=============\n");
    printw("                                                                     "
           "             \n");
    printw("                                Creator Mode                         "
           "             \n");
    printw("                                On/Off - 'f'                         "
           "             \n");
    printw("                              To select a cell:                      "
           "             \n");
    printw("      Move up - 'w'; move down - 's'; move left - 'a'; move right - 'd'  "
           "             \n");
    printw("                          Hard to be a binary God:                   "
           "             \n");
    printw("                             'q' - delete life                       "
           "             \n");
    printw("                            'e' - add new life!                      "
           "             \n");
    printw("                If for some reason you need to leave - 'ESC'         "
           "             \n");
    printw("                                                                     "
           "             \n");
    printw("====================================================================="
           "=============\n");
}
