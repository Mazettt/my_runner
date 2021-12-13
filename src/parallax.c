/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** parallax.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

#define SPEED 2

void parallax(beginning_t *begin, game_object_t *obj)
{
    float time;

    for (int i = 0; i < 3; ++i) {
        time = sfClock_getElapsedTime(obj[i].clock).microseconds;
        if (time >= 1000) {
            obj[i].rect.left += obj[i].speed * SPEED;
            sfClock_restart(obj[i].clock);
            i == 2 ? obj[4].pos.x -= obj[2].speed * SPEED : 0;
        }
        if (obj[i].rect.left >= 3960) {
            obj[i].rect.left = 0;
        }
        if (obj[2].rect.left == 1920 || obj[2].rect.left == 1920 * 2 || obj[2].rect.left == 1920 * 3)
            obj[4].pos.x = 1920;
    }
    sfSprite_setPosition(obj[4].sprite, obj[4].pos);
}
