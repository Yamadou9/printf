
NAME = libftprintf.a

SRC =   ft_hexa.c ft_putnbr.c ft_type.c

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I -g0.

RM = rm -f

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
