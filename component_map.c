/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** component map
*/

#include <stdlib.h>
#include "dg_component.h"
#include "map.h"

static void component_map_destroy(void *data)
{
    map_t *map = (map_t *)(data);

    map_destroy(map);
}

dg_component_t *component_map_create(char **map_str)
{
    void (*destroy)(void *) = &component_map_destroy;
    map_t *map = map_create(map_str);
    dg_component_t *component = dg_component_create("map", map, destroy);

    return component;
}
