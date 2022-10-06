/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:21:53 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/05 00:24:53 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list		*l;

	l = *begin_list;
	if (l)
	{
		while (l->next)
			l = l->next;
		l->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
