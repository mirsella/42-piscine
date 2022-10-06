/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:29:16 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/03 14:57:34 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i - 1);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		size;
	int		i;
	char	*tmp;

	size = 0;
	while (tab[size])
		size++;
	while (--size >= 0)
	{
		i = 1;
		while (i <= size)
		{
			if (cmp(tab[i - 1], tab[i]) > 0)
			{
				tmp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = tmp;
			}
			i++;
		}
	}
}
