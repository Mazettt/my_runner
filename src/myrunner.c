/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

void move_perso(beginning_t *begin, all_objects_t *all_objs, events_t *events)
{
    float time = sfClock_getElapsedTime(all_objs->perso.clock).microseconds;
    int offset = 5940;
    int max_value = 5940 + 1600;

    if (events->left && all_objs->perso.pos.x != 50)
        all_objs->perso.pos.x -= 2;
    if (events->right && all_objs->perso.pos.x != 1850)
        all_objs->perso.pos.x += 2;
    if (events->up && all_objs->perso.pos.y >= 900) {
        all_objs->perso.inc_pos = -2;
        all_objs->perso.rect.left = 5940 + 1246;
    }
    all_objs->perso.pos.y += all_objs->perso.inc_pos;
    if (all_objs->perso.pos.y <= 730)
        all_objs->perso.inc_pos = 2;
    if (all_objs->perso.pos.y >= 930) {
        all_objs->perso.inc_pos = 0;
        if (time >= 100000) {
            all_objs->perso.rect.left += 178;
            sfClock_restart(all_objs->perso.clock);
        }
    }
    if (all_objs->perso.rect.left >= max_value)
        all_objs->perso.rect.left = offset;
    sfSprite_setPosition(all_objs->perso.sprite, all_objs->perso.pos);
    for (int i = 0; i < NBR_BACKGROUND; ++i) {
        sfSprite_setTexture(all_objs->background[i].sprite, begin->texture, sfFalse);
        sfSprite_setTextureRect(all_objs->background[i].sprite, all_objs->background[i].rect);
    }
    for (int i = 0; i < NBR_SCREENS; ++i) {
        sfSprite_setTexture(all_objs->screens[i].sprite, begin->texture, sfFalse);
        sfSprite_setTextureRect(all_objs->screens[i].sprite, all_objs->screens[i].rect);
    }
    for (int i = 0; i < NBR_OBSTACLES; ++i) {
        sfSprite_setTexture(all_objs->obstacles[i].sprite, begin->texture, sfFalse);
        sfSprite_setTextureRect(all_objs->obstacles[i].sprite, all_objs->obstacles[i].rect);
    }
    sfSprite_setTexture(all_objs->perso.sprite, begin->texture, sfFalse);
    sfSprite_setTextureRect(all_objs->perso.sprite, all_objs->perso.rect);
}

int collisions(beginning_t *begin, all_objects_t *all_objs, scoreboard_t *score)
{
    sfFloatRect panda = sfSprite_getGlobalBounds(all_objs->perso.sprite);
    sfFloatRect rocher = sfSprite_getGlobalBounds(all_objs->obstacles[0].sprite);

    if (sfFloatRect_intersects(&panda, &rocher, NULL)) {
        sfSprite_setTexture(all_objs->screens[0].sprite, begin->texture, sfFalse);
        sfSprite_setTextureRect(all_objs->screens[0].sprite, all_objs->screens[0].rect);
        if (score->score > score->highest_score)
            score->highest_score = score->score;
        return (1);
    } else
        return (0);
}

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
    !score->title ? sfRenderWindow_drawSprite(begin->window, all_objs->obstacles[0].sprite, NULL) : 0;
    score->died ? sfRenderWindow_drawSprite(begin->window, all_objs->screens[0].sprite, NULL) : 0;
    score->title ? sfRenderWindow_drawSprite(begin->window, all_objs->screens[1].sprite, NULL) : 0;
}

void big_while(beginning_t *begin, all_objects_t *all_objs, events_t *events, scoreboard_t *score)
{
    float time;

    sfRenderWindow_clear(begin->window, sfBlack);
    my_clear_framebuffer(begin->framebuffer, sfBlack);
    my_events(begin, events, score, all_objs);
    score->title ? title_beginning(begin, all_objs, score) : 0;
    !score->title ? score->died = collisions(begin, all_objs, score) : 0;
    !score->died && !score->title ? parallax(begin, all_objs) : 0;
    !score->died && !score->title ? move_perso(begin, all_objs, events) : 0;
    time = sfClock_getElapsedTime(score->clock).microseconds;
    if (!score->title && !score->died && time >= 100000) {
        score->score += 1;
        sfClock_restart(score->clock);
    }
    draw_sprites(begin, all_objs, score, events);
    sfText_setString(score->display_score.text, my_itoa(score->score));
    sfText_setString(score->died_text.text, my_itoa(score->score));
    sfText_setString(score->highest.text, my_itoa(score->highest_score));
    sfRenderWindow_drawText(begin->window, score->display_score.text, NULL);
    sfRenderWindow_drawText(begin->window, score->legende.text, NULL);
    sfRenderWindow_drawText(begin->window, score->highest.text, NULL);
    score->died ? sfRenderWindow_drawText(begin->window, score->died_text.text, NULL) : 0;
    sfRenderWindow_display(begin->window);
}

void create_clocks(all_objects_t *all_objs)
{
    for (int i = 0; i < NBR_BACKGROUND; ++i)
        all_objs->background[i].clock = sfClock_create();
    for (int i = 0; i < NBR_SCREENS; ++i)
        all_objs->screens[i].clock = sfClock_create();
    for (int i = 0; i < NBR_OBSTACLES; ++i)
        all_objs->obstacles[i].clock = sfClock_create();
    all_objs->perso.clock = sfClock_create();
}

void destroy_clocks(all_objects_t *all_objs)
{
    for (int i = 0; i < NBR_BACKGROUND; ++i)
        sfClock_destroy(all_objs->background[i].clock);
    for (int i = 0; i < NBR_SCREENS; ++i)
        sfClock_destroy(all_objs->screens[i].clock);
    for (int i = 0; i < NBR_OBSTACLES; ++i)
        sfClock_destroy(all_objs->obstacles[i].clock);
    sfClock_destroy(all_objs->perso.clock);
}

int myrunner(bool inf)
{
    beginning_t beginning;
    all_objects_t all_objs;
    events_t events;
    scoreboard_t score;

    sfMusic *music = sfMusic_createFromFile("music/back_on_track.ogg");
    sfMusic_setVolume(music, 5);
    sfMusic_play(music);

    score.highest_score = get_backup();
    score.clock = sfClock_create();
    create_clocks(&all_objs);
    all_beginning(&beginning);
    init_all(&beginning, &all_objs, &events, &score);
    if (!beginning.window)
        return (84);
    while (sfRenderWindow_isOpen(beginning.window))
        big_while(&beginning, &all_objs, &events, &score);
    free(beginning.framebuffer);
    put_backup(score.highest_score);
    sfRenderWindow_destroy(beginning.window);
    destroy_clocks(&all_objs);
    sfClock_destroy(score.clock);
    sfMusic_destroy(music);
    return (0);
}
