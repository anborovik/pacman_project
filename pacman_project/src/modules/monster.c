#include <stdio.h>
#include "const.h"

void generate_monsters_coord(monster_coord * monster)
{
    srand(time(NULL));
    monster->mx = rand() % WIDTH;
    monster->my = rand() % HEIGHT;
}

void monster_movement(monster_coord * monster_list, player_coord * player, char (* map)[WIDTH])
{
    for (int i = 0; i < MONST_COUNT; i++) {
        int dy = player->py - monster_list[i].my;
        int dx = player->px - monster_list[i].mx;
        if (
            (dx > 0)&&
            (map[monster_list[i].my][monster_list[i].mx + 1] != '#')&&
            (map[monster_list[i].my][monster_list[i].mx + 1] != '&')&&
            (map[monster_list[i].my][monster_list[i].mx + 1] != '@')
        ) {
            char tmp = map[monster_list[i].my][monster_list[i].mx + 1];
            map[monster_list[i].my][monster_list[i].mx + 1] = '&';
            map[monster_list[i].my][monster_list[i].mx] = tmp;
            monster_list[i].mx++;
        } else if (
            (dx < 0)&&
            (map[monster_list[i].my][monster_list[i].mx - 1] != '#')&&
            (map[monster_list[i].my][monster_list[i].mx - 1] != '&')&&
            (map[monster_list[i].my][monster_list[i].mx - 1] != '@')
        ) {
            char tmp = map[monster_list[i].my][monster_list[i].mx - 1];
            map[monster_list[i].my][monster_list[i].mx - 1] = '&';
            map[monster_list[i].my][monster_list[i].mx] = tmp;
            monster_list[i].mx--;
        } else if (
            (dy > 0)&&
            (map[monster_list[i].my + 1][monster_list[i].mx] != '#')&&
            (map[monster_list[i].my + 1][monster_list[i].mx] != '&')&&
            (map[monster_list[i].my + 1][monster_list[i].mx] != '@')
        ) {
            char tmp = map[monster_list[i].my + 1][monster_list[i].mx];
            map[monster_list[i].my + 1][monster_list[i].mx] = '&';
            map[monster_list[i].my][monster_list[i].mx] = tmp;
            monster_list[i].my++;
        } else if (
            (dy < 0)&&
            (map[monster_list[i].my - 1][monster_list[i].mx] != '#')&&
            (map[monster_list[i].my - 1][monster_list[i].mx] != '&')&&
            (map[monster_list[i].my - 1][monster_list[i].mx] != '@')
        ) {
            char tmp = map[monster_list[i].my - 1][monster_list[i].mx];
            map[monster_list[i].my - 1][monster_list[i].mx] = '&';
            map[monster_list[i].my][monster_list[i].mx] = tmp;
            monster_list[i].my--;
        }
    }
}