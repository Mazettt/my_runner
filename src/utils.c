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
    beginning->window = sfRenderWindow_create(mode, "My runner",
    sfClose | sfFullscreen, NULL);
    beginning->framebuffer = my_framebuffer_create();
    beginning->texture = sfTexture_createFromFile("images/spritesheet.png",
    NULL);
}

sfMusic *set_music(void)
{
    sfMusic *music = sfMusic_createFromFile("music/back_on_track.ogg");

    sfMusic_setVolume(music, 0);
    sfMusic_play(music);
    return (music);
}

void destroy_all(beginning_t *begin, scoreboard_t *score, sfMusic *music)
{
    free(begin->framebuffer);
    sfRenderWindow_destroy(begin->window);
    sfMusic_destroy(music);
    put_backup(score->highest_score);
}
