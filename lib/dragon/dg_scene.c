/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_scene
*/

#include <stdlib.h>
#include "dg_scene.h"
#include "epitech_tools.h"

dg_scene_t *dg_scene_create(char *name)
{
    dg_scene_t *scene = malloc(sizeof(dg_scene_t));

    if (!scene)
        return 0;
    scene->name = name;
    scene->entities = 0;
    scene->systems = 0;
    return scene;
}

void dg_scene_add_ent(dg_scene_t *scene, dg_entity_t *entity)
{
    dg_entity_t **entities = 0;
    int ent_len = 0;

    if (!scene || !entity)
        return;
    if (scene->entities)
        for (ent_len = 0; scene->entities[ent_len]; ent_len++) {}
    entities = malloc(sizeof(dg_entity_t *) * (ent_len + 2));
    if (!entities)
        return;
    if (ent_len > 0) {
        for (int i = 0; i < ent_len; i++)
            entities[i] = scene->entities[i];
        free(scene->entities);
    }
    entities[ent_len] = entity;
    entities[ent_len + 1] = NULL;
    scene->entities = entities;
}

void dg_scene_add_sys(dg_scene_t *scene, dg_system_t *system)
{
    dg_system_t **systems = 0;
    int sys_len = 0;

    if (!scene || !system)
        return;
    if (scene->systems)
        for (sys_len = 0; scene->systems[sys_len]; sys_len++) {}
    systems = malloc(sizeof(dg_system_t *) * (sys_len + 2));
    if (!systems)
        return;
    if (sys_len > 0) {
        for (int i = 0; i < sys_len; i++)
            systems[i] = scene->systems[i];
        free(scene->systems);
    }
    systems[sys_len] = system;
    systems[sys_len + 1] = NULL;
    scene->systems = systems;
}

void dg_scene_destroy(dg_scene_t *scene)
{
    int ent_len = 0;
    int sys_len = 0;

    if (!scene)
        return;
    if (scene->entities) {
        for (ent_len = 0; scene->entities[ent_len]; ent_len++) {}
        for (int i = 0; i < ent_len; i++)
            dg_entity_destroy(scene->entities[i]);
        free(scene->entities);
    }
    if (scene->systems) {
        for (sys_len = 0; scene->systems[sys_len]; sys_len++) {}
        for (int i = 0; i < sys_len; i++)
            dg_system_destroy(scene->systems[i]);
        free(scene->systems);
    }
}

void dg_scene_update(dg_scene_t *sn, dg_window_t *w, sfTime dt)
{
    int ent_len = 0;
    int sys_len = 0;

    if (sn->entities)
        for (ent_len = 0; sn->entities[ent_len]; ent_len++) {}
    if (sn->systems)
        for (sys_len = 0; sn->systems[sys_len]; sys_len++) {}
    for (int y = 0; y < ent_len; y++) {
        for (int i = 0; i < sys_len; i++) {
            sn->systems[i]->system(sn->entities[y], w, sn->entities, dt);
        }
    }
}
