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

// int keyboard(beginning_t *begin)
// {
//     if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeySpace))
//         return (1);
//     if (sfKeyboard_isKeyPressed(sfKeyRight))
//         return (3);
//     if (sfKeyboard_isKeyPressed(sfKeyLeft))
//         return (2);
// }

void events_key_pressed(sfEvent event, beginning_t *begin, events_t *all_events, scoreboard_t *score)
{
    if (sfKeyEscape == event.key.code)
        score->title = 0;
    else if (sfKeySpace == event.key.code || sfKeyUp == event.key.code)
        all_events->up = 1;
    else if (sfKeyLeft == event.key.code || sfKeyQ == event.key.code)
        all_events->left = 1;
    else if (sfKeyRight == event.key.code || sfKeyD == event.key.code)
        all_events->right = 1;
}

void events_key_released(sfEvent event, events_t *all_events)
{
    if (sfKeySpace == event.key.code || sfKeyUp == event.key.code)
        all_events->up = 0;
    else if (sfKeyLeft == event.key.code || sfKeyQ == event.key.code)
        all_events->left = 0;
    else if (sfKeyRight == event.key.code || sfKeyD == event.key.code)
        all_events->right = 0;
}

void respawn(sfEvent event, scoreboard_t *score, beginning_t *begin, game_object_t *obj)
{
    if ((event.mouseButton.x > 664 && event.mouseButton.x < 1317) &&
    (event.mouseButton.y > 436 && event.mouseButton.y < 500)) {
        init_background(begin, obj);
        init_obstacle(begin, obj);
        init_perso(begin, obj);
        score->died = 0;
    } else if ((event.mouseButton.x > 664 && event.mouseButton.x < 1317) &&
    (event.mouseButton.y > 514 && event.mouseButton.y < 579)) {
        init_background(begin, obj);
        init_obstacle(begin, obj);
        init_perso(begin, obj);
        score->title = 0;
    }
    score->score = 0;
}

void menu(sfEvent event, scoreboard_t *score, beginning_t *begin, game_object_t *obj)
{
    if (sfMouseLeft == event.key.code)
        if ((event.mouseButton.x > 664 && event.mouseButton.x < 1316) &&
        (event.mouseButton.y > 404 && event.mouseButton.y < 468)) {
            score->title = 1;
        }
        if (!score->title && (event.mouseButton.x > 998 && event.mouseButton.x < 1316) &&
        (event.mouseButton.y > 660 && event.mouseButton.y < 724))
            sfRenderWindow_close(begin->window);
        if (score->died)
            respawn(event, score, begin, obj);

    // my_putpixel(event.y, event.x, begin->framebuffer, sfRed);
    // printf("Mouse x=%d y=%d\n", event.x, event.y);
}

int my_events(beginning_t *begin, events_t *all_events, scoreboard_t *score, game_object_t *obj)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(begin->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(begin->window);
        else if (event.type == sfEvtKeyPressed)
            events_key_pressed(event, begin, all_events, score);
        else if (event.type == sfEvtKeyReleased)
            events_key_released(event, all_events);
        else if (event.type == sfEvtMouseButtonPressed)
            menu(event, score, begin, obj);
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
