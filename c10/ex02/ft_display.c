/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:42:23 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/06 20:23:04 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	printfilename(int filecount, char *str)
{
	if (filecount > 1)
	{
		ft_putstr("==> ");
		ft_putstr(str);
		ft_putstr(" <==\n");
	}
}

void	ft_display_fd_tail(int fd, int size)
{
	int		sizereturned;
	char	buf[4096];

	sizereturned = 1;
	while (sizereturned > 0)
	{
		sizereturned = read(fd, buf, 4096);
		if (sizereturned < size)
			write(1, buf, sizereturned);
		else
			write(1, buf + sizereturned - size, size);
	}
}

void	ft_error(char *progname, char *filename)
{
	if (errno == 21)
	{
		ft_putstr(progname);
		ft_putstr(": error reading '");
		ft_putstr(filename);
		ft_putstr("': ");
		ft_putstr(strerror(errno));
	}
	else
	{
		ft_putstr(progname);
		ft_putstr(": cannot open '");
		ft_putstr(filename);
		ft_putstr("': ");
		ft_putstr(strerror(errno));
	}
	ft_putstr("\n");
}

void	ft_display_file_tail(char *file, int size, int nl[2], char *progname)
{
	int		fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		ft_error(progname, file);
	}
	else
	{
		printfilename(nl[1], file);
		ft_display_fd_tail(fd, size);
		if (nl[0] == 1)
			ft_putstr("\n");
		close(fd);
	}
}
