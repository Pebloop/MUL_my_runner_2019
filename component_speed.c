/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** component animator
*/

#include <stdlib.h>
#include "dg_component.h"

static void component_speed_destroy(void *data)
{
    float *speed = (float *)(data);

    free(speed);
}

dg_component_t *component_speed_create(float init_value)
{
    void (*destroy)(void *) = &component_speed_destroy;
    float *speed = malloc(sizeof(float));
    dg_component_t *component = dg_component_create("speed", speed, destroy);

    *speed = init_value;
    return component;
}
