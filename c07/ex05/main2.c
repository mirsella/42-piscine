#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str, char *charset);

int	main(void)
{
	char *str = "  ,   Hello World haha  , zzzzzzzz";
	char *charset = " ,";
	char **tab = ft_split(str, charset);
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
