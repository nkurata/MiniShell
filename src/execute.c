/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-2-minishell1-noe.kurata
** File description:
** prgm.c
*/

#include <sys/types.h>
#include <sys/wait.h>
#include "../include/mysh.h"

static int my_segfault(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 11) {
            my_printf("Segmentation fault\n");
            return 139;
        }
    }
    return status;
}

static pid_t do_fork(void)
{
    pid_t pid = fork();

    if (pid == - 1) {
        perror("fork");
        return 84;
    }
    return pid;
}

static int free_for(char **av)
{
    for (int i = 0; av[i] != NULL ; i++)
        free(av[i]);
    free(av);
    return 0;
}

int execute(int status, char *line, char **env)
{
    pid_t pid = do_fork();
    char **av = get_args(line);
    char *str = get_cmd(av[0], env);

    if (pid == 0) {
        if (execve(str, av, env) == -1) {
            printf("%s: Command not found.\n", av[0]);
            return 1;
        }
    } else {
        wait(&status);
        return my_segfault(status);
    }
    free(str);
    free_for(av);
    return status;
}
