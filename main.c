/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** main.c
*/

#include "include/my.h"

int main(int argc, char **argv, char **envp)
{
    char *ligne;
    char **arguments;
    int statut = 0;
    t_env *env = init_env(envp);

    while (statut == 0) {
        my_printf("$> ");
        ligne = read_line();
        if (ligne == NULL) {
            break;
        }
        arguments = split_line(ligne, " \t\n\r\a");
        statut = execute(arguments, &env);
        free(ligne);
        free(arguments);
    }
    free_env(env);
    return EXIT_SUCCESS;
}
//