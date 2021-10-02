/*
** EPITECH PROJECT, 2021
** gol
** File description:
** game_of_life.c
*/

#include "gol.h"

int get_neighbours(gol_t *gol, int x, int y)
{
    char pos[][2] = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};
    int xx, yy, nb = 0;
    for (int i = 0; i < 8 ; i++) {
        xx = pos[i][0] + x;
        yy = pos[i][1] + y;
        if (xx < 0 || xx >= MAP_WIDTH || yy < 0 || yy > MAP_HEIGHT)
            continue;
        nb += IS_SET(gol->map->map, xx, yy);
    }
    return (nb);
}

void make_game_of_life(gol_t *gol)
{
    char nb;
    for (int i = 0; i < MAP_HEIGHT / 2; i++) {
        for (int j = 0; j < MAP_WIDTH ; j++) {
            nb = get_neighbours(gol, j, i);
            if (IS_SET(gol->map->map, j, i))
                SET(gol->map->tmp, j, i, (nb == 3 || nb == 2));
            else
                SET(gol->map->tmp, j, i, nb == 3);
        }
    }
}