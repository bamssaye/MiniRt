/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template_ob.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:24:05 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/23 11:51:41 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

//==================================
t_object	*sphere_ob(t_vec3d xyz, t_color rgb, double dia);
t_object	*plane_ob(t_vec3d p_xyz, t_vec3d v_xyz, t_color rgb);
t_object	*cylinder_ob(t_vec3d cxyz, t_vec3d vxyz, double *d_h, t_color rgb);
int			sp_inter(void *object, t_inter_p *intersection);


t_object	*sphere_ob(t_vec3d xyz, t_color rgb, double dia)
{
	t_sphere	*obj;
	t_object	*obje;
	obje = malloc(sizeof(t_object));
	obj = malloc(sizeof(t_sphere));
	if (!obj || !obje)
		return (NULL);
	obj->radius = dia ;
	obj->color = rgb;
	obj->center = xyz;
	obje->type = SPHERE;
	obje->object = obj;
	obje->clean = NULL;
	obje->test_intersection = sp_inter;
	return (obj);
}
t_object	*plane_ob(t_vec3d p_xyz, t_vec3d v_xyz, t_color rgb)
{
	t_plane	*obj;
	t_object	*obje;
	obje = malloc(sizeof(t_object));
	obj = malloc(sizeof(t_plane));
	if (!obj || !obje)
		return (NULL);
	obj->color = rgb;
	obj->point = p_xyz;
	obj->normal = v_xyz;
	obje->type = PLANE;
	obje->object = obj;
	// obje->clean = ;
	// obje->test_intersection = ;
	return (obj);
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
	obj->normal = vxyz;
	obje->type = CYLINDER;
	obje->object = obj;
	// obje->clean = ;
	// obje->test_intersection = NULL;
	return (obj);
}
