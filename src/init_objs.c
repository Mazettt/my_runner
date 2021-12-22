/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** init_objs.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

void init_perso(beginning_t *begin, game_object_t *obj)
{
    obj[3].rect.top = 0;
    obj[3].rect.left = 5940;
    obj[3].rect.width = 178;
    obj[3].rect.height = 148;
    obj[3].pos.x = 500;
    obj[3].pos.y = 930;
    obj[3].inc_pos = 0;
    obj[3].origin.x = 89;
    obj[3].origin.y = 74;
    sfSprite_setOrigin(obj[3].sprite, obj[3].origin);
    sfSprite_setPosition(obj[3].sprite, obj[3].pos);
}

void init_obstacle(beginning_t *begin, game_object_t *obj)
{
    obj[4].rect.top = 154;
    obj[4].rect.left = 5940;
    obj[4].rect.width = 500;
    obj[4].rect.height = 379;
    obj[4].pos.x = 1920;
    obj[4].pos.y = 960;
    obj[4].origin.x = 250;
    obj[4].origin.y = 174;
    sfSprite_setOrigin(obj[4].sprite, obj[4].origin);
    sfSprite_setPosition(obj[4].sprite, obj[4].pos);
}

void init_all(beginning_t *begin, game_object_t *obj, events_t *events,
scoreboard_t *score)
{
    sfVector2f scale;

    scale.x = 0.25;
    scale.y = 0.25;
    for (int i = 0; i < NBR_OBJ; ++i)
        obj[i].sprite = sfSprite_create();
    init_events(events);
    init_score(score);
    init_background(begin, obj);
    init_died_message(begin, obj);
    init_title_screen(begin, obj);
    // init_highlight_options(begin, obj);
    // init_highlight_quit_game(begin, obj);
    // init_highlight_singleplayer(begin, obj);
    init_perso(begin, obj);
    init_obstacle(begin, obj);
    init_text(begin, score);
    sfSprite_setScale(obj[4].sprite, scale);
    for (int i = 0; i < NBR_OBJ; ++i)
        sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
}
