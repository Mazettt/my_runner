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
    char *buff = malloc(sizeof(char) * 2048);
    int fd = open(filepath, O_RDONLY);
    int r = read(fd, buff, 2048);
    int i = 0;

    while (buff[i] != '0')
        ++i;
    buff[i] = '\0';
    all_objs->map = buff;
    all_objs->size_map = i;
    printf("all_objs->size_map = %d\n", all_objs->size_map);
}
