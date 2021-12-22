/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** parallax.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

#define SPEED 2

void parallax(beginning_t *begin, all_objects_t *all_objs)
{
    float time;

    for (int i = 0; i < NBR_BACKGROUND; ++i) {
        time = sfClock_getElapsedTime(all_objs->background[i].clock).microseconds;
        if (time >= 1000) {
            all_objs->background[i].rect.left += all_objs->background[i].speed * SPEED;
            sfClock_restart(all_objs->background[i].clock);
            i == 2 ? all_objs->obstacles[0].pos.x -= all_objs->background[2].speed * SPEED : 0;
        }
        if (all_objs->background[i].rect.left >= 3960) {
            all_objs->background[i].rect.left = 0;
        }
        if (all_objs->background[2].rect.left == 1920 || all_objs->background[2].rect.left == 1920 * 2 || all_objs->background[2].rect.left == 1920 * 3)
            all_objs->obstacles[0].pos.x = 1920;
    }
    sfSprite_setPosition(all_objs->obstacles[0].sprite, all_objs->obstacles[0].pos);
}
