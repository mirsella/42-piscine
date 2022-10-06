/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:58:22 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/06 22:09:09 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

t_list	*ft_create_elem(void *data)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		list->data = malloc(sizeof(data) * ft_strlen(data));
		ft_strcpy(list->data, data);
		list->next = NULL;
	}
	return (list);
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	t_list	*last;
	int	i;

	i = 0;
	last = 0;
	list = 0;
	while (i < size)
	{
		list = ft_create_elem(strs[i]);
		list->next = last;
		last = list;
		i++;
	}
	return (list);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	printlist(t_list *begin_list)
{
	t_list *list;

	list = begin_list;
	while (list)
	{
		printf("%s\n", (char *)list->data);
		list = list->next;
	}
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*i;
	t_list	*j;
	t_list	*tmp;

	if (!*begin_list || !begin_list)
		return ;
	i = *begin_list;
	while(i->next)
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

void	free_fct(void *data)
{
	free(data);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*list;
	t_list	*last;

	if (!*begin_list || !begin_list)
		return ;
	list = (*begin_list)->next;
	last = *begin_list;
	while (list)
	{
		if (cmp(list->data, data_ref) == 0)
		{
			last->next = list->next;
			free_fct(list->data);
			free(list);
			list = last->next;
		}
		else
		{
			last = list;
			list = list->next;
		}
	}
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		list = *begin_list;
		*begin_list = (*begin_list)->next;
		free_fct(list->data);
		free(list);
	}
}

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc > 0)
	{
		list = ft_list_push_strs(argc, argv);
		printlist(list);
		printf("------------------------------------------\n");
		// ft_list_sort(&list, &ft_strcmp);
		// printlist(list);
		// printf("------------------------------------------\n");
		ft_list_remove_if(&list, "foo", &ft_strcmp, &free_fct);
		printlist(list);
	}

}
