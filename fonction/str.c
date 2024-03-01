/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** str.c
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

int my_strlen(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

char *my_strdup(const char *s)
{
    char *new_str;
    size_t len;
    size_t i;

    if (s == NULL) {
        return NULL;
    }
    len = my_strlen(s);
    new_str = malloc(len + 1);
    if (new_str == NULL) {
        return NULL;
    }
    for (i = 0; i < len; i++) {
        new_str[i] = s[i];
    }
    new_str[len] = '\0';
    return new_str;
}
//