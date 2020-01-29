/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** camera entity and system
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *entity_camera_create(void)
{
    dg_entity_t *entity = dg_entity_create();

    dg_entity_add(entity, component_camera_create(0, 0));
    return entity;
}

static void display_sprite(sfVector2f camera, dg_entity_t *entity,
    dg_window_t *w)
{
    sfVector2f reverse = {-camera.x, -camera.y};
    sfSprite *sprite = 0;

    if (dg_system_require(entity, 1, "sprite")) {
            sprite = (sfSprite *)(dg_entity_get(entity, "sprite"));
            sfSprite_move(sprite, reverse);
            sfRenderWindow_drawSprite(w->window, sprite, NULL);
            sfSprite_move(sprite, camera);
        }
}

void system_camera_sp_render(dg_entity_t *entity, dg_window_t *w,
    dg_entity_t **entities, sfTime dt)
{
    sfVector2f *camera = (sfVector2f *)(dg_entity_get(entity, "camera"));

    if (!entities)
        return;
    for (int i = 0; entities[i]; i++) {
        if (dg_system_require(entity, 1, "camera"))
            display_sprite(*camera, entities[i], w);
    }
}
