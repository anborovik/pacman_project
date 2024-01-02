#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "const.h"
#include "monster.h"

void generate_player_coord(player_coord * player)
{
    srand(time(NULL));
    player->px = rand() % WIDTH;
    player->py = rand() % HEIGHT;
}

int check_fail(player_coord * player, monster_coord monsters[])
{
    for (int i = 0; i < MONST_COUNT; i++) {
        if (
            (monsters[i].mx - player->px == 0)&&(monsters[i].my - player->py == 0)
        ) {
            return 1;
        }
    }
    return 0;
}

int check_movement(char action, char (* map)[WIDTH], player_coord * player, int * gold_count, monster_coord monsters[])
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
        monster_movement(monsters, player, map);
        int result = check_fail(player, monsters);
        return result;
}