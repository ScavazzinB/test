/*
** EPITECH PROJECT, 2024
** test
** File description:
** sprintf.c
*/

#include "../include/my.h"
#include <stdarg.h>


static int my_putstr_sprintf(char *str, char *dest, int j)
{
    int i = 0;

    while (str[i] != '\0') {
        dest[j] = str[i];
        i++;
        j++;
    }
}

static int my_put_nbr_sprintf(int nb, char *dest, int j)
{
    int i = 0;
    int div = 1;

    if (nb < 0) {
        dest[j] = '-';
        j++;
        nb = -nb;
    }
    while (nb / div >= 10) {
        div *= 10;
    }
    while (div > 0) {
        dest[j] = (nb / div) % 10 + '0';
        div /= 10;
        j++;
    }
    return j;
}

static int handle_format_specifier_sprintf(va_list *args, char specifier, char *str,
                                           int j)
{
    switch (specifier) {
        case 'd':
            j += my_put_nbr_sprintf(va_arg(*args, int), str, j);
            break;
        case 's':
            j += my_putstr_sprintf(va_arg(*args, char *), str, j);
            break;
        default:
            str[j] = '%';
            j++;
            break;
    }
    return j;
}

int my_sprintf(char *str, const char *format, ...)
{
    va_list args;
    int i = 0;
    int j = 0;

    va_start(args, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            j = handle_format_specifier_sprintf(&args, format[i], str, j);
        } else {
            str[j] = format[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
    va_end(args);
    return j;
}
