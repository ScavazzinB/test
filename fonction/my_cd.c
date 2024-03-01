/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** my_cd.c
*/

#include "../include/my.h"

static void change_directory_or_exit(const char *path)
{
    if (chdir(path) != 0) {
        perror("cd");
    }
}

static void handle_no_arguments(t_env *env)
{
    char *home = get_env_value(env, "HOME");

    if (home != NULL) {
        change_directory_or_exit(home);
    } else {
        my_fprintf(stderr, "cd: HOME not set\n");
    }
}

void my_cd(char **args, t_env *env)
{
    if (args[1] == NULL) {
        handle_no_arguments(env);
    } else {
        change_directory_or_exit(args[1]);
    }
}

char *get_env_value(t_env *env, const char *key)
{
    while (env != NULL) {
        if (my_strcmp(env->key, key) == 0) {
            return env->value;
        }
        env = env->next;
    }
    return NULL;
}
//