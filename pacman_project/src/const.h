#ifndef _const_h
#define _const_h

#define HEIGHT 9
#define WIDTH 45
#define MONST_COUNT 2
#define HIT_POINTS 10

#define WALL_COLOR 1
#define PLAYER_COLOR 2
#define MONSTER_COLOR 3
#define GOLD_COLOR 4

typedef struct {
    int px;
    int py;
} player_coord;


typedef struct {
    int mx;
    int my;
} monster_coord;

#endif