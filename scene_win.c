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

dg_scene_t *scene_win_create(int score)
{
    sfVector2f size = {1920, 1080};
    sfVector2f pos = {0, 0};
    char *background = "res/win_background.png";
    dg_scene_t *scene_win = dg_scene_create("win");

    dg_scene_add_ent(scene_win, entity_camera_create());
    dg_scene_add_ent(scene_win, entity_score_create(score));
    dg_scene_add_ent(scene_win, entity_sp_create(background, size, pos));
    dg_scene_add_sys(scene_win, dg_system_create(&system_camera_sp_render));
    dg_scene_add_sys(scene_win, dg_system_create(&system_display_text));
}
