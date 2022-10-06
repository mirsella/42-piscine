/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:58:07 by tgibier           #+#    #+#             */
/*   Updated: 2022/10/02 23:33:58 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"
#include <stdio.h>

int	printkey(char *filename, int key, int last)
{
	int		line;
	char	*str;
	char	*str2;

	str2 = ft_itoa(key);
	line = get_key_line(filename, str2);
	free(str2);
	str = get_data(filename, line);
	if (str)
	{
		ft_putstr(str);
		if (last == 0)
			ft_putstr(" ");
		free(str);
		return (1);
	}
	return (0);
}

int	printkeychar(char *filename, char *key, int nb, int last)
{
	int		line;
	char	*str;

	line = get_key_line(filename, key);
	str = get_data(filename, line);
	if (str)
	{
		ft_putstr(str);
		free(str);
		if (last == 0 || nb % 100 != 0)
			ft_putstr(" ");
		return (1);
	}
	return (0);
}

int	printnumbers2(char *filename, int nb, int last)
{
	if (nb % 100 >= 10 && nb % 100 <= 20)
	{
		if (! printkey(filename, nb % 100, last))
			return (0);
		return (1);
	}
	else
	{
		if (nb / 10 * 10 != 0 && nb % 10 != 0)
		{
			if (! printkey(filename, nb / 10 * 10, 0))
				return (0);
		}
		else if (nb / 10 * 10 != 0)
		{
			if (! printkey(filename, nb / 10 * 10, last))
				return (0);
		}
		if (nb % 10 != 0)
			if (! printkey(filename, nb % 10, last))
				return (0);
	}
	return (1);
}

int	nbcaseprint(int nb, char *filename, int last, int mill)
{
	if (mill > 0 && last == 1)
		last = 0;
	if (nb == 0)
		return (1);
	else if (nb / 100 != 0)
	{
		if (! printkey(filename, nb / 100, 0))
			return (0);
		if (! printkeychar(filename, "100", nb, last))
			return (0);
		if (! printnumbers2(filename, nb % 100, last))
			return (0);
	}
	else if (nb / 10 != 0)
	{
		if (! printnumbers2(filename, nb, last))
			return (0);
	}
	else
	{
		if (! printkey(filename, nb, last))
			return (0);
	}
	return (1);
}

int	printnumbers(char *filename, char *triolet, int mill, int last)
{
	int		nb;
	int		i;
	char	millstr[40];

	nb = ft_atoi(triolet);
	i = 1;
	millstr[0] = '1';
	while (i < mill * 3 + 1)
	{
		millstr[i] = '0';
		i++;
	}
	millstr[i] = '\0';
	if (nbcaseprint(nb, filename, last, mill) == 0)
		return (0);
	if (mill != 0 && nb != 0)
		if (! printkeychar(filename, millstr, 0, last))
			return (0);
	return (1);
}
