/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:37 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/23 13:25:35 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"


t_npc	pl_closest(t_vec3d ray, t_pl pl, double dist, t_vec3d origin)
{
	return ((t_npc){
		.color = pl.color,
		.dista = dist,
		.normal = pl.normal,
		.point = (t_vec3d){
			.x = origin.x + dist * ray.x,
			.y = origin.y + dist * ray.y,
			.z = origin.z + dist * ray.z,}
		}
	);
}

int plane_inter(t_pl *pl, t_hit *inter, t_bump *bump, int *style)
{
	double	dist;
	t_vec3d	*ray;

	ray = &inter->ray->direction;
	dist = pl_ray_dista(*(inter->ray), *pl, &inter->closest);
	if (dist > 0)
	{
		inter->closest = pl_closest(*ray, *pl, dist, inter->ray->origin);
		inter->hit_clos = 1;
		if (style && style[COLOR] != 1)
			set_style_pl(bump, style, inter, pl);
	}
	return (dist);
}

t_pl	copy_pl(t_vec3d po, t_vec3d no, t_color col, t_vec3d offset)
{
	if (offset.isv)
	{
		offset = v_scale(-1, no);
		return ((t_pl){
			.color = cpy_color(col), 
            .normal = offset,
			.point = po
		});
	}
	return ((t_pl){
		.color = cpy_color(col), 
        .normal = no, 
        .point = po
	});
}
