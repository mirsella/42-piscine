/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:16:04 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/25 18:31:09 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putstr(char *str);

int	throwerror(void)
{
	ft_putstr("Error\n");
	return (0);
}

int	*parsearg(char *str)
{
	int	*viewers;
	int	i;
	int	j;

	viewers = malloc(sizeof(int) * 16);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] >= '1' && str[i] <= '4')
			viewers[j++] = str[i] - '0';
		else
			return (0);
		i++;
	}
	if (j != 16)
		return (0);
	return (viewers);
}
