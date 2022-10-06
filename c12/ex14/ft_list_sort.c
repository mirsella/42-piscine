/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:17:27 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/06 16:46:37 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*i;
	t_list	*j;
	t_list	*tmp;

	i = *begin_list;
	if (i == 0)
		return ;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (cmp(i->data, j->data) > 0)
			{
				tmp = i->data;
				i->data = j->data;
				j->data = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
}
