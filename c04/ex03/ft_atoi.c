/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:36:14 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/19 10:17:32 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	nbminus;

	i = 0;
	result = 0;
	nbminus = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nbminus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nbminus % 2 != 0)
			result = result * 10 - (str[i] - '0');
		else
			result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}
