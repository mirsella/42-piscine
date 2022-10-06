all: ft_cat

ft_cat: ft_cat.o
	gcc -Wall -Wextra -Werror -o ft_cat ft_cat.o

ft_cat.o:
	gcc -Wall -Wextra -Werror -c ft_cat.c

clean:
	rm -f ft_cat.o

fclean: clean
	rm -f ft_cat

re: clean all
