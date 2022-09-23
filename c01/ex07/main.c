#include <stdio.h>
#include "ft_rev_int_tab.c"

int	main()
{
	int	tab[5] = {1, 2, 3, 4, 5};
	int	size = 5;
	ft_rev_int_tab(tab, size);
	int i = 0;
	while(i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	return (0);
}
