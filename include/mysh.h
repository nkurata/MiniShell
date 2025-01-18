/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-2-bsminishell1-noe.kurata
** File description:
** bs.h
*/

#ifndef BS_H
    #define BS_H

    #include "../print/include/my_printf.h"

int get_next_line(int status, char** env);
int builtins(char *line, char **env);
void my_cd(char **args, char **env);
int execute(int status, char *line, char **env);
char *get_cmd(char *line, char **env);
char **get_args(char *line);
void get_username(void);
int *word_len(char *line, int nb_words, int *len_args);
int check_the_spaces(char c);
char **get_path_array(char *path_env);

#endif
