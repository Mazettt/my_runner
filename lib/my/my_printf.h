/*
** EPITECH PROJECT, 2021
** B-PSU-100-MLH-1-1-bsmyprintf-martin.d-herouville
** File description:
** my_printf.h
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdarg.h>

int my_printf(char *str, ...);
int pstr(va_list list);
int pnbr(va_list list);
int pchar(va_list list);
int pchar_without_list(char c);
int pbinary(va_list list);
int convert_bin(int nb);
int convert_oct(int nb);
int put_zero(int nb);
int convert_base_tot(unsigned int nb, char *base);
int string_with_non_printable(va_list list);
int put_hex_lowercase(va_list list);
int put_hex_uppercase(va_list list);
int put_address_lowercase(va_list list);
int put_octal(va_list list);
int put_unsigned(va_list list);
int spaces(char *str, int i, int *count, int *bol);
int switch_params(char *str, int i, int *count, va_list list);
int minus(char *str, int i, int *count, va_list list);
int hashtag(char *str, int i, int *count, int *bol);

#endif
