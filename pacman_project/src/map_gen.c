#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct Cell
// cell structure
{
    int x;
    int y;
    bool wall_up;
    bool wall_down;
    bool wall_left;
    bool wall_right;
    bool visited;
};


int get_index(int x, int y, int width, int height)
// getting cell index in 1d grid
{
    if ((x < 0)||(x >= height)||(y < 0)||(y >= width)) {
        return -1;
    }
    return x * width + y;
}

struct Cell * get_next(struct Cell * current_cell, struct Cell grid[], int width, int height)
// getting cell next to current
{
    int neighbor_up_index = get_index(
        current_cell->x - 1, current_cell->y, width, height
    );
    int neighbor_right_index = get_index(
        current_cell->x, current_cell->y + 1, width, height
    );
    int neighbor_down_index = get_index(
        current_cell->x + 1, current_cell->y, width, height
    );
    int neighbor_left_index = get_index(
        current_cell->x, current_cell->y - 1, width, height
    );
    if ((neighbor_up_index >= 0)&&!(grid[neighbor_up_index].visited)) {
        return &grid[neighbor_up_index];
    }
    if ((neighbor_down_index >= 0)&&!(grid[neighbor_down_index].visited)) {
        return &grid[neighbor_down_index];
    }
    if ((neighbor_left_index >= 0)&&!(grid[neighbor_left_index].visited)) {
        return &grid[neighbor_left_index];
    }
    if ((neighbor_right_index >= 0)&&!(grid[neighbor_right_index].visited)) {
        return &grid[neighbor_right_index];
    }
    return NULL;
}


bool is_maze_completed(struct Cell grid[])
{
    int len = sizeof(grid)/sizeof(*grid);
    for (int i = 0; i < len; i++) {
        if (grid[i].visited == false) {
            return false;
        }
    }
    return true;
}


struct Cell * generate_thin_maze(int height, int width)
// generating part of map
{
    struct Cell *grid = malloc(sizeof(struct Cell) * height * width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[width * i + j].x = j;
            grid[width * i + j].y = i;
            grid[width * i + j].wall_up = true;
            grid[width * i + j].wall_down = true;
            grid[width * i + j].wall_left = true;
            grid[width * i + j].wall_right = true;
            grid[width * i + j].visited = false;
        }
    }
    struct Cell current_cell = grid[0];
    struct Cell *stack = malloc(sizeof(struct Cell) * height * width);
    int count = 0;
    while (is_maze_completed(grid)==true) {
        current_cell.visited = true;
        struct Cell * next_cell = get_next(&current_cell, grid, width, height);
        if (next_cell != NULL) {
            stack[count] = current_cell;
            count++;
            remove_wall(&current_cell, next_cell);
            current_cell = *next_cell;
        } else {
            current_cell = stack[count];
            count --;
        }
    }
    return grid;
    // free(sizeof(struct Cell) * height * width);

}


void remove_wall(struct Cell * cell_a, struct Cell * cell_b)
{
    int shift_x = cell_a->x - cell_b->x;
    int shift_y = cell_a->y - cell_b->y;
    if (shift_x==-1) {
        cell_a->wall_right = false;
        cell_b->wall_left = false;
    } else if (shift_x==1) {
        cell_a->wall_left = false;
        cell_b->wall_right = false;
    }
    if (shift_y==-1) {
        cell_a->wall_down = false;
        cell_b->wall_up = false;
    } else if (shift_y==1) {
        cell_a->wall_up = false;
        cell_b->wall_down = false;
    }
}


// double count_passages_to_walls_ratio(struct Cell map[])
// {
//     if (map==NULL) {
//         return 0;
//     }
//     int walls = 0, passages = 0;
//     for (int i)
// }






struct Cell * make_skeleton(int height, int width) {
    struct Cell * map = NULL;
    // while (count_passages_to_walls_ratio(map) <= 0.8) {
        struct Cell * maze = generate_thin_maze(height, width);

    // }
    return map;
}


struct Cell * generate_map(int * grid_pons[]) {
    int width = *(grid_pons[1]) - *(grid_pons[0]);
    int height = *(grid_pons[1] + 1) - *((grid_pons[0]) + 1);
    struct Cell * map = NULL;
    // while (quality_check(map)!=true) {
        map = make_skeleton(height, width);
    // }
    return map;
}

int main() {
    int lower_left_corner[] = {0, 0};
    int upper_right_corner[] = {15, 15};
    int * grid_pons[] = {lower_left_corner, upper_right_corner}; //add functions
    struct Cell * result = generate_map(grid_pons);
    return 0;
}