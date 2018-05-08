##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Made by Hugo SOHM
##

SRC	=	my_getnbr.c		\
		my_printf.c		\
		my_putchar.c		\
		my_putnbr_base.c	\
		my_put_nbr.c		\
		my_putstr.c		\
		my_strlen.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3 -W -Wall -Wextra -I ../../include/

NAME	=	libmy.a

all:		$(NAME)

$(NAME):
		gcc -c $(SRC)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
