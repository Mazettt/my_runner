/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** parallax.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

#define SPEED 3

void parallax_objs_rand(beginning_t *begin, all_objects_t *all_objs, int i)
{
    for (int j = 0; j < NBR_OBSTACLES / 2; ++j) {
        i == 2 ? all_objs->obstacles[j].pos.x -= all_objs->background[2].speed
        * SPEED * all_objs->factor_fps : 0;
        if (all_objs->obstacles[j].pos.x <= -200)
            all_objs->obstacles[j].pos.x = rand() % 1920 + 1920 * 2;
    }
}

void switch_obstacles(all_objects_t *all_objs, int nbr, int i)
{
    if (nbr == 1) {
        all_objs->obstacles[0].pos.x <= 0 ?
        (all_objs->obstacles[0].pos.x = 1920 + 50) :
        (all_objs->obstacles[4].pos.x = 1920 + 50);
    }
    if (nbr == 2) {
        all_objs->obstacles[1].pos.x <= 0 ?
        (all_objs->obstacles[1].pos.x = 1920 + 50) :
        (all_objs->obstacles[5].pos.x = 1920 + 50);
    }
    if (nbr == 3) {
        all_objs->obstacles[2].pos.x <= 0 ?
        (all_objs->obstacles[2].pos.x = 1920 + 50) :
        (all_objs->obstacles[6].pos.x = 1920 + 50);
    }
    if (nbr == 4) {
        all_objs->obstacles[3].pos.x <= 0 ?
        (all_objs->obstacles[3].pos.x = 1920 + 50) :
        (all_objs->obstacles[7].pos.x = 1920 + 50);
    }
}

void parallax_objs_map(beginning_t *begin, all_objects_t *all_objs, int i)
{
    int time = sfClock_getElapsedTime(all_objs->clock).microseconds;

    if (i != 2)
        return;
    if (time >= 120000) {
        switch_obstacles(all_objs, all_objs->map[all_objs->i] - 48, i);
        sfClock_restart(all_objs->clock);
        ++all_objs->i;
    }
    for (int j = 0; j < NBR_OBSTACLES; ++j)
        i == 2 ? all_objs->obstacles[j].pos.x -= all_objs->background[2].speed
        * SPEED * all_objs->factor_fps : 0;
}

void parallax(beginning_t *begin, all_objects_t *all_objs)
{
    float time;

    for (int i = 0; i < NBR_BACKGROUND; ++i) {
        time =
        sfClock_getElapsedTime(all_objs->background[i].clock).microseconds;
        if (time >= 10000) {
            all_objs->background[i].rect.left += all_objs->background[i].speed
            * SPEED * all_objs->factor_fps;
            sfClock_restart(all_objs->background[i].clock);
            all_objs->inf ? parallax_objs_rand(begin, all_objs, i) :
            parallax_objs_map(begin, all_objs, i);
        }
        if (all_objs->background[i].rect.left >= 3960)
            all_objs->background[i].rect.left = 0;
    }
    for (int j = 0; j < NBR_OBSTACLES; ++j)
        sfSprite_setPosition(all_objs->obstacles[j].sprite,
        all_objs->obstacles[j].pos);
}
