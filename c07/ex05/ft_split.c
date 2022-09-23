/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:17:07 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/22 19:09:35 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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
		if (ft_is_charset(str[i], charset))
		{
			while (ft_is_charset(str[i], charset) && str[i] != '\0')
				i++;
			if (str[i] != '\0')
				count++;
		}
		i++;
	}
	return (count);
}

char	*strrange(char *str, char *charset, int start, int end)
{
	char	*res;
	int		i;

	i = 0;
	// if (ft_is_charset(str[start], charset))
	// {
	// 	printf("str[start] = %c start = %d\n", str[start], start);
	// 	return (0);
	// }
	res = malloc(sizeof(char) * (end - start + 1));
	while (start < end)
	{
		res[i] = str[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

char	*splitn(char *str, char *charset, int i, int *start)
{
	int	startsep;
	int	tmpstart;
	char	*res;

	tmpstart = *start;
	startsep = 0;
	if (ft_is_charset(str[i], charset))
	{
		startsep = i;
		while (ft_is_charset(str[i], charset))
		{
			i++;
		}
		start = &i;
		// res = strrange(str, charset, tmpstart, startsep);
		// if (res == 0)
		// 	return (0);
		// return (res);
		return (strrange(str, charset, tmpstart, startsep));
	}
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		wordcount;
	int		start;
	char	**tab;

	i = 0;
	start = 0;
	wordcount = 0;
	tab = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	while (wordcount < count_words(str, charset))
	{
		if (str[i] == '\0')
			break ;
		tab[wordcount] = splitn(str, charset, i, &start);
		i++;
		if (tab[wordcount])
		{
			while (ft_is_charset(str[i], charset))
				i++;
			wordcount++;
			start = i;
		}
	}
	tab[wordcount] = 0;
	return (tab);
}
