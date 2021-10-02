/*
** EPITECH PROJECT, 2020
** gol
** File description:
** utils.c
*/

#include "gol.h"

void error(char *err)
{
    dprintf(2, "%s\n", err);
    exit(84);
}