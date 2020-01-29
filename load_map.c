/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** map entity and system
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libdragon.h"
#include "get_next_line.h"
#include "ecs.h"

static char **load_map_from_file(char *filepath)
{
    int file = open(filepath, O_RDONLY);
    char **map = malloc(sizeof(char *) * 3);

    for (int i = 0; i < 3; i++) {
        map[i] = get_next_line(file);
    }
    close(file);
    return map;
}

static void set_tile(int x, int y, char c, dg_scene_t *scene)
{
    dg_entity_t *entity = 0;

    if (c == '=')
        entity = entity_rail_create(x, y);
    dg_scene_add_ent(scene, entity);
}

void load_map(dg_scene_t *scene, char *filepath)
{
    char **map = load_map_from_file(filepath);

    for (int i = 0; i < 3; i++) {
        for (int y = 0; map && map[i] && map[i][y] != '\0'; y++) {
            set_tile(y * 32 * 8, 500 + (i * 130), map[i][y], scene);
        }
    }
    dg_scene_add_ent(scene, entity_map_create(map));
}
