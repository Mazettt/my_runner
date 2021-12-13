/*
** EPITECH PROJECT, 2021
** myscreensaver
** File description:
** draw_complex.c
*/

#include "../include/struct.h"
#include "../include/my_screensaver.h"

void my_clear_framebuffer(sfUint8 *framebuffer, sfColor color)
{
    my_draw_rectangle(framebuffer, WIDTH, HEIGHT, color);
}

void my_draw_circle_outline(sfUint8 *framebuffer, sfVector2i center, int radius,
int size, sfColor color)
{
    int xi = 0;
    int yi = 0;

    for (unsigned int i = center.x - radius; i < center.x + radius * 2; ++i) {
        for (unsigned int j = center.y - radius; j < center.y + radius * 2;
        ++j) {
            xi = (i - center.x) * (i - center.x);
            yi = (j - center.y) * (j - center.y);
            if (sqrt(xi + yi) < radius && sqrt(xi + yi) > radius - size)
                my_putpixel(j, i, framebuffer, color);
        }
    }
}

void my_draw_big_line(sfUint8 *framebuffer, int radius, sfVector2i point_a,
sfVector2i point_b, sfColor color)
{
    int x = 0;
    int y = 0;
    sfVector2i center;

    for (float n = 0; n <= 1; n += 0.001) {
        x = point_a.x + (point_b.x - point_a.x) * n;
        y = point_a.y + (point_b.y - point_a.y) * n;
        center.x = y;
        center.y = x;
        my_draw_circle(framebuffer, center, radius, color);
    }
}

void my_draw_big_line_faded(sfUint8 *framebuffer, int radius,
sfVector2i point_a, sfVector2i point_b, sfColor color)
{
    int x = 0;
    int y = 0;
    sfVector2i center;

    for (float n = 0; n <= 1; n += 0.001) {
        x = point_a.x + (point_b.x - point_a.x) * n;
        y = point_a.y + (point_b.y - point_a.y) * n;
        center.x = y;
        center.y = x;
        color.a = 255 * n;
        my_draw_circle(framebuffer, center, radius, color);
    }
}

sfColor switch_color(int nb)
{
    sfColor color;

    if (nb == 0)
        color = sfWhite;
    if (nb == 1)
        color = sfRed;
    if (nb == 2)
        color = sfGreen;
    if (nb == 3)
        color = sfBlue;
    if (nb == 4)
        color = sfYellow;
    if (nb == 5)
        color = sfMagenta;
    if (nb == 6)
        color = sfCyan;
    return (color);
}
