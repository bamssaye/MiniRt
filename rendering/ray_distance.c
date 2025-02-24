/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:22:56 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/24 11:18:32 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	cy_ray_dista(t_ray ray, t_cy cy);
double	pl_ray_dista(t_ray ray, t_pl pl, t_npc *closest);
double	sp_ray_dista(t_ray ray, t_sp sp);

double	sp_ray_dista(t_ray ray, t_sp sp)
{
	t_vec3d ori;

	double(a), (b), (c);
	ori = v_minus(ray.origin, sp.center);
	a = v_dot(ray.direction, ray.direction);
	b = 2.0 * v_dot(ori, ray.direction);
	c = v_dot(ori, ori) - (sp.radius * sp.radius);
	return (quad_equa(a, b, c));
}

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

// double	cone_ray_dista(t_ray ray, t_co cone)
// {
// 	t_vec3d	ori;

// 	double (a), (b), (c), (k), (k_sq);
// 	double (dir_dot_n), (dir_dot_dir);
// 	double (ori_dot_ori), (ori_dot_n);
// 	ori = v_minus(ray.origin, cone.point);
// 	dir_dot_n = v_dot(ray.direction, cone.normal);
// 	ori_dot_n = v_dot(ori, cone.normal);
// 	k = cone.radius / cone.height;
// 	k_sq = k * k;
// 	dir_dot_dir = v_dot(ray.direction, ray.direction);
// 	ori_dot_ori = v_dot(ori, ori);
// 	a = dir_dot_dir - dir_dot_n * dir_dot_n - k_sq * dir_dot_n * dir_dot_n;
// 	b = 2.0 * (v_dot(ori, ray.direction) - ori_dot_n * dir_dot_n - k_sq
// 			* ori_dot_n * dir_dot_n);
// 	c = ori_dot_ori - ori_dot_n * ori_dot_n - k_sq * ori_dot_n * ori_dot_n;
// 	return (quad_equa(a, b, c));
// }
