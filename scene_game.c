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
#include "map.h"

static sfVector2i get_score(dg_scene_t *scene)
{
    dg_entity_t *entity = 0;
    sfSprite *player = 0;
    sfVector2f pos = {0};
    map_t *map = 0;
    sfVector2i result = {0};

    if (!scene || !scene->entities)
        return (sfVector2i) {0};
    for (int i = 0; scene->entities[i]; i++) {
        entity = scene->entities[i];
        if (dg_system_require(entity, 1, "player")) {
            player = (sfSprite *)(dg_entity_get(entity, "sprite"));
            pos = sfSprite_getPosition(player);
        }
        if (dg_system_require(entity, 1, "map")) {
            map = (map_t *)(dg_entity_get(entity, "map"));
        }
    }
    result.x = pos.x / 100;
    result.y =  map->end * 32 * 8 / 100;
    return result;
}

void loop_general_game(dg_window_t *w, dg_scene_t **a_scene, sfTime dt)
{
    dg_entity_t *entity = 0;
    int *stat = 0;
    dg_scene_t *scene = *a_scene;
    sfVector2i score = get_score(scene);

    if (!scene || !scene->entities)
        return;
    for (int i = 0; scene->entities[i]; i++) {
        entity = scene->entities[i];
        stat = (int *)(dg_entity_get(entity, "stat"));
        if (stat && *stat == -1) {
            dg_scene_destroy(scene);
            *a_scene = scene_lose_create(score);
            return;
        } else if (stat && *stat == -2) {
            dg_scene_destroy(scene);
            *a_scene = scene_win_create(score.x);
            return;
        }
    }
}

dg_scene_t *scene_game_create(char *filepath)
{
    dg_scene_t *scene_game = dg_scene_create("game");

    dg_scene_add_ent(scene_game, entity_parallax_create());
    dg_scene_add_ent(scene_game, entity_camera_create());
    load_map(scene_game, filepath);
    dg_scene_add_ent(scene_game, entity_player_create());
    dg_scene_add_ent(scene_game, entity_music_create("res/ost.ogg"));
    dg_scene_add_sys(scene_game, dg_system_create(&system_parallax));
    dg_scene_add_sys(scene_game, dg_system_create(&system_player_control));
    dg_scene_add_sys(scene_game, dg_system_create(&system_player_animator));
    dg_scene_add_sys(scene_game, dg_system_create(&system_camera_sp_render));
    dg_scene_add_sys(scene_game, dg_system_create(&system_hud_sp_render));
    dg_scene_add_sys(scene_game, dg_system_create(&system_display_text));
    return scene_game;
}
