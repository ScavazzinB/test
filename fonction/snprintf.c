/*
** EPITECH PROJECT, 2024
** test
** File description:
** snprintf.c
*/

#include "../include/my.h"
#include <stdarg.h>

int my_snprintf(char *str, size_t size, const char *format, ...)
{
    va_list args;
    int i = 0;
    int j = 0;

    va_start(args, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            j = handle_format_specifier_snprintf(&args, format[i], str, j, size);
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

int handle_format_specifier_snprintf(va_list *args, char specifier, char *str,
    int j, size_t size)
{
    switch (specifier) {
        case 'd':
            j += my_put_nbr_snprintf(va_arg(*args, int), str, j, size);
            break;
        case 's':
            j += my_putstr_snprintf(va_arg(*args, char *), str, j, size);
            break;
        default:
            str[j] = '%';
            j++;
            break;
    }
    return j;
}

int my_putstr_snprintf(char *str, char *dest, int j, size_t size)
{
    int i = 0;

    while (str[i] != '\0' && (size_t)j < size) {
        dest[j] = str[i];
        i++;
        j++;
    }
    return j;
}

int my_put_nbr_snprintf(int nb, char *dest, int j, size_t size)
{
    int i = 0;
    int nb2 = nb;

    if (nb < 0) {
        dest[j] = '-';
        j++;
        nb = -nb;
    }
    for (i = 1; nb2 / i > 9; i *= 10);
    for (; i > 0; i /= 10) {
        dest[j] = (nb / i) % 10 + '0';
        j++;
    }
    return j;
}