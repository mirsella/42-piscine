#include <stdio.h>
#include "ft_strcpy.c"

int	main()
{
	char	dest[8];
	char	src[12] = "Hello World";

	ft_strcpy(dest, src);
	printf("%s", dest);
}
