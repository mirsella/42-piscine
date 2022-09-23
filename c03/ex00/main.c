/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:58:17 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/18 14:41:22 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strcmp.c"
#include <stdio.h>

int main()
{
    char *s1 = "Hello rld";
    char *s2 = "Hello world";
    printf("%d", ft_strcmp(s1, s2));
    return 0;
}
