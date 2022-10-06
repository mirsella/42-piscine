/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <lgillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:55:49 by lgillard          #+#    #+#             */
/*   Updated: 2022/10/02 23:35:39 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define DEFAULT_FILE "numbers.dict"

int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		get_key_line(char *filename, char *key);
int		is_valid_dict(char *filename, int lineindex, int linecount);
int		get_line_size(char *filename, int line);
int		ft_triolet(char *filename, char *str);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*strcpytrim(char *dest, char *src);
char	*get_line(char *filename, int line);
char	*ft_itoa(int nb);
char	*get_data(char *filename, int line);
char	*ft_strcpy(char *dest, char *src);
void	ft_putstr(char *str);

#endif
