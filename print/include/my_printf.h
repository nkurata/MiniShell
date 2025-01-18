/*
** EPITECH PROJECT, 2022
** hieyhjh
** File description:
** hjudfhgkj
*/

#ifndef PRINTF_H_
    #define PRINTF_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <stdarg.h>

void my_putchar(char c);
int show_number(int nb);
int show_string(char const *str);
char *reverse_string(char *str);
int to_number(char const *str);
int is_prime_number(int nb);
char *my_strcpy(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strlength(const char *str);
void display_limits(int nb);
char *openfile(char *av);
int my_printf(const char *restrict forma, ...);
int int_2_bin(int nb);
int int_2_oct(int nb);
int uns_dec(unsigned int nb);
char *hex_maj(int nb);
char *hex_min(int nb);
int power(int nb);
int my_compute_power_rec (int nb , int p);
int backn(char *str);
int	delim(char s, char *lim);
int	while_delim(char const *str, int i, char *lim);
int	count_words(char const *str, char *lim);
int	str_size(char *str, int i, char *lim);
char **my_str_to_lim_array(char *str, char lim);
int find_word(char *str);
int check_characters_alpha(char c);
int check_characters_word(char c);
char *my_strdup(const char *str);
char *my_strcat(char *dest, char const *src);

#endif
