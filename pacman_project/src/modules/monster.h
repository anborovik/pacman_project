#ifndef _monster_h
#define _monster_h

#include "const.h"

void generate_monsters_coord(monster_coord[]);

void monster_movement(monster_coord * monster_list, player_coord * player, char (* map)[WIDTH]);

#endif