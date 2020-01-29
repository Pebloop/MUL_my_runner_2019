/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** component text
*/

#include <stdlib.h>
#include "dg_component.h"
#include "libdragon.h"

static void component_text_destroy(void *data)
{
    sfText *text = (sfText *)(data);

    sfFont_destroy((sfFont *) sfText_getFont(text));
    sfText_destroy(text);
}

dg_component_t *component_text_create(sfVector2f *pos, int *scale,
    char *content)
{
    void (*destroy)(void *) = &component_text_destroy;
    sfText *text = sfText_create();
    dg_component_t *component = dg_component_create("text", text, destroy);

    sfText_setFont (text, sfFont_createFromFile("res/font.otf"));
    if (pos)
        sfText_setPosition(text, *pos);
    if (scale)
        sfText_setCharacterSize(text, *scale);
    sfText_setString(text, content);
    return component;
}

void system_display_text(dg_entity_t *entity, dg_window_t *w,
    dg_entity_t **entities, sfTime dt)
{
    sfText *text = (sfText *)(dg_entity_get(entity, "text"));

    if (!dg_system_require(entity, 1, "text"))
        return;
    sfRenderWindow_drawText (w->window, text, 0);
}
