/*|----------------------------------------------------|*/
/*| created by: shbshka                                |*/
/*| at 07.12.23 19:00 Msc Time                         |*/
/*|----------------------------------------------------|*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


void player_movement(int p_pons[], int *grid_pons[]);
int grid_generator(int p_pons[], int *monsters_pons[], int *blocks_pons[]);
int monster_generator(int *grid_pons[]);
int block_generator(int *grid_pons[]);


int main(int argc, char const *argv[])
{
    int p_pons[] = {0, 0};

    const int lower_left_corner[] = {0, 0};
    const int upper_right_corner[] = {15, 15};

    int *grid_pons[] = {lower_left_corner, upper_right_corner}; //add functions
    int *monster_pons[] = monster_generator(grid_pons); //add function
    int *block_pons[] = block_generator(grid_pons); //add function
    grid_generator(p_pons, monster_pons, block_pons);
    
    while(1) 
    {
        player_movement(p_pons, -1);
    }

    return(0);
}


int monster_generator(int *grid_pons[])
{
/*
* ТЗ: написать генерацию монстра в кол-ве от 1 до 5 штук
*/
}


int block_generator(int *grid_pons[])
{
/*
* ТЗ: написать генерацию блоков и стен так, чтобы получился лабиринт (это трудно, но возможно)
* для начала достаточно рандомно расставленных блоков
*/
}


int grid_generator(int p_pons[], int *monsters_pons[], int *blocks_pons[])
{
/*
* ТЗ: написать генерацию поля, принимающую на вход позиции игрока {x, y},
* позиции монстров {{x, y}, {x, y}...}, позиции блоков {{x, y}, {x, y}...},
* преобразующую это все в красивый консольный формат
*/
}


void player_movement(int p_pons[], int *grid_pons[])

/* 
* Reads the movement from input and directs its
* handling to other functions
*/

{
    char move;

    /* 
    * a whitespace before %c eliminates 
    * the unnecessary input trace 
    */

    scanf(" %c", move);
    move = toupper(move);

    switch(move)
    {
    case 'A':
        {
            if (p_pons[0] > 0)
                p_pons[0] -=1;
                break;
        }
    case 'D':
        {
            if (p_pons[0] < grid_pons[1][0])
                p_pons[0] +=1;
                break;
        }
    case 'W':
        {
            if (p_pons[1] < grid_pons[1][1])
                p_pons[1] += 1;
                break;
        }
    case 'S':
        {
            if (p_pons[1] > 0)
                p_pons[1] -=1;
                break;
        }
    }

    return (p_pons);
}
