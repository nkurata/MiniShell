/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-2-minishell1-noe.kurata
** File description:
** get_cmd.c
*/

#include "../include/mysh.h"

static int free_for(char **av)
{
    for (int i = 0; av[i] != NULL ; i++)
        free(av[i]);
    free(av);
    return 0;
}

char *get_path_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            return env[i];
        }
    }
    return NULL;
}

char *get_cmd(char *line, char **env)
{
    char *path_env = get_path_env(env);
    char **path = get_path_array(path_env);
    char *path_cmd = NULL;
    struct stat ap;

    for (int i = 0; path[i] != NULL; i++) {
        path_cmd = malloc(sizeof(char) * (my_strlength(path[i]) +
        my_strlength(line) + 2));
        my_strcpy(path_cmd, path[i]);
        path_cmd[my_strlength(path[i])] = '/';
        path_cmd[my_strlength(path[i]) + 1] = '\0';
        path_cmd = my_strcat(path_cmd, line);
        if (stat(path_cmd, &ap) != -1) {
            return path_cmd;
        }
    }
    free(path_cmd);
    free_for(path);
    free(path_env);
    return line;
}
