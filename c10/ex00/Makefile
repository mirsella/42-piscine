all: ft_display_file

ft_display_file: ft_display_file.o
	gcc -Wall -Wextra -Werror -o ft_display_file ft_display_file.o

ft_display_file.o:
	gcc -Wall -Wextra -Werror -c ft_display_file.c

clean:
	rm -f *.o *.gch

fclean: clean
	rm -f ft_display_file
