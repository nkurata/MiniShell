/*
** EPITECH PROJECT, 2022
** B-BOO-101-PAR-1-1-phoenixd01-noe.kurata
** File description:
** task04.c
*/

#include "../include/my_printf.h"

int show_string(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}
