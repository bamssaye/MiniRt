/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template_ob.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:24:05 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/08 07:15:18 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_tex init_img(char *path)
{
	return ((t_tex){
		.img = NULL,
		.addr = NULL,
		.path = path
	});
}

t_object	*sphere_ob(t_vec3d xyz, t_color rgb, double dia, char *path)
{
	t_sphere	*obj;
	t_object	*obje;

	obje = malloc(sizeof(t_object));
	obj = malloc(sizeof(t_sphere));
	if (!obj || !obje)
		return (NULL);
	obj->radius = dia;
	obj->color = rgb;
	obj->center = xyz;
	obj->tex = init_img(path);
	obje->type = SPHERE;
	obje->object = obj;
	return (obje);
}

t_object	*plane_ob(t_vec3d p_xyz, t_vec3d v_xyz, t_color rgb, char *path)
{
	t_plane		*obj;
	t_object	*obje;

	obje = malloc(sizeof(t_object));
	(void)path;
	obj = malloc(sizeof(t_plane));
	if (!obj || !obje)
		return (NULL);
	obj->color = rgb;
	obj->point = p_xyz;
	obj->normal = vec3d_normalize(v_xyz);
	obje->type = PLANE;
	obje->object = obj;
	
	return (obje);
}

t_object	*cylinder_ob(t_vec3d cxyz, t_vec3d vxyz, double *d_h, t_color rgb)
{
	t_cylinder	*obj;
	t_object	*obje;

	obje = malloc(sizeof(t_object));
	obj = malloc(sizeof(t_cylinder));
	if (!obj || !obje)
		return (NULL);
	obj->radius = d_h[0];
	obj->len = d_h[1];
	obj->point = cxyz;
	obj->color = rgb;
	obj->normal = vec3d_normalize(vxyz);
	obje->type = CYLINDER;
	obje->object = obj;
	return (obje);
}
