/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:06:44 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/19 23:37:14 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	check_li(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isalnum(str[i]))
			return (1);
	return (0);
}

char	**tospace(char *str)
{
	char	**line;
	int		i;

	i = -1;
	if (!check_li(str))
		return (NULL);
	while (str[++i])
		if (ft_isspace(str[i]))
			str[i] = ' ';
	line = ft_split(str, ' ');
	return (line);
}

t_color	check_color(char *str)
{
	t_color	color[1];
	char	**s;
	int		i;

	s = ft_split(str, ',');
	i = -1;
	if (check_str(s, 3))
		return (arry_c(s), (t_color){-1, -1, -1, 1});
	while (s[++i])
		if (!ft_range(ft_atoii(s[i]), 0, 255))
			return (arry_c(s), (t_color){-1, -1, -1, 1});
	color[0] = (t_color){ft_atoii(s[0]).num, ft_atoii(s[1]).num,
		ft_atoii(s[2]).num, 0};
	arry_c(s);
	return (color[0]);
}

t_vec3d	check_xyz(char *str, double min, double max)
{
	t_vec3d	xyz[1];
	char	**s;
	int		i;

	s = ft_split(str, ',');
	i = -1;
	if (check_str(s, 3))
		return (arry_c(s), (t_vec3d){-1, -1, -1, 1});
	while (s[++i])
		if (!ft_ranges(ft_atof(s[i]), min, max))
			return (arry_c(s), (t_vec3d){-1, -1, -1, 1});
	xyz[0] = (t_vec3d){ft_atof(s[0]).num, ft_atof(s[1]).num, ft_atof(s[2]).num,
		0};
	arry_c(s);
	return (xyz[0]);
}
