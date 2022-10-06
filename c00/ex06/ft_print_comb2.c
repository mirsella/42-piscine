/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:11:13 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/14 17:37:32 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putcomma(int a)
{
	if (a < 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_printint(int num)
{
	if (num < 10)
	{
		ft_putchar('0');
		ft_putchar(num + '0');
	}
	else
	{
		ft_putchar((num / 10) + '0');
		ft_putchar((num % 10) + '0');
	}
}

void	ft_print_comb2(void)
{
	int	comb[2];

	comb[0] = 0;
	while (comb[0] <= 98)
	{
		comb[1] = comb[0] + 1;
		while (comb[1] <= 99)
		{
			ft_printint(comb[0]);
			ft_putchar(' ');
			ft_printint(comb[1]);
			ft_putcomma(comb[0]);
			comb[1]++;
		}
		comb[0]++;
	}
}
