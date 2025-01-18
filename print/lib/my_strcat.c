/*
** EPITECH PROJECT, 2022
** strcat
** File description:
** strcat
*/

#include "../include/my_printf.h"

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlength(dest);
    int j = 0;

    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
