/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** manage the general use of the lib
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libdragon.h"
#include "parallax.h"
#include "ecs.h"
#include "epitech_tools.h"
#include "my_runner.h"

typedef struct val {
    dg_scene_t *scene;
} val_t;

void *dg_init(dg_window_t *w)
{
    val_t *v = malloc(sizeof(val_t));

    v->scene = scene_game_create((char *)(w->arg));
    return v;
}

int dg_loop(dg_window_t *w, void *data, sfTime dt)
{
    val_t *v = ((val_t *)(data));

    sfRenderWindow_clear(w->window, sfBlack);
    if (!dg_strcmp(v->scene->name, "game"))
        loop_general_game(w, &(v->scene), dt);
    else
        loop_general_end(w, &(v->scene), dt);
    dg_scene_update(v->scene, w, dt);
    return 0;
}

void dg_end(void *var, int id)
{
    val_t *v = ((val_t *)(var));

    dg_scene_destroy(v->scene);
}

int main(int argc, char **argv)
{
    int file = -1;
    sfVector2f screen_size = {1920, 1080};

    if (argc == 2 && !dg_strcmp(argv[1], "-h"))
        print_usage();
    else if (argc != 2)
        return 84;
    else {
        file = open(argv[1], O_RDONLY);
        if (file == -1)
            return 84;
        close(file);
        dg_play(screen_size, "LibDragon", 0, argv[1]);
    }
    return 0;
}
