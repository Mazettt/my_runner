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

    all_structs.all_objs.music = set_music("music/BattleAgainstaTrueHero.ogg",
    sfTrue);
    all_structs.all_objs.jump_music = set_music("music/jump.ogg", sfTrue);
    infini(inf, &all_structs.all_objs, filepath);
    create_clocks(&all_structs.all_objs, &all_structs.score, &all_structs.fps);
    all_beginning(&begin);
    init_all(&begin, &all_structs.all_objs, &all_structs.events,
    &all_structs.score);
    init_text(&begin, &all_structs.score, &all_structs.fps);
    sfWindow_setFramerateLimit((sfWindow *)begin.window, 60);
    if (!begin.window || !begin.texture || !begin.framebuffer)
        return (84);
    while (sfRenderWindow_isOpen(begin.window))
        big_loop(&begin, &all_structs);
    destroy_all(&begin, &all_structs.score, &all_structs.all_objs);
    destroy_clocks(&all_structs.all_objs, &all_structs.score, &all_structs.fps);
    return (0);
}
