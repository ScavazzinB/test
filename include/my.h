/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <stddef.h>
    #include <sys/types.h>
    #include <sys/wait.h>

typedef struct env {
    char *key;
    char *value;
    struct env *next;
} t_env;

void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
char *my_strdup(const char *s);
void my_put_nbr(int nb);
int my_atoi(char *str);
void my_printf(const char *format, ...);
void my_fprintf(FILE *stream, const char *format, ...);
int my_str_isnum(const char *str);
int my_str_isalpha(const char *str);
t_env *init_env(char **envp);
void free_env(t_env *env);
char *read_line(void);
char **split_line(char *line, const char *delim);
int execute(char **args, t_env **env);
void my_cd(char **args, t_env *env);
char *get_env_value(t_env *env, const char *key);
void my_env(t_env *env);
void my_exit(char **args, t_env *env);
int my_getnbr(char *str);
void my_setenv(char **args, t_env **env);
void my_unsetenv(char **args, t_env **env);
t_env *add_env(t_env *env, const char *key, const char *value);
t_env *remove_env(t_env *env, const char *key);
int my_strcat(char *dest, char *src);
int my_strcpy(char *dest, char *src);
void *my_realloc(void *ptr, size_t size);
void *my_memcpy(void *dest, const void *src, size_t n);
void handle_child_process(char **args, t_env *env);
int handle_parent_process(pid_t pid);
int execute_program(char **args, t_env **env);
int execute_builtin(char **args, t_env **env);
int is_builtin_command(char *command);
char *get_command_path(char *command, t_env *env);
char **convert_env_to_array(t_env *env);
int get_env_size(t_env *env);
void handle_format_specifier_printf(va_list *args, char specifier);
int my_snprintf(char *str, size_t size, const char *format, ...);
int my_sprintf(char *str, const char *format, ...);
int handle_format_specifier_snprintf(va_list *args, char specifier, char *str,
    int j, size_t size);
int my_putstr_snprintf(char *str, char *dest, int j, size_t size);
int my_put_nbr_snprintf(int nb, char *dest, int j, size_t size);

#endif
