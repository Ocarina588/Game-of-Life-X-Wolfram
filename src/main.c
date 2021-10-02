/*
** EPITECH PROJECT, 2020
** gol
** File description:
** main.c
*/

#include <stdio.h>
#include "gol.h"

int main(int ac, char **av)
{
    gol_t *gol = new_gol();

    if (ac == 2)
        gol->rule = atoi(av[1]);

    while (sfRenderWindow_isOpen(gol->window->render))
        manager(gol);

    free_manager(gol);
    return (0);
}