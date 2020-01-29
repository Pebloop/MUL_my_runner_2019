/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** component stat
*/

#include <stdlib.h>
#include "dg_component.h"
#include "libdragon.h"

static void component_camera_destroy(void *data)
{
    sfVector2f *camera = (sfVector2f *)(data);

    free(camera);
}

dg_component_t *component_camera_create(int x, int y)
{
    void (*destroy)(void *) = &component_camera_destroy;
    sfVector2f *camera = 0;
    dg_component_t *component = 0;

    camera = malloc(sizeof(sfVector2f));
    camera->x = x;
    camera->y = y;
    component = dg_component_create("camera", camera, destroy);
    return component;
}
