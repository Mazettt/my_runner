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

void init_obstacle(beginning_t *begin, all_objects_t *all_objs)
{
    sfVector2f scale;

    scale.x = 0.75;
    scale.y = 0.75;
    all_objs->obstacles[0].rect.top = 231;
    all_objs->obstacles[0].rect.left = 5940;
    all_objs->obstacles[0].rect.width = 116;
    all_objs->obstacles[0].rect.height = 122;
    all_objs->obstacles[0].pos.x = (!all_objs->inf ? -1000 : 1920);
    all_objs->obstacles[0].pos.y = 1010;
    all_objs->obstacles[0].origin.x = 116 / 2;
    all_objs->obstacles[0].origin.y = 122;
    sfSprite_setPosition(all_objs->obstacles[0].sprite, all_objs->obstacles[0].pos);
    sfSprite_setOrigin(all_objs->obstacles[0].sprite, all_objs->obstacles[0].origin);
    sfSprite_setScale(all_objs->obstacles[0].sprite, scale);
    all_objs->obstacles[1].rect.top = 167;
    all_objs->obstacles[1].rect.left = 6095;
    all_objs->obstacles[1].rect.width = 93;
    all_objs->obstacles[1].rect.height = 186;
    all_objs->obstacles[1].pos.x = (!all_objs->inf ? -1000 : 1920 + 1000);
    all_objs->obstacles[1].pos.y = 1010;
    all_objs->obstacles[1].origin.x = 93 / 2;
    all_objs->obstacles[1].origin.y = 186;
    sfSprite_setPosition(all_objs->obstacles[1].sprite, all_objs->obstacles[1].pos);
    sfSprite_setOrigin(all_objs->obstacles[1].sprite, all_objs->obstacles[1].origin);
    sfSprite_setScale(all_objs->obstacles[1].sprite, scale);
    all_objs->obstacles[2].rect.top = 149;
    all_objs->obstacles[2].rect.left = 6225;
    all_objs->obstacles[2].rect.width = 100;
    all_objs->obstacles[2].rect.height = 204;
    all_objs->obstacles[2].pos.x = (!all_objs->inf ? -1000 : 1920 + 2000);
    all_objs->obstacles[2].pos.y = 1010;
    all_objs->obstacles[2].origin.x = 100 / 2;
    all_objs->obstacles[2].origin.y = 204;
    sfSprite_setPosition(all_objs->obstacles[2].sprite, all_objs->obstacles[2].pos);
    sfSprite_setOrigin(all_objs->obstacles[2].sprite, all_objs->obstacles[2].origin);
    sfSprite_setScale(all_objs->obstacles[2].sprite, scale);
    all_objs->obstacles[3].rect.top = 194;
    all_objs->obstacles[3].rect.left = 6360;
    all_objs->obstacles[3].rect.width = 170;
    all_objs->obstacles[3].rect.height = 159;
    all_objs->obstacles[3].pos.x = (!all_objs->inf ? -1000 : 1920 + 3000);
    all_objs->obstacles[3].pos.y = 1010;
    all_objs->obstacles[3].origin.x = 170 / 2;
    all_objs->obstacles[3].origin.y = 159;
    sfSprite_setPosition(all_objs->obstacles[3].sprite, all_objs->obstacles[3].pos);
    sfSprite_setOrigin(all_objs->obstacles[3].sprite, all_objs->obstacles[3].origin);
    sfSprite_setScale(all_objs->obstacles[3].sprite, scale);
}

void init_all(beginning_t *begin, all_objects_t *all_objs, events_t *events,
scoreboard_t *score)
{
    all_objs->i = 0;
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
