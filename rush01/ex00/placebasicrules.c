/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placebasicrules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:19:45 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/25 18:33:34 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*getrules(int num)
{
	if (num == 4)
		return ((int [3]){1, 1, 1});
	if (num == 1)
		return ((int [3]){4, 4, 4});
	if (num == 3)
		return ((int [3]){2, 1, 2});
	if (num == 2)
		return ((int [3]){3, 2, 1});
	return (0);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	getviewermax(int *viewers, int x, int y)
{
	if (x == 0 && y == 0)
		return (max(viewers[0], viewers[8]));
	if (x == 3 && y == 0)
		return (max(viewers[4], viewers[11]));
	if (x == 0 && y == 3)
		return (max(viewers[3], viewers[12]));
	if (x == 3 || y == 3)
		return (max(viewers[7], viewers[15]));
	return (0);
}

int	getviewer(int *viewers, int x, int y)
{
	if (x == 0)
		return (viewers[y]);
	if (x == 3)
		return (viewers[y + 4]);
	if (y == 0)
		return (viewers[x + 8]);
	if (y == 3)
		return (viewers[x + 11]);
	return (0);
}

void	placebasic(int **grid, int *viewers)
{
	int	x;
	int	y;
	int	*value;

	x = 0;
	y = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if ((x == 0 || x == 3) && (y == 0 || y == 3))
			{
				value = getrules(getviewermax(viewers, x, y));
				grid[x][y] = value[0];
			}
			else if ((x == 0 || x == 3) || (y == 0 || y == 3))
			{
				value = getrules(getviewer(viewers, x, y));
				grid[x][y] = value[0];
			}
			y++;
		}
		x++;
	}
}
