/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:55:36 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/18 21:26:38 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	printnums(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
		ft_putchar(tab[i++] + '0');
	if (tab[0] < (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	incrementOne(int *tab, int n, int index)
{

	int	indexFirst;

	n++;
	indexFirst = index - 1;
	while (tab[index - 1] == 8)
	{
		indexFirst--;
	}
	index = indexFirst;
	while (tab[index + 1] >= 8)
	{

		if (tab[index] == 8)
		{
			tab[index]++;
			index++;
		}
		else if (tab[index] == 9)
		{
			tab[index] = tab[index - 1] + 1;
			index++;
		}
		else
		{
			tab[index]++;
			tab[index + 1] = tab[index] + 1;
		}

	}
}

void	increment(int *tab, int n)
{
	int	index;

	index = n - 1;

	while (index >= 0)
	{
		if (tab[index] == 9)
		{
			incrementOne(tab, n, index);
		}
		else if (index == n - 1)
		{
			tab[index]++;
		}
		index--;
	}
}

void	ft_print_combn(int n)
{
	int	tab[9];
	int	index;

	index = 0;
	while (index < n)
	{
		tab[index] = index;
		index++;
	}

	printnums(tab, n);
	while (tab[0] < 10 - n)
	{
		increment(tab, n);
		printnums(tab, n);
	}
}
