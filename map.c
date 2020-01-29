/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** manage the parralax
*/

#include <stdlib.h>
#include "map.h"

map_t *map_create(char **map_str)
{
    map_t *map = malloc(sizeof(map_t));
    int size = 0;

    if (!map)
        return 0;
    map->map = map_str;
    for (int i = 0; i < 3; i++) {
        for (int y = 0; map_str && map_str[i] && map_str[i][y] != '\0'; y++)
            size = (size < y) ? y : size;
    }
    map->end = size;
    return map;
}

void map_destroy(map_t *map)
{
    for (int i = 0; i < 3; i++)
        if (map->map[i])
            free(map->map[i]);
    free(map->map);
    free(map);
}
