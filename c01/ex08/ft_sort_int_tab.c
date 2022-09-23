/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:01:41 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/15 22:40:31 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	index;
	int	index_search;

	index = 0;
	index_search = 0;
	while (index < size)
	{
		while (index_search < size)
		{
			if (tab[index_search] < tab[index])
			{
				temp = tab[index];
				tab[index] = tab[index_search];
				tab[index_search] = temp;
			}
			else
			{
			index_search++;
			}
		}
		index++;
		index_search = index + 1;
	}
}
