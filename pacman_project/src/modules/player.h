#ifndef _player_h
#define _player_h

typedef struct {
    int px;
    int py;
} player_coord;

void generate_player_coord(player_coord * player);

void check_movement(char action, char (* map)[45], int * px, int * py, int * gold_count);

#endif