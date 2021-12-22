/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>

typedef struct beginning_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfUint8 *framebuffer;
    sfTexture *texture;
    sfSprite *sprite;
} beginning_t;

typedef struct text_s {
    sfFont *font;
    sfText *text;
    sfVector2f pos;
} text_t;

typedef struct scoreboard_s {
    text_t display_score;
    text_t highest;
    text_t legende;
    text_t died_text;
    int title;
    int died;
    int score;
    int highest_score;
    sfClock *clock;
} scoreboard_t;

typedef struct game_object_s {
    sfClock *clock;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f origin;
    sfVector2f pos;
    int inc_pos;
    int speed;
} game_object_t;

typedef struct all_objects_s {
    game_object_t background[3];
    game_object_t perso;
    game_object_t obstacles;
    game_object_t screens[2];
} all_objects_t;

typedef struct events_s {
    int left;
    int right;
    int up;
    int escape;
    int singleplayer;
    int options;
    int quit_game;
} events_t;

#endif
