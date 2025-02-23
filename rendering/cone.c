/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:56:21 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/23 15:06:29 by iel-koub         ###   ########.fr       */
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

////  soultion probleme 
// int	quad(double a, double b, double c, double *t1, double *t2)
// {
// 	double	disc;

// 	disc = b * b - 4.0 * a * c;
// 	if (a == 0.0 || disc < 0.0)
// 		return (0);
// 	disc = sqrt(disc);
// 	*t1 = (-b - disc) / (2.0 * a);
// 	*t2 = (-b + disc) / (2.0 * a);
// 	return (1);
// }

// int calculate_cone_intersection(t_ray ray, t_cone cone, t_vec3d ori, double *t1, double *t2)
// {
// 	double dn, on, k, k_sq, a, b, c;

// 	dn = vec3d_dot(ray.direction, cone.normal);
// 	on = vec3d_dot(ori, cone.normal);
// 	k = cone.radius / cone.height;
// 	k_sq = k * k;
// 	a = vec3d_dot(ray.direction, ray.direction) - dn * dn - k_sq * dn * dn;
// 	b = 2.0 * (vec3d_dot(ori, ray.direction) - on * dn - k_sq * on * dn);
// 	c = vec3d_dot(ori, ori) - on * on - k_sq * on * on;
// 	return quad(a, b, c, t1, t2);
// }

// double	cone_ray_dista(t_ray ray, t_cone cone)
// {
// 	t_vec3d	ori;
// 	double t1, t2, min_t, h;
// 	int		i;
// 	double	roots[2];
// 	t_vec3d hit;

// 	ori = vec3d_minus(ray.origin, cone.point);
// 	if (!calculate_cone_intersection(ray, cone, ori, &t1, &t2))
// 		return (-1);
// 	min_t = INFINITY;
// 	roots[0] = t1;
// 	roots[1] = t2;
// 	i = -1;
// 	while (++i < 2)
// 	{
// 		if (roots[i] > 0.0)
// 		{
// 			hit = vec3d_plus(vec3d_scale(roots[i], ray.direction), ray.origin);
// 			h = vec3d_dot(vec3d_minus(hit, cone.point), cone.normal);
// 			if (h >= 0 && h <= cone.height && roots[i] < min_t)
// 				min_t = roots[i];
// 		}
// 	}
// 	if (min_t == INFINITY)
// 		return (-1);
// 	return (min_t);
// }

// int	check_cone_hit(t_cone *cone, t_in_pa *p)
// {
// 	double	t;
// 	t_vec3d	a2h;
// 	double	proj;
// 	double	k_sq;

// 	t = cone_ray_dista(*p->ray, *cone);
// 	if (t > 0.0 && t < p->closest.dista)
// 	{
// 		p->closest.point = vec3d_plus(vec3d_scale(t, p->ray->direction),
// 				p->ray->origin);
// 		a2h = vec3d_minus(p->closest.point, cone->point);
// 		proj = vec3d_dot(a2h, cone->normal);
// 		k_sq = (cone->radius / cone->height) * (cone->radius / cone->height);
// 		p->closest.normal = vec3d_normalize(vec3d_minus(a2h, vec3d_scale(proj
// 						* (1 + k_sq), cone->normal)));
// 		p->closest.dista = t;
// 		p->hit_clos = 1;
// 		p->closest.color = cpy_color(cone->color);
// 		return (1);
// 	}
// 	return (0);
// }

// void	cone_caps(t_plane *pl, t_cone *cone)
// {
// 	t_vec3d	base;

// 	base = vec3d_plus(cone->point, vec3d_scale(cone->height, cone->normal));
// 	*pl = copy_pl(base, cone->normal, cone->color, (t_vec3d){0, 0, 0, 0});
// }

// void	co_inter(t_cone *cone, t_in_pa *f_inter)
// {
// 	t_plane	base;
// 	t_in_pa	tmp;
// 	t_in_pa	cap;

// 	tmp = *f_inter;
// 	cap = *f_inter;
// 	if (check_cone_hit(cone, &tmp) && tmp.hit_clos
// 		&& tmp.closest.dista < f_inter->closest.dista)
// 		*f_inter = tmp;
// 	cone_caps(&base, cone);
// 	if (plane_inter(&base, &cap) && cap.hit_clos)
// 	{
// 		if (vec3d_length(vec3d_minus(cap.closest.point,
// 					base.point)) <= cone->radius
// 			&& cap.closest.dista < f_inter->closest.dista)
// 		{
// 			f_inter->closest = cap.closest;
// 			f_inter->closest.normal = base.normal;
// 			f_inter->hit_clos = 1;
// 		}
// 	}
// }


