/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** big_loop.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

int title_beginning(beginning_t *begin, all_objects_t *all_objs,
scoreboard_t *score)
{
    sfSprite_setTexture(all_objs->screens[1].sprite, begin->texture, sfFalse);
    sfSprite_setTextureRect(all_objs->screens[1].sprite,
    all_objs->screens[1].rect);
}

void increment_score(scoreboard_t *score, all_objects_t *all_objs)
{
    float time = sfClock_getElapsedTime(score->clock).microseconds;

    if (!score->title && !score->died && !score->won && all_objs->inf &&
    time >= 100000) {
        score->score += 1;
        sfClock_restart(score->clock);
    } else if (!score->title && !score->died && !score->won && !all_objs->inf &&
    time >= 100000)
        score->score = all_objs->i;
    if (score->score > score->highest_score)
        score->highest_score = score->score;
    !all_objs->inf && all_objs->i >= all_objs->size_map + 15 ?
    score->won = 1 : 0;
}

void draw_sprites(beginning_t *begin, all_objects_t *all_objs,
scoreboard_t *score, events_t *events)
{
    increment_score(score, all_objs);
    !score->title ? sfRenderWindow_drawSprite(begin->window,
    all_objs->background[0].sprite, NULL) : 0;
    !score->title ? sfRenderWindow_drawSprite(begin->window,
    all_objs->background[1].sprite, NULL) : 0;
    !score->title ? sfRenderWindow_drawSprite(begin->window,
    all_objs->background[2].sprite, NULL) : 0;
    !score->title ? sfRenderWindow_drawSprite(begin->window,
    all_objs->perso.sprite, NULL) : 0;
    for (int i = 0; i < NBR_OBSTACLES / (all_objs->inf + 1); ++i)
        !score->title && !score->won ? sfRenderWindow_drawSprite(begin->window,
        all_objs->obstacles[i].sprite, NULL) : 0;
    score->died ? sfRenderWindow_drawSprite(begin->window,
    all_objs->screens[0].sprite, NULL) : 0;
    score->won ? sfRenderWindow_drawSprite(begin->window,
    all_objs->screens[2].sprite, NULL) : 0;
    score->title ? sfRenderWindow_drawSprite(begin->window,
    all_objs->screens[1].sprite, NULL) : 0;
}

void draw_texts(beginning_t *begin, scoreboard_t *score, fps_t *fps)
{
    score->died ? sfText_setString(score->legende.text, "Highest :") :
    sfText_setString(score->legende.text, "Highest : \nScore : ");
    sfText_setString(score->display_score.text, my_itoa(score->score));
    sfText_setString(score->died_text.text, my_itoa(score->score));
    sfText_setString(score->highest.text, my_itoa(score->highest_score));
    display_fps(fps, score, begin);
    !score->died ? sfRenderWindow_drawText(begin->window,
    score->display_score.text, NULL) : 0;
    sfRenderWindow_drawText(begin->window, score->legende.text, NULL);
    sfRenderWindow_drawText(begin->window, score->highest.text, NULL);
    !score->title && (score->died || score->won) ?
    sfRenderWindow_drawText(begin->window, score->died_text.text, NULL) : 0;
}

void big_loop(beginning_t *begin, all_t *all_structs)
{
    events_t *events = &all_structs->events;
    scoreboard_t *score = &all_structs->score;
    all_objects_t *all_objs = &all_structs->all_objs;
    fps_t *fps = &all_structs->fps;
    bool test_title = (score->title == 1) ? true : false;
    bool test_died = (score->died == 1) ? true : false;

    clean_window(begin, sfBlack);
    my_events(begin, events, score, all_objs);
    get_factor(fps, all_objs);
    score->title ? title_beginning(begin, all_objs, score) : 0;
    !score->title && !score->won ?
    score->died = collisions(begin, all_objs, score) : 0;
    !score->died && !score->title ? parallax(begin, all_objs),
    move_perso(begin, all_objs, events, fps) : 0;
    draw_sprites(begin, all_objs, score, events);
    draw_texts(begin, score, fps);
    play_music(all_objs, score, test_died, test_title);
    sfRenderWindow_display(begin->window);
}
