/*
** EPITECH PROJECT, 2021
** myprintf
** File description:
** put_myprintf_complex.c
*/


#include "my.h"
#include "my_printf.h"

int string_with_non_printable(va_list list)
{
    int count = 0;
    char *str = va_arg(list, char *);

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] < 32 || str[i] >= 127 && str[i] != '\0') {
            my_putchar('\\');
            ++count;
            count += put_zero(str[i]);
            count += convert_oct(str[i]);
        } else {
            my_putchar(str[i]);
            ++count;
        }
    }
    return (count);
}

int put_hex_lowercase(va_list list)
{
    unsigned int nb = va_arg(list, int);

    return (convert_base_tot(nb, "0123456789abcdef"));
}

int put_hex_uppercase(va_list list)
{
    unsigned int nb = va_arg(list, int);

    return (convert_base_tot(nb, "0123456789ABCDEF"));
}

int put_address_lowercase(va_list list)
{
    int count = 0;

    my_putstr("0x");
    count = 2;
    count += put_hex_lowercase(list);
    return (count);
}

int put_octal(va_list list)
{
    int count = 0;
    unsigned int nb = va_arg(list, int);

    count += convert_base_tot(nb, "01234567");
    return (count);
}