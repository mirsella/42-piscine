/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:48:08 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/02 22:56:04 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"

int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	calltriolet(int argc, char **argv)
{
	int		lineindex;
	int		linecount;

	lineindex = 0;
	linecount = 0;
	if (argc == 3)
	{
		if (is_valid_input(argv[2]) != 1)
			return (-1);
		if (is_valid_dict(argv[1], lineindex, linecount) != 1)
			return (-2);
		if (ft_triolet(argv[1], argv[2]) != 1)
			return (-3);
	}
	else if (argc == 2)
	{
		if (is_valid_input(argv[1]) != 1)
			return (-1);
		if (is_valid_dict(DEFAULT_FILE, lineindex, linecount) != 1)
			return (-2);
		if (ft_triolet(DEFAULT_FILE, argv[1]) != 1)
			return (-3);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	retcode;

	retcode = calltriolet(argc, argv);
	if (retcode == -1 || retcode == -2)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	else if (retcode == -3)
	{
		ft_putstr("\nError\n");
		return (1);
	}
	return (0);
}
