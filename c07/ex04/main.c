/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 03:29:23 by badam             #+#    #+#             */
/*   Updated: 2022/09/29 09:44:13 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	char	*str;

	printf("42:%s\n", ft_convert_base("--2a", "0123456789abcdef", "0123456789"));
	printf("-2a:%s\n", ft_convert_base("-42", "0123456789", "0123456789abcdef"));
	printf("101010:%s\n", ft_convert_base("42", "0123456789", "01"));
	printf("-ff:%s\n", ft_convert_base("   --++---255", "0123456789", "0123456789abcdef"));
	str = ft_convert_base("0", "0123456789", "9abcdef");
	printf("str:%s\n", str);
}
