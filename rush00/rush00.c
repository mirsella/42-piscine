/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 08:51:13 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/17 15:53:56 by mprioux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	draw(int x, int y, int row, int col)
{
	if (x < 0 || y < 0)
		return ;
	if ((col == 0 || col == x - 1) && (row == 0 || row == y - 1))
	{
		ft_putchar('o');
	}
	else if ((col == 0 || col == x - 1) && (row > 0 && row < y - 1))
	{
		ft_putchar('|');
	}
	else if ((row == 0 || row == y - 1) && (col > 0 || col < x - 1))
	{
		ft_putchar('-');
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
