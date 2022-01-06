/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** init_objs.c
*/

#include "../../include/myrunner.h"
#include "../../include/struct.h"

#define HAUTEUR 20

void init_perso(beginning_t *begin, all_objects_t *all_objs)
{
    all_objs->perso.rect.top = 0;
    all_objs->perso.rect.left = 5940;
    all_objs->perso.rect.width = 178;
    all_objs->perso.rect.height = 148;
    all_objs->perso.pos.x = 500;
    all_objs->perso.pos.y = 930;
    all_objs->perso.inc_pos = 0;
    all_objs->perso.origin.x = 89;
    all_objs->perso.origin.y = 74;
    sfSprite_setOrigin(all_objs->perso.sprite, all_objs->perso.origin);
    sfSprite_setPosition(all_objs->perso.sprite, all_objs->perso.pos);
}

void create_sprites(beginning_t *begin, all_objects_t *all_objs,
events_t *events, scoreboard_t *score)
{
    for (int i = 0; i < NBR_BACKGROUND; ++i)
        all_objs->background[i].sprite = sfSprite_create();
    for (int i = 0; i < NBR_SCREENS; ++i)
        all_objs->screens[i].sprite = sfSprite_create();
    for (int i = 0; i < NBR_OBSTACLES; ++i)
        all_objs->obstacles[i].sprite = sfSprite_create();
    all_objs->perso.sprite = sfSprite_create();
}

void set_textures_rect(beginning_t *begin, all_objects_t *all_objs,
events_t *events, scoreboard_t *score)
{
    for (int i = 0; i < NBR_BACKGROUND; ++i)
        sfSprite_setTextureRect(all_objs->background[i].sprite,
        all_objs->background[i].rect);
    for (int i = 0; i < NBR_SCREENS; ++i)
        sfSprite_setTextureRect(all_objs->screens[i].sprite,
        all_objs->screens[i].rect);
    for (int i = 0; i < NBR_OBSTACLES; ++i)
        sfSprite_setTextureRect(all_objs->obstacles[i].sprite,
        all_objs->obstacles[i].rect);
    sfSprite_setTextureRect(all_objs->perso.sprite, all_objs->perso.rect);
}

void init_all(beginning_t *begin, all_objects_t *all_objs, events_t *events,
scoreboard_t *score)
{
    score->highest_score = get_backup();
    all_objs->i = 0;
    create_sprites(begin, all_objs, events, score);
    init_events(events);
    init_score(score);
    init_background(begin, all_objs);
    init_died_message(begin, all_objs);
    init_won_message(begin, all_objs);
    init_title_screen(begin, all_objs);
    init_perso(begin, all_objs);
    init_obstacle(begin, all_objs);
    set_textures_rect(begin, all_objs, events, score);
}
