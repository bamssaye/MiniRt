/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:37 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/19 21:13:59 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	pl_ray_dista(t_ray ray, t_pl pl, t_npc *closest)
{
	t_vec3d	inter_p;

	double(dist), (dot);
	dist = -1;
	dot = v_dot(pl.normal, ray.direction);
	inter_p = v_minus(pl.point, ray.origin);
	dist = v_dot(inter_p, pl.normal) / dot;
	if ((dist <= 0) || (fabs(dot) < EPSILON))
		return (0);
	closest->normal = pl.normal;
	if (dot < 0)
		closest->normal = v_scale(-1, closest->normal);
	return (dist);
}

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

int	plane_inter(t_pl *plane, t_hit *param)
{
	double	dist;
	t_vec3d	*ray;

	ray = &param->ray->direction;
	dist = pl_ray_dista(*(param->ray), *plane, &param->closest);
	if (dist > 0)
	{
		param->closest = pl_closest(*ray, *plane, dist, param->ray->origin);
		param->hit_clos = 1;
		// if (plane->tex.img)
		// 	param->closest.color = pl_texture_col(plane->tex,
		// 			param->closest.point, *plane);
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
