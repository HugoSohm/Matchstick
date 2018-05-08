##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Made by Hugo SOHM
##

CFLAGS	+=	-Iinclude -W -Wall -Wextra -g

LDFLAGS	+=	-L ./lib/my -lmy

SRC	=	./src/ai.c		\
		./src/get_next_line.c	\
		./src/main.c	\
		./src/map.c	\
		./src/player.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
		make -C lib/my clean
		rm -f $(OBJ)

fclean:	clean
		make -C lib/my fclean
		rm -f $(NAME)

re:		fclean all
