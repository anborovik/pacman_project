#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>
// #include <conio.h>
#include "./modules/map_gen.h"
#include "./modules/player.h"
#include "./modules/const.h"


char map[HEIGHT][WIDTH];
char action;
int gold_total = 0, gold_count = 0;
int lvl = 0;


// ncurses for linux
int main(int lvl)
{
    int x, y;
    player_coord player = {0, 0};
    read_map(lvl, &player, map, &gold_total);
    do {
        // cleare buffer
        clear();

        // check movements
        check_movement(action, map, &(player.py), &(player.px), &gold_count);

        // show screen
        initscr();
        if (gold_count == gold_total) {
            printw("You win! Press Ctrl+C to exit or press Space for next level.");
            char key;
            while (key = getch()) {
                if (key==' ') {
                    clear(); 
                    lvl++;
                    player.px = 0;
                    player.py = 0;
                    read_map(lvl, &player, map, &gold_total);
                    break;
                }
            }
        }
        for (int k = 0; k < HEIGHT; k++) {
            for (int l = 0; l < WIDTH; l++) {
                printw("%c", map[k][l]);
            }
        }

        printw("px = %d py = %d\n", player.px, player.py);
        printw("Level %d. Gold: %d/%d", lvl, gold_count, gold_total);
    } while (action = getch());
    endwin();
}


// // conio for windows
// int main(int lvl)
// {
//     int x, y;
//     player_coord player = {1, 1};
//     read_map(lvl, &player, map, &gold_total);
//     do {
//         // cleare buffer
//         system("cls"); 

//         // check movements
//         check_movement(action, map, &(player.py), &(player.px), &gold_count);

//         // show screen
//         if (gold_count == gold_total) {
//             cprintf("You win! Press Ctrl+C to exit or press Space for next level.");
//             char key;
//             while (key = getch()) {
//                 if (key==' ') {
//                     system("cls"); 
//                     lvl++;
//                     read_map(lvl, &player, map, &gold_total);
//                     break;
//                 }
//             }
//         }
//         for (int k = 0; k < HEIGHT; k++) {
//             for (int l = 0; l < WIDTH; l++) {
//                 cprintf("%c", map[k][l]);
//             }
//         }
//         cprintf("Level %d. Gold: %d/%d", lvl, gold_count, gold_total);
//     } while (action = getch());
// }