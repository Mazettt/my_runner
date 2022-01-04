/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** collisions.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

void die_song(int test, scoreboard_t *score, sfMusic *music)
{
    sfClock *clock;
    int time = 0;

    if (test - score->died == -1) {
        clock = sfClock_create();
        sfMusic_setVolume(music, 30);
        sfMusic_play(music);
        do {
            time = sfClock_getElapsedTime(clock).microseconds;
        } while (time < 500000);
        sfClock_destroy(clock);
    }
}

int collisions(beginning_t *begin, all_objects_t *all_objs, scoreboard_t *score)
{
    sfFloatRect panda = sfSprite_getGlobalBounds(all_objs->perso.sprite);
    sfFloatRect rocher;
    sfMusic *music = sfMusic_createFromFile("music/die.ogg");
    int test = score->died;

    for (int i = 0; i < NBR_OBSTACLES; ++i) {
        rocher = sfSprite_getGlobalBounds(all_objs->obstacles[i].sprite);
        if (sfFloatRect_intersects(&panda, &rocher, NULL)) {
            score->died = 1;
            die_song(test, score, music);
            sfSprite_setTexture(all_objs->screens[0].sprite, begin->texture,
            sfFalse);
            sfSprite_setTextureRect(all_objs->screens[0].sprite,
            all_objs->screens[0].rect);
            if (score->score > score->highest_score)
                score->highest_score = score->score;
            sfMusic_destroy(music);
            return (1);
        }
    }
    sfMusic_destroy(music);
    return (0);
}