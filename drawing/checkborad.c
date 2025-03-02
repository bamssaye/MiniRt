/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkborad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:33:49 by bamssaye          #+#    #+#             */
/*   Updated: 2025/03/01 18:45:49 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vec3d	v_perpendicular(t_vec3d v)
{
	t_vec3d		perp;

	if (fabs(v.x) <= fabs(v.y) && fabs(v.x) <= fabs(v.z))
		perp = v_cross(v, (t_vec3d){1, 0, 0, 0});
	else if (fabs(v.y) <= fabs(v.z))
		perp = v_cross(v, (t_vec3d){0, 1, 0, 0});
	else
		perp = v_cross(v, (t_vec3d){0, 0, 1, 0});
	return (v_normalize(perp));
}

t_color	sp_checkerboard(t_vec3d *hpoint, t_sp *sp)
{
	t_vec3d		local;

	double (u), (v);
	int (x), (y);
	local = v_minus(*hpoint, sp->center);
	u = (-(atan2(local.z, local.x)) + PI) / (2.0 * PI);
	v = acos(local.y / sp->radius) / PI;
	x = floor(u * 60);
	y = floor(v * 60);
	if ((x + y) % 2 == 0)
		return ((t_color){0, 0, 0, 0});
	else
		return ((t_color){255, 255, 255, 0});
}

t_color	pl_checkerboard(t_vec3d *hpoint, t_pl *pl)
{
	t_vec3d		local;
	t_vec3d		uv;

	int (x), (y);
	local = v_minus(*hpoint, pl->point);
	uv = hight_right_up(pl->normal, local, 1);
	x = floor(uv.x / 5);
	y = floor(uv.y / 5);
	if ((x + y) % 2 == 0)
		return ((t_color){0, 0, 0, 0});
	else
		return ((t_color){255, 255, 255, 0});
}

t_color	cy_checkerboard(t_vec3d *hpoint, t_cy *cy)
{
	t_vec3d		local;
	t_vec3d		uv;

	double (u), (v);
	int (x), (y);
	local = v_minus(*hpoint, cy->point);
	uv = hight_right_up(cy->normal, local, 0);
	u = 0.5 + uv.x / (2 * PI);
	v = fmod(uv.y / cy->len + 1.0, 1.0);
	x = floor(u * 20);
	y = floor(v * 20);
	if ((x + y) % 2 == 0)
		return ((t_color){0, 0, 0, 0});
	else
		return ((t_color){255, 255, 255, 0});
}

t_color	co_checkerboard(t_vec3d *hpoint, t_co *co)
{
	t_vec3d		local;
	t_vec3d		uv;

	double (u), (v);
	int (x), (y);
	local = v_minus(*hpoint, co->point);
	uv = hight_right_up(co->normal, local, 0);
	u = 0.5 + uv.x / (2 * PI);
	v = fmod(uv.y / co->height + 1, 1.0);
	x = floor(u * 20);
	y = floor(v * 20);
	if ((x + y) % 2 == 0)
		return ((t_color){0, 0, 0, 0});
	else
		return ((t_color){255, 255, 255, 0});
}
