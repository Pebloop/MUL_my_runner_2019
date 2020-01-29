/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_entity cget
*/

#include <stdlib.h>
#include "dg_entity.h"
#include "epitech_tools.h"

dg_component_t *dg_entity_cget(dg_entity_t *entity, char *name)
{
    if (!entity || !name)
        return 0;
    for (int i = 0; i < entity->quantity; i++) {
        if (!dg_strcmp(entity->components[i]->name, name))
            return entity->components[i];
    }
    return 0;
}
