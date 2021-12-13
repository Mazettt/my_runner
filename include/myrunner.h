/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner.h
*/

#ifndef MYRUNNER_H_
    #define MYRUNNER_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include "struct.h"

    #define WIDTH 1920
    #define HEIGHT 1080
    #define NBR_OBJ 4

int myrunner(void);
void manage_mouse_click(sfMouseButtonEvent event, beginning_t *begin);

// move
void parallax(beginning_t *begin, game_object_t *obj, sfClock *clock);

// init objs
void init_background(beginning_t *begin, game_object_t *obj);
void init_perso(beginning_t *begin, game_object_t *obj);

// utils
void my_clear_framebuffer(sfUint8 *framebuffer, sfColor color);
void all_beginning(beginning_t *beginning);
int my_events(beginning_t *begin);
sfColor my_rgb(sfColor color);
sfColor my_rgb_fast(sfColor color, int speed);

#endif