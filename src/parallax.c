/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** parallax.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

void parallax(beginning_t *begin, game_object_t *obj, sfClock *clock)
{
    float time = sfClock_getElapsedTime(clock).microseconds;

    for (int i = 0; i < 3; ++i) {
        if (time >= 10000 * obj[i].speed)
            obj[i].rect.left += obj[i].speed;
        if (obj[i].rect.left >= 1920)
            obj[i].rect.left = 0;
    }
}
