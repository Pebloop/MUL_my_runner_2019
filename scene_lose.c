/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** scene game
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libdragon.h"
#include "parallax.h"
#include "ecs.h"
#include "my_runner.h"

void loop_general_end(dg_window_t *w, dg_scene_t **a_scene, sfTime dt)
{
    dg_scene_t *scene = *a_scene;

    if (keyboard_is_key_down(sfKeySpace)) {
        dg_scene_destroy(scene);
        *a_scene = scene_game_create((char *)(w->arg));
        return;
    }
}

dg_scene_t *scene_lose_create(sfVector2i score)
{
    sfVector2f size = {1920, 1080};
    sfVector2f pos = {0, 0};
    char *background = "res/lose_background.png";
    dg_scene_t *scene_lose = dg_scene_create("lose");

    dg_scene_add_ent(scene_lose, entity_camera_create());
    dg_scene_add_ent(scene_lose, entity_score_create(score.x));
    dg_scene_add_ent(scene_lose, entity_progress_create(score));
    dg_scene_add_ent(scene_lose, entity_sp_create(background, size, pos));
    dg_scene_add_sys(scene_lose, dg_system_create(&system_camera_sp_render));
    dg_scene_add_sys(scene_lose, dg_system_create(&system_display_text));
}
