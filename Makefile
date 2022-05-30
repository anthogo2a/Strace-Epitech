##
## EPITECH PROJECT, 2021
## makefile_strace
## File description:
## strace_tech2
##

NAME	=	strace

ASM	=	nasm

CC	=	gcc

SRC	=	src/main.c  	\
		src/utils.c 	\
		src/arg.c		\

OBJ	=	${SRC:.c=.o}

CFLAGS	=	-I include/ -g3 -Wall

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

all:    $(NAME)

clean:
	rm -fr $(OBJ)

fclean:	clean
	rm -fr $(NAME)

re:	fclean all




