/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-2-minishell1-noe.kurata
** File description:
** get_args.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../include/mysh.h"

int check_the_spaces(char c)
{
    if (c == ' ' || c == '\t')
        return 1;
    return 0;
}

static int count_word(char *line)
{
    int c = 0;
    int s = 0;
    for (int i = 0; i < my_strlength(line); i++) {
        if (!check_the_spaces(line[i]))
            s++;
        if (check_the_spaces(line[i]) &&
        !check_the_spaces(line[i - 1]) && i > 0) {
            c++;
            s = 0;
        }
    }
    if (s > 0)
        c++;
    return c;
}

static int rm_sp(char *line, int i)
{
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    return i;
}

void* check_alloc(char** array, int *len_args)
{
    if (array == NULL || len_args == NULL) {
        free(array);
        free(len_args);
        return NULL;
    }
    return array;
}

char **get_args(char *line)
{
    int nb_words = count_word(line);
    int *len_args = malloc(sizeof(int) * nb_words);
    char **array = malloc(sizeof(char *) * (nb_words + 1));
    int x = 0;
    if (check_alloc(array, len_args) == NULL)
        return NULL;
    len_args = word_len(line, nb_words, len_args);
    for (int i = 0; i < nb_words; i++) {
        array[i] = malloc(sizeof(char) * (len_args[i] + 1));
        for (int j = 0; j < len_args[i]; j++) {
            x = rm_sp(line, x);
            array[i][j] = line[x];
            x++;
        }
        array[i][len_args[i]] = '\0';
        x++;
    }
    array[nb_words] = NULL;
    free(len_args);
    return array;
}
