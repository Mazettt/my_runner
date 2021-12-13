/*
** EPITECH PROJECT, 2021
** myprintf
** File description:
** convert_base.c
*/

#include "my.h"
#include "my_printf.h"

int put_zero(int nb)
{
    int count = 0;

    if (nb <= 7) {
        my_putstr("00");
        count += 2;
    } else if (nb >= 8 && nb <= 63) {
        my_putchar('0');
        ++count;
    }
    return (count);
}

int convert_oct(int nb)
{
    int count = 0;
    int modulo = 0;
    int result = 0;

    modulo = nb % 8;
    nb /= 8;
    if (nb > 0)
        count += convert_oct(nb);
    my_put_nbr(modulo);
    return (count + 1);
}

int convert_base_tot(unsigned int nb, char *base)
{
    int count = 0;
    int size = my_strlen(base);
    int div = 0;
    int mod = 0;

    div = nb / size;
    mod = nb % size;
    if (nb >= size) {
        count += convert_base_tot(div, base);
        count += convert_base_tot(mod, base);
    } else {
        my_putchar(base[nb]);
        ++count;
    }
    return (count);
}
