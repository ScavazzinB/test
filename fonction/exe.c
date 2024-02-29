/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** exe.c
*/

#include "../include/my.h"

void handle_child_process(char **args, t_env *env)
{
    char *path = get_command_path(args[0], env);
    if (path == NULL) {
        my_fprintf(stderr, "%s: Command not found\n", args[0]);
        exit(EXIT_FAILURE);
    }
    if (execve(path, args, convert_env_to_array(env)) == -1) {
        perror("execve");
        exit(EXIT_FAILURE);
    }
}

int handle_parent_process(pid_t pid)
{
    int status;
    pid_t wpid;

    do {
        wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    } else if (WIFSIGNALED(status)) {
        return WTERMSIG(status) + 128;
    }
    return 0;
}

int execute_program(char **args, t_env **env)
{
    pid_t pid = fork();
    int exit_status;

    if (pid == 0) {
        handle_child_process(args, *env);
    } else if (pid < 0) {
        perror("fork");
        return EXIT_FAILURE;
    } else {
        exit_status = handle_parent_process(pid);
        return exit_status;
    }
    return 0;
}

void execute_builtin(char **args, t_env **env)
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
