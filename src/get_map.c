/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** get_map.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"

void getmap(all_objects_t *all_objs, char *filepath)
{
    char *buff = malloc(sizeof(char) * 80);
    int fd = open(filepath, O_RDONLY);
    int r = read(fd, buff, 80);

    all_objs->map = buff;
}
