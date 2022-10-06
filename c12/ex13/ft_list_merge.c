/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:05:38 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/06 16:14:32 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list **begin_list2)
{
	t_list	*tmp;

	tmp = *begin_list1;
	if (*begin_list1 == 0)
		*begin_list1 = *begin_list2;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *begin_list2;
	}
}
