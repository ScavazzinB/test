/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** my_exit.c
*/

#include "../include/my.h"

void my_exit(char **args, t_env *env)
{
    if (args[1] != NULL) {
        if (my_str_isnum(args[1]) == 0) {
            my_printf("exit: Expression Syntax.\n");
            return;
        }
        if (args[2] != NULL) {
            my_printf("exit: Expression Syntax.\n");
            return;
        }
        my_printf("exit\n");
        exit(my_getnbr(args[1]));
    }
    my_printf("exit\n");
    exit(0);
}

int my_getnbr(char *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    for (; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return (sign * res);
}
//