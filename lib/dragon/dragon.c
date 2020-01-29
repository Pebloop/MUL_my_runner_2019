/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** manage the general use of the lib
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "framebuffer.h"
#include "dg_window.h"

void *dg_init(dg_window_t *);

void dg_end(void *, int);

int dg_loop(dg_window_t *, void *, sfTime);

static void dg_manage_event(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}

static void dg_render_screen(dg_window_t *window, void *var)
{
    sfEvent event;
    sfClock *clock = sfClock_create();
    sfTime dt = {0};

    while (sfRenderWindow_isOpen(window->window)) {
        dg_manage_event(window->window, event);
        dg_loop(window, var, dt);
        framebuffer_update(window->fb, window->window);
        sfRenderWindow_display(window->window);
        dt = sfClock_getElapsedTime(clock);
        sfClock_restart(clock);
    }
    dg_end(var, window->id);
    sfClock_destroy(clock);
}

int dg_play(sfVector2f screen_size, char *name, int id, void *arg)
{
    dg_window_t *window = dg_window_create(screen_size, name, id, arg);
    void *data = 0;
    int to_return = 0;

    sfRenderWindow_setFramerateLimit (window->window, 60);
    data = dg_init(window);
    sfRenderWindow_clear(window->window, sfBlack);
    dg_render_screen(window, data);
    dg_window_destroy(window);
    return to_return;
}
