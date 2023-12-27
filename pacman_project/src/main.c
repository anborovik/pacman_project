#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <ncurses.h>
#include <conio.h>
#include "./modules/map_gen.h"
#include "./modules/player_action.h"


int px = 1, py = 1;
char map[9][45];
char action;
int gold_total = 0, gold_count = 0;
int lvl = 0;


// int main(int lvl)
// {
//     int x, y;
//     read_map(lvl);
//     do {
//         // cleare buffer
//         clear();

//         // check movements
//         check_movement(action, &px, &py);

//         // show screen
//         initscr();
//         for (int k = 0; k < 9; k++) {
//             for (int l = 0; l < 45; l++) {
//                 printw("%c", map[k][l]);
//             }
//         }
//         printw("Level %d. Gold: %d/%d", lvl, gold_count, gold_total);
//     } while (action = getch());
//     endwin();
// }


int main(int lvl)
{
    int x, y;
    read_map(lvl, &py, &px, map, &gold_total);
    do {
        // cleare buffer
        system("cls"); 

        // check movements
        check_movement(action, map, &px, &py, &gold_count);

        // show screen
        if (gold_count == gold_total) {
            cprintf("You win! Press Ctrl+C to exit or press Space for next level.");
            char key;
            while (key = getch()) {
                if (key==' ') {
                    system("cls"); 
                    lvl++;
                    read_map(lvl, &py, &px, map, &gold_total);
                    break;
                }
            }
        }
        for (int k = 0; k < 9; k++) {
            for (int l = 0; l < 45; l++) {
                cprintf("%c", map[k][l]);
            }
        }
        cprintf("Level %d. Gold: %d/%d", lvl, gold_count, gold_total);
    } while (action = getch());
}