/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkborad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:33:49 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/28 21:37:25 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_color	sp_checkerboard(t_vec3d *hpoint, t_sp *sp)
{
	t_vec3d local;

	double (u), (v);
	int (x), (y);
	local = v_minus(*hpoint, sp->center);
	u = (-(atan2(local.z, local.x)) + PI) / (2.0 * PI);
	v = acos(local.y / sp->radius) / PI;
	x = (int)floor(u * 60);
	y = (int)floor(v * 60);
	if ((x + y) % 2 == 0)
		return ((t_color){0, 0, 0, 0});
	else
		return ((t_color){255, 255, 255, 0});
}
t_color	pl_checkerboard(t_vec3d *hpoint, t_pl *pl)
{
	t_vec3d	local;
	t_vec3d uv;

	int (x), (y);
	local = v_minus(*hpoint, pl->point);
	uv = hight_right_up(pl->normal, local, 1, 1);
	x = (int)floor(uv.x / 20);
	y = (int)floor(uv.y / 20);
	if ((x + y) % 2 == 0)
		return ((t_color){0, 0, 0, 0});
	else
		return ((t_color){255, 255, 255, 0});
}

t_color	cy_checkerboard(t_vec3d *hpoint, t_cy *cy)
{
	t_vec3d	local;
	t_vec3d uv;

	double (u), (v);
	int (x), (y);
	local = v_minus(*hpoint, cy->point);
	uv = hight_right_up(cy->normal, local, 0, cy->len);
	u = 0.5 + uv.x / (2 * PI);
    v = fmod(uv.y / cy->len + 1.0, 1.0);
	x = (int)floor(u * 20);
	y = (int)floor(v * 20);
	if ((x + y) % 2 == 0)
		return ((t_color){0, 0, 0, 0});
	else
		return ((t_color){255, 255, 255, 0});
}

t_color	co_checkerboard(t_vec3d *hpoint, t_co *co)
{
	t_vec3d	local;
	t_vec3d u_v;

	double (u), (v);
	int (x), (y);
	local = v_minus(*hpoint, co->point);
	u_v = hight_right_up(co->normal, local, 0, co->height);
	u = 0.5 + u_v.x / (2 * PI);
	v = fmod(u_v.y / co->height + 1, 1.0);
	x = (int)floor(u * 20);
	y = (int)floor(v * 20);
	if ((x + y) % 2 == 0)
		return ((t_color){0, 0, 0, 0});
	else
		return ((t_color){255, 255, 255, 0});
}
