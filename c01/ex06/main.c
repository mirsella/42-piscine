#include <stdio.h>
#include "ft_strlen.c"

int	main()
{
	char	*str = "Hello World!";
	ft_strlen(str);
	printf("%d", ft_strlen(str));
	return (0);
}
