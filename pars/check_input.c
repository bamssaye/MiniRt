/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:06:44 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/01 05:12:21 by bamssaye         ###   ########.fr       */
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
	int  c;

	s = ft_split(str, ',');
	c = 0;
	if (ft_range(ft_atoii(s[0]), 0, 255) && ++c)
		rgb[0].r = ft_atoii(s[0]);
	if (ft_range(ft_atoii(s[1]), 0, 255) && c++)
		rgb[0].g = ft_atoii(s[1]);
	if (ft_range(ft_atoii(s[2]), 0, 255) && c++)
		rgb[0].b = ft_atoii(s[2]);
	if (c != 3 || s[3])
		printf("ERROR\n"), exit(1);
	arry_c(s);
	return (rgb[0]);
}
t_xyz check_xyz(char *str, double min, double max)
{
	char **s;
	t_xyz xyz[1];
	int  c;

	s = ft_split(str, ',');
	c = 0;
	if (ft_range(ft_atof(s[0]), min, max) && ++c)
		xyz[0].x = ft_atof(s[0]);
	if (ft_range(ft_atof(s[1]), min, max) && c++)
		xyz[0].y = ft_atof(s[1]);
	if (ft_range(ft_atof(s[2]), min, max) && c++)
		xyz[0].z = ft_atof(s[2]);
	if (c != 3 || s[3])
		printf("ERROR\n"), exit(1);
	arry_c(s);
	return (xyz[0]);
}