##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/backup.c	\
		src/clocks.c	\
		src/collisions.c	\
		src/draw.c	\
		src/events.c	\
		src/get_map.c	\
		src/init/init_objs.c	\
		src/init/init_screens.c	\
		src/init/init_structs.c	\
		src/init/init_texts.c	\
		src/my_itoa.c	\
		src/myrunner.c	\
		src/parallax.c	\
		src/utils.c	\
		src/move_perso.c	\
		src/fps.c	\

# SRC_TESTS	=	tests/tests_advanced.c	\
# 			tests/tests_convert.c	\
# 			tests/tests_simple.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

NAME_TESTS	=	unit_tests

BIN	=	vgcore*	\
		unit_tests*	\

FLAGS	=	-I./include	\
			-L./lib	\
			-lmy	\
			-g	\

WFLAGS	=	-Wall	\
			-Werror	\
			-Wextra	\

CSFML_FLAGS	=	-lcsfml-graphics	\
				-lcsfml-window	\
				-lcsfml-system	\
				-lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(FLAGS) $(CSFML_FLAGS) -lm

clean:
	rm -f $(BIN)
	rm -f $(OBJ)
	make -C lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean all
	make clean

exec:	re
	@echo
	@echo "-------------------------------------------------"
	@echo
	@./$(NAME)

gcovr:
		gcovr --exclude tests
		gcovr --exclude tests --branches

tests_run:	fclean
		gcc -o $(NAME_TESTS) $(SRC) $(SRC_TESTS) --coverage -lcriterion
		./$(NAME_TESTS)
