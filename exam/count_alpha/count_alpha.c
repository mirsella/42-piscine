/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:40:00 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/05 18:57:37 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	count[27] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char 	*str = argv[1];
	int	i;
	int	last;

	if (argc == 2)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				count[str[i] - 'A']++;
			if (str[i] >= 'a' && str[i] <= 'z')
				count[str[i] - 'a']++;
			i++;
		}
		i = 0;
		while (i < 26)
			if (count[i++] > 0)
				last = i;
		i = 0;
		while (i < 26)
		{
			if (count[i] > 0)
				printf("%d%c", count[i], 'a' + i);
			if (i < last - 1)
				printf(", ");
			i++;
		}
	}
	printf("\n");
}
