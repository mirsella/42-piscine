/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkxy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:40:11 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/25 18:24:07 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isxvalid(int **grid, int x, int *viewers)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (grid[x][i] > max)
		{
			max = grid[x][i];
			count++;
		}
		if (grid[x][i] > 4 || grid[x][i] < 1)
			return (0);
		i++;
	}
	if (count != viewers[x + 8])
		return (0);
	return (1);
}

int	isxvalidrev(int **grid, int x, int *viewers)
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (grid[x][i] > max)
		{
			max = grid[x][i];
			count++;
		}
		if (grid[x][i] > 4 || grid[x][i] < 1)
			return (0);
		i--;
	}
	if (count != viewers[x + 12])
		return (0);
	return (1);
}

int	isyvalid(int **grid, int y, int *viewers)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (grid[i][y] > max)
		{
			max = grid[i][y];
			count++;
		}
		if (grid[i][y] > 4 || grid[i][y] < 1)
		{
			return (0);
		}
		i++;
	}
	if (count != viewers[y])
	{
		return (0);
	}
	return (1);
}

int	isyvalidrev(int **grid, int y, int *viewers)
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (grid[i][y] > max)
		{
			max = grid[i][y];
			count++;
		}
		if (grid[i][y] > 4 || grid[i][y] < 1)
			return (0);
		i--;
	}
	if (count != viewers[y + 4])
	{
		return (0);
	}
	return (1);
}
