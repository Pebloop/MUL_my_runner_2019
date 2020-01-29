/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the dg_component struct
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

void load_map(dg_scene_t *, char *);

void print_usage(void);

int keyboard_is_key_down(sfKeyCode);

void loop_general_game(dg_window_t *, dg_scene_t **, sfTime);

void loop_general_end(dg_window_t *, dg_scene_t **, sfTime);

#endif /*MY_RUNNER_H*/
