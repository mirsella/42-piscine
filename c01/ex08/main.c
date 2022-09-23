#include <stdio.h>
#include "ft_sort_int_tab.c"

int	main()
{
	int	tab[5] = {400,32,1,0,5};
	int	size = 5;
	ft_sort_int_tab(tab, size);
	int i = 0;
	while (i < size)
	{
		printf("%d%c", tab[i], ',');
		i++;
	}
	return (0);
}
