/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** move_perso.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

void set_all_textures(beginning_t *begin, all_objects_t *all_objs,
events_t *events)
{
    for (int i = 0; i < NBR_BACKGROUND; ++i) {
        sfSprite_setTexture(all_objs->background[i].sprite,
        begin->texture, sfFalse);
        sfSprite_setTextureRect(all_objs->background[i].sprite,
        all_objs->background[i].rect);
    }
    for (int i = 0; i < NBR_SCREENS; ++i) {
        sfSprite_setTexture(all_objs->screens[i].sprite,
        begin->texture, sfFalse);
        sfSprite_setTextureRect(all_objs->screens[i].sprite,
        all_objs->screens[i].rect);
    }
    for (int i = 0; i < NBR_OBSTACLES; ++i) {
        sfSprite_setTexture(all_objs->obstacles[i].sprite,
        begin->texture, sfFalse);
        sfSprite_setTextureRect(all_objs->obstacles[i].sprite,
        all_objs->obstacles[i].rect);
    }
    sfSprite_setTexture(all_objs->perso.sprite, begin->texture, sfFalse);
    sfSprite_setTextureRect(all_objs->perso.sprite, all_objs->perso.rect);
}

void change_animation(beginning_t *begin, all_objects_t *all_objs)
{
    float time = sfClock_getElapsedTime(all_objs->perso.clock).microseconds;

    if (all_objs->perso.pos.y >= 930) {
        all_objs->perso.inc_pos = 0;
        if (time >= 100000) {
            all_objs->perso.rect.left += 178;
            sfClock_restart(all_objs->perso.clock);
        }
    }
}

void movements(beginning_t *begin, all_objects_t *all_objs, events_t *events,
fps_t *fps)
{
    if (events->left && all_objs->perso.pos.x != 50)
        all_objs->perso.pos.x -= 2 * all_objs->factor_fps *
        sqrt(all_objs->factor_fps);
    if (events->right && all_objs->perso.pos.x != 1850)
        all_objs->perso.pos.x += 2 * all_objs->factor_fps *
        sqrt(all_objs->factor_fps);
    if (events->up && all_objs->perso.pos.y >= 900) {
        all_objs->perso.inc_pos = -3 * all_objs->factor_fps *
        sqrt(all_objs->factor_fps);
        all_objs->perso.rect.left = 5940 + 1246;
    }
}

void move_perso(beginning_t *begin, all_objects_t *all_objs, events_t *events,
fps_t *fps)
{
    movements(begin, all_objs, events, fps);
    if (!events->up && all_objs->perso.pos.y < 900)
        all_objs->perso.inc_pos = 3 * all_objs->factor_fps *
        sqrt(all_objs->factor_fps);
    all_objs->perso.pos.y += all_objs->perso.inc_pos;
    if (all_objs->perso.pos.y <= 600)
        all_objs->perso.inc_pos = 3 * all_objs->factor_fps *
        sqrt(all_objs->factor_fps);
    change_animation(begin, all_objs);
    if (all_objs->perso.rect.left >= 5940 + 1600)
        all_objs->perso.rect.left = 5940;
    sfSprite_setPosition(all_objs->perso.sprite, all_objs->perso.pos);
    set_all_textures(begin, all_objs, events);
}
