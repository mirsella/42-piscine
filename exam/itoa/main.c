/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:23:21 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/05 17:33:44 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_intlen(int num)
{
	int	counter;

	counter = 0;
	if (num < 0)
	{
		counter++;
	}
	while (num)
	{
		num = num / 10;
		counter++;
	}
	return (counter);
}

char	*itoa(int value)
{
	int	len;
	char	*str;
	int	neg = 1;

	len = ft_intlen(value);
	str = malloc(sizeof(char) * len + 1);
	str[len] = 0;
	len--;
	if (value == 0)
	{
		str = malloc(1);
		str[0] = '0';
		return (str);
	}
	if (value < 0)
	{
		neg = -1;
		str[0] = '-';
	}
	while ((neg > 0 && len >= 0) || (neg < 0 && len > 0))
	{
		str[len] = (value % 10 * neg) + '0';
		value /= 10;
		len--;
	}
	return (str);
}

int	main(void)
{
	printf("%s\n", itoa(155));
	printf("%s\n", itoa(-155));
	printf("%s\n", itoa(0));
	printf("%s\n", itoa(2147483647));
	printf("%s\n", itoa(-2147483648));
	return (0);
}
