/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** component sound
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "dg_component.h"

static void component_sound_destroy(void *data)
{
    sfMusic *sound = (sfMusic *)(data);

    sfMusic_destroy(sound);
}

dg_component_t *component_sound_create(char *path)
{
    void (*destroy)(void *) = &component_sound_destroy;
    sfMusic *sound = sfMusic_createFromFile(path);

    dg_component_t *component = dg_component_create("sound", sound, destroy);
    return component;
}

void sound_play(sfMusic *sound)
{
    sfTime time = {0};

    sfMusic_setPlayingOffset(sound, time);
    sfMusic_play(sound);
}
