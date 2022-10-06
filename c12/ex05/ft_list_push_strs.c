/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:41:39 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/06 15:29:58 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*l;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = 0;
	l = 0;
	while (i < size)
	{
		l = ft_create_elem(strs[i]);
		l->next = tmp;
		tmp = l;
		i++;
	}
	return (l);
}
