/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** init_objs.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

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

void init_obstacle(beginning_t *begin, all_objects_t *all_objs)
{
    sfVector2f scale;

    scale.x = 0.25;
    scale.y = 0.25;
    all_objs->obstacles[0].rect.top = 154;
    all_objs->obstacles[0].rect.left = 5940;
    all_objs->obstacles[0].rect.width = 500;
    all_objs->obstacles[0].rect.height = 379;
    all_objs->obstacles[0].pos.x = 1920;
    all_objs->obstacles[0].pos.y = 960;
    all_objs->obstacles[0].origin.x = 250;
    all_objs->obstacles[0].origin.y = 174;
    sfSprite_setOrigin(all_objs->obstacles[0].sprite, all_objs->obstacles[0].origin);
    sfSprite_setPosition(all_objs->obstacles[0].sprite, all_objs->obstacles[0].pos);
    sfSprite_setScale(all_objs->obstacles[0].sprite, scale);
}

void init_all(beginning_t *begin, all_objects_t *all_objs, events_t *events,
scoreboard_t *score)
{
    for (int i = 0; i < NBR_BACKGROUND; ++i)
        all_objs->background[i].sprite = sfSprite_create();
    for (int i = 0; i < NBR_SCREENS; ++i)
        all_objs->screens[i].sprite = sfSprite_create();
    for (int i = 0; i < NBR_OBSTACLES; ++i)
        all_objs->obstacles[i].sprite = sfSprite_create();
    all_objs->perso.sprite = sfSprite_create();
    init_events(events);
    init_score(score);
    init_background(begin, all_objs);
    init_died_message(begin, all_objs);
    init_title_screen(begin, all_objs);
    // init_highlight_options(begin, obj);
    // init_highlight_quit_game(begin, obj);
    // init_highlight_singleplayer(begin, obj);
    init_perso(begin, all_objs);
    init_obstacle(begin, all_objs);
    init_text(begin, score);
    for (int i = 0; i < NBR_BACKGROUND; ++i)
        sfSprite_setTextureRect(all_objs->background[i].sprite, all_objs->background[i].rect);
    for (int i = 0; i < NBR_SCREENS; ++i)
        sfSprite_setTextureRect(all_objs->screens[i].sprite, all_objs->screens[i].rect);
    for (int i = 0; i < NBR_OBSTACLES; ++i)
        sfSprite_setTextureRect(all_objs->obstacles[i].sprite, all_objs->obstacles[i].rect);
    sfSprite_setTextureRect(all_objs->perso.sprite, all_objs->perso.rect);
    // for (int i = 0; i < NBR_OBJ; ++i)
    //     sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
}
