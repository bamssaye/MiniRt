/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:24:05 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/05 04:46:08 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_sphere	*sphere_ob(t_xyz xyz, t_rgb rgb, double dia)
{
	t_sphere	*obj;

	obj = malloc(sizeof(t_sphere));
	if (!obj)
		return (NULL);
	obj->sph_dia[0] = dia;
	obj->sph_rgb[0] = rgb;
	obj->sph_xyz[0] = xyz;
	return (obj);
}

t_plane	*plane_ob(t_xyz p_xyz, t_xyz v_xyz, t_rgb rgb)
{
	t_plane	*obj;

	obj = malloc(sizeof(t_plane));
	if (!obj)
		return (NULL);
	obj->pl_rgb[0] = rgb;
	obj->pl_xyz[0] = p_xyz;
	obj->vec_xyz[0] = v_xyz;
	return (obj);
}

t_cylinder	*cylinder_ob(t_xyz cxyz, t_xyz vxyz, double *d_h, t_rgb rgb)
{
	t_cylinder	*obj;

	obj = malloc(sizeof(t_cylinder));
	if (!obj)
		return (NULL);
	obj->c_dia[0] = d_h[0];
	obj->c_hei[0] = d_h[1];
	obj->cy_xyz[0] = cxyz;
	obj->sy_rgb[0] = rgb;
	obj->vec_xyz[0] = vxyz;
	return (obj);
}
