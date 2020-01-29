/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** sprite entity and system
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *entity_sp_create(char *file, sfVector2f size, sfVector2f pos)
{
    sfVector2f scale = {1, 1};
    dg_entity_t *entity = dg_entity_create();
    sfSprite *sprite = 0;
    spritesheet_t *sheet = 0;

    dg_entity_add(entity, component_sheet_create(file, size.x, size.y));
    sheet = (spritesheet_t *)(entity->components[0]->data);
    dg_entity_add(entity, component_sprite_create(&pos, &scale));
    sprite = (sfSprite *)(entity->components[1]->data);
    spritesheet_to_sprite(sheet, sprite, 0);
    return entity;
}
