/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** init_objs.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

void init_background(beginning_t *begin, game_object_t *obj)
{
    // Sky
    obj[0].rect.top = 0;
    obj[0].rect.left = 0;
    obj[0].rect.width = 1980;
    obj[0].rect.height = 1080;
    obj[0].speed = 1;
    // Mountains
    obj[1].rect.top = 1080;
    obj[1].rect.left = 0;
    obj[1].rect.width = 1980;
    obj[1].rect.height = 1080;
    obj[1].speed = 2;
    // Floor
    obj[2].rect.top = 1080 * 2;
    obj[2].rect.left = 0;
    obj[2].rect.width = 1980;
    obj[2].rect.height = 1080;
    obj[2].speed = 3;
}

void init_perso(beginning_t *begin, game_object_t *obj)
{
    obj[3].rect.top = 0;
    obj[3].rect.left = 5940;
    obj[3].rect.width = 178;
    obj[3].rect.height = 148;
    obj[3].pos.x = 500;
    obj[3].pos.y = 930;
    obj[3].inc_pos = 0;
    obj[3].origin.x = 89;
    obj[3].origin.y = 74;
    sfSprite_setOrigin(obj[3].sprite, obj[3].origin);
    sfSprite_setPosition(obj[3].sprite, obj[3].pos);
}

void init_obstacle(beginning_t *begin, game_object_t *obj)
{
    obj[4].rect.top = 154;
    obj[4].rect.left = 5940;
    obj[4].rect.width = 500;
    obj[4].rect.height = 379;
    obj[4].pos.x = 1920;
    obj[4].pos.y = 960;
    obj[4].origin.x = 250;
    obj[4].origin.y = 174;
    sfSprite_setOrigin(obj[4].sprite, obj[4].origin);
    sfSprite_setPosition(obj[4].sprite, obj[4].pos);
}

void init_died_message(beginning_t *begin, game_object_t *obj)
{
    obj[5].rect.top = 2160;
    obj[5].rect.left = 5940;
    obj[5].rect.width = 1920;
    obj[5].rect.height = 1080;
}

void init_title_screen(beginning_t *begin, game_object_t *obj)
{
    obj[6].rect.top = 1080;
    obj[6].rect.left = 5940;
    obj[6].rect.width = 1920;
    obj[6].rect.height = 1080;
}

void init_text(beginning_t *begin, scoreboard_t *score)
{
    score->display_score.pos.x = 175;
    score->display_score.pos.y = 70;
    score->display_score.font = sfFont_createFromFile("minecraft_font.ttf");
    score->display_score.text = sfText_create();
    sfText_setFont(score->display_score.text, score->display_score.font);
    sfText_setColor(score->display_score.text, sfWhite);
    sfText_setCharacterSize(score->display_score.text, 30);
    sfText_setPosition(score->display_score.text, score->display_score.pos);

    score->highest.pos.x = 195;
    score->highest.pos.y = 30;
    score->highest.font = sfFont_createFromFile("minecraft_font.ttf");
    score->highest.text = sfText_create();
    sfText_setFont(score->highest.text, score->highest.font);
    sfText_setColor(score->highest.text, sfWhite);
    sfText_setCharacterSize(score->highest.text, 30);
    sfText_setPosition(score->highest.text, score->highest.pos);

    score->legende.pos.x = 30;
    score->legende.pos.y = 30;
    score->legende.font = sfFont_createFromFile("minecraft_font.ttf");
    score->legende.text = sfText_create();
    sfText_setFont(score->legende.text, score->legende.font);
    sfText_setColor(score->legende.text, sfWhite);
    sfText_setCharacterSize(score->legende.text, 30);
    sfText_setPosition(score->legende.text, score->legende.pos);
    sfText_setString(score->legende.text, "Highest : \nScore : ");

    score->died_text.pos.x = 1040;
    score->died_text.pos.y = 329;
    score->died_text.font = sfFont_createFromFile("minecraft_font.ttf");
    score->died_text.text = sfText_create();
    sfText_setFont(score->died_text.text, score->died_text.font);
    sfText_setColor(score->died_text.text, sfWhite);
    sfText_setCharacterSize(score->died_text.text, 26);
    sfText_setPosition(score->died_text.text, score->died_text.pos);
}
