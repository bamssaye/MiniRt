/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:18:36 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/15 04:36:25 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

//initialize_light_parameters
t_obslight	initlight_inter(t_light l_param, t_in_pa *pa)
{
	t_vec3d		light_dire;

	light_dire = vec3d_minus(&l_param.position, &pa->inters.point);
	return ((t_obslight){
		.light = (t_slight){
		.ambient_color = (t_color){0, 0, 0, 0},
		.light_color = (t_color){0, 0, 0, 0},
		},
		.light_dire = vec3d_normalize(&light_dire),
		.max_dista = vec3d_magnitude(&light_dire),
		.ray = (t_ray){
			.origin = pa->inters.point,
			.direction = vec3d_normalize(&light_dire),
		},
		.stuck = 0});
}


//check_intersection_with_object
void	inter_wobject(t_object *obj, t_in_pa *param, t_minirt *aml)	
{
	t_pl		*plane;
	t_cy	*cy;
	t_sp	*sp;

	if (obj->type == SPHERE)
	{
		sp = (t_sp *)obj->object;
		(void)aml;
		sp_inter(sp, param);
	}
	else if (obj->type == PLANE)
	{
		plane = (t_pl *)obj->object;
		plane_inter(plane, param);
	}
	else if (obj->type == CYLINDER)
	{
		cy = (t_cy *)obj->object;
		cy_inter(cy, param);
	}
}
