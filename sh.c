/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** sh.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "include/my.h"

static t_env *create_env_node(char *key, char *value)
{
    t_env *new_node = malloc(sizeof(t_env));

    if (!new_node) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    new_node->key = my_strdup(key);
    new_node->value = my_strdup(value);
    new_node->next = NULL;
    return new_node;
}

static void add_env_node(t_env **head, t_env **current, t_env *new_node)
{
    if (!*head) {
        *head = new_node;
    } else {
        (*current)->next = new_node;
    }
    *current = new_node;
}

t_env *init_env(char **envp)
{
    t_env *head = NULL;
    t_env *current = NULL;
    char *pair;
    char *key;
    char *value;
    int i = 0;

    while (envp[i]) {
        pair = my_strdup(envp[i]);
        key = strtok(pair, "=");
        value = strtok(NULL, "");
        add_env_node(&head, &current, create_env_node(key, value));
        free(pair);
        i++;
    }
    return head;
}

void free_env(t_env *env)
{
    t_env *tmp;

    while (env) {
        tmp = env;
        env = env->next;
        free(tmp->key);
        free(tmp->value);
        free(tmp);
    }
}

char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    getline(&line, &bufsize, stdin);
    return line;
}

int is_builtin_command(char *command)
{
    const char *builtins[] = {"cd", "setenv", "unsetenv", "env", "exit", NULL};

    for (int i = 0; builtins[i]; i++) {
        if (my_strcmp(command, builtins[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
