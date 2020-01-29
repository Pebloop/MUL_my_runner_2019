/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** hud system
*/

#include <stdlib.h>
#include "libdragon.h"

void system_hud_sp_render(dg_entity_t *entity, dg_window_t *w,
    dg_entity_t **entities, sfTime dt)
{
    sfSprite *sprite = (sfSprite *)(dg_entity_get(entity, "hud_sprite"));

    if (!dg_system_require(entity, 1, "hud_sprite"))
        return;
    sfRenderWindow_drawSprite(w->window, sprite, NULL);
}
