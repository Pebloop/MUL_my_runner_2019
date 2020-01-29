/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** component parallax
*/

#include <stdlib.h>
#include "dg_component.h"
#include "libdragon.h"
#include "parallax.h"

static void component_parallax_destroy(void *data)
{
    parallax_t *parallax = (parallax_t *)(data);

    parallax_free(parallax);
}

dg_component_t *component_parallax_create(parallax_t *(*set_parallax)(void))
{
    void (*destroy)(void *) = &component_parallax_destroy;
    parallax_t * parallax = set_parallax();
    dg_component_t *component = dg_component_create("parallax",
        parallax, destroy);

    return component;
}
