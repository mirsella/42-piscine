/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:40:53 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/02 09:28:48 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_totallen(int size, char **strs, char *sep)
{
	int	i;
	int	strslen;

	i = 0;
	strslen = 0;
	while (i < size)
	{
		strslen = strslen + ft_strlen(strs[i]);
		i++;
	}
	strslen = strslen + (ft_strlen(sep) * (size - 1));
	return (strslen);
}

char	*ft_join(int size, char **strs, char *sep, char *dest)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		while (k < ft_strlen(strs[i]))
			dest[j++] = strs[i][k++];
		if (i < size - 1)
		{
			k = 0;
			while (k < ft_strlen(sep))
				dest[j++] = sep[k++];
		}
		k = 0;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;

	if (size == 0)
	{
		dest = malloc(sizeof(char));
		if (dest == NULL)
			return (NULL);
		*dest = 0;
		return (dest);
	}
	dest = malloc(sizeof(*dest) * (ft_totallen(size, strs, sep) + 1));
	if (dest == NULL)
		return (NULL);
	return (ft_join(size, strs, sep, dest));
}
