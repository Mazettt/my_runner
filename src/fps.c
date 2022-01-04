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

int display_fps(fps_t *fps, scoreboard_t *score, beginning_t *begin)
{
    float time = sfClock_getElapsedTime(fps->display_clock).microseconds;
    int fps_int = get_fps(fps);

    if (time >= 500000) {
        sfText_setString(fps->fps_display.text, my_itoa(fps_int));
        sfClock_restart(fps->display_clock);
    }
    !score->title && !score->died ? sfRenderWindow_drawText(begin->window,
    fps->fps_display.text, NULL), sfRenderWindow_drawText(begin->window,
    fps->legende.text, NULL) : 0;
}
