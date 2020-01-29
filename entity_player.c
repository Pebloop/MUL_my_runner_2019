/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** player entity and system
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static animator_t *set_player_animator(void)
{
    animator_t *animator = animator_create();
    spritesheet_t *ss = spritesheet_create("res/train.png", 32, 32);
    animation_t *forward = animation_create(ss, 10);

    animation_add(forward, 0);
    animation_add(forward, 1);
    animation_add(forward, 2);
    animation_add(forward, 3);
    animator_add(animator, "forward", forward);
    return animator;
}

dg_entity_t *entity_player_create(void)
{
    sfVector2f scale = {8, 8};
    sfVector2f pos = {100, 500};
    sfVector2f fpos = {50, 50};
    dg_entity_t *player = dg_entity_create();

    dg_entity_add(player, component_sprite_create(&pos, &scale));
    dg_entity_add(player, component_animator_create(&set_player_animator));
    dg_entity_add(player, component_speed_create(1));
    dg_entity_add(player, component_stat_create(0));
    dg_entity_add(player, component_player_create());
    dg_entity_add(player, component_sound_create("res/jump.ogg"));
    dg_entity_add(player, component_text_create(&fpos, NULL, "Score : 0"));
    return player;
}
