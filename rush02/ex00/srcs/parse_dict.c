/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:13:17 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/02 22:40:11 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"
#include <unistd.h>

int	is_valid_line(char *line)
{
	int		i;

	i = 0;
	if (line == NULL)
		return (-6);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != ':')
		return (-5);
	i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while ((line[i] >= 32 && line[i] <= 126) || line[i] == ' ')
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '\0')
	{
		return (-4);
	}
	return (1);
}

int	is_valid_emptyline(char *line)
{
	int	lineindex;

	lineindex = 0;
	while (line[lineindex] == ' ' || line[lineindex] == '\t')
		lineindex++;
	if (line[lineindex] == '\n')
		lineindex++;
	if (line[lineindex] != '\0')
		return (0);
	return (1);
}

int	is_valid_dict(char *filename, int lineindex, int linecount)
{
	int		i;
	char	*line;

	i = 0;
	linecount = 0;
	while (i++ || 1)
	{
		line = get_line(filename, i);
		if (line == NULL)
			break ;
		lineindex = 0;
		if (get_line_size(filename, i) == 0)
			continue ;
		if (line[lineindex] == ' ' || line[lineindex] == '\t')
			if (is_valid_emptyline(line) != 1)
				return (-3);
		if (is_valid_line(line) != 1)
			return (is_valid_line(line));
		linecount++;
		free(line);
	}
	free(line);
	if (linecount < 2)
		return (-1);
	return (1);
}

char	*get_data(char *filename, int line)
{
	char	*str;
	char	*data;
	int		i;

	str = get_line(filename, line);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != ':')
		i++;
	data = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (str == NULL || data == NULL)
	{
		free(str);
		free(data);
		return (NULL);
	}
	i++;
	strcpytrim(data, str + i);
	free(str);
	return (data);
}

int	get_key_line(char *filename, char *key)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_line(filename, i);
		if (line == NULL)
			return (-1);
		if (ft_strncmp(line, key, ft_strlen(key)) == 0)
		{
			free(line);
			return (i);
		}
		free(line);
		i++;
	}
}
