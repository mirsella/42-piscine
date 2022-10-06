/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:21:13 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/06 17:18:53 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *begin_list;
	if (current && cmp(current->data, data_ref) == 0)
	{
		next = current->next;
		free_fct(current->data);
		free(current);
		current = next;
	}
	*begin_list = current;
	while (current && current->next)
	{
		if (cmp(current->next->data, data_ref) == 0)
		{
			next = current->next->next;
			free_fct(current->next->data);
			free(current->next);
			current->next = next;
		}
		else
			current = current->next;
	}
}
