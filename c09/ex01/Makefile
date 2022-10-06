OBJS = srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o

%.o: %.c
	gcc -Wall -Wextra -Werror -c -I./includes $< -o $@

libft.a: ${OBJS}
	ar -rcs libft.a ${OBJS}

all: libft.a

clean:
	rm -f ${OBJS}

fclean:		clean
	rm -f libft.a

re:			fclean all

.PHONY:		all clean fclean re
