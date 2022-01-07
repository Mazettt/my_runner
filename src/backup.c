/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** backup.c
*/

#include "../include/myrunner.h"
#include "../include/struct.h"
#include "../include/my.h"

int get_nbr_custom(char *buff)
{
    int result = 0;

    for (int i = 0; isnum(buff[i]); ++i) {
        result *= 10;
        result += (buff[i] - 48);
    }
    return (result);
}

int get_backup(bool inf)
{
    char buffer[11];
    int fd = inf ? open("highest_inf.json", O_RDONLY) :
    open("highest_map.json", O_RDONLY);
    int r = read(fd, buffer, 11);
    int nbr = get_nbr_custom(buffer);

    close(fd);
    return (nbr);
}

void put_backup(int nbr, bool inf)
{
    int fd = inf ? open("highest_inf.json", O_WRONLY) :
    open("highest_map.json", O_WRONLY);
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
