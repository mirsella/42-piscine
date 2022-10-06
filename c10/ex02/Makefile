all: ft_tail

ft_tail: ft_tail.o
	gcc -g3 -Wall -Wextra -Werror -o ft_tail ft_tail.o ft_display.o

ft_tail.o:
	gcc -g3 -Wall -Wextra -Werror -c ft_tail.c ft_display.c

clean:
	rm -f *.o

fclean: clean
	rm -f ft_tail

re: clean all
