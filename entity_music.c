/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** music entity and system
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *entity_music_create(char *path)
{
    dg_entity_t *entity = dg_entity_create();

    dg_entity_add(entity, component_music_create(path));
    return entity;
}
