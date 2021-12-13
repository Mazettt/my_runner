/*
** EPITECH PROJECT, 2021
** B-PSU-100-MLH-1-1-bsmyprintf-martin.d-herouville
** File description:
** put_myprintf.c
*/


#include "my.h"
#include "my_printf.h"

int pstr(va_list list)
{
    char *str = va_arg(list, char *);

    my_putstr(str);
    return (my_strlen(str));
}

int pnbr(va_list list)
{
    int count = 0;
    int nb = va_arg(list, int);
    int size = nb;

    while (size != 0) {
        size /= 10;
        ++count;
    }
    if (nb < 0)
        ++count;
    my_put_nbr(nb);
    return (count);
}

int pchar(va_list list)
{
    char c = va_arg(list, int);

    my_putchar(c);
    return (1);
}

int pbinary(va_list list)
{
    int count = 0;
    int nb = va_arg(list, int);
    unsigned int nb2 = 0;

    if (nb < 0) {
        nb = nb * (-1);
        my_putchar(45);
        ++count;
    }
    nb2 = nb;
    count += convert_base_tot(nb2, "01");
    return (count);
}

int put_unsigned(va_list list)
{
    unsigned int nb = va_arg(list, int);
    int count = 0;

    count = convert_base_tot(nb, "0123456789");
    return (count);
}
