/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

void infini(bool inf, all_objects_t *all_objs, char *filepath)
{
    if (!inf)
        getmap(all_objs, filepath);
    all_objs->inf = inf;
}

int myrunner(bool inf, char *filepath)
{
    all_objects_t all_objs;
    beginning_t begin;
    scoreboard_t score;
    events_t events;
    fps_t fps;
    sfMusic *music = set_music();

    infini(inf, &all_objs, filepath);
    create_clocks(&all_objs, &score, &fps);
    all_beginning(&begin);
    init_all(&begin, &all_objs, &events, &score);
    init_text(&begin, &score, &fps);
    // sfWindow_setFramerateLimit((sfWindow *)begin.window, 144);
    if (!begin.window || !begin.texture || !begin.framebuffer)
        return (84);
    while (sfRenderWindow_isOpen(begin.window))
        big_loop(&begin, &all_objs, &events, &score, &fps);
    destroy_all(&begin, &score, music);
    destroy_clocks(&all_objs, &score, &fps);
    return (0);
}
