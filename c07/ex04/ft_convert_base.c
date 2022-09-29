/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:10:24 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/29 09:35:40 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_nbrlen(int nbr, char *base);

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	neg;
	int	res;

	i = 0;
	j = 0;
	neg = 1;
	res = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg *= -1;
	}
	while (str[i] && str[i] != '+' && str[i] != '-')
	{
		while (base[j] && str[i] != base[j])
			j++;
		if (base[j] == '\0')
			return (res * neg);
		res = res * ft_strlen(base) + j;
		j = 0;
		i++;
	}
	return (res * neg);
}

char	*ft_itoa_base(int nbr, char *base)
{
	char	*str;
	int		i;
	int		neg;

	i = ft_nbrlen(nbr, base);
	neg = 1;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (nbr < 0)
	{
		neg = -1;
		str[0] = '-';
	}
	while (i > 0 && nbr != 0)
	{
		str[i - 1] = base[(nbr % ft_strlen(base)) * neg];
		nbr /= ft_strlen(base);
		i--;
	}
	return (str);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*str;

	if (!nbr || !ft_check_base(base_from) || !ft_check_base(base_to))
		return (0);
	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	nb = ft_atoi_base(nbr, base_from);
	if (nb == 0)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		str[0] = base_to[0];
		str[1] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (ft_nbrlen(nb, base_to) + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, ft_itoa_base(nb, base_to));
	return (str);
}
