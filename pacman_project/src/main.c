#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>
#include "./modules/map_gen.h"
#include "./modules/player.h"
#include "./modules/monster.h"
#include "./modules/const.h"


char map[HEIGHT][WIDTH];
char action;
int gold_total = 0, gold_count = 0;
int lvl = 0;
int hp = HIT_POINTS;


// ncurses for linux
int main(int lvl)
{
    initscr();
    player_coord player = {0, 0};
    monster_coord monster_list[MONST_COUNT];
    printw("Welcome! To start new game press Space");
    char key;
    while (key = getch()) {
        if (key==' ') {
            read_map(lvl, &player, map, &gold_total, monster_list);
            do {
                // cleare buffer
                clear();

                // check movements
                int fail_situation = check_movement(action, map, &player, &gold_count, monster_list);
                if (fail_situation == 1) {
                    if (hp > 0) {
                        printw("You fail! Press Ctrl+C to exit or press Space to restart level.");
                        char key;
                        while (key = getch()) {
                            if (key==' ') {
                                clear();
                                player.px = 0;
                                player.py = 0;
                                gold_total = 0;
                                gold_count = 0;
                                hp--;
                                read_map(lvl, &player, map, &gold_total, monster_list);
                                break;
                            }
                        }
                    } else {
                        printw("Game over! Press Ctrl+C to exit or press Space to restart from level 1.");
                        char key;
                        while (key = getch()) {
                            if (key==' ') {
                                clear();
                                player.px = 0;
                                player.py = 0;
                                gold_total = 0;
                                gold_count = 0;
                                lvl = 1;
                                hp=HIT_POINTS;
                                read_map(lvl, &player, map, &gold_total, monster_list);
                                break;
                            }
                        }
                    }
                    
                }

                // show screen
                if (gold_count == gold_total) {
                    printw("You win! Press Ctrl+C to exit or press Space for next level.");
                    char key;
                    while (key = getch()) {
                        if (key==' ') {
                            clear(); 
                            lvl++;
                            player.px = 0;
                            player.py = 0;
                            gold_total = 0;
                            gold_count = 0;
                            read_map(lvl, &player, map, &gold_total, monster_list);
                            break;
                        }
                    }
                }
                for (int k = 0; k < HEIGHT; k++) {
                    for (int l = 0; l < WIDTH; l++) {
                        printw("%c", map[k][l]);
                    }
                }
                printw("Level %d. Hit points: %d. Gold: %d/%d", lvl, hp, gold_count, gold_total);
            } while (action = getch());
        }
    }
    endwin();
}