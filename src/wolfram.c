/*
** EPITECH PROJECT, 2021
** gol
** File description:
** wolfram.c
*/

#include "gol.h"

void shift_lines(gol_t *gol)
{
    for (int i = MAP_HEIGHT / 2; i < MAP_HEIGHT - 1; i++)
        for (int j = 0; j < MAP_WIDTH ; j++)
            SET(gol->map->tmp, j, i, IS_SET(gol->map->map, j, i + 1));
}

int generate_new_cell(gol_t *gol, int x, int y)
{
    char a, b, c, d;
    a = x - 1 < 0 ? 0 : IS_SET(gol->map->tmp, x - 1, y - 1);
    b = IS_SET(gol->map->tmp, x, y - 1);
    c = x + 1 >= MAP_WIDTH ? 0 : IS_SET(gol->map->tmp, x + 1, y - 1);
    d = a << 2 | b << 1 | c;
    return (gol->rule >> d & 1);
}

void generate_new_line(gol_t *gol)
{
    for (int i = 0; i < MAP_WIDTH ; i++)
        SET(gol->map->tmp, i, MAP_HEIGHT - 1, generate_new_cell(gol, i, MAP_HEIGHT - 1));
}

void make_wolfram(gol_t *gol)
{
    shift_lines(gol);
    generate_new_line(gol);
}