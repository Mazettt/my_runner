/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** events.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"
#include "../include/my.h"

void events_key_pressed(sfEvent event, beginning_t *begin, events_t *all_events,
scoreboard_t *score)
{
    if (sfKeyEscape == event.key.code)
        score->title = 1;
    else if (sfKeySpace == event.key.code || sfKeyUp == event.key.code)
        all_events->up = 1;
    else if (sfKeyLeft == event.key.code || sfKeyQ == event.key.code)
        all_events->left = 1;
    else if (sfKeyRight == event.key.code || sfKeyD == event.key.code)
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

void mouse_passed(sfEvent event, events_t *events, scoreboard_t *score)
{
    if (score->title &&
    (event.mouseMove.x > 664 && event.mouseMove.x < 1316) &&
    (event.mouseMove.y > 404 && event.mouseMove.y < 468)) {
        events->singleplayer = 1;
    } else if (score->title &&
    (event.mouseMove.x < 664 || event.mouseMove.x > 1316) &&
    (event.mouseMove.y < 404 || event.mouseMove.y > 468)) {
        events->singleplayer = 0;
    }
    if (score->title &&
    (event.mouseMove.x > 998 && event.mouseMove.x < 1316) &&
    (event.mouseMove.y > 660 && event.mouseMove.y < 724)) {
        events->quit_game = 1;
    } else if (score->title &&
    (event.mouseMove.x < 998 || event.mouseMove.x > 1316) &&
    (event.mouseMove.y < 660 || event.mouseMove.y > 724)) {
        events->quit_game = 0;
    }
    my_put_nbr(events->singleplayer);
    my_putchar('\n');
    // if (score->title &&
    // (event.mouseMove.x < 998 && event.mouseMove.x > 1316) &&
    // (event.mouseMove.y < 660 && event.mouseMove.y > 724))

}

int my_events(beginning_t *begin, events_t *all_events, scoreboard_t *score,
all_objects_t *all_objs)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(begin->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(begin->window);
        else if (event.type == sfEvtKeyPressed)
            events_key_pressed(event, begin, all_events, score);
        else if (event.type == sfEvtKeyReleased)
            events_key_released(event, all_events);
        else if (event.type == sfEvtMouseButtonPressed)
            menu(event, score, begin, all_objs);
        // else if (event.type == sfEvtMouseMoved)
        //     mouse_passed(event, all_events, score);
    }
    return (0);
}
