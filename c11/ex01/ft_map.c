/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:36:24 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/30 09:55:13 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*res;

	i = 0;
	res = malloc(sizeof(int) * length);
	if (!res)
		return (NULL);
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}
