/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** component player
*/

#include <stdlib.h>
#include "dg_component.h"

static void component_player_destroy(void *data)
{
    return;
}

dg_component_t *component_player_create(void)
{
    void (*destroy)(void *) = &component_player_destroy;
    dg_component_t *component = dg_component_create("player", NULL, destroy);

    return component;
}
