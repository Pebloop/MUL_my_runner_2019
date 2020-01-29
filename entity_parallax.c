/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** parralax entity and system
*/

#include <stdlib.h>
#include "libdragon.h"
#include "parallax.h"
#include "ecs.h"

static parallax_t *set_parallax(void)
{
    parallax_t *parallax = parallax_create();

    parallax_add_layer(parallax, "res/background/layer_01.png", 1);
    parallax_add_layer(parallax, "res/background/layer_02.png", 2);
    parallax_add_layer(parallax, "res/background/layer_03.png", 4);
    parallax_add_layer(parallax, "res/background/layer_04.png", 6);
    parallax_add_layer(parallax, "res/background/layer_05.png", 9);
    parallax_add_layer(parallax, "res/background/layer_06.png", 13);
    return parallax;
}

dg_entity_t *entity_parallax_create(void)
{
    dg_entity_t *entity = dg_entity_create();

    dg_entity_add(entity, component_parallax_create(&set_parallax));
}

void system_parallax(dg_entity_t *entity, dg_window_t *w,
    dg_entity_t **entities, sfTime dt)
{
    parallax_t *parallax = (parallax_t *)(dg_entity_get(entity, "parallax"));

    if (!dg_system_require(entity, 1, "parallax"))
        return;
    parallax_update(parallax, w->window, dt.microseconds / 100000.0);
}
