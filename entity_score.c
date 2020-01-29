/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** map entity and system
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

int get_score_size(int);

dg_entity_t *entity_score_create(int score)
{
    dg_entity_t *entity = dg_entity_create();
    sfVector2f pos = {850, 450};
    int scale = 32;
    char str[18] = "Score :           ";
    int nb_size = get_score_size(score);

    for (int i = nb_size - 1; i >= 0; i--) {
        str[8 + i] = (int)(score) % 10 + '0';
        score /= 10;
    }
    str[8 + nb_size] = '\0';
    dg_entity_add(entity, component_text_create(&pos, &scale, str));
    return entity;
}
