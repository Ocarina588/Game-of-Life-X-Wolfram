/*
** EPITECH PROJECT, 2020
** gol
** File description:
** gol.h
*/

#ifndef GOL_H
#define GOL_H

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CELL_SIZE   5
#define WIN_WIDTH   1920
#define WIN_HEIGHT  1080
#define MAP_WIDTH   (WIN_WIDTH / CELL_SIZE)
#define MAP_HEIGHT  (WIN_HEIGHT / CELL_SIZE)
#define MAP_SIZE    (MAP_WIDTH * MAP_HEIGHT)
#define ARRAY_SIZE  (MAP_SIZE / 64 + !!(MAP_SIZE % 64))
#define IS_SET(map, x, y) (map[((y) * MAP_WIDTH + (x)) / 64] >> (((y) * MAP_WIDTH + (x)) % 64) & 1L)
#define SET(map, x, y, nb) (map[((y) * MAP_WIDTH + (x)) / 64] ^= (-(unsigned long)!!(nb) ^ map[((y) * MAP_WIDTH + (x)) / 64]) & (1UL << (((y) * MAP_WIDTH + (x)) % 64) ))

typedef struct window_s {
    sfRenderWindow *render;
    sfVideoMode mode;
    sfEvent event;
} window_t;

typedef struct map_s {
    long int map[ARRAY_SIZE];
    long int tmp[ARRAY_SIZE];
    sfRectangleShape *draw[MAP_SIZE];
} map_t;

typedef struct gol_s {
    window_t *window;
    map_t *map;
    unsigned char rule;
} gol_t;

//utils
void error(char *err);

//init
gol_t *new_gol(void);

//manager
void manager(gol_t *gol);
void free_manager(gol_t *gol);

//map
void draw_map(gol_t *gol);
void swap_map(gol_t *gol);

//wolfram
void make_wolfram(gol_t *gol);

//game of life
void make_game_of_life(gol_t *gol);

#endif