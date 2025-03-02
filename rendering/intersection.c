/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:17 by iel-koub          #+#    #+#             */
/*   Updated: 2025/03/01 19:49:11 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void	inter_wobject(t_object *obj, t_hit *param, t_minirt *rt)
{
	t_obj	objs;

	(void)rt;
	if (obj->type == SPHERE)
	{
		objs.sp = (t_sp *)obj->object;
		sp_inter(objs.sp, param, &obj->bum_tex, obj->style);
	}
	else if (obj->type == PLANE)
	{
		objs.pl = (t_pl *)obj->object;
		plane_inter(objs.pl, param, &obj->bum_tex, obj->style);
	}
	else if (obj->type == CYLINDER)
	{
		objs.cy = (t_cy *)obj->object;
		cy_inter(objs.cy, param, &obj->bum_tex, obj->style);
	}
	else if (obj->type == CONE)
	{
		objs.co = (t_co *)obj->object;
		co_inter(objs.co, param, &obj->bum_tex, obj->style);
	}
}

t_obslight	initlight_inter(t_light l_param, t_hit *pa)
{
	t_vec3d	light_dire;

	light_dire = v_minus(l_param.position, pa->inters.point);
	return ((t_obslight){
		.c = l_param.color,
		.light_dire = v_normalize(light_dire),
		.m_dis = v_magnitude(light_dire),
		.ray = (t_ray){
		.origin = pa->inters.point,
		.direction = v_normalize(light_dire)},
		.stuck = 0});
}

t_color	specular_light(t_trace_light *t_li, t_vec3d position)
{
	t_color	color;

	t_vec3d(ref_dir);
	t_vec3d(view_dir);
	ref_dir = v_normalize(v_minus(v_scale(2.0 * v_dot(t_li->inters.normal,
						t_li->l_pa.light_dire), t_li->inters.normal),
				t_li->l_pa.light_dire));
	view_dir = v_normalize(v_minus(position, t_li->inters.point));
	color = c_scale(fmin(1.5 * pow(fmax(0.0, v_dot(ref_dir, view_dir)), 10),
				0.08), (t_color){255, 255, 255, 0});
	return (color);
}
