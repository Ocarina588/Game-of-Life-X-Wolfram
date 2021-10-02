/*
** EPITECH PROJECT, 2020
** gol
** File description:
** manager.c
*/

#include "gol.h"

void event_manager(gol_t *gol)
{
    if (gol->window->event.type == sfEvtClosed)
        sfRenderWindow_close(gol->window->render);
}

void free_manager(gol_t *gol)
{
    sfRenderWindow_destroy(gol->window->render);
    for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT ; i++)
        sfRectangleShape_destroy(gol->map->draw[i]);
    free(gol->window);
    free(gol->map);
    free(gol);
}

int compare_color(sfColor a, sfColor b)
{
    return (a.r == b.r && a.b == b.b && a.g == b.g && a.a == b.a);
}

void colors_manager(gol_t *gol)
{
    static sfColor begin = {232, 26, 187, 255};
    static sfColor end = {41, 133, 222};
    static int rd = (41 - 232) / 20;
    static int gd = (133 - 26) / 40;
    static int bd = (222 - 187) / 40;
    sfColor tmp;

    for (int i = 0; i < MAP_HEIGHT * MAP_WIDTH ; i++) {
        tmp = sfRectangleShape_getFillColor(gol->map->draw[i]);
        if (!compare_color(tmp, sfWhite) && !compare_color(tmp, sfBlack)) {
            if ((int)tmp.r + rd <= 0)
                tmp.r = 0;
            else
                tmp.r += rd;
            tmp.g += gd;
            tmp.b += bd;
            if ((int)tmp.a - 3 <= 0)
                tmp = sfBlack;
            else
                tmp.a -= 3;
            sfRectangleShape_setFillColor(gol->map->draw[i], tmp);
        }
    }
}

void swap_manager(gol_t *gol)
{
    for (int i = 0; i < MAP_HEIGHT ; i++) {
        for (int j = 0; j < MAP_WIDTH ; j++) {
            if (IS_SET(gol->map->tmp, j, i))
                sfRectangleShape_setFillColor(gol->map->draw[i * MAP_WIDTH + j], sfWhite);
            else if (!IS_SET(gol->map->tmp, j, i) && compare_color(sfRectangleShape_getFillColor(gol->map->draw[i * MAP_WIDTH + j]), sfWhite))
                sfRectangleShape_setFillColor(gol->map->draw[i * MAP_WIDTH + j],  (sfColor){232, 26, 187, 255});
            SET(gol->map->map, j, i, IS_SET(gol->map->tmp, j, i));
        }
    }
}

void manager(gol_t *gol)
{
    static int i = 0;
    sfRenderWindow_clear(gol->window->render, sfBlack);

    while (sfRenderWindow_pollEvent(gol->window->render, &gol->window->event))
        event_manager(gol);

    memset(gol->map->tmp, 0, ARRAY_SIZE * sizeof(long int));

    make_wolfram(gol);
    make_game_of_life(gol);
    swap_manager(gol);
    colors_manager(gol);
    draw_map(gol);

    sfRenderWindow_display(gol->window->render);
}