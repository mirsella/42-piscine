#include "ft_strlcpy.c"
#include <stdio.h>

int	main()
{
	char	str[] = "Hello World!";
	char	dest[sizeof(str)];
	printf("%d\n", ft_strlcpy(dest, str, 10));
	printf("%s\n", dest);
}
