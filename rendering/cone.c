/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:56:21 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/23 13:24:01 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"



int	check_cone_hit(t_co *cone, t_hit *p)
{
	t_cone_hit	co_hit;

	double (dist), (height_pos), (projection), (k_sq);
	dist = cone_ray_dista(*p->ray, *cone);
	if (dist > 0.0 && dist < p->closest.dista)
	{
		co_hit.point = v_plus(v_scale(dist, p->ray->direction), p->ray->origin);
		height_pos = v_dot(v_minus(co_hit.point, cone->point), cone->normal);
		if (height_pos >= 0 && height_pos <= cone->height)
		{
			p->closest.point = co_hit.point;
			co_hit.apex_to_hit = v_minus(co_hit.point, cone->point);
			projection = v_dot(co_hit.apex_to_hit, cone->normal);
			k_sq = (cone->radius / cone->height) \
			* (cone->radius / cone->height);
			co_hit.axis_proj = v_scale(projection * (1 + k_sq), cone->normal);
			co_hit.normal = v_minus(co_hit.apex_to_hit, co_hit.axis_proj);
			p->closest.normal = v_normalize(co_hit.normal);
			p->closest.dista = dist;
			p->hit_clos = 1;
			p->closest.color = cpy_color(cone->color);
			return (1);
		}
	}
	return (0);
}

int	cone_caps(t_pl *pl, t_co *cone, t_cone_utils *co)
{
	t_vec3d	base_point;

	base_point = v_plus(cone->point, v_scale(cone->height, cone->normal));
	*pl = copy_pl(base_point, cone->normal, cone->color, (t_vec3d){0, 0, 0, 0});
	return (plane_inter(&co->base_cap, &co->cap_inter, NULL, NULL));
}

void	co_inter(t_co *cone, t_hit *f_inter, t_bump *bump, int *style)
{
	t_cone_utils (co);
	co.tmp_inter = *f_inter;
	if (check_cone_hit(cone, &co.tmp_inter) \
		&& co.tmp_inter.closest.dista < f_inter->closest.dista)
	{
		*f_inter = co.tmp_inter;
		if (style[COLOR] != 1)
			set_style_co(bump, style, f_inter, cone);
	}
	co.cap_inter = *f_inter;
	if (cone_caps(&co.base_cap, cone, &co))
	{
		co.hit_point = co.cap_inter.closest.point;
		co.cap_center = co.base_cap.point;
		co.distance = v_magnitude(v_minus(co.hit_point, co.cap_center));
		if (co.distance <= cone->radius \
			&& co.cap_inter.closest.dista < f_inter->closest.dista)
		{
			f_inter->closest = co.cap_inter.closest;
			f_inter->closest.normal = co.base_cap.normal;
			f_inter->hit_clos = 1;
			if (style[COLOR] != 1)
				set_style_co(bump, style, f_inter, cone);
		}
	}
}
