/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-2-minishell1-noe.kurata
** File description:
** gen_trm.c
*/

#include <signal.h>
#include <string.h>
#include "../include/mysh.h"

static void sig_handler(int sig)
{
    if (sig == SIGINT) {
        my_printf("\n$> ");
    }
}

static int start_prompt(int status, char *line, char **env)
{
    line = strtok(line, "\n");
    if (builtins(line, env))
        status = execute(status, line, env);
    return status;
}

int get_next_line(int status, char** env)
{
    char *line = NULL;
    size_t size = 0;

    while (1) {
        signal(SIGINT, sig_handler);
        if (isatty(0) == 1)
            my_printf("$> ");
        if (getline(&line, &size, stdin) == -1)
            break;
        if (line[0] == '\n')
            continue;
        else
            status = start_prompt(status, line, env);
    }
    if (isatty(0) == 1)
        my_printf("exit\n");
    free(line);
    return status;
}
