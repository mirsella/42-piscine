#include <stdio.h>
#include "ft_strncpy.c"

int	main()
{
	char	dest[11];
	char	src[11] = "Hello World";
	unsigned int	n = 13;

	printf("%s", ft_strncpy(dest, src, n));
}
