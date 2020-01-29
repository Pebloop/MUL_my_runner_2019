/*
** EPITECH PROJECT, 2020
** libdragon
** File description:
** component sheet
*/

#include <stdlib.h>
#include "dg_component.h"
#include "libdragon.h"

static void component_sheet_destroy(void *data)
{
    spritesheet_t *sheet = (spritesheet_t *)(data);

    spritesheet_free(sheet);
}

dg_component_t *component_sheet_create(char *path, int x, int y)
{
    void (*destroy)(void *) = &component_sheet_destroy;
    spritesheet_t *sheet = spritesheet_create(path, x, y);
    dg_component_t *component = dg_component_create("sheet", sheet, destroy);

    return component;
}
