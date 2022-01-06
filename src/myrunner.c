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
    all_t all_structs;
    beginning_t begin;
    sfMusic *music = set_music();

    infini(inf, &all_structs.all_objs, filepath);
    create_clocks(&all_structs.all_objs, &all_structs.score, &all_structs.fps);
    all_beginning(&begin);
    init_all(&begin, &all_structs.all_objs, &all_structs.events,
    &all_structs.score);
    init_text(&begin, &all_structs.score, &all_structs.fps);
    if (!begin.window || !begin.texture || !begin.framebuffer)
        return (84);
    while (sfRenderWindow_isOpen(begin.window))
        big_loop(&begin, &all_structs);
    destroy_all(&begin, &all_structs.score, music);
    destroy_clocks(&all_structs.all_objs, &all_structs.score, &all_structs.fps);
    return (0);
}
    // sfWindow_setFramerateLimit((sfWindow *)begin.window, 144);
