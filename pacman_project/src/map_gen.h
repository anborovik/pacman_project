#ifndef _map_gen_h
#define _map_gen_h
#include "player.h"
#include "monster.h"

void read_map(
    int lvl,
    player_coord * player,
    char * map[],
    int * gold_total,
    monster_coord monster_list[]
);

#endif