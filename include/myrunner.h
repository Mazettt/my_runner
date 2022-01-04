/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner.h
*/

#ifndef MYRUNNER_H_
    #define MYRUNNER_H_

    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <math.h>
    #include "struct.h"

int myrunner(bool inf, char *filepath);
char *my_itoa(int nb);
void getmap(all_objects_t *all_objs, char *filepath);
int display_fps(fps_t *fps, scoreboard_t *score, beginning_t *begin);

// move
void parallax(beginning_t *begin, all_objects_t *all_objs);
void move_perso(beginning_t *begin, all_objects_t *all_objs, events_t *events);

// collisions
int collisions(beginning_t *begin, all_objects_t *all_objs,
scoreboard_t *score);

// clocks
void create_clocks(all_objects_t *all_objs, scoreboard_t *score, fps_t *fps);
void destroy_clocks(all_objects_t *all_objs, scoreboard_t *score, fps_t *fps);

// init objs
void init_all(beginning_t *begin, all_objects_t *all_objs, events_t *events,
scoreboard_t *score);
void init_perso(beginning_t *begin, all_objects_t *all_objs);
void init_obstacle(beginning_t *begin, all_objects_t *all_objs);

// init screens
void init_background(beginning_t *begin, all_objects_t *all_objs);
void init_died_message(beginning_t *begin, all_objects_t *all_objs);
void init_title_screen(beginning_t *begin, all_objects_t *all_objs);
void init_highlight_singleplayer(beginning_t *begin, game_object_t *obj);
void init_highlight_options(beginning_t *begin, game_object_t *obj);
void init_highlight_quit_game(beginning_t *begin, game_object_t *obj);

// init text
void init_text(beginning_t *begin, scoreboard_t *score, fps_t *fps);

// init structs
void init_events(events_t *events);
void init_score(scoreboard_t *score);

// utils
void my_clear_framebuffer(sfUint8 *framebuffer, sfColor color);
void all_beginning(beginning_t *beginning);
int my_events(beginning_t *begin, events_t *all_events, scoreboard_t *score,
all_objects_t *all_objs);

// backup
int get_backup(void);
void put_backup(int nbr);

#endif
