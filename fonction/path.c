/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** path.c
*/

#include "../include/my.h"

char *get_command_path(char *command, t_env *env)
{
    char *path_env = get_env_value(env, "PATH");
    char **paths = split_line(path_env);
    char *command_path = malloc(1024);

    for (int i = 0; paths[i] != NULL; i++) {
        snprintf(command_path, 1024, "%s/%s", paths[i], command);
        if (access(command_path, X_OK) == 0) {
            free(paths);
            return command_path;
        }
    }
    free(paths);
    free(command_path);
    return NULL;
}

char **convert_env_to_array(t_env *env)
{
    int env_size = get_env_size(env);
    char **env_array = malloc((env_size + 1) * sizeof(char *));
    t_env *current = env;
    int i = 0;

    while (current != NULL) {
        env_array[i] = malloc(strlen(current->key) + strlen(current->value) + 2);
        sprintf(env_array[i], "%s=%s", current->key, current->value);
        current = current->next;
        i++;
    }
    env_array[i] = NULL;
    return env_array;
}

int get_env_size(t_env *env)
{
    int size = 0;
    t_env *current = env;

    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}
