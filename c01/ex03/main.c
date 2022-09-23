/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:19:00 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/21 18:25:49 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
    *div = a / b;
    *mod = a % b;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int a;
	int b;
	int div;
	int mod;

	a = 10;
	b = 3;
	ft_div_mod(a, b, &div, &mod);
	ft_putchar(div + '0');
	ft_putchar('\n');
	ft_putchar(mod + '0');
	return (0);
}
