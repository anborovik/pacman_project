#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define HEIGHT 9
#define WIDTH 45

typedef struct {
    int px;
    int py;
} player_coord;


void generate_player_coord(player_coord * player)
{
    srand(time(NULL));
    player->px = rand() / WIDTH;
    player->py = rand() / HEIGHT;
}

void check_movement(char action, char (* map)[WIDTH], int * px, int * py, int * gold_count)
{
    if ((action == 'w')&&(map[*py-1][*px]!='#')) {
            map[*py][*px] = ' ';
            (*py)--;
        } else if ((action == 's')&&(map[*py+1][*px]!='#')) {
            map[*py][*px] = ' ';
            (*py)++;
        } else if ((action == 'a')&&(map[*py][*px-1]!='#')) {
            map[*py][*px] = ' ';
            (*px)--;
        } else if ((action == 'd')&&(map[*py][*px+1]!='#')) {
            map[*py][*px] = ' ';
            (*px)++;
        }
        if (map[*py][*px]=='*') {
            *gold_count += 100;
        }
        map[*py][*px] = '@';
}