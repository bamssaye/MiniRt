/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkborad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:33:49 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/26 23:05:33 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vec3d	find_perpendicular(t_vec3d normal, t_vec3d hpoint, t_vec3d point)
{
	t_vec3d	right;
	t_vec3d	up;
	t_vec3d	local_point;

	if (fabs(normal.x) < fabs(normal.y))
	{
		if (fabs(normal.x) < fabs(normal.z))
			right = v_normalize(v_cross((t_vec3d){1, 0, 0, 0}, normal));
		else
			right = v_normalize(v_cross((t_vec3d){0, 0, 1, 0}, normal));
	}
	else
	{
		if (fabs(normal.y) < fabs(normal.z))
			right = v_normalize(v_cross((t_vec3d){0, 1, 0, 0}, normal));
		else
			right = v_normalize(v_cross((t_vec3d){0, 0, 1, 0}, normal));
	}
	up = v_normalize(v_cross(normal, right));
	local_point = v_minus(hpoint, point);
	return ((t_vec3d){
		.x = v_dot(local_point, right),
		.y = v_dot(local_point, up),
		.z = v_dot(local_point, normal)});
}

t_color	sp_checkerboard(t_vec3d *hpoint, t_sp *sp)
{
	double (u), (v), (scale);
	int (x), (y);
	u = 0.5 + atan2(hpoint->z - sp->center.z, hpoint->x - sp->center.x) / (2
			* PI);
	v = 0.5 - asin((hpoint->y - sp->center.y) / sp->radius) / PI;
	scale = 60;
	x = floor(u * scale);
	y = floor(v * scale);
	if ((x + y) % 2 == 0)
		return ((t_color){0, 0, 0, 0});
	else
		return ((t_color){255, 255, 255, 0});
}

t_color	pl_checkerboard(t_vec3d *hpoint, t_pl *pl)
{
	t_vec3d	local;

	double (scale);
	int (x), (y);
	local = find_perpendicular(pl->normal, *hpoint, pl->point);
	scale = 20;
	x = floor(local.x / scale);
	y = floor(local.y / scale);
	if ((x + y) % 2 == 0)
		return ((t_color){0, 0, 0, 0});
	else
		return ((t_color){255, 255, 255, 0});
}

t_color	cy_checkerboard(t_vec3d *hpoint, t_cy *cy)
{
	t_vec3d	local;

	double (u), (v), (scale);
	int (x), (y);
	local = find_perpendicular(cy->normal, *hpoint, cy->point);
	u = 0.5 + atan2(local.y, local.x) / (2 * PI);
	v = fabs(local.z / cy->len);
	scale = 20;
	x = floor(u * scale);
	y = floor(v * scale);
	if ((x + y) % 2 == 0)
		return ((t_color){0, 0, 0, 0});
	else
		return ((t_color){255, 255, 255, 0});
}

t_color	co_checkerboard(t_vec3d *hpoint, t_co *co)
{
	t_vec3d	local;

	double (u), (v), (scale);
	int (x), (y);
	local = find_perpendicular(co->normal, *hpoint, co->point);
	u = 0.5 + atan2(local.y, local.x) / (2 * PI);
	v = fabs(local.z / co->height);
	scale = 20;
	x = floor(u * scale);
	y = floor(v * scale);
	if ((x + y) % 2 == 0)
		return ((t_color){0, 0, 0, 0});
	else
		return ((t_color){255, 255, 255, 0});
}
