/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

void init_objs(beginning_t *begin, game_object_t *obj)
{
    sfVector2f scale;

    scale.x = 0.25;
    scale.y = 0.25;
    for (int i = 0; i < NBR_OBJ; ++i)
        obj[i].sprite = sfSprite_create();
    init_background(begin, obj);
    init_perso(begin, obj);
    init_obstacle(begin, obj);
    init_died_message(begin, obj);
    init_title_screen(begin, obj);
    sfSprite_setScale(obj[4].sprite, scale);
    for (int i = 0; i < NBR_OBJ; ++i) {
        sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
    }
}

void init_events(events_t *events)
{
    events->left = 0;
    events->right = 0;
    events->up = 0;
    events->escape = 0;
}

void init_score(scoreboard_t *score)
{
    score->score = 0;
    score->highest_score = 0;
    score->title = 0;
    score->died = 0;
}

void move_perso(beginning_t *begin, game_object_t *obj, events_t *events)
{
    float time = sfClock_getElapsedTime(obj[3].clock).microseconds;
    int offset = 5940;
    int max_value = 5940 + 1600;

    if (events->left && obj[3].pos.x != 50)
        obj[3].pos.x -= 2;

    if (events->right && obj[3].pos.x != 1850)
        obj[3].pos.x += 2;

    if (events->up && obj[3].pos.y >= 900) {
        obj[3].inc_pos = -2;
        obj[3].rect.left = 5940 + 1246;
    }
    obj[3].pos.y += obj[3].inc_pos;
    if (obj[3].pos.y <= 730)
        obj[3].inc_pos = 2;
    if (obj[3].pos.y >= 930) {
        obj[3].inc_pos = 0;
        if (time >= 100000) {
            obj[3].rect.left += 178;
            sfClock_restart(obj[3].clock);
        }
    }
    if (obj[3].rect.left >= max_value)
        obj[3].rect.left = offset;
    sfSprite_setPosition(obj[3].sprite, obj[3].pos);
    for (int i = 0; i < NBR_OBJ - 1; ++i) {
        sfSprite_setTexture(obj[i].sprite, begin->texture, sfFalse);
        sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
    }
}

int collisions(beginning_t *begin, game_object_t *obj, scoreboard_t *score)
{
    sfFloatRect panda = sfSprite_getGlobalBounds(obj[3].sprite);
    sfFloatRect rocher = sfSprite_getGlobalBounds(obj[4].sprite);

    if (sfFloatRect_intersects(&panda, &rocher, NULL)) {
        sfSprite_setTexture(obj[5].sprite, begin->texture, sfFalse);
        sfSprite_setTextureRect(obj[5].sprite, obj[5].rect);
        if (score->score > score->highest_score)
            score->highest_score = score->score;
        // sfRenderWindow_drawSprite(begin->window, obj[5].sprite, NULL);
        return (1);
    } else
        return (0);
}

int title_beginning(beginning_t *begin, game_object_t *obj, scoreboard_t *score)
{
    sfSprite_setTexture(obj[6].sprite, begin->texture, sfFalse);
    sfSprite_setTextureRect(obj[6].sprite, obj[6].rect);
    // sfRenderWindow_drawSprite(begin->window, obj[6].sprite, NULL);
}

// void my_putpixel(int x, int y, sfUint8 *framebuffer, sfColor color)
// {
//     x <= 0 ? x = 1, color.a = 0: x;
//     x >= HEIGHT ? x = HEIGHT - 2, color.a = 0 : x;
//     y <= 0 ? y = 1, color.a = 0 : y;
//     y >= WIDTH ? y = WIDTH - 2, color.a = 0 : y;
//     *(sfColor *)(4 * (x * WIDTH + y) + framebuffer) = color;
// }

void draw_sprites(beginning_t *begin, game_object_t *obj, scoreboard_t *score)
{
    score->title ? sfRenderWindow_drawSprite(begin->window, obj[0].sprite, NULL) : 0;
    score->title ? sfRenderWindow_drawSprite(begin->window, obj[1].sprite, NULL) : 0;
    score->title ? sfRenderWindow_drawSprite(begin->window, obj[2].sprite, NULL) : 0;
    score->title ? sfRenderWindow_drawSprite(begin->window, obj[3].sprite, NULL) : 0;
    score->title ? sfRenderWindow_drawSprite(begin->window, obj[4].sprite, NULL) : 0;
    score->died ? sfRenderWindow_drawSprite(begin->window, obj[5].sprite, NULL) : 0;
    !score->title ? sfRenderWindow_drawSprite(begin->window, obj[6].sprite, NULL) : 0;
}

char *my_itoa(int nb)
{
    int i = 0;
    char *str;
    int tmp = nb;

    while (tmp > 0) {
        tmp /= 10;
        ++i;
    }
    str = malloc(sizeof(str) * (i + 1));
    str[i] = '\0';
    while (i > 0) {
        i--;
        str[i] = nb % 10 + 48;
        nb /= 10;
    }
    return (str);
}

void big_while(beginning_t *begin, game_object_t *obj, events_t *events, scoreboard_t *score)
{
    float time;

    sfRenderWindow_clear(begin->window, sfBlack);
    my_clear_framebuffer(begin->framebuffer, sfBlack);
    my_events(begin, events, score, obj);
    !score->title ? title_beginning(begin, obj, score) : 0;
    score->title ? score->died = collisions(begin, obj, score) : 0;
    !score->died && score->title ? parallax(begin, obj) : 0;
    !score->died && score->title ? move_perso(begin, obj, events) : 0;
    time = sfClock_getElapsedTime(score->clock).microseconds;
    if (score->title && !score->died && time >= 100000) {
        score->score += 1;
        sfClock_restart(score->clock);
    }
    draw_sprites(begin, obj, score);
    sfText_setString(score->display_score.text, my_itoa(score->score));
    sfText_setString(score->died_text.text, my_itoa(score->score));
    sfText_setString(score->highest.text, my_itoa(score->highest_score));
    sfRenderWindow_drawText(begin->window, score->display_score.text, NULL);
    sfRenderWindow_drawText(begin->window, score->legende.text, NULL);
    sfRenderWindow_drawText(begin->window, score->highest.text, NULL);
    score->died ? sfRenderWindow_drawText(begin->window, score->died_text.text, NULL) : 0;
    sfRenderWindow_display(begin->window);
}

int myrunner(void)
{
    beginning_t beginning;
    game_object_t *obj = malloc(sizeof(game_object_t) * NBR_OBJ);
    events_t events;
    scoreboard_t score;

    // sfMusic *music = sfMusic_createFromFile("music/toe.ogg");
    // sfMusic_setVolume(music, 20);
    // sfMusic_play(music);

    score.clock = sfClock_create();
    for (int i = 0; i < NBR_OBJ; ++i)
        obj[i].clock = sfClock_create();
    all_beginning(&beginning);
    init_score(&score);
    init_events(&events);
    init_objs(&beginning, obj);
    init_text(&beginning, &score);
    if (!beginning.window)
        return (84);
    while (sfRenderWindow_isOpen(beginning.window))
        big_while(&beginning, obj, &events, &score);
    free(beginning.framebuffer);
    sfRenderWindow_destroy(beginning.window);
    for (int i = 0; i < NBR_OBJ; ++i)
        sfClock_destroy(obj[i].clock);
    sfClock_destroy(score.clock);
    // sfMusic_destroy(music);
    return (0);
}
