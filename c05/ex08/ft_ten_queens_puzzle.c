/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:47:38 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/28 12:57:38 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	ft_printgrid(int grid[10][10])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 10)
	{
		while (y < 10)
		{
			if (grid[x][y] == 1)
				write(1, "1", 1);
			else if (grid[x][y] == 2)
				write(1, "2", 1);
			else
				write(1, "0", 1);
			y++;
		}
		write(1, "\n", 1);
		y = 0;
		x++;
	}
	write(1, "\n", 1);
}

void	ft_print(int grid[10][10])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 9)
	{
		while (y < 9)
		{
			if (grid[x][y] == 2)
			{
				write(1, &y + '0', 1);
			}
			y++;
		}
		x++;
	}
}

void	drawpath(int grid[10][10], int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10 && j < 10)
	{
		if (grid[x + i][y + j] != 2 && grid[x + i][y - j] != 2
			&& grid[x][j] != 2 && grid[i][y] != 2)
		{
			grid[x][j] = 1;
			grid[i][y] = 1;
			if (ft_min(x, y) == x && y + i < 9)
				grid[x + i][y + i] = 1;
			if (ft_min(x, y) == x && y - i + 1 > 0)
				grid[x + i][y - i] = 1;
			if (ft_min(x, y) == y && x + i < 9)
				grid[x + i][y + i] = 1;
			if (ft_min(x, y) == y && x - i + 1 > 0)
				grid[x + i][y - i] = 1;
		}
		i++;
		j++;
	}
}

void	solve(int grid[10][10], int x, int *solutions)
{
	int	y;

	if (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			if (grid[x][y] == 0)
			{
				printf("before x = %d, y = %d\n", x, y);
				drawpath(grid, x, y);
				grid[x][y] = 2;
				ft_printgrid(grid);
				solve(grid, x + 1, solutions);
				grid[x][y] = 0;
				printf("after x = %d, y = %d\n", x, y);
			}
			y++;
		}
	}
	else
	{
		*solutions = *solutions + 1;
		ft_print(grid);
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	solutions;
	int	grid[10][10];
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			grid[x][y] = 0;
			y++;
		}
		x++;
	}
	solutions = 0;
	solve(grid, 0, &solutions);
	ft_printgrid(grid);
	return (solutions);
}
