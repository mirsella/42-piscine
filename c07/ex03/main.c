/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:56:54 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/29 15:42:12 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	char **strs = malloc(sizeof(char *) * 3);
	char *str;

	strs[0] = "hello";
	strs[1] = "world";
	strs[2] = "again";
	char *sep = "__";
	str = ft_strjoin(3, strs, sep);
	printf("result : %s", str);
	free(str);
	free(strs);
	return (0);
}
