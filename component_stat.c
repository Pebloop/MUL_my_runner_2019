/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** component stat
*/

#include <stdlib.h>
#include "dg_component.h"

static void component_stat_destroy(void *data)
{
    int *stat = (int *)(data);

    free(stat);
}

dg_component_t *component_stat_create(int init_value)
{
    void (*destroy)(void *) = &component_stat_destroy;
    int *stat = malloc(sizeof(int));
    dg_component_t *component = dg_component_create("stat", stat, destroy);

    *stat = init_value;
    return component;
}
