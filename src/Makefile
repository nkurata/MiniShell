##
## EPITECH PROJECT, 2023
## B-PSU-200-PAR-2-2-minishell2-noe.kurata
## File description:
## Makefile
##

SRC		=	src/main.c		\
			src/prgm.c		\
			src/execute.c	\
			src/get_cmd.c	\
			src/gen_trm.c	\
			src/builtin.c	\
			src/array.c	\

NAME	=	mysh

INCLUDE =	-Iinclude -Lprint/ -lmy -g3

CFLAGS	=	-Wall -Wextra

OBJ     = 		$(SRC:.c=.o)

all:	$(OBJ)
	make -C print/
	cc -o $(NAME) $(SRC) $(INCLUDE) $(CFLAGS)

clean:
	make clean -C print/
	rm -f $(OBJ)

fclean: clean
	make fclean -C print/
	rm -f $(NAME)

re: fclean all
