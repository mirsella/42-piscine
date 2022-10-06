/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:54:57 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/03 09:56:33 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	*strcpytrim(char *dest, char *src)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (src[start])
	{
		while (src[start] == ' ' || src[start] == '\t')
			start++;
		end = start;
		while (src[end] && src[end] != ' ' && src[end] != '\t')
			end++;
		ft_strncat(dest, src + start, end - start);
		start = end ;
	}
	dest[end] = '\0';
	return (dest);
}

int	get_line_sizefd(int fd, int line)
{
	char	buf;
	char	lbuf;
	int		line_size;
	int		nb_lines;
	int		emptyline;

	nb_lines = 0;
	line_size = 0;
	lbuf = '\0';
	emptyline = 0;
	while (read(fd, &buf, 1))
	{
		if ((lbuf == '\n' || line == 0) && buf == '\n' && line == nb_lines)
			emptyline = 1;
		if (buf == '\n')
			nb_lines++;
		else if (nb_lines == line)
			line_size++;
		lbuf = buf;
	}
	if (emptyline == 0 && line_size == 0)
		return (-1);
	return (line_size);
}

int	get_line_size(char *filename, int line)
{
	int	fd;
	int	line_size;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	line_size = get_line_sizefd(fd, line);
	close(fd);
	return (line_size);
}

int	error(int fd, int line_size, char *str)
{
	if (line_size == -1 || str == NULL || fd == -1)
	{
		free(str);
		close(fd);
		return (1);
	}
	return (0);
}

char	*get_line(char *filename, int line)
{
	int		fd;
	int		nb_lines;
	int		line_size;
	char	*str;
	char	buf;

	fd = open(filename, O_RDONLY);
	line_size = get_line_size(filename, line);
	str = malloc(sizeof(char) * (line_size + 1));
	if (error(fd, line_size, str))
		return (NULL);
	nb_lines = 0;
	line_size = 0;
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			nb_lines++;
		else if (nb_lines == line)
			str[line_size++] = buf;
	}
	str[line_size] = '\0';
	close(fd);
	return (str);
}
