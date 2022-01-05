##
## EPITECH PROJECT, 2021
## B-CPE-100-MLH-1-1-cpoolday10-martin.d-herouville
## File description:
## Makefile lib
##

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_atoi.c	\
		is.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	cp my.h ../../include/
	ar rc libmy.a $(OBJ)
	cp $(NAME) ..

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	all fclean
