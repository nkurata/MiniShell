/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-2-minishell2-noe.kurata [WSL: Ubuntu]
** File description:
** word_len.c
*/

#include "../include/mysh.h"

int *word_len(char *line, int nb_words, int *len_args)
{
    int l = 0;
    int i = 0;

    for (int k = 0; line[k] != '\0'; k++) {
        if (i == nb_words)
            break;
        if (!check_the_spaces(line[k]))
            l++;
        if (check_the_spaces(line[k]) &&
        !check_the_spaces(line[k - 1]) && k > 0) {
            len_args[i] = l;
            i++;
            l = 0;
        }
    }
    if (l > 0)
        len_args[i++] = l;
    return len_args;
}
