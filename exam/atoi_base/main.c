/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:37:03 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/05 18:00:28 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	valueof(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else
		return (-1);

}

int	ft_atoi_base(char *str, int base)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (valueof(str[i]) >= 0 && valueof(str[i]) < base)
	{
		nbr = nbr * base + valueof(str[i]);
		i++;
	}
	return (nbr * sign);
}


int	main(void)
{
	printf("%d\n", ft_atoi_base("2a", 16));
	printf("%d\n", ft_atoi_base("0", 16));
	printf("%d\n", ft_atoi_base("", 16));
	printf("%d\n", ft_atoi_base("7fffffff", 16));
	printf("%d\n", ft_atoi_base("-80000000", 16));
	return (0);
}
