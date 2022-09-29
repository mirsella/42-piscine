/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:55:36 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/27 16:29:21 by lgillard         ###   ########.fr       */
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

int	recursive(int *tab, int n, int i)
{
	int	j;

	j = 0;
	if (i == n)
	{
		printnums(tab, n);
		return (0);
	}
	while (j <= 9)
	{
		tab[i] = j;
		if (i == 0 || tab[i] > tab[i - 1])
			recursive(tab, n, i + 1);
		j++;
	}
	return (0);
}

void	ft_print_combn(int n)
{
	int	tab[9];
	int	i;

	i = 0;
	while (i < 9)
		tab[i++] = 0;
	recursive(tab, n, 0);
}
