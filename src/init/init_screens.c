/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** init_screens.c
*/

#include "../../include/myrunner.h"
#include "../../include/struct.h"

void init_background(beginning_t *begin, all_objects_t *all_objs)
{
    all_objs->background[0].rect.top = 0;
    all_objs->background[0].rect.left = 0;
    all_objs->background[0].rect.width = 1980;
    all_objs->background[0].rect.height = 1080;
    all_objs->background[0].speed = 1;
    all_objs->background[1].rect.top = 1080;
    all_objs->background[1].rect.left = 0;
    all_objs->background[1].rect.width = 1980;
    all_objs->background[1].rect.height = 1080;
    all_objs->background[1].speed = 2;
    all_objs->background[2].rect.top = 1080 * 2;
    all_objs->background[2].rect.left = 0;
    all_objs->background[2].rect.width = 1980;
    all_objs->background[2].rect.height = 1080;
    all_objs->background[2].speed = 3;
}

void init_died_message(beginning_t *begin, all_objects_t *all_objs)
{
    all_objs->screens[0].rect.top = 2160;
    all_objs->screens[0].rect.left = 5940;
    all_objs->screens[0].rect.width = 1920;
    all_objs->screens[0].rect.height = 1080;
}

void init_title_screen(beginning_t *begin, all_objects_t *all_objs)
{
    all_objs->screens[1].rect.top = 1080;
    all_objs->screens[1].rect.left = 5940;
    all_objs->screens[1].rect.width = 1920;
    all_objs->screens[1].rect.height = 1080;
}

// void init_highlight_singleplayer(beginning_t *begin, game_object_t *obj)
// {
//     obj[7].rect.top = 887;
//     obj[7].rect.left = 5940;
//     obj[7].rect.width = 652;
//     obj[7].rect.height = 65;
//     obj[7].pos.x = 664;
//     obj[7].pos.y = 435;
//     sfSprite_setPosition(obj[7].sprite, obj[7].pos);
// }

// void init_highlight_options(beginning_t *begin, game_object_t *obj)
// {
//     obj[8].rect.top = 952;
//     obj[8].rect.left = 5940;
//     obj[8].rect.width = 652;
//     obj[8].rect.height = 65;
//     obj[8].pos.x = 665;
//     obj[8].pos.y = 660;
//     sfSprite_setPosition(obj[8].sprite, obj[8].pos);
// }

// void init_highlight_quit_game(beginning_t *begin, game_object_t *obj)
// {
//     obj[9].rect.top = 1016;
//     obj[9].rect.left = 5940;
//     obj[9].rect.width = 652;
//     obj[9].rect.height = 65;
//     obj[9].pos.x = 665;
//     obj[9].pos.y = 660;
//     sfSprite_setPosition(obj[9].sprite, obj[9].pos);
// }
