/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** main.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"
#include "../include/my.h"

void help(void)
{
    my_putstr("Finite runner created with CSFML.\n\n");
    my_putstr("USAGE\n    ./my_runner map.txt\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("    -i launch the game in infinity mode.\n");
    my_putstr("    -h print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("    Up arrow / space    Jump\n");
    my_putstr("    Left arrow / Q      Move left\n");
    my_putstr("    Right arrow / D     Move right\n");
    my_putstr("    Escape              Pause game\n");
    my_putstr("MAP\n");
    my_putstr("    1: Obstacle number 1\n");
    my_putstr("    2: Obstacle number 2\n");
    my_putstr("    3: Obstacle number 3\n");
    my_putstr("    4: Obstacle number 4\n");
    my_putstr("    0: end of map.\n");
}

int main(int ac, char **av)
{
    bool inf = false;

    if (ac == 1) {
        my_putstr("./my_runner: bad arguments: 0 given but 1 is required\n");
        my_putstr("retry with -h\n");
        return (84);
    }
    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return (0);
    } else if (av[1][0] == '-' && av[1][1] == 'i') {
        inf = true;
        myrunner(inf, "");
    } else
        myrunner(inf, av[1]);
    return (0);
}
