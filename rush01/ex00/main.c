/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:21:51 by yasaidi           #+#    #+#             */
/*   Updated: 2022/09/25 18:31:34 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	throwerror(void);
void	printgrid(int **grid);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		*parsearg(char *str);
int		solve(int **grid, int *viewers, int x);

int	main(int argc, char **argv)
{
	int		*viewers;
	int		**grid;
	int		i;

	grid = malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
		grid[i++] = malloc(sizeof(int) * 4);
	if (argc != 2)
	{
		throwerror();
		return (1);
	}
	viewers = parsearg(argv[1]);
	if (viewers == NULL)
	{
		throwerror();
		return (1);
	}
	solve(grid, viewers, 0);
	printgrid(grid);
	return (0);
}
