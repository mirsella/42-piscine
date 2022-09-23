/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:23:21 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/23 14:24:10 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_intlen(int num)
{
	int	counter;

	counter = 0;
	while (num)
	{
		num = num / 10;
		counter++;
	}
	return (counter);
}

char	*itoa(int value)
{
	int		i;
	int		j;
	char	*resultrev;
	char	*result;

	i = 0;
	resultrev = malloc(sizeof(char) * ft_intlen(value) + 1);
	result = malloc(sizeof(char) * ft_intlen(value) + 1);
	while (value)
	{
		resultrev[i] = (value % 10) + '0';
		value = value / 10;
		i++;
	}
	resultrev[i--] = '\0';
	j = 0;
	while (resultrev[i])
	{
		result[j] = resultrev[i];
		i--;
		j++;
	}
	return (result);
}

int	main(void)
{
	char	*str;
	int		nb;

	nb = 1203456789;
	str = itoa(nb);
	printf("%s\n", str);
	return (0);
}
