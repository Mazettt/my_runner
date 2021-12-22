/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** backup.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"
#include "../include/my.h"

int get_backup(void)
{
    char buffer[11];
    int fd = open("highest.json", O_RDONLY);
    int r = read(fd, buffer, 11);
    int nbr = my_getnbr(buffer);

    close(fd);
    return (nbr);
}

void put_backup(int nbr)
{
    int fd = open("highest.json", O_WRONLY);
    char *buff;
    int nbr2 = nbr;
    int i = 0;

    for (; nbr2 > 0; ++i)
        nbr2 /= 10;
    buff = malloc(sizeof(char) * i);
    buff = my_itoa(nbr);
    write(fd, buff, i);
    close(fd);
}
