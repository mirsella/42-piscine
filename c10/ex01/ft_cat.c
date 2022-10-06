/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:13:00 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/03 15:05:26 by lgillard         ###   ########.fr       */
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

void	ft_display_file(char *file)
{
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("ft_cat: ");
		ft_putstr(file);
		ft_putstr(": ");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
	}
	else
	{
		while (read(fd, &c, 1) > 0)
			write(1, &c, 1);
		close(fd);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	i = 1;
	if (argc == 1 || (argv[i][0] == '-' && argv[i][1] == '\0'))
	{
		while (read(0, &c, 1) > 0)
			write(1, &c, 1);
	}
	else
	{
		while (i < argc)
		{
			ft_display_file(argv[i]);
			i++;
		}
	}
	return (0);
}
