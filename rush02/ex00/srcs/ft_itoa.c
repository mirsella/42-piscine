/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:11:23 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/01 17:49:57 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_nbrlen(int num)
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

// don't support negative numbers
char	*ft_itoa(int value)
{
	char	*str;
	int		len;

	if (value == 0)
		return ("0");
	len = ft_nbrlen(value);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (value)
	{
		str[len - 1] = value % 10 + '0';
		value = value / 10;
		len--;
	}
	return (str);
}
