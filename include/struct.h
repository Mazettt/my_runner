/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdio.h>
    #include <math.h>

    #define WIDTH 1920
    #define HEIGHT 1080
    #define NBR_BACKGROUND 3
    #define NBR_OBSTACLES 8
    #define NBR_SCREENS 3
    #define NBR_OBJ 7
    #define VOLUME_MUSIC 10
    #define VOLUME_DIED 40
    #define VOLUME_JUMP 10

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
    int won;
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
    int size_map;
    int i;
    bool inf;
    float factor_fps;
    sfClock *clock;
    sfMusic *music;
    sfMusic *jump_music;
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

typedef struct all_s {
    all_objects_t all_objs;
    events_t events;
    scoreboard_t score;
    fps_t fps;
} all_t;

#endif
