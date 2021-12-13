/*
** EPITECH PROJECT, 2021
** myprintf
** File description:
** formatage.c
*/

#include "my.h"
#include "my_printf.h"

int spaces(char *str, int i, int *count, int *bol)
{
    if (str[i] == '%' && str[i + 1] == ' ') {
        ++i;
        while (str[i] == ' ') {
            my_putchar(' ');
            ++*count;
            ++i;
        }
        *bol = 1;
    }
    return (i);
}

int hashtag(char *str, int i, int *count, int *bol)
{
    if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'x') {
        i += 2;
        *bol = 1;
        my_putstr("0x");
        *count += 2;
    }
    if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'o') {
        i += 2;
        *bol = 1;
        my_putchar('0');
        *count += 1;
    }
    return (i);
}

int minus(char *str, int i, int *count, va_list list)
{
    int minus_var = 0;
    int diff_count = *count;

    if (str[i] == '%' && str[i + 1] == '-') {
        i += 2;
        minus_var = my_getnbr(&str[i]);
        while (isnum(str[i]))
            ++i;
        if (str[i] == '+') {
            my_putchar('+');
            ++*count;
            ++i;
        }
        switch_params(str, i, count, list);
        diff_count = *count - diff_count;
        for (; minus_var > diff_count; --minus_var, ++*count)
            my_putchar(' ');
        return (i + 1);
    } else
        return (i);
}
