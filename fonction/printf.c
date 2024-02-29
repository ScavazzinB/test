/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** printf.c
*/

#include "../include/my.h"
#include <stdarg.h>

void my_printf(const char *format, ...)
{
    va_list args;
    int i = 0;

    va_start(args, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            handle_format_specifier_printf(&args, format[i]);
        }
            my_putchar(format[i]);
        i++;
    }
    va_end(args);
}

void handle_format_specifier_printf(va_list *args, char specifier)
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
