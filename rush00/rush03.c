/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 08:51:13 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/17 15:06:42 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	draw(int x, int y, int row, int col)
{
	if (col == 0 && (row == 0 || row == y - 1))
	{
		ft_putchar('A');
	}
	else if (col == x - 1 && (row == 0 || row == y - 1))
	{
		ft_putchar('C');
	}
	else if (((row == 0 || row == y - 1) && (col > 0 || col < x - 1))
		|| ((col == 0 || col == x - 1) && (row > 0 && row < y - 1)))
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	col;
	int	row;

	if (x < 0 || y < 0)
		return ;
	col = 0;
	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			draw(x, y, row, col);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
