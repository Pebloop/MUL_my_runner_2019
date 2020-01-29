/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** map entity and system
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *entity_map_create(char **map)
{
    dg_entity_t *entity = dg_entity_create();

    dg_entity_add(entity, component_map_create(map));
    return entity;
}
