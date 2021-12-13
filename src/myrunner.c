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
    init_obstacle(begin, obj);
    init_died_message(begin, obj);
    for (int i = 0; i < NBR_OBJ - 1; ++i) {
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

void move_perso(beginning_t *begin, game_object_t *obj)
{
    float time = sfClock_getElapsedTime(obj[3].clock).microseconds;
    int offset = 5940;
    int max_value = 5940 + 1600;

    if (keyboard(begin) == 2 && obj[3].pos.x != 50)
        obj[3].pos.x -= 2;
    if (keyboard(begin) == 3 && obj[3].pos.x != 1850)
        obj[3].pos.x += 2;
    if (keyboard(begin) == 1 && obj[3].pos.y >= 900) {
        obj[3].inc_pos = -2;
        obj[3].rect.left = 5940 + 1246;
    }
    obj[3].pos.y += obj[3].inc_pos;
    if (obj[3].pos.y <= 730)
        obj[3].inc_pos = 2;
    if (obj[3].pos.y >= 930) {
        obj[3].inc_pos = 0;
        if (time >= 100000) {
            obj[3].rect.left += 178;
            sfClock_restart(obj[3].clock);
        }
    }
    if (obj[3].rect.left >= max_value)
        obj[3].rect.left = offset;
    sfSprite_setPosition(obj[3].sprite, obj[3].pos);
    for (int i = 0; i < NBR_OBJ - 1; ++i)
        sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
}

int collisions(beginning_t *begin, game_object_t *obj)
{
    sfFloatRect panda = sfSprite_getGlobalBounds(obj[3].sprite);
    sfFloatRect rocher = sfSprite_getGlobalBounds(obj[4].sprite);

    if (sfFloatRect_intersects(&panda, &rocher, NULL)) {
        for (int i = 0; i < NBR_OBJ - 1; ++i) {
            obj[i].inc_pos = 0;
            obj[i].speed = 0;
        }
        printf("oui\n");
        sfSprite_setTexture(obj[5].sprite, begin->texture, sfFalse);
        sfSprite_setTextureRect(obj[5].sprite, obj[5].rect);
        return (0);
    } else
        return (1);
        // sfRenderWindow_close(begin->window);
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

void big_while(beginning_t *begin, game_object_t *obj)
{
    int bol = 1;

    sfRenderWindow_clear(begin->window, sfBlack);
    my_clear_framebuffer(begin->framebuffer, sfBlack);
    bol = collisions(begin, obj);
    bol ? parallax(begin, obj) : 0;
    bol ? move_perso(begin, obj) : 0;
    my_events(begin);
    for (int i = 0; i < NBR_OBJ; ++i)
        sfRenderWindow_drawSprite(begin->window, obj[i].sprite, NULL);
    sfRenderWindow_display(begin->window);
}

int myrunner(void)
{
    beginning_t beginning;
    game_object_t *obj = malloc(sizeof(game_object_t) * NBR_OBJ);

    // float time;
    // sfMusic *music = sfMusic_createFromFile("music/toe.ogg");
    // sfMusic_play(music);

    for (int i = 0; i < NBR_OBJ; ++i)
        obj[i].clock = sfClock_create();
    all_beginning(&beginning);
    init_objs(&beginning, obj);
    if (!beginning.window)
        return (84);
    while (sfRenderWindow_isOpen(beginning.window))
        big_while(&beginning, obj);
        // time = sfClock_getElapsedTime(clock).microseconds;
        // seconds = time.microseconds / 1000000.0;
    free(beginning.framebuffer);
    sfRenderWindow_destroy(beginning.window);
    for (int i = 0; i < NBR_OBJ; ++i)
        sfClock_destroy(obj[i].clock);
    // sfMusic_destroy(music);
    return (0);
}
