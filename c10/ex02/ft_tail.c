/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:13:00 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/06 14:06:05 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putstr(char *str);
void	ft_display_fd_tail(int fd, int size);
void	ft_display_file_tail(char *file, int size, int nl[2], char *progname);
void	printfilename(int filecount, char *str);

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

void	ft_display(int argc, char **argv, int i, int size)
{
	int	newline[2];

	newline[1] = argc - i;
	newline[0] = 0;
	if (i == argc)
		ft_display_fd_tail(0, size);
	while (i < argc)
	{
		if (newline[1] > 1 && i < argc - 1)
			newline[0] = 1;
		else
			newline[0] = 0;
		if (argv[i][0] == '-' || newline[1] == 0)
		{
			printfilename(newline[1], "standard input");
			ft_display_fd_tail(0, size);
		}
		else
		{
			ft_display_file_tail(argv[i], size, newline, argv[0]);
		}
		i++;
	}
}

int	isnumber(char *str, char *progname)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (1);
	ft_putstr(progname);
	ft_putstr(": invalid number of bytes: ‘");
	ft_putstr(str);
	ft_putstr("’\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	size;

	i = 2;
	size = 0;
	if (argc < 2)
		return (0);
	if (argv[1][0] == '-' && argv[1][1] == 'c')
	{
		if (argv[1][2] == '\0')
		{
			if (isnumber(argv[i], argv[0]))
				size = ft_atoi(argv[i++]);
		}
		else
		{
			if (isnumber(argv[1] + 2, argv[0]))
				size = ft_atoi(argv[1] + 2);
			i = 2;
		}
	}
	if (size <= 0)
		return (1);
	ft_display(argc, argv, i, size);
	return (0);
}
