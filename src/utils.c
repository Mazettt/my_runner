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
    beginning->window = sfRenderWindow_create(mode, "Screensaver",
    sfClose | sfFullscreen, NULL);
    beginning->framebuffer = my_framebuffer_create();
    beginning->texture = sfTexture_createFromFile("spritesheet.png", NULL);
    if (!beginning->texture)
        exit(84);
    // beginning->sprite = sfSprite_create();
}

int my_events(beginning_t *begin)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(begin->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(begin->window);
        else if (event.type == sfEvtKeyPressed && sfKeyEscape == event.key.code)
            sfRenderWindow_close(begin->window);
        else if (event.type == sfEvtKeyPressed && sfKeySpace == event.key.code)
            return (1);
        // else if (event.type == sfEvtMouseButtonPressed && sfMouseLeft == event.key.code)
        //     manage_mouse_click(event.mouseButton, begin);
    }
    return (0);
}

sfColor my_rgb(sfColor color)
{
    if (color.r == 255 && color.b == 0)
        ++color.g;
    if (color.g == 255 && color.b == 0)
        --color.r;
    if (color.g == 255 && color.r == 0)
        ++color.b;
    if (color.b == 255 && color.r == 0)
        --color.g;
    if (color.b == 255 && color.g == 0)
        ++color.r;
    if (color.r == 255 && color.g == 0)
        --color.b;
    return (color);
}

sfColor my_rgb_fast(sfColor color, int speed)
{
    if (color.r == 255 && color.b == 0)
        color.g += speed;
    if (color.g == 255 && color.b == 0)
        color.r -= speed;
    if (color.g == 255 && color.r == 0)
        color.b += speed;
    if (color.b == 255 && color.r == 0)
        color.g -= speed;
    if (color.b == 255 && color.g == 0)
        color.r += speed;
    if (color.r == 255 && color.g == 0)
        color.b -= speed;
    return (color);
}

// sfColor rgb_billy(sfColor color)
// {
//     !color.b && 255 == color.r ? 255 == ++color.g ? --color.r : 0 :
//     !color.b && 255 == color.g ? !--color.r ? ++color.b : 0 :
//     !color.r && 255 == color.g ? 255 == ++color.b ? --color.g : 0 :
//     !color.r && 255 == color.b ? !--color.g ? ++color.r : 0 :
//     !color.g && 255 == color.b ? 255 == ++color.r ? --color.b : 0 :
//     !color.g && 255 == color.r ? !--color.b ? ++color.g : 0 : 0;
//     return (color);
// }
