##
## EPITECH PROJECT, 2024
## B-PSU-200-NCE-2-1-minishell1-baptiste.scavazzin
## File description:
## Make
##

NAME	= my_sh

SRCS	= fonction/str.c \
		fonction/path.c \
		fonction/str2.c \
		fonction/split_line.c \
		fonction/my_realloc.c \
		fonction/my_atoi.c \
		fonction/alpha.c \
		fonction/fprintf.c \
		fonction/printf.c \
		fonction/sprintf.c \
		fonction/snprintf.c \
		fonction/my_cd.c \
		fonction/my_env.c \
		fonction/my_exit.c \
		fonction/my_setenv.c \
		fonction/my_unsetenv.c \
		fonction/exe.c \
		main.c \
		sh.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -I ./include -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc -o $(NAME) $(OBJS) -I./include -g3

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

unit_tests:	re
	gcc -o unit_tests $(SRCS) tests/*.c \
	--coverage -lcriterion -I./include

tests_run: 	unit_tests
	./unit_tests
