/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** alpha.c
*/

#include "../include/my.h"

int my_str_isalpha(const char *str)
{
    if (str == NULL) {
        return 0;
    }
    while (*str) {
        if ((*str < 'A' || *str > 'Z') && (*str < 'a' || *str > 'z')) {
            return 0;
        }
        str++;
    }
    return 84;
}

int my_str_isnum(const char *str)
{
    if (str == NULL) {
        return 0;
    }
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }
    return 84;
}
