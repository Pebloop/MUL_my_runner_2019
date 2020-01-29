/*
** EPITECH PROJECT, 2019
** 103cipher
** File description:
** print error messages
*/

#include <stdio.h>
#include <unistd.h>

void print_usage(void)
{
    write(1, "Train runner created with CSFML.\n\n", 34);
    write(1, "USAGE\n    ./my_runner map/map.map\n\n", 35);
    write(1, "OPTIONS\n", 8);
    write(1, "    -h          print the usage and quit.\n\n", 43);
    write(1, "USER INTERACTIONS\n", 18);
    write(1, "    SPACE_KEY   jump\n", 21);
    write(1, "    DOWN_KEY    go down\n", 24);
    write(1, "    UP_KEY      go up\n\n", 23);
    write(1, "RULES\n", 6);
    write(1, "    * Stay on the rails to stay alive\n", 38);
    write(1, "    * if you leave the railway, you lose\n", 41);
    write(1, "    * Go to the last rail (the most to the right) to win\n", 57);
    write(1, "\nCREATE A MAP\n", 14);
    write(1, "    * Create a file with the format : map/$(NAME).map\n", 54);
    write(1, "    * edit the file on three lines :\n", 37);
    write(1, "         - '=' for rails\n", 25);
    write(1, "         - ' ' for nothing\n", 27);
}
