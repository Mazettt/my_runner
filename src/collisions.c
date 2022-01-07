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
        sfMusic_setVolume(music, VOLUME_DIED);
        sfMusic_play(music);
        do {
            time = sfClock_getElapsedTime(clock).microseconds;
        } while (time < 500000);
        sfClock_destroy(clock);
    }
}

int check_collision(beginning_t *begin, all_objects_t *all_objs,
scoreboard_t *score, sfFloatRect *panda_rocher)
{
    sfMusic *music = sfMusic_createFromFile("music/die.ogg");
    int test = score->died;

    if (sfFloatRect_intersects(&panda_rocher[0], &panda_rocher[1], NULL)) {
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
    sfMusic_destroy(music);
    return (0);
}

int collisions(beginning_t *begin, all_objects_t *all_objs, scoreboard_t *score)
{
    sfFloatRect panda_rocher[2];
    int ret = 0;

    panda_rocher[0] = sfSprite_getGlobalBounds(all_objs->perso.sprite);
    panda_rocher[0].top -= 10;
    panda_rocher[0].left -= 10;
    panda_rocher[0].height -= 10;
    panda_rocher[0].width -= 10;
    for (int i = 0; i < NBR_OBSTACLES; ++i) {
        panda_rocher[1] =
        sfSprite_getGlobalBounds(all_objs->obstacles[i].sprite);
        panda_rocher[1].top -= 10;
        panda_rocher[1].left -= 10;
        panda_rocher[1].height -= 10;
        panda_rocher[1].width -= 10;
        if (check_collision(begin, all_objs, score, panda_rocher) == 1)
            return (1);
    }
    return (0);
}
