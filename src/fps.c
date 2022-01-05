/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** fps.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

int get_fps(fps_t *fps)
{
    fps->time = sfClock_getElapsedTime(fps->clock).microseconds;
    fps->fps = 1 / (fps->time / 1000000);
    sfClock_restart(fps->clock);
    return (fps->fps);
}

void display_fps(fps_t *fps, scoreboard_t *score, beginning_t *begin)
{
    float time = sfClock_getElapsedTime(fps->display_clock).microseconds;

    if (time >= 500000) {
        sfText_setString(fps->fps_display.text, my_itoa(fps->fps));
        sfClock_restart(fps->display_clock);
    }
    !score->title && !score->died ? sfRenderWindow_drawText(begin->window,
    fps->fps_display.text, NULL), sfRenderWindow_drawText(begin->window,
    fps->legende.text, NULL) : 0;
}

void get_factor(fps_t *fps, all_objects_t *all_objs)
{
    all_objs->factor_fps = sqrtf((float)200 / (float)fps->fps);
}
