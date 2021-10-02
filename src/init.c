/*
** EPITECH PROJECT, 2020
** gol
** File description:
** init.c
*/

#include "gol.h"

window_t *new_window(char *name, int x, int y)
{
    window_t *window = malloc(sizeof(window_t));

    if (!window)
        error("window alloc failed");

    window->mode = (sfVideoMode){x, y, 32};
    window->render = sfRenderWindow_create(window->mode, name, sfDefaultStyle, 0);

    if (!window->render)
        error("render alloc failed");

    return (window);
}

map_t *new_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        error("map alloc failed");

    memset(map, 0, sizeof(map_t));
    for (int i = 0; i < MAP_HEIGHT * MAP_WIDTH ; i++) {
        map->draw[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(map->draw[i], (sfVector2f){CELL_SIZE, CELL_SIZE});
        sfRectangleShape_setFillColor(map->draw[i], sfBlack);
        sfRectangleShape_setPosition(map->draw[i], (sfVector2f){i % MAP_WIDTH * CELL_SIZE, i / MAP_WIDTH * CELL_SIZE});
    }

    return (map);
}

gol_t *new_gol(void)
{
    gol_t *gol = malloc(sizeof(gol_t));

    if (!gol)
        error("gol alloc failed");

    gol->rule = 30;
    gol->window = new_window("game of life deluxe", 1920, 1080);
    gol->map = new_map();

    SET(gol->map->map, MAP_WIDTH / 2, (MAP_HEIGHT - 1), 1L);

    return (gol);
}