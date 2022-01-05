/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** init_obstacles.c
*/

#include "../../include/myrunner.h"
#include "../../include/struct.h"

void init_first_spike(beginning_t *begin, all_objects_t *all_objs,
sfVector2f scale)
{
    all_objs->obstacles[0].rect.top = 231;
    all_objs->obstacles[0].rect.left = 5940;
    all_objs->obstacles[0].rect.width = 116;
    all_objs->obstacles[0].rect.height = 122;
    all_objs->obstacles[0].pos.x = (!all_objs->inf ? -1000 : 1920);
    all_objs->obstacles[0].pos.y = 1010;
    all_objs->obstacles[0].origin.x = 116 / 2;
    all_objs->obstacles[0].origin.y = 122;
    sfSprite_setPosition(all_objs->obstacles[0].sprite,
    all_objs->obstacles[0].pos);
    sfSprite_setOrigin(all_objs->obstacles[0].sprite,
    all_objs->obstacles[0].origin);
    sfSprite_setScale(all_objs->obstacles[0].sprite, scale);
}

void init_second_spike(beginning_t *begin, all_objects_t *all_objs,
sfVector2f scale)
{
    all_objs->obstacles[1].rect.top = 167;
    all_objs->obstacles[1].rect.left = 6095;
    all_objs->obstacles[1].rect.width = 93;
    all_objs->obstacles[1].rect.height = 186;
    all_objs->obstacles[1].pos.x = (!all_objs->inf ? -1000 : 1920 + 1000);
    all_objs->obstacles[1].pos.y = 1010;
    all_objs->obstacles[1].origin.x = 93 / 2;
    all_objs->obstacles[1].origin.y = 186;
    sfSprite_setPosition(all_objs->obstacles[1].sprite,
    all_objs->obstacles[1].pos);
    sfSprite_setOrigin(all_objs->obstacles[1].sprite,
    all_objs->obstacles[1].origin);
    sfSprite_setScale(all_objs->obstacles[1].sprite, scale);
}

void init_third_spike(beginning_t *begin, all_objects_t *all_objs,
sfVector2f scale)
{
    all_objs->obstacles[2].rect.top = 149;
    all_objs->obstacles[2].rect.left = 6225;
    all_objs->obstacles[2].rect.width = 100;
    all_objs->obstacles[2].rect.height = 204;
    all_objs->obstacles[2].pos.x = (!all_objs->inf ? -1000 : 1920 + 2000);
    all_objs->obstacles[2].pos.y = 1010;
    all_objs->obstacles[2].origin.x = 100 / 2;
    all_objs->obstacles[2].origin.y = 204;
    sfSprite_setPosition(all_objs->obstacles[2].sprite,
    all_objs->obstacles[2].pos);
    sfSprite_setOrigin(all_objs->obstacles[2].sprite,
    all_objs->obstacles[2].origin);
    sfSprite_setScale(all_objs->obstacles[2].sprite, scale);
}

void init_fourth_spike(beginning_t *begin, all_objects_t *all_objs,
sfVector2f scale)
{
    all_objs->obstacles[3].rect.top = 194;
    all_objs->obstacles[3].rect.left = 6360;
    all_objs->obstacles[3].rect.width = 170;
    all_objs->obstacles[3].rect.height = 159;
    all_objs->obstacles[3].pos.x = (!all_objs->inf ? -1000 : 1920 + 3000);
    all_objs->obstacles[3].pos.y = 1010;
    all_objs->obstacles[3].origin.x = 170 / 2;
    all_objs->obstacles[3].origin.y = 159;
    sfSprite_setPosition(all_objs->obstacles[3].sprite,
    all_objs->obstacles[3].pos);
    sfSprite_setOrigin(all_objs->obstacles[3].sprite,
    all_objs->obstacles[3].origin);
    sfSprite_setScale(all_objs->obstacles[3].sprite, scale);
}

void init_obstacle(beginning_t *begin, all_objects_t *all_objs)
{
    sfVector2f scale;

    scale.x = 0.75;
    scale.y = 0.75;
    init_first_spike(begin, all_objs, scale);
    init_second_spike(begin, all_objs, scale);
    init_third_spike(begin, all_objs, scale);
    init_fourth_spike(begin, all_objs, scale);
}