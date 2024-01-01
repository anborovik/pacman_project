#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "const.h"


typedef struct {
    int px;
    int py;
} player_coord;


void generate_player_coord(player_coord * player)
{
    srand(time(NULL));
    player->px = rand() % WIDTH;
    player->py = rand() % HEIGHT;
}

void check_movement(char action, char (* map)[WIDTH], player_coord * player, int * gold_count)
{
    if ((action == 'w')&&(map[player->py-1][player->px]!='#')) {
            map[player->py][player->px] = ' ';
            (player->py)--;
        } else if ((action == 's')&&(map[player->py+1][player->px]!='#')) {
            map[player->py][player->px] = ' ';
            (player->py)++;
        } else if ((action == 'a')&&(map[player->py][player->px-1]!='#')) {
            map[player->py][player->px] = ' ';
            (player->px)--;
        } else if ((action == 'd')&&(map[player->py][player->px+1]!='#')) {
            map[player->py][player->px] = ' ';
            (player->px)++;
        }
        if (map[player->py][player->px]=='*') {
            *gold_count += 100;
        }
        map[player->py][player->px] = '@';
}