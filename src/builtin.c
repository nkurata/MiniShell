/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-2-minishell1-noe.kurata
** File description:
** builtin.c
*/

#include "../include/mysh.h"

static char *get_path(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        if (my_strncmp(env[i], "HOME=", 5) == 0)
            return env[i];
    return NULL;
}

static void free_args(char **args)
{
    for (int i = 0; args[i] != NULL; i++)
        free(args[i]);
    free(args);
}

int builtins(char *line, char **env)
{
    char **args = get_args(line);
    if (my_strcmp(args[0], "env") == 0) {
        for (int i = 0; env[i] != NULL; i++)
            my_printf("%s\n", env[i]);
        return 0;
    } if (my_strcmp(args[0], "cd") == 0) {
        my_cd(args, env);
        return 0;
    } if (my_strcmp(args[0], "exit") == 0) {
        printf("exit\n");
        exit(0);
    }
    free_args(args);
    return 1;
}

void my_cd(char **args, char **env)
{
    char *path_env;
    if (args[1] == NULL) {
        path_env = get_path(env);
        chdir(path_env + 5);
    } else {
        chdir(args[1]);
    }
    free_args(args);

}
