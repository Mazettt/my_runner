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
    #include <stdbool.h>

    #define WIDTH 1920
    #define HEIGHT 1080
    #define NBR_OBJ 7
    #define NBR_BACKGROUND 3
    #define NBR_SCREENS 2
    #define NBR_OBSTACLES 4

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
    game_object_t background[NBR_BACKGROUND];
    game_object_t screens[NBR_SCREENS];
    game_object_t obstacles [NBR_OBSTACLES];
    game_object_t perso;
    char *map;
    int i;
    bool inf;
    sfClock *clock;
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

typedef struct fps_s {
    text_t fps_display;
    text_t legende;
    sfClock *clock;
    sfClock *display_clock;
    float time;
    int fps;
    int frame_counter;
} fps_t;

#endif
