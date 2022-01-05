/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** events.c
*/

#include "../../include/myrunner.h"
#include "../../include/struct.h"
#include "../../include/my.h"

void my_events(beginning_t *begin, events_t *all_events, scoreboard_t *score,
all_objects_t *all_objs)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(begin->window, &event))
        switch (event.type) {
            case sfEvtClosed:
                sfRenderWindow_close(begin->window);
                break;
            case sfEvtKeyPressed:
                events_key_pressed(event, begin, all_events, score);
                break;
            case sfEvtKeyReleased:
                events_key_released(event, all_events);
                break;
            case sfEvtMouseButtonPressed:
                menu(event, score, begin, all_objs);
                break;
            default:
                break;
        }
}
