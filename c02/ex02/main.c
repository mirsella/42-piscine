#include "ft_str_is_alpha.c"
#include <stdio.h>

int	main()
{
	int	result = ft_str_is_alpha("ab?cd");
	printf("%d", result);
	result = ft_str_is_alpha("Z");
	printf("%d", result);
}
