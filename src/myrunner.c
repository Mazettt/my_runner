/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

int title_beginning(beginning_t *begin, all_objects_t *all_objs, scoreboard_t *score)
{
    sfSprite_setTexture(all_objs->screens[1].sprite, begin->texture, sfFalse);
    sfSprite_setTextureRect(all_objs->screens[1].sprite, all_objs->screens[1].rect);
}

void draw_sprites(beginning_t *begin, all_objects_t *all_objs, scoreboard_t *score,
events_t *events)
{
    !score->title ? sfRenderWindow_drawSprite(begin->window, all_objs->background[0].sprite, NULL) : 0;
    !score->title ? sfRenderWindow_drawSprite(begin->window, all_objs->background[1].sprite, NULL) : 0;
    !score->title ? sfRenderWindow_drawSprite(begin->window, all_objs->background[2].sprite, NULL) : 0;
    !score->title ? sfRenderWindow_drawSprite(begin->window, all_objs->perso.sprite, NULL) : 0;
    for (int i = 0; i < NBR_OBSTACLES; ++i)
        !score->title ? sfRenderWindow_drawSprite(begin->window, all_objs->obstacles[i].sprite, NULL) : 0;
    score->died ? sfRenderWindow_drawSprite(begin->window, all_objs->screens[0].sprite, NULL) : 0;
    score->title ? sfRenderWindow_drawSprite(begin->window, all_objs->screens[1].sprite, NULL) : 0;
}

void draw_texts(beginning_t *begin, scoreboard_t *score, fps_t *fps)
{
    score->died ? sfText_setString(score->legende.text, "Highest :") :
    sfText_setString(score->legende.text, "Highest : \nScore : ");
    sfText_setString(score->display_score.text, my_itoa(score->score));
    sfText_setString(score->died_text.text, my_itoa(score->score));
    sfText_setString(score->highest.text, my_itoa(score->highest_score));
    display_fps(fps, score, begin);
    !score->died ? sfRenderWindow_drawText(begin->window, score->display_score.text, NULL) : 0;
    sfRenderWindow_drawText(begin->window, score->legende.text, NULL);
    sfRenderWindow_drawText(begin->window, score->highest.text, NULL);
    !score->title && score->died ? sfRenderWindow_drawText(begin->window, score->died_text.text, NULL) : 0;
}

void increment_score(scoreboard_t *score)
{
    float time = sfClock_getElapsedTime(score->clock).microseconds;

    if (!score->title && !score->died && time >= 100000) {
        score->score += 1;
        sfClock_restart(score->clock);
    }
}

void big_while(beginning_t *begin, all_objects_t *all_objs, events_t *events,
scoreboard_t *score, fps_t *fps)
{
    sfRenderWindow_clear(begin->window, sfBlack);
    my_clear_framebuffer(begin->framebuffer, sfBlack);
    my_events(begin, events, score, all_objs);
    score->title ? title_beginning(begin, all_objs, score) : 0;
    get_fps(fps);
    get_factor(fps, all_objs);
    !score->title ? score->died = collisions(begin, all_objs, score) : 0;
    !score->died && !score->title ? parallax(begin, all_objs) : 0;
    !score->died && !score->title ? move_perso(begin, all_objs, events, fps) : 0;
    increment_score(score);
    all_objs->i >= 100 ? score->title = 1 : 0;
    draw_sprites(begin, all_objs, score, events);
    draw_texts(begin, score, fps);
    // printf("score->score = %d\n", score->score);
    sfRenderWindow_display(begin->window);
}

int myrunner(bool inf, char *filepath)
{
    all_objects_t all_objs;
    beginning_t beginning;
    scoreboard_t score;
    events_t events;
    fps_t fps;
    sfMusic *music = sfMusic_createFromFile("music/back_on_track.ogg");

    !inf ? getmap(&all_objs, filepath) : 0;
    all_objs.inf = inf;
    sfMusic_setVolume(music, 0);
    sfMusic_play(music);
    score.highest_score = get_backup();
    create_clocks(&all_objs, &score, &fps);
    all_beginning(&beginning);
    sfWindow_setFramerateLimit((sfWindow *)beginning.window, 30);
    init_all(&beginning, &all_objs, &events, &score);
    init_text(&beginning, &score, &fps);
    if (!beginning.window || !beginning.texture || !beginning.framebuffer)
        return (84);
    while (sfRenderWindow_isOpen(beginning.window))
        big_while(&beginning, &all_objs, &events, &score, &fps);
    free(beginning.framebuffer);
    put_backup(score.highest_score);
    sfRenderWindow_destroy(beginning.window);
    destroy_clocks(&all_objs, &score, &fps);
    sfMusic_destroy(music);
    return (0);
}
