/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** manage the parralax add layer
*/

#include <stdlib.h>
#include "parallax.h"
#include "libdragon.h"

static void old_to_new(parallax_t *parallax, float *speeds, sfSprite ***sprites)
{
    if (parallax->layers > 0) {
        for (int i = 0; i < parallax->layers; i++) {
            speeds[i] = parallax->speed[i];
            sprites[i] = parallax->sprites[i];
        }
        free(parallax->sprites);
        free(parallax->speed);
    }
}

void parallax_add_layer(parallax_t *parallax, char *filepath, float speed)
{
    sfTexture *tex = sfTexture_createFromFile(filepath, 0);
    sfSprite ***sprites = malloc(sizeof(sfSprite **) * (parallax->layers + 1));
    sfSprite **layer = malloc(sizeof(sfSprite *) * 3);
    float *speeds = malloc(sizeof(float) * (parallax->layers + 1));
    sfVector2f move_layer1 = {1920, 0};
    sfVector2f move_layer2 = {-1920, 0};

    old_to_new(parallax, speeds, sprites);
    for (int i = 0; i < 3; i++) {
        layer[i] = sfSprite_create();
        sfSprite_setTexture(layer[i], tex, 1);
    }
    sfSprite_move(layer[0], move_layer2);
    sfSprite_move(layer[2], move_layer1);
    sprites[parallax->layers] = layer;
    speeds[parallax->layers] = speed;
    parallax->sprites = sprites;
    parallax->speed = speeds;
    parallax->layers++;
}
