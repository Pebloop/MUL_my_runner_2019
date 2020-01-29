/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** component animator
*/

#include <stdlib.h>
#include "dg_component.h"
#include "libdragon.h"

static void component_animator_destroy(void *data)
{
    animator_t *animator = (animator_t *)(data);
    animation_t *anim = 0;

    for (int i = 0; i < animator->length; i++) {
        anim = animator->animations[i];
        spritesheet_free(anim->sheet);
    }
    animator_free(animator);
}

dg_component_t *component_animator_create(animator_t *(*set_animator)(void))
{
    void (*destroy)(void *) = &component_animator_destroy;
    animator_t *animator = set_animator();
    dg_component_t *component = dg_component_create("animator",
        animator, destroy);

    return component;
}
