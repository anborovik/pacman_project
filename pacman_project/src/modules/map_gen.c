#include <stdio.h>
#include <string.h>
#include "player.h"

#define HEIGHT 9
#define WIDTH 45


char result[100] = {'0'};

char * generate_filename(int lvl)
{
    const char * filename = "./maps/lvl_";
    const char * ext = ".txt";
    char lvl_name[3] = {'0'};
    itoa(lvl, lvl_name, 10);
    strcpy(result, filename);
    strcat(result, lvl_name);
    strcat(result, ext);
    return result;
}

void read_map(int lvl, player_coord * player, char (* map)[WIDTH], int * gold_total)
{
    int i = 0, j = 0;
    
    char * filename = generate_filename(lvl);
    char c;
    FILE * lvl_map;
    lvl_map = fopen(filename, "r");
    if (lvl_map) {
        while ((c = getc(lvl_map)) != EOF) {
            if (c != '\n') {
                if (c == '*') {
                    map[i][j] = '*';
                    *gold_total += 100;
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
        // while (map[player->py][player->px] != " ") {
        //     generate_player_coord(player);
        // }
        printf("px = %d py = %d\n", player->px, player->py);
        map[player->py][player->px] = '@';
        fclose(lvl_map);
    }
}
