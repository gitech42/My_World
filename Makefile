##
## EPITECH PROJECT, 2021
## my world
## File description:
## makefile
##

SRC	=	src/*.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_world

CFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lm -g

CC	=	gcc

CPPFLAGS	=	-I includes

all:
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(CPPFLAGS)
clean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
	rm -rf *~

fclean:	clean

re:	fclean	all
