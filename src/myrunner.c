/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

void init_objs(beginning_t *begin, game_object_t *obj)
{
    for (int i = 0; i < NBR_OBJ; ++i)
        obj[i].sprite = sfSprite_create();
    init_background(begin, obj);
    init_perso(begin, obj);
    for (int i = 0; i < NBR_OBJ; ++i) {
        sfSprite_setTexture(obj[i].sprite, begin->texture, sfFalse);
        sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
    }
}

// int space_event(beginning_t *begin)
// {
//     sfEvent event;

//     while (sfRenderWindow_pollEvent(begin->window, &event)) {
//         if (event.type == sfEvtKeyPressed && sfKeySpace == event.key.code)
//             return (1);
//     }
//     return (0);
// }

void move_perso(beginning_t *begin, game_object_t *obj, sfClock *clock)
{
    float time = sfClock_getElapsedTime(clock).microseconds;
    int offset = 3840;
    int max_value = 3840 + 1700;

    if (my_events(begin) && obj[3].pos.y >= 880)
        obj[3].inc_pos = -2;
    obj[3].pos.y += obj[3].inc_pos;
    if (obj[3].pos.y <= 700)
        obj[3].inc_pos = 2;
    if (obj[3].pos.y >= 900)
        obj[3].inc_pos = 0;
    if (time >= 100000) {
        obj[3].rect.left += 170;
        sfClock_restart(clock);
    }
    if (obj[3].rect.left >= max_value)
        obj[3].rect.left = offset;
    sfSprite_setPosition(obj[3].sprite, obj[3].pos);
    for (int i = 0; i < NBR_OBJ; ++i)
        sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
}

// void my_putpixel(int x, int y, sfUint8 *framebuffer, sfColor color)
// {
//     x <= 0 ? x = 1, color.a = 0: x;
//     x >= HEIGHT ? x = HEIGHT - 2, color.a = 0 : x;
//     y <= 0 ? y = 1, color.a = 0 : y;
//     y >= WIDTH ? y = WIDTH - 2, color.a = 0 : y;
//     *(sfColor *)(4 * (x * WIDTH + y) + framebuffer) = color;
// }

// void manage_mouse_click(sfMouseButtonEvent event, beginning_t *begin)
// {
//     my_putpixel(event.y, event.x, begin->framebuffer, sfRed);
//     printf("Mouse x=%d y=%d\n", event.x, event.y);
// }

void big_while(beginning_t *begin, game_object_t *obj, sfClock *clock)
{
    sfRenderWindow_clear(begin->window, sfBlack);
    my_clear_framebuffer(begin->framebuffer, sfBlack);
    parallax(begin, obj, clock);
    move_perso(begin, obj, clock);
    for (int i = 0; i < NBR_OBJ; ++i)
        sfRenderWindow_drawSprite(begin->window, obj[i].sprite, NULL);
    sfRenderWindow_display(begin->window);
}

int myrunner(void)
{
    beginning_t beginning;
    game_object_t *obj = malloc(sizeof(game_object_t) * NBR_OBJ);
    sfClock *clock;
    float time;
    // sfMusic *music = sfMusic_createFromFile("music/toe.ogg");
    // sfMusic_play(music);

    clock = sfClock_create();
    all_beginning(&beginning);
    init_objs(&beginning, obj);
    if (!beginning.window)
        return (84);
    while (sfRenderWindow_isOpen(beginning.window))
        big_while(&beginning, obj, clock);
        // time = sfClock_getElapsedTime(clock).microseconds;
        // seconds = time.microseconds / 1000000.0;
    free(beginning.framebuffer);
    sfRenderWindow_destroy(beginning.window);
    // sfMusic_destroy(music);
    return (0);
}
