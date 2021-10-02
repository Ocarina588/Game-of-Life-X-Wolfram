/*
** EPITECH PROJECT, 2020
** gol
** File description:
** draw.c
*/

#include "gol.h"

void draw_map(gol_t *gol)
{
    for (int i = 0; i < MAP_HEIGHT * MAP_WIDTH; i++)
        sfRenderWindow_drawRectangleShape(gol->window->render, gol->map->draw[i], NULL);
}