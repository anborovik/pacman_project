#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
// #include <conio.h>

int px = 1, py = 1;
char map[9][45];
char action;
int gold_total = 0, gold_count = 0;
char result[100] = {'0'};

char * generate_filename(int lvl)
{
    const char * filename = "./maps/lvl_";
    const char * ext = ".txt";
    // char * lvl_name = lvl + '0';
    strcpy(result, filename);
    // strcat(result, lvl_name);
    strcat(result, ext);
    return result;
}

void read_map(int lvl)
{
    int i = 0, j = 0;
    
    char * filename = generate_filename(lvl);
    char c;
    FILE * lvl_map;
    lvl_map = fopen(filename, "r");
    if (lvl_map) {
        while ((c = getc(lvl_map)) != EOF) {
            if (c != '\n') {
                if ((i == py)&&(j == px)) {
                    map[i][j] = '@';
                    j++;
                } else if (c == '*') {
                    map[i][j] = '*';
                    gold_total += 100;
                    j++;
                } else {
                    map[i][j] = c;
                    j++;
                }
            } else {
                map[i][j] = c;
                j = 0;
                i++;
            }
        }  
        fclose(lvl_map);
    }
}


void check_movement(char action, int * px, int * py)
{
    if ((action == 'w')&&(map[*py-1][*px]!='#')) {
            map[*py][*px] = ' ';
            (*py)--;
        } else if ((action == 's')&&(map[*py+1][*px]!='#')) {
            map[*py][*px] = ' ';
            (*py)++;
        } else if ((action == 'a')&&(map[*py][*px-1]!='#')) {
            map[*py][*px] = ' ';
            (*px)--;
        } else if ((action == 'd')&&(map[*py][*px+1]!='#')) {
            map[*py][*px] = ' ';
            (*px)++;
        }
        if (map[*py][*px]=='*') {
            gold_count += 100;
        }
        map[*py][*px] = '@';
}


int main(int lvl)
{
    int x, y;
    read_map(lvl);
    do {
        // system("cls"); // cleare buffer
        clear();

        // check movements
        check_movement(action, &px, &py);
    //     printf("px = %d py = %d\n", px, py);

    //     // show screen
    //     for (int k = 0; k < 9; k++) {
    //         for (int l = 0; l < 45; l++) {
    //             printf("%c", map[k][l]);
    //         }
    //     }
    //     printf("Level %d. Gold: %d/%d", lvl, gold_count, gold_total);
    // } while (action = getch());

    // show screen
    initscr();
        for (int k = 0; k < 9; k++) {
            for (int l = 0; l < 45; l++) {
                printw("%c", map[k][l]);
            }
        }
        printw("Level %d. Gold: %d/%d", lvl, gold_count, gold_total);
    } while (action = getch());
    endwin();
}
