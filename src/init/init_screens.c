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
