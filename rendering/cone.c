/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:56:21 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/17 13:26:03 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	cone_ray_dista(t_ray ray, t_cone cone)
{
	t_vec3d	ori;
	double	dir_dot_n;
	double	ori_dot_n;
	double	k;
	double	k_sq;
	double	dir_dot_dir;
	double	ori_dot_ori;
	double	a;
	double	b;
	double	c;

	ori = vec3d_minus(ray.origin, cone.point);
	dir_dot_n = vec3d_dot(ray.direction, cone.normal);
	ori_dot_n = vec3d_dot(ori, cone.normal);
	k = cone.radius / cone.height;
	k_sq = k * k;
	dir_dot_dir = vec3d_dot(ray.direction, ray.direction);
	ori_dot_ori = vec3d_dot(ori, ori);
	a = dir_dot_dir - dir_dot_n * dir_dot_n - k_sq * dir_dot_n * dir_dot_n;
	b = 2.0 * (vec3d_dot(ori, ray.direction) - ori_dot_n * dir_dot_n - k_sq
			* ori_dot_n * dir_dot_n);
	c = ori_dot_ori - ori_dot_n * ori_dot_n - k_sq * ori_dot_n * ori_dot_n;
	return (quad_equa(a, b, c));
}

int	check_cone_hit(t_cone *cone, t_in_pa *p)
{
	double	dist;
	t_vec3d	hit_point;
	double	height_pos;
	double	k_sq;
	double	projection;
	t_vec3d	apex_to_hit;
	t_vec3d	axis_projection;
	t_vec3d	normal;

	dist = cone_ray_dista(*p->ray, *cone);
	if (dist > 0.0 && dist < p->closest.dista)
	{
		hit_point = vec3d_plus(vec3d_scale(dist, p->ray->direction),
				p->ray->origin);
		height_pos = vec3d_dot(vec3d_minus(hit_point, cone->point),
				cone->normal);
		if (height_pos >= 0 && height_pos <= cone->height)
		{
			p->closest.point = hit_point;
			apex_to_hit = vec3d_minus(hit_point, cone->point);
			projection = vec3d_dot(apex_to_hit, cone->normal);
			k_sq = (cone->radius / cone->height) * (cone->radius / cone->height);
			axis_projection = vec3d_scale(projection * (1 + k_sq), cone->normal);
			normal = vec3d_minus(apex_to_hit, axis_projection);
			p->closest.normal = vec3d_normalize(normal);
			p->closest.dista = dist;
			p->hit_clos = 1;
			p->closest.color = cpy_color(cone->color);
			return (1);
		}
	}
	return (0);
}

void	cone_caps(t_plane *pl, t_cone *cone)
{
	t_vec3d	base_point;

	base_point = vec3d_plus(cone->point, vec3d_scale(cone->height,
				cone->normal));
	*pl = copy_pl(base_point, cone->normal, cone->color, (t_vec3d){0, 0, 0, 0});
}

void	co_inter(t_cone *cone, t_in_pa *f_inter)
{
	t_plane	base_cap;
	double	distance;
	t_in_pa(tmp_inter), (cap_inter);
	t_vec3d(hit_point), (cap_center);

	tmp_inter = *f_inter;
	cap_inter = *f_inter;
	if (check_cone_hit(cone, &tmp_inter)
		&& tmp_inter.closest.dista < f_inter->closest.dista)
		*f_inter = tmp_inter;
	cone_caps(&base_cap, cone);
	if (plane_inter(&base_cap, &cap_inter))
	{
		hit_point = cap_inter.closest.point;
		cap_center = base_cap.point;
		distance = vec3d_length(vec3d_minus(hit_point, cap_center));
		if (distance <= cone->radius
			&& cap_inter.closest.dista < f_inter->closest.dista)
		{
			f_inter->closest = cap_inter.closest;
			f_inter->closest.normal = base_cap.normal;
			f_inter->hit_clos = 1;
		}
	}
}
