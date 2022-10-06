/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:00:15 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/05 16:58:48 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int	ft_isoperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	return (0);
}

void	filloperators(t_op *op)
{
	op[0].op = '+';
	op[0].f = &ft_add;
	op[1].op = '-';
	op[1].f = &ft_sub;
	op[2].op = '*';
	op[2].f = &ft_mul;
	op[3].op = '/';
	op[3].f = &ft_div;
	op[4].op = '%';
	op[4].f = &ft_mod;
}

int	main(int argc, char **argv)
{
	int		i;
	t_op	op[5];

	i = 0;
	filloperators(op);
	if (argc == 4)
	{
		if (ft_isoperator(argv[2][0]) && argv[2][1] == '\0')
		{
			while (i < 5)
			{
				if (argv[2][0] == op[i].op)
					op[i].f(ft_atoi(argv[1]), ft_atoi(argv[3]));
				i++;
			}
		}
		else
			ft_putnbr(0);
		ft_putchar('\n');
	}
	return (0);
}
