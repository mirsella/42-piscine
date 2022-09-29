#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str, char *charset);

int	main(void)
{
	char *str = "vint8rltfiVI	7d2z 5Z3	7O373s6BrsBnurysdfusdygfusygYGHSVjLddk";
	char *charset = "LNkbxYI";
	// char *str = " hello word	";
	// char *charset = " ,!";
	char **tab = ft_split(str, charset);
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
