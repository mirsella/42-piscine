/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:47:38 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/22 09:45:52 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	check(int grid[10][10], int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 9 && j < 9)
	{
		if (grid[x][j] == 1 || grid[i][y] == 1)
			return (0);
		i++;
		j++;
	}
	return (0);
}

int	solve(int grid[10][10], int x, int *solutions)
{
	int	y;

	y = 0;
	while (y < 10)
	{
		if (check(grid, x, y))
		{
			if (x == 9)
				*solutions = *solutions + 1;
			else
			{
				grid[x][y] = 1;
				solve(grid, x + 1, solutions);
				grid[x][y] = 0;
			}
		}
		y++;
	}
	return (*solutions);
}

void	print(int grid[10][10])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 9)
	{
		while (y < 9)
		{
			if (grid[x][y])
			{
				write(1, &y + '0', 1);
			}
			y++;
		}
		x++;
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
	return (solutions);
}
