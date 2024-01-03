#ifndef _player_h
#define _player_h

#include "const.h"

void generate_player_coord(player_coord * player);

int check_movement(
    char action,
    char (* map)[WIDTH],
    player_coord * player,
    int * gold_count,
    monster_coord monsters[]
);

#endif