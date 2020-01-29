/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** keyboard key down management
*/

#include <stdlib.h>
#include "libdragon.h"
#include "epitech_tools.h"

const sfKeyCode KEY_INDEX[3] = {sfKeyDown, sfKeyUp, sfKeySpace};

static int get_key_index(sfKeyCode key)
{
    int i = 0;

    for (i = 0; i < 3 && key != KEY_INDEX[i]; i++) {}
    if (i == 3)
        return -1;
    return i;
}

int keyboard_is_key_down(sfKeyCode key)
{
    static int status[3] = {0};
    int index = get_key_index(key);
    int to_return = 0;

    if (index == -1)
        return 0;
    if (sfKeyboard_isKeyPressed(key)) {
        if (status[index] == 0) {
            to_return = 1;
        }
        status[index] = 1;
    } else {
        status[index] = 0;
    }
    return to_return;
}
