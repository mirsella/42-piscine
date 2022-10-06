/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkduplicatesxy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:24:01 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/25 18:24:05 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkduplicatesx(int **grid, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (grid[x][i] == grid[x][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checkduplicatesy(int **grid, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (grid[i][y] == grid[j][y])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
