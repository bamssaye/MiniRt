/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:11:59 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/05 06:21:11 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	set_ambient(char **s, t_minirt *aml)
{
	t_rgb	rgb;
	double	al;

	if (aml->amc[0] || check_str(s, 3) || !ft_ranges(ft_atof(s[1]), 0.0, 1.0))
		return (1);
	al = ft_atof(s[1]).num;
	rgb = check_color(s[2]);
	if (rgb.isv)
		return (1);
	aml->amc[0] = 1;
	aml->am_light.al = al;
	aml->am_light.al_rgb = rgb;
	return (0);
}

int	set_camera(char **s, t_minirt *aml)
{
	t_xyz	c_xyz;
	t_xyz	vec_xyz;
	int		fov;

	if (aml->amc[1] || check_str(s, 4) || !ft_ranges(ft_atof(s[3]), 0, 180))
		return (1);
	fov = ft_atoii(s[3]).num;
	c_xyz = check_xyz(s[1], -IN_MIN, IN_MAX);
	vec_xyz = check_xyz(s[2], -1.0, 1.0);
	if (c_xyz.isv || vec_xyz.isv)
		return (1);
	aml->amc[1] = 1;
	aml->camera.c_xyz = c_xyz;
	aml->camera.vec_xyz = vec_xyz;
	aml->camera.fov = fov;
	return (0);
}

int	set_light(char **s, t_minirt *aml)
{
	t_xyz	light_xyz;
	t_rgb	light_rgb;
	double	light_bri;

	if (aml->amc[2] || check_str(s, 4) || !ft_ranges(ft_atof(s[2]), 0, 180))
		return (1);
	light_bri = ft_atof(s[2]).num;
	light_rgb = check_color(s[3]);
	light_xyz = check_xyz(s[1], -IN_MIN, IN_MAX);
	if (light_rgb.isv || light_xyz.isv)
		return (1);
	aml->amc[2] = 1;
	aml->light.light_bri = light_bri;
	aml->light.light_rgb = light_rgb;
	aml->light.light_xyz = light_xyz;
	return (0);
}
