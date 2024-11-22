##
## EPITECH PROJECT, 2022
## Delivery
## File description:
## Makefile
##

SRC = 	SRC/minishell.c \
		SRC/cmd.c \
		SRC/research_path.c \
		SRC/str_path.c \
		SRC/error.c \
		SRC/str_unset.c \
		SRC/research_usr.c \
		SRC/unsetenv.c \
		SRC/research.c \
		SRC/mini_fct.c \
		SRC/segv.c \
		SRC/pipe.c \
		SRC/echo.c \
		SRC/special_variables.c \
		SRC/dbl_pipe.c \
		lib/my_strcat.c \
		lib/string_split.c \
		lib/my_strcpy.c \
		lib/my_strlen.c \
		lib/my_str_to_word_array.c \
		lib/my_strncpy.c \
		lib/my_strcmp.c \
		lib/my_strdup.c \
		lib/my_strncat.c \
		lib/my_strncmp.c \
		fct_printf/my_printf.c \
		fct_printf/my_put_nbr.c \
		fct_printf/octal.c \
		fct_printf/binaire.c \
		fct_printf/my_putchar.c \
		fct_printf/my_putstr.c \
		fct_printf/hexadecimal.c \
		fct_printf/pointeur.c \

OBJ = $(SRC:.c=.o)

NAME = 42sh

all: $(NAME)

$(NAME): 		$(OBJ)
		gcc -o $(NAME) $(OBJ)
		make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
