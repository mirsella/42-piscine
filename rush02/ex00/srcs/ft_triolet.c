/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triolet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:30:25 by tgibier           #+#    #+#             */
/*   Updated: 2022/10/04 16:04:33 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"
#include <stdio.h>

int	printnumbers(char *filename, char *str, int mill, int last);
int	printkey(char *filename, int key, int last);

int	nbcase(char *str, char *triolet, int size, int i)
{
	if (size % 3 == 1 && i == 0)
	{
		triolet[0] = '0';
		triolet[1] = '0';
		triolet[2] = str[i];
		i++;
	}
	else if (size % 3 == 2 && i == 0)
	{
		triolet[0] = '0';
		triolet[1] = str[i];
		triolet[2] = str[i + 1];
		i += 2;
	}
	else
	{
		triolet[0] = str[i];
		triolet[1] = str[i + 1];
		triolet[2] = str[i + 2];
		i += 3;
	}
	triolet[3] = '\0';
	return (i);
}

int	isnextallzero(char *str, int i)
{
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_triolet(char *filename, char	*str)
{
	int		size;
	char	triolet[4];
	int		i;
	int		mill;
	int		last;

	last = 0;
	if (ft_atoi(str) == 0)
		if (!printkey(filename, 0, 1))
			return (1);
	while (*str == '0')
		str++;
	size = ft_strlen(str);
	mill = (size - 1) / 3;
	i = 0;
	while (i < size)
	{	
		i = nbcase(str, triolet, size, i);
		if (!(i < size) || isnextallzero(str, i))
			last = 1;
		if (printnumbers(filename, triolet, mill, last) == 0)
			return (0);
		mill--;
	}
	return (1);
}
