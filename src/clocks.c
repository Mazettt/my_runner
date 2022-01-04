/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** clocks.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

void create_clocks(all_objects_t *all_objs, scoreboard_t *score, fps_t *fps)
{
    score->clock = sfClock_create();
    fps->clock = sfClock_create();
    fps->display_clock = sfClock_create();
    all_objs->clock = sfClock_create();
    for (int i = 0; i < NBR_BACKGROUND; ++i)
        all_objs->background[i].clock = sfClock_create();
    for (int i = 0; i < NBR_SCREENS; ++i)
        all_objs->screens[i].clock = sfClock_create();
    for (int i = 0; i < NBR_OBSTACLES; ++i)
        all_objs->obstacles[i].clock = sfClock_create();
    all_objs->perso.clock = sfClock_create();
}

void destroy_clocks(all_objects_t *all_objs, scoreboard_t *score, fps_t *fps)
{
    for (int i = 0; i < NBR_BACKGROUND; ++i)
        sfClock_destroy(all_objs->background[i].clock);
    for (int i = 0; i < NBR_SCREENS; ++i)
        sfClock_destroy(all_objs->screens[i].clock);
    for (int i = 0; i < NBR_OBSTACLES; ++i)
        sfClock_destroy(all_objs->obstacles[i].clock);
    sfClock_destroy(all_objs->perso.clock);
    sfClock_destroy(score->clock);
    sfClock_destroy(fps->clock);
    sfClock_destroy(fps->display_clock);
}
