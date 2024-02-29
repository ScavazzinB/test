/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** my_env.c
*/

#include "../include/my.h"

void my_env(t_env *env)
{
    t_env *current = env;

    while (current != NULL) {
        my_printf("%s=%s\n", current->key, current->value);
        current = current->next;
    }
}
