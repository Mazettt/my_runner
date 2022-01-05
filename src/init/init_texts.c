/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** init_texts.c
*/

#include "../../include/myrunner.h"
#include "../../include/struct.h"

void init_scores(beginning_t *begin, scoreboard_t *score)
{
    score->display_score.pos.x = 135;
    score->display_score.pos.y = 60;
    score->display_score.font = sfFont_createFromFile("fonts/JungleAdventurer.otf");
    score->display_score.text = sfText_create();
    sfText_setFont(score->display_score.text, score->display_score.font);
    sfText_setColor(score->display_score.text, sfWhite);
    sfText_setCharacterSize(score->display_score.text, 30);
    sfText_setPosition(score->display_score.text, score->display_score.pos);
    score->died_text.pos.x = 1020;
    score->died_text.pos.y = 317;
    score->died_text.font = sfFont_createFromFile("fonts/JungleAdventurer.otf");
    score->died_text.text = sfText_create();
    sfText_setFont(score->died_text.text, score->died_text.font);
    sfText_setColor(score->died_text.text, sfWhite);
    sfText_setCharacterSize(score->died_text.text, 35);
    sfText_setPosition(score->died_text.text, score->died_text.pos);
}
void init_highest(beginning_t *begin, scoreboard_t *score)
{
    score->highest.pos.x = 155;
    score->highest.pos.y = 30;
    score->highest.font = sfFont_createFromFile("fonts/JungleAdventurer.otf");
    score->highest.text = sfText_create();
    sfText_setFont(score->highest.text, score->highest.font);
    sfText_setColor(score->highest.text, sfWhite);
    sfText_setCharacterSize(score->highest.text, 30);
    sfText_setPosition(score->highest.text, score->highest.pos);
}

void init_legende(beginning_t *begin, scoreboard_t *score)
{
    score->legende.pos.x = 30;
    score->legende.pos.y = 30;
    score->legende.font = sfFont_createFromFile("fonts/JungleAdventurer.otf");
    score->legende.text = sfText_create();
    sfText_setFont(score->legende.text, score->legende.font);
    sfText_setColor(score->legende.text, sfWhite);
    sfText_setCharacterSize(score->legende.text, 30);
    sfText_setPosition(score->legende.text, score->legende.pos);
    sfText_setString(score->legende.text, "Highest : \nScore : ");
}

void init_fps(beginning_t *begin, fps_t *fps)
{
    fps->fps_display.pos.x = 80;
    fps->fps_display.pos.y = 1040;
    fps->fps_display.font = sfFont_createFromFile("fonts/JungleAdventurer.otf");
    fps->fps_display.text = sfText_create();
    sfText_setFont(fps->fps_display.text, fps->fps_display.font);
    sfText_setColor(fps->fps_display.text, sfWhite);
    sfText_setCharacterSize(fps->fps_display.text, 20);
    sfText_setPosition(fps->fps_display.text, fps->fps_display.pos);
    fps->legende.pos.x = 30;
    fps->legende.pos.y = 1040;
    fps->legende.font = sfFont_createFromFile("fonts/JungleAdventurer.otf");
    fps->legende.text = sfText_create();
    sfText_setFont(fps->legende.text, fps->legende.font);
    sfText_setColor(fps->legende.text, sfWhite);
    sfText_setCharacterSize(fps->legende.text, 20);
    sfText_setPosition(fps->legende.text, fps->legende.pos);
    sfText_setString(fps->legende.text, "FPS: ");
}

void init_text(beginning_t *begin, scoreboard_t *score, fps_t *fps)
{
    init_highest(begin, score);
    init_scores(begin, score);
    init_legende(begin, score);
    init_fps(begin, fps);
}
