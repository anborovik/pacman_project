#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int px = 1, py = 1;
char map[9][45];
char action;
int gold_total = 0, gold_count = 0;


void read_map(int lvl)
{
    int i = 0, j = 0;
    char lvl_name = lvl + '0';
    char filename[20] = {"./maps/lvl_", lvl_name, ".txt"};
    char c;
    FILE * lvl_map;
    lvl_map = fopen("./maps/lvl_1.txt", "r");
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
    printf("%c\n", map[*py][*px-1]);
    if ((action == 'w')&&(map[*py-1][*px]!='#')) {
            map[*py][*px] = ' ';
            *py--;
        } else if ((action == 's')&&(map[*py+1][*px]!='#')) {
            map[*py][*px] = ' ';
            *py++;
        } else if ((action == 'a')&&(map[*py][*px-1]!='#')) {
            map[*py][*px] = ' ';
            *px--;
        } else if ((action == 'd')&&(map[*py][*px+1]!='#')) {
            map[*py][*px] = ' ';
            *px++;
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
        system("cls"); // cleare buffer

        // check movements
        check_movement(action, &px, &py);
        printf("px = %d py = %d\n", px, py);

        // show screen
        for (int k = 0; k < 9; k++) {
            for (int l = 0; l < 45; l++) {
                printf("%c", map[k][l]);
            }
        }
        printf("Level %d. Gold: %d/%d", lvl, gold_count, gold_total);
    } while (action = getch());
}
