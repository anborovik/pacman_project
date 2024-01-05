#include <stdio.h>
#include <string.h>
#include "player.h"
#include "monster.h"
#include "const.h"


char result[100] = {'0'};

char * generate_filename(int lvl)
{
    const char * filename = "./src/maps/lvl_";
    const char * ext = ".txt";
    char lvl_name[3] = {'0'};
    sprintf(lvl_name, "%d", lvl);
    strcpy(result, filename);
    strcat(result, lvl_name);
    strcat(result, ext);
    return result;
}

void read_map(
    int lvl,
    player_coord * player,
    char (* map)[WIDTH],
    int * gold_total,
    monster_coord * monster_list
)
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
        while (map[player->py][player->px] != ' ') {
            generate_player_coord(player);
        }
        map[player->py][player->px] = '@';
        for (int i = 0; i < MONST_COUNT; i++) {
            while (map[monster_list[i].my][monster_list[i].mx] != ' ') {
                generate_monsters_coord(monster_list + i);
            }
            map[monster_list[i].my][monster_list[i].mx] = '&';
        }
        fclose(lvl_map);
    }
}
