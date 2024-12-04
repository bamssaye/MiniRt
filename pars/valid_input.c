/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:09:49 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/04 02:11:08 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"



int	valid_line(char **s, t_minirt *mrt)
{
	size_t len;
	
	len = ft_strlen(s[0]);
	if (!ft_strncmp(s[0], "A", len))
		set_ambient(s, mrt);
	else if (!ft_strncmp(s[0], "C", len))
		set_camera(s, mrt);
	else if (!ft_strncmp(s[0], "L", len))
		set_light(s, mrt);
	else if (!ft_strncmp(s[0], "sp", len))
		set_sphere(s, mrt);
	else if (!ft_strncmp(s[0], "pl", len))
		set_plane(s, mrt);
	else if (!ft_strncmp(s[0], "cy", len))
		set_cylinder(s, mrt);
	return (0);
}
