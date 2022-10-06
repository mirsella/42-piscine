/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:17:07 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/02 09:23:16 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		if (str[i] && !ft_is_charset(str[i], charset))
			count++;
		while (str[i] && !ft_is_charset(str[i], charset))
			i++;
	}
	return (count);
}

char	*getword(char *str, int i, char *charset)
{
	char	*res;
	int		j;
	int		wordlen;

	j = 0;
	wordlen = 0;
	while (str[i + wordlen] && !ft_is_charset(str[i + wordlen], charset))
		wordlen++;
	res = malloc(sizeof(char) * (wordlen + 1));
	while (str[i] != '\0' && !ft_is_charset(str[i], charset))
	{
		res[j] = str[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		wordcount;
	char	**tab;

	i = 0;
	wordcount = 0;
	tab = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	while (str[i])
	{
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		if (str[i])
		{
			tab[wordcount] = getword(str, i, charset);
			wordcount++;
		}
		while (str[i] && !ft_is_charset(str[i], charset))
			i++;
	}
	tab[wordcount] = 0;
	return (tab);
}
