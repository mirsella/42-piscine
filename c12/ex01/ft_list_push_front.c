/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:14:38 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/04 20:44:03 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*l;

	if (*begin_list)
	{
		l = ft_create_elem(data);
		l->next = *begin_list;
		*begin_list = l;
	}
	else
		*begin_list = ft_create_elem(data);
}
