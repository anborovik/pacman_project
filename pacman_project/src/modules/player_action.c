#include <stdio.h>


void check_movement(char action, char (* map)[45], int * px, int * py, int * gold_count)
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