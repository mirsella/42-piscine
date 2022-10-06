/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:17:40 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/25 18:37:37 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		isxvalid(int **grid, int x, int *viewers);
int		isxvalidrev(int **grid, int x, int *viewers);
int		isyvalid(int **grid, int x, int *viewers);
int		isyvalidrev(int **grid, int x, int *viewers);
int		checkduplicatesx(int **grid, int x);
int		checkduplicatesy(int **grid, int y);
void	ft_putchar(char c);

void	printgrid(int **grid)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			ft_putchar(grid[x][y] + '0');
			if (y != 3)
				ft_putchar(' ');
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}

void	setgrid(int **grid, int x, int value)
{
	grid[x][3] = value % 10;
	grid[x][2] = value / 10 % 10;
	grid[x][1] = value / 100 % 10;
	grid[x][0] = value / 1000;
}

int	checkyvalid(int **grid, int *viewers)
{
	int	y;

	y = 0;
	while (y < 4)
	{
		if (isyvalid(grid, y, viewers) == 0
			|| isyvalidrev(grid, y, viewers) == 0
			|| checkduplicatesy(grid, y) == 0)
			return (0);
		y++;
	}
	return (1);
}

int	solve(int **grid, int *viewers, int x)
{
	int	try;

	try = 1234;
	while (try <= 4321)
	{
		setgrid(grid, x, try);
		if (isxvalid(grid, x, viewers) && isxvalidrev(grid, x, viewers)
			&& checkduplicatesx(grid, x))
		{
			if (x == 3)
			{
				if (checkyvalid(grid, viewers))
					return (1);
			}
			else
			{
				if (solve(grid, viewers, x + 1))
					return (1);
			}
		}
		try++;
	}
	return (0);
}
