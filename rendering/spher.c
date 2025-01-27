/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spher.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:55:45 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/27 23:50:13 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	sp_ray_dista(t_ray ray, t_sphere sp) //calculate_sphere_ray_dista
{
	t_vec3d		ori;

	double (a), (b), (c);
	ori = vec3d_minus(ray.origin, sp.center);
	a = vec3d_dot(ray.direction, ray.direction);
	b = 2.0 * vec3d_dot(ori, ray.direction);
	c = vec3d_dot(ori, ori) - (sp.radius * sp.radius);
	return (quad_equa(a, b, c));
}

t_npc	c_sp_inter(t_ray ray, double dist, t_sphere sp)
{
	t_vec3d	point;
	t_vec3d	normal;

	point = vec3d_scale(dist, ray.direction);
	point = vec3d_plus(ray.origin, point);
	normal = vec3d_minus(point, sp.center);
	normal = vec3d_normalize(normal);
	return ((t_npc){
		.color = sp.color,
		.dista = dist,
		.normal = normal,
		.point = point});
}

void	sp_inter(t_sphere *sp, t_in_pa *intersection)
{
	double	dist;

	dist = sp_ray_dista(*(intersection->ray), *sp);
	if (dist > 0.0)
	{
		intersection->closest = c_sp_inter(*intersection->ray, dist, *sp);
		intersection->hit_clos = 1;
	}
}
