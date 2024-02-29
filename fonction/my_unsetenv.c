/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** my_unsetenv.c
*/

#include "../include/my.h"

static void remove_env_variable(t_env **env, t_env *prev, t_env *current)
{
    if (prev == NULL) {
        *env = current->next;
    } else {
        prev->next = current->next;
    }
    free(current->key);
    free(current->value);
    free(current);
}

static void unset_env_variable(char *var, t_env **env)
{
    t_env *current = *env;
    t_env *prev = NULL;

    while (current != NULL) {
        if (my_strcmp(current->key, var) == 0) {
            remove_env_variable(env, prev, current);
            return;
        }
        prev = current;
        current = current->next;
    }
    my_fprintf(stderr, "Variable '%s' not found\n", var);
}

void my_unsetenv(char **args, t_env **env)
{
    if (args[1] == NULL) {
        my_fprintf(stderr, "Usage: unsetenv VAR\n");
        return;
    }
    unset_env_variable(args[1], env);
}
