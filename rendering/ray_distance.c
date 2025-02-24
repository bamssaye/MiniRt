/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:22:56 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/24 12:49:10 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	sp_ray_dista(t_ray ray, t_sp sp)
{
	t_vec3d	ori;

	double (a), (b), (c);
	ori = v_minus(ray.origin, sp.center);
	a = v_dot(ray.direction, ray.direction);
	b = 2.0 * v_dot(ori, ray.direction);
	c = v_dot(ori, ori) - (sp.radius * sp.radius);
	return (quad_equa(a, b, c));
}

double	pl_ray_dista(t_ray ray, t_pl pl, t_npc *closest)
{
	t_vec3d	inter_p;

	double (dist), (dot);
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

double	cy_ray_dista(t_ray ray, t_cy cy)
{
	t_vec3d	ori;

	double (a), (b), (c), (d_dn), (d_on);
	ori = v_minus(ray.origin, cy.point);
	d_on = v_dot(ori, cy.normal);
	d_dn = v_dot(ray.direction, cy.normal);
	a = v_dot(ray.direction, ray.direction) - (d_dn * d_dn);
	b = 2.0 * (v_dot(ori, ray.direction) - d_dn * d_on);
	c = v_dot(ori, ori) - (d_on * d_on) - (cy.radius * cy.radius);
	return (quad_equa(a, b, c));
}
