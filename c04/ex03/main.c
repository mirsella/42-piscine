/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:24:01 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/19 10:17:51 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_atoi.c"

int	main(void)
{
	char *str;

	str = "   ---+--+1234ab567";
	printf("%d", ft_atoi(str));
	return (0);
}