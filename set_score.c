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

int get_score_size(int nb)
{
    int size = 0;

    if (nb == 0)
        return 1;
    while (nb > 0) {
        nb /= 10;
        size++;
    }
    return size;
}

void set_score(dg_entity_t *entity)
{
    sfSprite *sprite = (sfSprite *)(dg_entity_get(entity, "sprite"));
    sfText *text = (sfText *)(dg_entity_get(entity, "text"));
    sfVector2f pos = sfSprite_getPosition(sprite);
    int nb_size = get_score_size(pos.x / 100);
    char new_line[19] = "Score :           ";

    pos.x /= 100;
    for (int i = nb_size - 1; i >= 0; i--) {
        new_line[8 + i] = (int)(pos.x) % 10 + '0';
        pos.x /= 10;
    }
    new_line[8 + nb_size] = '\0';
    sfText_setString(text, new_line);
}

static void if_jump(sfVector2f *strengh, sfSprite *sprite, int *stat, sfTime dt)
{
    sfVector2f move = {0, 0};
    sfVector2f pos = sfSprite_getPosition(sprite);
    float gravity = 9.81;

    strengh->x += gravity * (dt.microseconds / 50000.0);
    move.y = strengh->x * (dt.microseconds / 50000.0);
    sfSprite_move(sprite, move);
    if (sfSprite_getPosition(sprite).y >= strengh->y) {
        *stat = 0;
        move.x = sfSprite_getPosition(sprite).x;
        move.y = strengh->y;
        sfSprite_setPosition(sprite, move);
    }
}

void player_jump(sfSprite *sprite, int *stat, sfMusic *jump, sfTime dt)
{
    static sfVector2f strengh = {0};
    sfVector2f pos = sfSprite_getPosition(sprite);

    if (keyboard_is_key_down(sfKeySpace) && *stat == 0) {
        strengh.x = -70;
        *stat = 1;
        strengh.y = pos.y;
        sound_play(jump);
    } else if (*stat == 1) {
        if_jump(&strengh, sprite, stat, dt);
    }
}
