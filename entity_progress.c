/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** map entity and system
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *entity_progress_create(sfVector2i score)
{
    dg_entity_t *entity = dg_entity_create();
    sfVector2f pos = {590, 900};
    int scale = 50;
    char str[21] = "progress :     / 100";
    int result = 100 * score.x / score.y;

    for (int i = 2; i >= 0; i--) {
        str[11 + i] = result % 10 + '0';
        result /= 10;
    }
    dg_entity_add(entity, component_text_create(&pos, &scale, str));
    return entity;
}
