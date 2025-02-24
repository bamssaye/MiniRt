/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:56:21 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/24 15:59:35 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	quad(double a, double b, double c, double *res)
{
	double	disc;

	disc = b * b - 4.0 * a * c;
	if (a == 0.0 || disc < 0.0)
		return (0);
	disc = sqrt(disc);
	res[0] = (-b - disc) / (2.0 * a);
	res[1] = (-b + disc) / (2.0 * a);
	return (1);
}

int	calc_cone_inter(t_ray ray, t_co cone, t_vec3d ori, double *res)
{
	t_cone_inter	ci;

	ci.dn = v_dot(ray.direction, cone.normal);
	ci.on = v_dot(ori, cone.normal);
	ci.k = cone.radius / cone.height;
	ci.k_sq = ci.k * ci.k;
	ci.a = v_dot(ray.direction, ray.direction) - ci.dn * ci.dn
		- ci.k_sq * ci.dn * ci.dn;
	ci.b = 2.0 * (v_dot(ori, ray.direction) - ci.on * ci.dn
			- ci.k_sq * ci.on * ci.dn);
	ci.c = v_dot(ori, ori) - ci.on * ci.on - ci.k_sq * ci.on * ci.on;
	return (quad(ci.a, ci.b, ci.c, res));
}

double	cone_ray_dista(t_ray ray, t_co cone)
{
	t_cone_dist	cd;

	cd.ori = v_minus(ray.origin, cone.point);
	if (!calc_cone_inter(ray, cone, cd.ori, cd.roots))
		return (-1);
	cd.min_t = INFINITY;
	cd.i = -1;
	while (++cd.i < 2)
	{
		if (cd.roots[cd.i] > 0.0)
		{
			cd.hit = v_plus(v_scale(cd.roots[cd.i], ray.direction), ray.origin);
			cd.h = v_dot(v_minus(cd.hit, cone.point), cone.normal);
			if (cd.h >= 0 && cd.h <= cone.height && cd.roots[cd.i] < cd.min_t)
				cd.min_t = cd.roots[cd.i];
		}
	}
	if (cd.min_t == INFINITY)
		return (-1);
	return (cd.min_t);
}

int	check_cone_hit(t_co *cone, t_hit *p)
{
	t_cone_hit	ch;

	ch.t = cone_ray_dista(*p->ray, *cone);
	if (ch.t > 0.0 && ch.t < p->closest.dista)
	{
		p->closest.point = v_plus(v_scale(ch.t, p->ray->direction),
				p->ray->origin);
		ch.a2h = v_minus(p->closest.point, cone->point);
		ch.proj = v_dot(ch.a2h, cone->normal);
		ch.k_sq = (cone->radius / cone->height) * (cone->radius / cone->height);
		p->closest.normal = v_normalize(v_minus(ch.a2h, v_scale(ch.proj
						* (1 + ch.k_sq), cone->normal)));
		p->closest.dista = ch.t;
		p->hit_clos = 1;
		p->closest.color = cpy_color(cone->color);
		return (1);
	}
	return (0);
}
