/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** init_objs.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

void init_background(beginning_t *begin, game_object_t *obj)
{
    // Sky
    obj[0].rect.top = 0;
    obj[0].rect.left = 0;
    obj[0].rect.width = 1920;
    obj[0].rect.height = 1080;
    obj[0].speed = 1;
    // Mountains
    obj[1].rect.top = 1080;
    obj[1].rect.left = 0;
    obj[1].rect.width = 1920;
    obj[1].rect.height = 1080;
    obj[1].speed = 2;
    // Floor
    obj[2].rect.top = 1080 * 2;
    obj[2].rect.left = 0;
    obj[2].rect.width = 1920;
    obj[2].rect.height = 1080;
    obj[2].speed = 3;
}

void init_perso(beginning_t *begin, game_object_t *obj)
{
    // Perso
    obj[3].rect.top = 0;
    obj[3].rect.left = 3840;
    obj[3].rect.width = 170;
    obj[3].rect.height = 200;
    obj[3].pos.x = 500;
    obj[3].pos.y = 900;
    obj[3].inc_pos = 0;
    obj[3].origin.x = 85;
    obj[3].origin.y = 67;
    sfSprite_setOrigin(obj[3].sprite, obj[3].origin);
    sfSprite_setPosition(obj[3].sprite, obj[3].pos);
}
