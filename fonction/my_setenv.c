/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** my_setenv.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

static void update_existing_variable(t_env *current, char *value)
{
    free(current->value);
    current->value = my_strdup(value);
}

static t_env *create_new_variable(char *key, char *value)
{
    t_env *new_node = malloc(sizeof(t_env));

    if (new_node == NULL) {
        my_fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }
    new_node->key = my_strdup(key);
    new_node->value = my_strdup(value);
    return new_node;
}

void my_setenv(char **args, t_env **env)
{
    t_env *new_node;

    if (args[1] == NULL || args[2] == NULL) {
        my_fprintf(stderr, "Usage: setenv VAR VALUE\n");
        return;
    }
    for (t_env *current = *env; current != NULL; current = current->next) {
        if (my_strcmp(current->key, args[1]) == 0) {
            update_existing_variable(current, args[2]);
            return;
        }
    }
    new_node = create_new_variable(args[1], args[2]);
    new_node->next = *env;
    *env = new_node;
}
//