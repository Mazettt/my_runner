/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** music.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

sfMusic *set_music(char *filepath)
{
    sfMusic *music = sfMusic_createFromFile(filepath);

    sfMusic_setVolume(music, 0);
    sfMusic_play(music);
    return (music);
}

void play_music(all_objects_t *all_objs, scoreboard_t *score, bool test_died,
bool test_title)
{
    if (!score->title && !score->died)
        sfMusic_setVolume(all_objs->music, 10);
    else
        sfMusic_setVolume(all_objs->music, 0);
    if ((test_died && !score->died) || (test_title && !score->title))
        sfMusic_play(all_objs->music);
}

void play_jump_sound(all_objects_t *all_objs)
{
    if (all_objs->perso.pos.y <= 900)
        sfMusic_setVolume(all_objs->jump_music, 10);
    else
        sfMusic_setVolume(all_objs->jump_music, 0);
}
