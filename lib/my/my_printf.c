/*
** EPITECH PROJECT, 2021
** B-PSU-100-MLH-1-1-bsmyprintf-martin.d-herouville
** File description:
** my_printf.c
*/


#include "my.h"
#include "my_printf.h"

int in_string(char c)
{
    if (c == '\n')
        return (2);
    else if (c == '%')
        return (1);
    else
        return (0);
}

int switch_params(char *str, int i, int *count, va_list list)
{
    static const char flag[] = {'s', 'c', 'd', 'i', 'b', 'S', 'x', 'X', 'p',
    'o', 'u', '\0'};
    static const int (*switch_flags[])(va_list) = {pstr, pchar, pnbr, pnbr,
    pbinary, string_with_non_printable, put_hex_lowercase, put_hex_uppercase,
    put_address_lowercase, put_octal, put_unsigned};

    for (int j = 0; flag[j] != '\0'; ++j) {
        if (str[i] == flag[j]) {
            *count += (*switch_flags[j])(list);
            return (0);
        }
    }
    if (isletter(str[i])) {
        my_putchar('%');
        my_putchar(str[i]);
        *count += 2;
        return (0);
    }
    return (1);
}

int my_printf2(char *str, int i, int *bool_break)
{
    if (str[i] == '%' && str[i + 1] == '%') {
        my_putchar('%');
        i += str[i + 2] == '\0' ? *bool_break = 1 : 2;
    }
    return (i);
}

int my_printf3(char *str, int i, int bol, int count)
{
    if (in_string(str[i]) == 0 && bol == 0) {
        my_putchar(str[i]);
        ++count;
    }
    if (str[i] == '\n') {
        my_putchar('\n');
        ++count;
    }
    return (count);
}

int my_printf(char *str, ...)
{
    int count = 0;
    va_list list;

    va_start(list, str);
    for (int i = 0, bool_break = 0, bol = 0; str[i] != '\0'; ++i) {
        i = my_printf2(str, i, &bool_break);
        i = spaces(str, i, &count, &bol);
        i = minus(str, i, &count, list);
        i = hashtag(str, i, &count, &bol);
        if (bool_break == 1) {
            bool_break = 0;
            continue;
        }
        count = my_printf3(str, i, bol, count);
        str[i] == '%' ? bol = 1, switch_params(str, i, &count, list), ++i : 0;
        bol ? bol = switch_params(str, i, &count, list) : 0;
    }
    va_end(list);
    return (count);
}
