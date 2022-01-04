/*
** EPITECH PROJECT, 2021
** myscreensaver
** File description:
** utils.c
*/

#include "../include/struct.h"
#include "../include/myrunner.h"


sfUint8 *my_framebuffer_create(void)
{
    sfUint8 *framebuffer = malloc(sizeof(sfUint8) * (WIDTH * HEIGHT * 4));
    return (framebuffer);
}

void all_beginning(beginning_t *beginning)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    beginning->mode = mode;
    beginning->window = sfRenderWindow_create(mode, "My runner",
    sfClose | sfFullscreen, NULL);
    beginning->framebuffer = my_framebuffer_create();
    beginning->texture = sfTexture_createFromFile("images/spritesheet.png",
    NULL);
}

// int keyboard(beginning_t *begin)
// {
//     if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeySpace))
//         return (1);
//     if (sfKeyboard_isKeyPressed(sfKeyRight))
//         return (3);
//     if (sfKeyboard_isKeyPressed(sfKeyLeft))
//         return (2);
// }
