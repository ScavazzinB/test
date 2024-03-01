/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** split_line.c
*/

#include "../include/my.h"

static char **allocate_tokens(int bufsize) {
    char **tokens = malloc(bufsize * sizeof(char *));
    if (!tokens) {
        my_fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }
    return tokens;
}

static char **resize_tokens(char **tokens, int *bufsize) {
    *bufsize += 64;
    tokens = my_realloc(tokens, *bufsize * sizeof(char *));
    if (!tokens) {
        my_fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }
    return tokens;
}

char **split_line(char *line, const char *delim)
{
    int bufsize = 64, position = 0;
    char **tokens = allocate_tokens(bufsize);
    char *token;

    token = strtok(line, delim);
    while (token != NULL) {
        tokens[position++] = token;
        if (position >= bufsize) {
            tokens = resize_tokens(tokens, &bufsize);
        }
        token = strtok(NULL, delim);
    }
    tokens[position] = NULL;
    return tokens;
}

