/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** manage the parralax
*/

#include <stdlib.h>
#include "parallax.h"
#include "libdragon.h"

parallax_t *parallax_create(void)
{
    parallax_t *parallax = malloc(sizeof(parallax_t));

    if (!parallax)
        return 0;
    parallax->layers = 0;
    parallax->sprites = 0;
    parallax->speed = 0;
    return parallax;
}

static void parallax_replace_update(sfSprite **layer, int *pos, int width)
{
    int max[2] = {0, pos[0]};
    sfVector2f move = {0, 0};

    for (int y = 1; y < 3; y++) {
        if (max[1] < pos[y]) {
            max[1] = pos[y];
            max[0] = y;
        }
    }
    move.x = max[1] + width - 1;
    for (int y = 1; y < 3; y++) {
        if (pos[y] < -width)
            sfSprite_setPosition(layer[y], move);
    }
}

void parallax_update(parallax_t *parallax, sfRenderWindow *window, float second)
{
    sfSprite **layer = 0;
    sfVector2f move = {-second, 0};
    int pos[3] = {0};

    for (int i = 0; i < parallax->layers; i++) {
        layer = parallax->sprites[i];
        move.x = -second * parallax->speed[i];
        for (int y = 0; y < 3; y++) {
            sfRenderWindow_drawSprite(window, layer[y], NULL);
            sfSprite_move(layer[y], move);
            pos[y] = sfSprite_getPosition(layer[y]).x;
        }
        parallax_replace_update(layer, pos, 1920);
    }
}

void parallax_free(parallax_t *parallax)
{
    for (int i = 0; i < parallax->layers; i++) {
        for (int y = 0; y < 3; y++)
            sfSprite_destroy(parallax->sprites[i][y]);
        free (parallax->sprites[i]);
    }
    free(parallax->sprites);
    free(parallax->speed);
    free(parallax);
}
