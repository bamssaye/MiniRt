/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:56:02 by iel-koub          #+#    #+#             */
/*   Updated: 2025/03/01 18:51:23 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void	cone_caps(t_pl *pl, t_co *cone)
{
	t_vec3d	base;

	base = v_plus(cone->point, v_scale(cone->height, cone->normal));
	*pl = copy_pl(base, cone->normal, cone->color, (t_vec3d){0, 0, 0, 0});
}

void	cap_inter(t_co *cone, t_hit *f_inter, t_bump *bump, int *style)
{
	t_pl	base_cap;
	t_hit	cap_inter;
	double	distance;

	cap_inter = *f_inter;
	cone_caps(&base_cap, cone);
	if (plane_inter(&base_cap, &cap_inter, NULL, NULL))
	{
		distance = v_magnitude(v_minus(cap_inter.closest.point,
					base_cap.point));
		if (distance <= cone->radius
			&& cap_inter.closest.dista < f_inter->closest.dista)
		{
			f_inter->closest = cap_inter.closest;
			f_inter->closest.normal = base_cap.normal;
			f_inter->hit_clos = 1;
			if (style[COLOR] != 1)
				set_style_co(bump, style, f_inter, cone);
		}
	}
}

static void	cap_intersection(t_co *cone, t_hit *f_inter, t_bump *bump,
		int *style)
{
	t_pl	base_cap;
	t_hit	cap_inter;
	double	distance;

	cap_inter = *f_inter;
	cone_caps(&base_cap, cone);
	if (plane_inter(&base_cap, &cap_inter, NULL, NULL))
	{
		distance = v_magnitude(v_minus(cap_inter.closest.point,
					base_cap.point));
		if (distance <= cone->radius
			&& cap_inter.closest.dista < f_inter->closest.dista)
		{
			f_inter->closest = cap_inter.closest;
			f_inter->closest.normal = base_cap.normal;
			f_inter->hit_clos = 1;
			if (style[COLOR] != 1)
				set_style_co(bump, style, f_inter, cone);
		}
	}
}

void	co_inter(t_co *cone, t_hit *f_inter, t_bump *bump, int *style)
{
	t_hit	tmp_inter;

	tmp_inter = *f_inter;
	if (check_cone_hit(cone, &tmp_inter)
		&& tmp_inter.closest.dista < f_inter->closest.dista)
	{
		*f_inter = tmp_inter;
		if (style[COLOR] != 1)
			set_style_co(bump, style, f_inter, cone);
	}
	cap_intersection(cone, f_inter, bump, style);
}
