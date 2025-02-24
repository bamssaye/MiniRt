/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:56:21 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/24 11:16:05 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

////  soultion probleme 
int	quad(double a, double b, double c, double *t1, double *t2)
{
	double	disc;

	disc = b * b - 4.0 * a * c;
	if (a == 0.0 || disc < 0.0)
		return (0);
	disc = sqrt(disc);
	*t1 = (-b - disc) / (2.0 * a);
	*t2 = (-b + disc) / (2.0 * a);
	return (1);
}

int calculate_cone_intersection(t_ray ray, t_co cone, t_vec3d ori, double *t1, double *t2)
{
	double dn, on, k, k_sq, a, b, c;

	dn = v_dot(ray.direction, cone.normal);
	on = v_dot(ori, cone.normal);
	k = cone.radius / cone.height;
	k_sq = k * k;
	a = v_dot(ray.direction, ray.direction) - dn * dn - k_sq * dn * dn;
	b = 2.0 * (v_dot(ori, ray.direction) - on * dn - k_sq * on * dn);
	c = v_dot(ori, ori) - on * on - k_sq * on * on;
	return quad(a, b, c, t1, t2);
}

double	cone_ray_dista(t_ray ray, t_co cone)
{
	t_vec3d	ori;
	double t1, t2, min_t, h;
	int		i;
	double	roots[2];
	t_vec3d hit;

	ori = v_minus(ray.origin, cone.point);
	if (!calculate_cone_intersection(ray, cone, ori, &t1, &t2))
		return (-1);
	min_t = INFINITY;
	roots[0] = t1;
	roots[1] = t2;
	i = -1;
	while (++i < 2)
	{
		if (roots[i] > 0.0)
		{
			hit = v_plus(v_scale(roots[i], ray.direction), ray.origin);
			h = v_dot(v_minus(hit, cone.point), cone.normal);
			if (h >= 0 && h <= cone.height && roots[i] < min_t)
				min_t = roots[i];
		}
	}
	if (min_t == INFINITY)
		return (-1);
	return (min_t);
}

int	check_cone_hit(t_co *cone, t_hit *p)
{
	double	t;
	t_vec3d	a2h;
	double	proj;
	double	k_sq;

	t = cone_ray_dista(*p->ray, *cone);
	if (t > 0.0 && t < p->closest.dista)
	{
		p->closest.point = v_plus(v_scale(t, p->ray->direction),
				p->ray->origin);
		a2h = v_minus(p->closest.point, cone->point);
		proj = v_dot(a2h, cone->normal);
		k_sq = (cone->radius / cone->height) * (cone->radius / cone->height);
		p->closest.normal = v_normalize(v_minus(a2h, v_scale(proj
						* (1 + k_sq), cone->normal)));
		p->closest.dista = t;
		p->hit_clos = 1;
		p->closest.color = cpy_color(cone->color);
		return (1);
	}
	return (0);
}

void	cone_caps(t_pl *pl, t_co *cone)
{
	t_vec3d	base;

	base = v_plus(cone->point, v_scale(cone->height, cone->normal));
	*pl = copy_pl(base, cone->normal, cone->color, (t_vec3d){0, 0, 0, 0});
}

void	co_inter(t_co *cone, t_hit *f_inter, t_bump *bump, int *style)
{
	t_pl	base;
	t_hit	tmp;
	t_hit	cap;

	tmp = *f_inter;
	cap = *f_inter;
	if (check_cone_hit(cone, &tmp) && tmp.hit_clos && tmp.closest.dista < f_inter->closest.dista)
	{
		*f_inter = tmp;
		if (style[COLOR] != 1)
			set_style_co(bump, style, f_inter, cone);
	}
	cone_caps(&base, cone);
	if (plane_inter(&base, &cap, NULL, NULL) && cap.hit_clos)
	{
		if (v_magnitude(v_minus(cap.closest.point,
					base.point)) <= cone->radius
			&& cap.closest.dista < f_inter->closest.dista)
		{
			f_inter->closest = cap.closest;
			f_inter->closest.normal = base.normal;
			f_inter->hit_clos = 1;
			if (style[COLOR] != 1)
				set_style_co(bump, style, f_inter, cone);
		}
	}
}

