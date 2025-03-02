/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:11:59 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/27 23:24:43 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	set_ambient(char **s, t_minirt *rt)
{
	double	al;
	t_color	color;

	if (rt->amc[A] || check_str(s, 3) || !ft_ranges(ft_atof(s[1]), 0.0, 1.0))
		return (print_err("\t{check Ambient data }", ""));
	al = ft_atof(s[1]).num;
	color = check_color(s[2]);
	if (color.isv)
		return (print_err("\t{check Ambient data }", ""));
	rt->amc[A] = 1;
	rt->am_light.al = al;
	rt->am_light.al_color = c_scale(al, color);
	return (0);
}

int	set_camera(char **s, t_minirt *rt)
{
	t_vec3d	c_xyz;
	t_vec3d	vec_xyz;
	int		fov;

	if (rt->amc[C] || check_str(s, 4) || !ft_ranges(ft_atof(s[3]), 0, 180))
		return (print_err("\t{check Camera data}", ""));
	fov = ft_atoii(s[3]).num;
	c_xyz = check_xyz(s[1], -IN_MIN, IN_MAX);
	vec_xyz = check_xyz(s[2], -1.0, 1.0);
	if (c_xyz.isv || vec_xyz.isv)
		return (print_err("\t{check Camera data}", ""));
	rt->amc[C] = 1;
	rt->cam.position = c_xyz;
	rt->cam.normal = vec_xyz;
	rt->cam.fov = fov;
	rt->cam.look_at = v_normalize(rt->cam.normal);
	rt->cam.u = c_r_v(&rt->cam);
	rt->cam.v = v_normalize(v_cross(rt->cam.look_at, rt->cam.u));
	rt->cam.top_left = c_topleft(&rt->cam);
	return (0);
}

t_object	*light_ob(t_vec3d light_vec3d, double light_bri, t_color color)
{
	t_light		*obj;
	t_object	*obje;

	obje = malloc(sizeof(t_object));
	ft_memset(obje, 0, sizeof(t_object));
	if (!obje)
		return (NULL);
	obj = malloc(sizeof(t_light));
	if (!obj)
		return (free(obje), NULL);
	obj->intensity = light_bri;
	obj->color = c_scale(light_bri, color);
	obj->position = light_vec3d;
	obje->type = LIGHT;
	obje->path = NULL;
	obje->object = obj;
	return (obje);
}

int	set_light(char **s, t_minirt *rt)
{
	t_vec3d		light_vec3d;
	double		light_bri;
	t_object	*light;
	t_color		color;

	if (rt->amc[L] && !rt->bouns)
		return (print_err("\t{multiple spot in bouns part}", ""));
	if (check_str(s, 4) || !ft_ranges(ft_atof(s[2]), 0.0, 1.0))
		return (print_err("\t{check Light data}", ""));
	light_bri = ft_atof(s[2]).num;
	light_vec3d = check_xyz(s[1], -IN_MIN, IN_MAX);
	color = check_color(s[3]);
	if (light_vec3d.isv || color.isv)
		return (print_err("\t{check Light data}", ""));
	rt->amc[L] = 1;
	light = light_ob(light_vec3d, light_bri, color);
	ft_lstadd_back(&rt->object, ft_lstnew(light));
	return (0);
}
