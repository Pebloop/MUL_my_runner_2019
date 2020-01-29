/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_window
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "dg_window.h"

dg_window_t *dg_window_create(
    sfVector2f size,
    char *name,
    int id,
    void *arg
    )
{
    dg_window_t *window = malloc(sizeof(dg_window_t));
    sfVideoMode mode = {size.x, size.y, 32};

    if (!window)
        return 0;
    window->id = id;
    window->window = sfRenderWindow_create(mode, name, sfClose, NULL);
    window->fb = framebuffer_create(mode.width, mode.height);
    window->arg = arg;
    return window;
}

void dg_window_destroy(dg_window_t *window)
{
    framebuffer_destroy(window->fb);
    sfRenderWindow_destroy(window->window);
    free(window);
}
