/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:11:59 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/12 06:28:54 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	set_ambient(char **s, t_minirt *aml)
{
	double	al;
	t_color	rgb;

	if (aml->amc[A] || check_str(s, 3) || !ft_ranges(ft_atof(s[1]), 0.0, 1.0))
		return (1);
	al = ft_atof(s[1]).num;
	rgb = check_color(s[2]);
	if (rgb.isv)
		return (1);
	aml->amc[A] = 1;
	aml->am_light.al = al;
	aml->am_light.al_rgb = color_scale(al, rgb);
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
	aml->camera.look_at = vec3d_normalize(vec_xyz);
	aml->camera.u = c_up_v(&aml->camera);
	aml->camera.v = c_r_v(&aml->camera);
	aml->camera.top_left = c_topleft(&aml->camera);
	return (0);
}

t_object	*light_ob(t_vec3d light_vec3d, double light_bri, t_color color)
{
	t_light	*obj;
	t_object	*obje;

	obje = malloc(sizeof(t_object));
	if (!obje)
		return (NULL);
	obj = malloc(sizeof(t_light));
	if (!obj)
		return (free(obje), NULL);
	obj->intensity = light_bri;
	obj->color = color;
	obj->position = vec3d_scale(light_bri, light_vec3d);	
	obje->type = LIGHT;
	obje->object = obj;
	return (obje);
}

int	set_light(char **s, t_minirt *aml)
{
	t_vec3d	light_vec3d;
	double	light_bri;
	t_object *light;
	t_color	color;

	if (check_str(s, 4) || !ft_ranges(ft_atof(s[2]), 0.0, 1.0))
		return (1);
	light_bri = ft_atof(s[2]).num;
	light_vec3d = check_xyz(s[1], -IN_MIN, IN_MAX);
	color = check_color(s[3]);
	if (light_vec3d.isv || color.isv)
		return (1);
	aml->amc[L] = 1;
	light = light_ob(light_vec3d, light_bri, color);
	ft_lstadd_back(&aml->object, ft_lstnew(light));
	return (0);
}
