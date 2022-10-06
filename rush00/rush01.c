/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altsobgn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:27:03 by altsobgn          #+#    #+#             */
/*   Updated: 2022/09/17 19:27:08 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	draw(int x, int y, int row, int col)
{
	if ((col == 0 && row == 0)
		|| (row == y - 1 && col == x - 1 && x > 1 && y > 1))
	{
		ft_putchar('/');
	}
	else if ((col == x - 1 && row == 0) || (row == y - 1 && (col == 0)))
	{
		ft_putchar('\\');
	}
	else if (((row == 0 || row == y - 1) && (col > 0 || col < x - 1))
		|| ((col == 0 || col == x - 1) && (row > 0 && row < y - 1)))
	{
		ft_putchar('*');
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
