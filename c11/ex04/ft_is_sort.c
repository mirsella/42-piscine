/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:05:41 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/30 10:33:45 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	croissant;
	int	decroissant;

	i = 0;
	croissant = 1;
	decroissant = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			croissant = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			decroissant = 0;
		i++;
	}
	if (croissant == 1 || decroissant == 1)
		return (1);
	else
		return (0);
}
