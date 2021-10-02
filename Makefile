##
## EPITECH PROJECT, 2019
## make file
## File description:
## sdf
##

SRC	=	src/main.c	\
		src/utils.c	\
		src/manager.c	\
		src/init.c	\
		src/map.c	\
		src/game_of_life.c	\
		src/wolfram.c	\

OBJ     =       $(SRC:.c=.o)

NAME    =       gol

CFLAGS	=	-Iinclude -g

CSFML	=	-l csfml-graphics -l csfml-window -l m -l csfml-system -lcsfml-audio

all:    $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CSFML)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
