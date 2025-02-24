/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:04 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/24 11:07:27 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

// static void		cy_caps(t_pl *pl, t_cy *cy, int is_top);
// static int		check_cap_intersection(t_cy *cy, t_hit *inter, int type);
// static int		check_cylinder_caps_intersection(t_cy *cy, t_hit *inter);
// static int		check_cylinder_hit(t_cy *cy, t_hit *p);

void	cy_inter(t_cy *cy, t_hit *f_inter, t_bump *bump, int *style)
{
	t_hit (tmp_body), (tmp_caps);
	tmp_body = *f_inter;
	if (check_cylinder_hit(cy, &tmp_body))
	{
		*f_inter = tmp_body;
		if (style[COLOR] != 1)
			set_style_cy(bump, style, f_inter, cy);
	}
	tmp_caps = *f_inter;
	if (check_cylinder_caps_intersection(cy, &tmp_caps))
	{
		if (tmp_caps.closest.dista < f_inter->closest.dista)
		{
			*f_inter = tmp_caps;
			if (style[COLOR] != 1)
				set_style_cy(bump, style, f_inter, cy);
		}
	}
}

void	cy_caps(t_pl *pl, t_cy *cy, int is_top)
{
	t_vec3d	offset;
	t_vec3d	cap_ce;

	if (is_top)
	{
		offset = v_scale(cy->len / 2.0, cy->normal);
		cap_ce = v_plus(cy->point, offset);
		offset.isv = 1;
	}
	else
	{
		offset = v_scale(-cy->len / 2.0, cy->normal);
		cap_ce = v_plus(cy->point, offset);
		offset.isv = 0;
	}
	*pl = copy_pl(cap_ce, cy->normal, cy->color, offset);
}

int	check_cap_intersection(t_cy *cy, t_hit *inter, int type)
{
	t_vec3d	point_to_center;
	t_pl	cap;

	cy_caps(&cap, cy, type);
	if (plane_inter(&cap, inter, NULL, NULL))
	{
		point_to_center = v_minus(inter->closest.point, cap.point);
		if (v_magnitude(point_to_center) < cy->radius)
		{
			if (v_dot(inter->ray->direction, cap.normal) > 0)
				inter->closest.normal = v_scale(-1, cap.normal);
			else
				inter->closest.normal = cap.normal;
			inter->closest.dista = inter->closest.dista;
			inter->hit_clos = 1;
			inter->closest.color = cpy_color(cy->color);
			return (1);
		}
	}
	return (0);
}

int	check_cylinder_caps_intersection(t_cy *cy, t_hit *inter)
{
	t_hit (bottom_inter), (top_inter);
	int (hit_bottom), (hit_top);
	top_inter = *inter;
	bottom_inter = *inter;
	hit_top = check_cap_intersection(cy, &top_inter, 1);
	hit_bottom = check_cap_intersection(cy, &bottom_inter, 0);
	if (hit_top && hit_bottom)
	{
		if (top_inter.closest.dista < bottom_inter.closest.dista)
			*inter = top_inter;
		else
			*inter = bottom_inter;
		return (1);
	}
	if (hit_top)
	{
		*inter = top_inter;
		return (1);
	}
	if (hit_bottom)
	{
		*inter = bottom_inter;
		return (1);
	}
	return (0);
}

int	check_cylinder_hit(t_cy *cy, t_hit *p)
{
	double	dist;
	t_vec3d	point_to_center;

	dist = cy_ray_dista(*p->ray, *cy);
	if (dist > 0.0)
	{
		p->closest.point = v_plus(p->ray->origin, v_scale(dist,
					p->ray->direction));
		p->closest.normal = v_normalize(v_minus(p->closest.point, cy->point));
		point_to_center = v_minus(p->closest.point, cy->point);
		if (fabs(v_dot(point_to_center, cy->normal)) < cy->len / 2.0)
		{
			p->closest.dista = dist;
			p->hit_clos = 1;
			p->closest.color = cpy_color(cy->color);
			return (1);
		}
	}
	return (0);
}
