/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:45:03 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/20 23:57:29 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isbase(char *base)
{
	int	j;
	int	i;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] < 32 || base[i] > 126))
			return (0);
		j = 0;
		while (base[j] != '\0')
		{
			if (base[j] == base[i] && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	int		i;
	int		nbr_final[100];
	long	nb;

	nb = nbr;
	base_len = ft_strlen(base);
	if (! ft_isbase(base))
		return ;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == 0)
		ft_putchar(base[0]);
	i = 0;
	while (nb != 0)
	{
		nbr_final[i] = nb % base_len;
		nb = nb / base_len;
		i++;
	}
	while (--i >= 0)
		ft_putchar(base[nbr_final[i]]);
}
