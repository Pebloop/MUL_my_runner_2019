/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** define the map struct
*/

#ifndef MAP_H_
#define MAP_H_

typedef struct map {
    int end;
    char **map;
} map_t;

map_t *map_create(char **);

void map_destroy(map_t *);

#endif /*MAP_H*/
