/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:17 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/19 21:19:50 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

// initialize_light_parameters
t_obslight	initlight_inter(t_light l_param, t_hit *pa)
{
	t_vec3d light_dire;

	light_dire = v_minus(l_param.position, pa->inters.point);
	return ((t_obslight){.light = (t_slight){
				.ambient_color = (t_color){0, 0, 0, 0},
				.light_color = (t_color){0, 0, 0, 0},
			},
		.light_dire = v_normalize(light_dire),
		.max_dista = v_magnitude(light_dire),
		.ray =
			(t_ray){
				.origin = pa->inters.point,
				.direction = v_normalize(light_dire),
				},
		.stuck = 0});
}
// check_intersection_with_object
void	inter_wobject(t_object *obj, t_hit *param, t_minirt *rt)
{
	t_obj objs;

	(void)rt;
	if (obj->type == SPHERE)
	{
		objs.sp = (t_sp *)obj->object;
		sp_inter(objs.sp, param);
	}
	else if (obj->type == PLANE)
	{
		objs.pl = (t_pl *)obj->object;
		plane_inter(objs.pl, param);
	}
	else if (obj->type == CYLINDER)
	{
		objs.cy = (t_cy *)obj->object;
		cy_inter(objs.cy, param);
	}
	else if (obj->type == CONE)
	{
		objs.co = (t_co *)obj->object;
		co_inter(objs.co, param);
	}
}
