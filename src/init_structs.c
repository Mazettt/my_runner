/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** init_structs.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

void init_events(events_t *events)
{
    events->left = 0;
    events->right = 0;
    events->up = 0;
    events->escape = 0;
    events->quit_game = 0;
    events->singleplayer = 0;
    events->options = 0;
}

void init_score(scoreboard_t *score)
{
    score->score = 0;
    score->title = 1;
    score->died = 0;
}
