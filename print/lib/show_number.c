/*
** EPITECH PROJECT, 2022
** bootcamp
** File description:
** task03.c
*/

#include "../include/my_printf.h"

void display_limits(int nb)
{
    if (nb == (-2147483648))
        write(1, "2147483648\n", 12);
    if (nb == 2147483647)
        write(1, "2147483647\n", 12);
}

int show_number(int nb)
{
    if (nb < (-2147483648) || nb > 2147483647)
        write(1, "to big/small\n", 14);
    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * (-1);
    } if (nb >= 0 && nb <= 9) {
        int res = nb + 48;
        write(1, &res , 1);
    } else if (nb > 9) {
        show_number(nb / 10);
        int unit = nb % 10 + 48;
        write(1, &unit, 1);
    }
    display_limits(nb);
    return nb;
}
