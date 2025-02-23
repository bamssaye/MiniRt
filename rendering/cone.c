/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:56:21 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/22 11:56:40 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

/*
   a   = D|D - (1+k*k)*(D|V)^2
   b/2 = D|X - (1+k*k)*(D|V)*(X|V)
   c   = X|X - (1+k*k)*(X|V)^2
*/

double	cone_ray_dista(t_ray ray, t_co cone)
{
	t_vec3d	ori;

	double (a), (b), (c), (k), (k_sq);
	double (dir_dot_n), (dir_dot_dir);
	double (ori_dot_ori), (ori_dot_n);
	ori = v_minus(ray.origin, cone.point);
	dir_dot_n = v_dot(ray.direction, cone.normal);
	ori_dot_n = v_dot(ori, cone.normal);
	k = cone.radius / cone.height;
	k_sq = k * k;
	dir_dot_dir = v_dot(ray.direction, ray.direction);
	ori_dot_ori = v_dot(ori, ori);
	a = dir_dot_dir - dir_dot_n * dir_dot_n - k_sq * dir_dot_n * dir_dot_n;
	b = 2.0 * (v_dot(ori, ray.direction) - ori_dot_n * dir_dot_n - k_sq
			* ori_dot_n * dir_dot_n);
	c = ori_dot_ori - ori_dot_n * ori_dot_n - k_sq * ori_dot_n * ori_dot_n;
	return (quad_equa(a, b, c));
}

int	check_cone_hit(t_co *cone, t_hit *p)
{
	t_vec3d (hit_point), (apex_to_hit), (axis_projection), (normal);
	double  (dist), (height_pos), (projection), (k_sq);
	dist = cone_ray_dista(*p->ray, *cone);
	if (dist > 0.0 && dist < p->closest.dista)
	{
		hit_point = v_plus(v_scale(dist, p->ray->direction), p->ray->origin);
		height_pos = v_dot(v_minus(hit_point, cone->point), cone->normal);
		if (height_pos >= 0 && height_pos <= cone->height)
		{
			p->closest.point = hit_point;
			apex_to_hit = v_minus(hit_point, cone->point);
			projection = v_dot(apex_to_hit, cone->normal);
			k_sq = (cone->radius / cone->height) * (cone->radius / cone->height);
			axis_projection = v_scale(projection * (1 + k_sq), cone->normal);
			normal = v_minus(apex_to_hit, axis_projection);
			p->closest.normal = v_normalize(normal);
			p->closest.dista = dist;
			p->hit_clos = 1;
			p->closest.color = cpy_color(cone->color);
			return (1);
		}
	}
	return (0);
}

void	cone_caps(t_pl *pl, t_co *cone)
{
	t_vec3d	base_point;

	base_point = v_plus(cone->point, v_scale(cone->height, cone->normal));
	*pl = copy_pl(base_point, cone->normal, cone->color, (t_vec3d){0, 0, 0, 0});
}

void	co_inter(t_co *cone, t_hit *f_inter, t_bump *bump, int *style)
{
	t_pl	base_cap;
	double	distance;

	t_hit (tmp_inter), (cap_inter);
	t_vec3d (hit_point), (cap_center);
	tmp_inter = *f_inter;
	if (check_cone_hit(cone, &tmp_inter) && tmp_inter.closest.dista < f_inter->closest.dista){
		*f_inter = tmp_inter;
		if (style[COLOR] != 1)
			set_style_co(bump, style, f_inter, cone);
	}
	cap_inter = *f_inter;
	cone_caps(&base_cap, cone);
	if (plane_inter(&base_cap, &cap_inter, NULL, NULL)) // to check nULL 
	{
		hit_point = cap_inter.closest.point;
		cap_center = base_cap.point;
		distance = v_magnitude(v_minus(hit_point, cap_center));
		if (distance <= cone->radius && cap_inter.closest.dista < f_inter->closest.dista)
		{
			f_inter->closest = cap_inter.closest;
			f_inter->closest.normal = base_cap.normal;
			f_inter->hit_clos = 1;
			if (style[COLOR] != 1)
				set_style_co(bump, style, f_inter, cone);
		}
	}
}
