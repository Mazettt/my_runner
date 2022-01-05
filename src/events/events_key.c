/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** events_key.c
*/

#include "../../include/myrunner.h"
#include "../../include/struct.h"
#include "../../include/my.h"

void events_key_pressed(sfEvent event, beginning_t *begin, events_t *all_events,
scoreboard_t *score)
{
    if (sfKeyEscape == event.key.code)
        score->title = 1;
    if (sfKeySpace == event.key.code || sfKeyUp == event.key.code)
        all_events->up = 1;
    if (sfKeyLeft == event.key.code || sfKeyQ == event.key.code)
        all_events->left = 1;
    if (sfKeyRight == event.key.code || sfKeyD == event.key.code)
        all_events->right = 1;
}

void events_key_released(sfEvent event, events_t *all_events)
{
    if (sfKeySpace == event.key.code || sfKeyUp == event.key.code)
        all_events->up = 0;
    else if (sfKeyLeft == event.key.code || sfKeyQ == event.key.code)
        all_events->left = 0;
    else if (sfKeyRight == event.key.code || sfKeyD == event.key.code)
        all_events->right = 0;
}
