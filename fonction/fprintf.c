/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** fprintf.c
*/

#include "../include/my.h"
#include <stdarg.h>

void handle_format_specifier(FILE *stream, char specifier, va_list *args)
{
    switch (specifier) {
        case 'd':
            my_put_nbr(va_arg(*args, int));
            break;
        case 's':
            my_putstr(va_arg(*args, char *));
            break;
        default:
            my_putchar('%');
            break;
    }
}

void my_fprintf(FILE *stream, const char *format, ...)
{
    va_list args;
    int i = 0;

    va_start(args, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            handle_format_specifier(stream, format[i], &args);
        } else {
            my_putchar(format[i]);
        }
        i++;
    }
    va_end(args);
}
//