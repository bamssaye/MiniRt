/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:17 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/17 13:26:31 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_obslight	initlight_inter(t_light l_param, t_in_pa *pa)
// initialize_light_parameters
{
	t_vec3d light_dire;

	light_dire = vec3d_minus(l_param.position, pa->inters.point);
	return ((t_obslight){.light = (t_slight){
				.ambient_color = (t_color){0, 0, 0, 0},
				.light_color = (t_color){0, 0, 0, 0},
			},
		.light_dire = vec3d_normalize(light_dire),
		.max_dista = vec3d_length(light_dire),
		.ray =
			(t_ray){
				.origin = pa->inters.point,
				.direction = vec3d_normalize(light_dire),
				},
		.stuck = 0});
}

void	inter_wobject(t_object *obj, t_in_pa *param, t_minirt *aml)
// check_intersection_with_object
{
	t_plane *plane;
	t_cylinder *cy;
	t_sphere *sp;
	t_cone *co;

	if (obj->type == SPHERE)
	{
		sp = (t_sphere *)obj->object;
		(void)aml;
		sp_inter(sp, param);
	}
	else if (obj->type == PLANE)
	{
		plane = (t_plane *)obj->object;
		plane_inter(plane, param);
	}
	else if (obj->type == CYLINDER)
	{
		cy = (t_cylinder *)obj->object;
		cy_inter(cy, param);
	}
	else if (obj->type == CONE)
	{
		co = (t_cone *)obj->object;
		co_inter(co, param);
	}
}
