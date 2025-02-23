/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spher.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:52 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/23 13:38:05 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"


t_npc	c_sp_inter(t_ray ray, double dist, t_sp sp)
{
	t_vec3d	point;
	t_vec3d	normal;

	point = v_scale(dist, ray.direction);
	point = v_plus(ray.origin, point);
	normal = v_minus(point, sp.center);
	normal = v_normalize(normal);
	return ((t_npc){
		.color = sp.color,
		.dista = dist,
		.normal = normal,
		.point = point
	});
}

void	sp_inter(t_sp *sp, t_hit *intersection, t_bump *bump, int *style)
{
	double	dist;

	dist = sp_ray_dista(*(intersection->ray), *sp);
	if (dist > 0.0)
	{
		intersection->closest = c_sp_inter(*intersection->ray, dist, *sp);
		intersection->hit_clos = 1;
		if (style[COLOR] != 1)
			set_style_sp(bump, style, intersection, sp);
	}
}
