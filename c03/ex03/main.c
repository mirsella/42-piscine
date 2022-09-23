/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:45:24 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/18 00:04:02 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_strncat.c"

int	main(void)
{
	char	dest[100] = "Hello ";
	char	src[] = "World!";

	printf("%s", ft_strncat(dest, src, 4));
	return (0);
}
