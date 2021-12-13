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
// #include "myrunner.h"

typedef struct beginning_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfUint8 *framebuffer;
    sfTexture *texture;
    sfSprite *sprite;
} beginning_t;

typedef struct scoreboard_s {
    int score;
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

#endif
