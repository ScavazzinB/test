/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** path.c
*/

#include "../include/my.h"

char *get_command_path(char *command, t_env *env)
{
    char *path_value = get_env_value(env, "PATH");
    if (path_value == NULL) {
        my_printf("Debug: PATH variable is not set.\n");
        return NULL;
    }

    char *path_copy = strdup(path_value);
    if (path_copy == NULL) {
        my_fprintf(stderr, "Failed to duplicate PATH value.\n");
        return NULL;
    }

    char **paths = split_line(path_copy, ":");
    char *command_path = NULL;

    for (int i = 0; paths[i] != NULL; i++) {
        char *full_path = malloc(strlen(paths[i]) + strlen(command) + 2);
        if (full_path == NULL) {
            my_fprintf(stderr, "Allocation error\n");
            free(path_copy);
            free(paths);
            return NULL;
        }
        sprintf(full_path, "%s/%s", paths[i], command);
        if (access(full_path, X_OK) == 0) {
            command_path = strdup(full_path);
            free(full_path);
            break;
        }
        free(full_path);
    }
    free(path_copy);
    free(paths);

    if (command_path == NULL) {
        my_fprintf(stderr, "Command not found: %s\n", command);
    }

    return command_path;
}

char **convert_env_to_array(t_env *env)
{
    int env_size = get_env_size(env);
    char **env_array = malloc((env_size + 1) * sizeof(char *));
    t_env *current = env;
    int i = 0;

    while (current != NULL) {
        env_array[i] = malloc(strlen(current->key) + strlen(current->value) + 2);
        my_sprintf(env_array[i], "%s=%s", current->key, current->value);
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
