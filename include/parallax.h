/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** define the parallax struct
*/

#ifndef PARALLAX_H_
#define PARALLAX_H_

#include "libdragon.h"

typedef struct parallax {
    int layers;
    sfSprite ***sprites;
    float *speed;
} parallax_t;

parallax_t *parallax_create();

void parallax_free(parallax_t *);

void parallax_add_layer(parallax_t *, char *, float);

void parallax_update(parallax_t *, sfRenderWindow *, float);

#endif /*PARALLAX_H*/
