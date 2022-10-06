/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:16:41 by lgillard          #+#    #+#             */
/*   Updated: 2022/09/18 16:08:26 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	findi;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		findi = 0;
		while (str[i + findi] == to_find[findi])
		{
			if (to_find[findi + 1] == '\0')
				return (&str[i]);
			findi++;
		}
		i++;
	}
	return (0);
}
