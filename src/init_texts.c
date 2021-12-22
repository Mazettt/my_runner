/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** init_texts.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

void init_scores(beginning_t *begin, scoreboard_t *score)
{
    score->display_score.pos.x = 175;
    score->display_score.pos.y = 70;
    score->display_score.font = sfFont_createFromFile("minecraft_font.ttf");
    score->display_score.text = sfText_create();
    sfText_setFont(score->display_score.text, score->display_score.font);
    sfText_setColor(score->display_score.text, sfWhite);
    sfText_setCharacterSize(score->display_score.text, 30);
    sfText_setPosition(score->display_score.text, score->display_score.pos);
    score->died_text.pos.x = 1040;
    score->died_text.pos.y = 329;
    score->died_text.font = sfFont_createFromFile("minecraft_font.ttf");
    score->died_text.text = sfText_create();
    sfText_setFont(score->died_text.text, score->died_text.font);
    sfText_setColor(score->died_text.text, sfWhite);
    sfText_setCharacterSize(score->died_text.text, 26);
    sfText_setPosition(score->died_text.text, score->died_text.pos);
}
void init_highest(beginning_t *begin, scoreboard_t *score)
{
    score->highest.pos.x = 195;
    score->highest.pos.y = 30;
    score->highest.font = sfFont_createFromFile("minecraft_font.ttf");
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
    score->legende.font = sfFont_createFromFile("minecraft_font.ttf");
    score->legende.text = sfText_create();
    sfText_setFont(score->legende.text, score->legende.font);
    sfText_setColor(score->legende.text, sfWhite);
    sfText_setCharacterSize(score->legende.text, 30);
    sfText_setPosition(score->legende.text, score->legende.pos);
    sfText_setString(score->legende.text, "Highest : \nScore : ");
}

void init_text(beginning_t *begin, scoreboard_t *score)
{
    init_highest(begin, score);
    init_scores(begin, score);
    init_legende(begin, score);
}
