/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:40:53 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/29 15:50:50 by lgillard         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	destlen;

	i = 0;
	destlen = ft_strlen(dest);
	while (src[i])
	{
		dest[destlen + i] = src[i];
		i++;
	}
	return (dest);
}

int	ft_totallen(int size, char **strs, char *sep)
{
	int	i;
	int	strslen;

	i = 0;
	strslen = 0;
	if (size == 0)
		return (0);
	while (i < size)
	{
		strslen += ft_strlen(strs[i]);
		i++;
	}
	strslen += ft_strlen(sep) * (size - 1);
	return (strslen);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		word;
	char	*str;

	str = malloc(sizeof(char) * (ft_totallen(size, strs, sep) + 1));
	if (!str)
		return (0);
	str[0] = 0;
	if (size == 0)
		return (str);
	word = 0;
	while (word < size)
	{
		ft_strcat(str, strs[word]);
		if (word < size - 1)
			ft_strcat(str, sep);
		word++;
	}
	str[ft_totallen(size, strs, sep)] = 0;
	return (str);
