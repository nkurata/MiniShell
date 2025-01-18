/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-2-minishell1-noe.kurata
** File description:
** main.c
*/

#include "../include/mysh.h"

void get_username(void)
{
    my_printf("$> ");
}

int main(int ac, char **av, char **env)
{
    int status = 0;
    if (ac != 1)
        return 84;
    if (av[0] == NULL)
        return 84;
    return get_next_line(status, env);
}
