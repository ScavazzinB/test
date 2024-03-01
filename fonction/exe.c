/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** exe.c
*/

#include "../include/my.h"

static int is_builtin(char *command)
{
    const char *builtins[] = {"cd","setenv",
            "unsetenv","env","exit",NULL};

    for (int i = 0; builtins[i] != NULL; i++) {
        if (my_strcmp(command, builtins[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

void handle_child_process(char **args, t_env *env)
{
    char *path = get_command_path(args[0], env);
    if (path == NULL) {
        my_fprintf(stderr, "%s: Command not found\n", args[0]);
        return;
    }
    if (execve(path, args, convert_env_to_array(env)) == -1) {
        perror("execve");
    }
    free(path);
}

int handle_parent_process(pid_t pid)
{
    int status;
    pid_t wpid;

    do {
        wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));

    if (WIFEXITED(status)) {
        int exit_status = WEXITSTATUS(status);
        if (exit_status == 127) {
        } else if (exit_status == 126) {
        }
        return exit_status;
    } else if (WIFSIGNALED(status)) {
        return WTERMSIG(status) + 128;
    }
    return 0;
}


int execute_program(char **args, t_env **env)
{
    pid_t pid;
    int status;
    char *command_path;

    if (is_builtin(args[0])) {
        return execute_builtin(args, env);
    } else {
        pid = fork();
        if (pid == 0) {
            char *path_value = get_env_value(*env, "PATH");
            if (path_value == NULL) {
            } else {
            }

            command_path = get_command_path(args[0], *env);
            if (command_path != NULL) {
                execve(command_path, args, convert_env_to_array(*env));
                free(command_path);
            }
            my_fprintf(stderr, "%s: Command not found\n", args[0]);
            _exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("fork");
            return EXIT_FAILURE;
        } else {
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                return WEXITSTATUS(status);
            }
        }
    }
    return EXIT_SUCCESS;
}

int execute_builtin(char **args, t_env **env)
{
    if (my_strcmp(args[0], "cd") == 0) {
        my_cd(args, *env);
    }
    if (my_strcmp(args[0], "setenv") == 0) {
        my_setenv(args, *env);
    }
    if (my_strcmp(args[0], "unsetenv") == 0) {
        my_unsetenv(args, *env);
    }
    if (my_strcmp(args[0], "env") == 0) {
        my_env(*env);
    }
    if (my_strcmp(args[0], "exit") == 0) {
        my_exit(args, *env);
    }
    return 0;
}

int execute(char **args, t_env **env)
{
    int exit_status = 0;

    if (args[0] == NULL) {
        return 0;
    }
    if (is_builtin_command(args[0])) {
        execute_builtin(args, env);
    } else {
        exit_status = execute_program(args, env);
    }
    return exit_status;
}
