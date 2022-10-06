all: rush-02

rush-02:
	cd srcs && gcc -Wall -Wextra -Werror -c -I../includes *.c
	gcc -Wall -Wextra -Werror -o rush-02 srcs/*.o

clean:
	rm -f srcs/*.o

fclean:	clean
	rm -f rush-02

re: fclean all

.PHONY:	all clean fclean re
