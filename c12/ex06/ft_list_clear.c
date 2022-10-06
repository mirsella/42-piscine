/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:07:51 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/05 11:29:24 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*l;
	t_list	*tmp;

	l = begin_list;
	while (l)
	{
		tmp = l->next;
		free_fct(l->data);
		free(l);
		l = tmp;
	}
}
