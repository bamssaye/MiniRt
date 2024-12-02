/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:06:44 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/01 23:33:32 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int ft_isspace(int c)
{
	return (c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == '\n');
}

int  ft_range(double n, double min, double max)
{
    return (n >= min && n <= max);
}

int check_li(char *str)
{
	int i;
	
	i = -1;
	while (str[++i])
		if (ft_isalnum(str[i]))
			return (1);
	return (0);
}

char **_tospace(char *str)
{
	int i;
	char **line;
	
	i = -1;
	while (str[++i])
		if (ft_isspace(str[i]))
			str[i] = ' ';
	line = ft_split(str, ' ');
	return (free(str), line);
}

t_rgb check_color(char *str)
{
	char **s;
	t_rgb rgb[1];

	if (!str)
		(printf("ERROR\n")), (exit(1));
	s = ft_split(str, ',');
    if (!s[1] || !ft_range(ft_atoii(s[0]), 0, 255) || 
        !s[2] || !ft_range(ft_atoii(s[1]), 0, 255) || 
        !ft_range(ft_atoii(s[2]), 0, 255) || s[3])
        (printf("ERROR\n")), (exit(1));
    rgb[0] = (t_rgb){ft_atoii(s[0]), ft_atoii(s[1]), ft_atoii(s[2])};
	arry_c(s);
	return (rgb[0]);
}
t_xyz check_xyz(char *str, double min, double max)
{
	char **s;
	t_xyz xyz[1];

	if (!str)
		(printf("ERROR\n")), (exit(1));
	s = ft_split(str, ',');
	if (!s[1] || !ft_range(ft_atof(s[0]), min, max) ||
		!s[2] || !ft_range(ft_atof(s[1]), min, max) ||
		!ft_range(ft_atof(s[2]), min, max) || s[3])
		(printf("ERROR\n")), (exit(1));
	xyz[0] = (t_xyz){ft_atof(s[0]), ft_atof(s[1]), ft_atof(s[2])};
	arry_c(s);
	return (xyz[0]);
}