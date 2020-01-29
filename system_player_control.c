/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** player control system
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include "libdragon.h"
#include "my_runner.h"
#include "ecs.h"
#include "map.h"

void set_score(dg_entity_t *);

void player_jump(sfSprite *, int *, sfMusic *, sfTime);

static char get_tile(char **map, sfVector2f pos)
{
    int y = (pos.y == 500 ? 0 : pos.y == 630 ? 1 : 2);
    int x = (pos.x + 32 * 4) / 8 / 32;
    int c = 0;

    if (!map || !map[y])
        return ' ';
    for (c = 0; map && map[y] && map[y][c] != '\0' && c < x; c++) {}
    return map[y][c];
}

static int check_collision(map_t *map, sfVector2f pos)
{
    if (get_tile(map->map, pos) != '=')
        return -1;
    if (pos.x > map->end * 32 * 8)
        return -2;
    return 0;
}

static void train_move(map_t *map, dg_entity_t *player, sfVector2f *camera,
    sfTime dt)
{
    sfSprite *sprite = (sfSprite *)(dg_entity_get(player, "sprite"));
    sfMusic *sound = (sfMusic *)(dg_entity_get(player, "sound"));
    sfVector2f pos = sfSprite_getPosition(sprite);
    int *stat = (int *)(dg_entity_get(player, "stat"));
    int y = (pos.y == 500 ? 0 : pos.y == 630 ? 1 : 2);

    if (*stat == 0) {
        *stat = check_collision(map, pos);
        if (keyboard_is_key_down(sfKeyDown) && y < 2)
            pos.y += 130;
        if (keyboard_is_key_down(sfKeyUp) && y > 0)
            pos.y -= 130;
    }
    sfSprite_setPosition(sprite, pos);
    camera->x = pos.x - 50;
    player_jump(sprite, stat, sound, dt);
}

void system_player_control(dg_entity_t *entity, dg_window_t *w,
    dg_entity_t **entities, sfTime dt)
{
    sfSprite *sprite = (sfSprite *)(dg_entity_get(entity, "sprite"));
    sfVector2f move = {dt.microseconds / 10000.0, 0};
    map_t *map = 0;
    sfVector2f *camera = 0;
    float *speed = (float *)(dg_entity_get(entity, "speed"));

    if (!dg_system_require(entity, 1, "player"))
        return;
    *speed += (*speed < 100) ? dt.microseconds / 3000000.0 : 0;
    move.x *= * speed;
    sfSprite_move(sprite, move);
    for (int i = 0; entities[i]; i++) {
        if (dg_system_require(entities[i], 1, "map"))
            map = (map_t *)(dg_entity_get(entities[i], "map"));
        if (dg_system_require(entities[i], 1, "camera"))
            camera = (sfVector2f *)(dg_entity_get(entities[i], "camera"));
    }
    if (map && camera)
        train_move(map, entity, camera, dt);
    set_score(entity);
}
