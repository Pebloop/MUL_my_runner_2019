/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** component sprite
*/

#include <stdlib.h>
#include "dg_component.h"
#include "libdragon.h"

static void component_sprite_destroy(void *data)
{
    sfSprite *sprite = (sfSprite *)(data);

    sfSprite_destroy(sprite);
}

dg_component_t *component_sprite_create(sfVector2f *pos, sfVector2f *scale)
{
    void (*destroy)(void *) = &component_sprite_destroy;
    sfSprite *sprite = sfSprite_create();
    dg_component_t *component = dg_component_create("sprite", sprite, destroy);

    if (pos)
        sfSprite_setPosition(sprite, *pos);
    if (scale)
        sfSprite_setScale(sprite, *scale);
    return component;
}
