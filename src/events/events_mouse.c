/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** events_mouse.c
*/

#include "../../include/myrunner.h"
#include "../../include/struct.h"
#include "../../include/my.h"

void respawn(sfEvent event, scoreboard_t *score, beginning_t *begin,
all_objects_t *all_objs)
{
    if ((event.mouseButton.x > 664 && event.mouseButton.x < 1317) &&
    (event.mouseButton.y > 436 && event.mouseButton.y < 500)) {
        init_perso(begin, all_objs);
        init_background(begin, all_objs);
        init_obstacle(begin, all_objs);
        score->died = 0;
        all_objs->i = 0;
    } else if ((event.mouseButton.x > 664 && event.mouseButton.x < 1317) &&
    (event.mouseButton.y > 514 && event.mouseButton.y < 579)) {
        init_background(begin, all_objs);
        init_obstacle(begin, all_objs);
        init_perso(begin, all_objs);
        score->title = 1;
    }
    score->score = 0;
}

void menu(sfEvent event, scoreboard_t *score, beginning_t *begin,
all_objects_t *all_objs)
{
    if (sfMouseLeft == event.key.code)
        if ((event.mouseButton.x > 864 && event.mouseButton.x < 1112) &&
        (event.mouseButton.y > 438 && event.mouseButton.y < 513)) {
            score->title = 0;
        }
        if (score->title &&
        (event.mouseButton.x > 899 && event.mouseButton.x < 1077) &&
        (event.mouseButton.y > 537 && event.mouseButton.y < 565))
            sfRenderWindow_close(begin->window);
        if (score->died)
            respawn(event, score, begin, all_objs);
}
