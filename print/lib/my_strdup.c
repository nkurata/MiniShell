/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-2-minishell1-noe.kurata
** File description:
** my_strdup.c
*/

#include "../include/my_printf.h"

char *my_strdup(const char *str)
{
    int len = my_strlength(str) + 1;
    char* new_str = malloc(len);

    if (new_str == NULL)
        return NULL;
    for (size_t i = 0; i < len; i++)
        new_str[i] = str[i];
    return new_str;
}
