/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:11:59 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/27 19:15:59 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	set_ambient(char **s, t_minirt *aml)
{
	double	al;

	if (aml->amc[A] || check_str(s, 2) || !ft_ranges(ft_atof(s[1]), 0.0, 1.0))
		return (1);
	al = ft_atof(s[1]).num;
	aml->amc[A] = 1;
	aml->am_light.al = al;
	return (0);
}

int	set_camera(char **s, t_minirt *aml)
{
	t_vec3d	c_xyz;
	t_vec3d	vec_xyz;
	int		fov;

	if (aml->amc[C] || check_str(s, 4) || !ft_ranges(ft_atof(s[3]), 0, 180))
		return (1);
	fov = ft_atoii(s[3]).num;
	c_xyz = check_xyz(s[1], -IN_MIN, IN_MAX);
	vec_xyz = check_xyz(s[2], -1.0, 1.0);
	if (c_xyz.isv || vec_xyz.isv)
		return (1);
	aml->amc[C] = 1;
	aml->camera.position = c_xyz;
	aml->camera.normal = vec_xyz;
	aml->camera.fov = fov;
	aml->camera.look_at = c_look_at(&aml->camera);
	aml->camera.u = c_up_v(&aml->camera);
	aml->camera.v = c_r_v(&aml->camera);
	aml->camera.top_left = c_topleft(&aml->camera);
	return (0);
}

int	set_light(char **s, t_minirt *aml)
{
	t_vec3d	light_vec3d;
	double	light_bri;

	if (aml->amc[L] || check_str(s, 3) || !ft_ranges(ft_atof(s[2]), 0, 180))
		return (1);
	light_bri = ft_atof(s[2]).num;
	light_vec3d = check_xyz(s[1], -IN_MIN, IN_MAX);
	if (light_vec3d.isv)
		return (1);
	aml->amc[L] = 1;
	aml->light.intensity = light_bri;
	aml->light.position = light_vec3d;
	return (0);
}
