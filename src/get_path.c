/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-2-minishell2-noe.kurata
** File description:
** get_path.c
*/

#include "../include/mysh.h"

static int *set_len(int *path_len, char *line, int nb_paths)
{
    int c = 0;
    int x = 0;

    for (int i = 0; i < my_strlength(line); i++) {
        if (x == nb_paths)
            break;
        if (line[i] != ':')
            c++;
        if (line[i] == ':' && i > 0 && line[i - 1] != ':') {
            path_len[x] = c;
            x++;
            c = 0;
        }
    }
    if (c > 0)
        path_len[x++] = c;
    return path_len;
}

static int num_path(char *line)
{
    int nb_paths = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ':')
            nb_paths++;
    }
    return nb_paths + 1;
}

static int rm_col(char *line, int x)
{
    while (line[x] == ':')
        x++;
    return x;
}

char **get_path_array(char *path_env)
{
    char *line = path_env + 5;
    int nb_paths = num_path(line);
    int x = 0;
    int path_len[nb_paths];

    set_len(path_len, line, nb_paths);
    char **array = malloc(sizeof(char *) * (nb_paths + 1));
    if (array == NULL)
        return NULL;
    for (int i = 0; i < nb_paths; i++) {
        array[i] = malloc(sizeof(char) * (path_len[i] + 1));
        for (int j = 0; j < path_len[i]; j++) {
            x = rm_col(line, x);
            array[i][j] = line[x];
            x++;
        }
        array[i][path_len[i]] = '\0';
    }
    array[nb_paths] = NULL;
    return array;
}
