/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:09:49 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/16 21:36:15 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	valid_line(char **s, t_minirt *mrt)
{
	size_t	len;

	len = ft_strlen(s[0]);
	if (!ft_strncmp(s[0], "A", len))
		return (set_ambient(s, mrt));
	if (!ft_strncmp(s[0], "C", len))
		return (set_camera(s, mrt));
	if (!ft_strncmp(s[0], "L", len))
		return (set_light(s, mrt));
	if (!ft_strncmp(s[0], "sp", len))
		return (set_sphere(s, mrt));
	if (!ft_strncmp(s[0], "pl", len))
		return (set_plane(s, mrt));
	if (!ft_strncmp(s[0], "cy", len))
		return (set_cylinder(s, mrt));
	if (!ft_strncmp(s[0], "co", len))
		return (set_cone(s, mrt));
	return (1);
}
