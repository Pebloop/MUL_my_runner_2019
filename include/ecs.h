/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** define the ecs content
*/

#ifndef ECS_H_
#define ECS_H_

#include "parallax.h"
#include <SFML/Audio.h>

void dg_component_destroy(dg_component_t *);

dg_component_t *component_sprite_create(sfVector2f *, sfVector2f *);

dg_component_t *component_animator_create(animator_t *(*)(void));

dg_component_t *component_speed_create(float);

dg_component_t *component_stat_create(int);

dg_component_t *component_map_create(char **);

dg_component_t *component_player_create(void);

dg_component_t *component_parallax_create(parallax_t *(*)(void));

dg_component_t *component_camera_create(int, int);

dg_component_t *component_text_create(sfVector2f *, int *, char *);

dg_component_t *component_music_create(char *);

dg_component_t *component_sound_create(char *);

dg_component_t *component_sheet_create(char *, int, int);

dg_entity_t *entity_player_create(void);

dg_entity_t *entity_rail_create(int, int);

dg_entity_t *entity_camera_create(void);

dg_entity_t *entity_parallax_create(void);

dg_entity_t *entity_map_create(char **);

dg_entity_t *entity_sp_create(char *, sfVector2f, sfVector2f);

dg_entity_t *entity_music_create(char *);

dg_entity_t *entity_score_create(int);

dg_entity_t *entity_progress_create(sfVector2i);

void system_player_control(dg_entity_t *, dg_window_t *,
    dg_entity_t **, sfTime);

void system_parallax(dg_entity_t *, dg_window_t *,
    dg_entity_t **, sfTime);

void system_camera_sp_render(dg_entity_t *, dg_window_t *,
    dg_entity_t **, sfTime);

void system_hud_sp_render(dg_entity_t *, dg_window_t *,
    dg_entity_t **, sfTime);

void system_display_text(dg_entity_t *, dg_window_t *,
    dg_entity_t **, sfTime);

dg_scene_t *scene_game_create(char *);

dg_scene_t *scene_lose_create(sfVector2i);

dg_scene_t *scene_win_create(int);

void sound_play(sfMusic *);

#endif /*ECS_H*/
