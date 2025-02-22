/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkborad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:33:49 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/22 12:06:09 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_color pl_checkerboard(t_vec3d *hpoint, t_pl *pl);
t_color sp_checkerboard(t_vec3d *hpoint, t_sp *sp);
t_color cy_checkerboard(t_vec3d *hpoint, t_cy *cy);

t_color sp_checkerboard(t_vec3d *hpoint, t_sp *sp)
{	
	double (u), (v), (scale);
    int (x), (y);
	u = 0.5 + atan2(hpoint->z - sp->center.z, \
        hpoint->x - sp->center.x) / (2 * PI);
    v = 0.5 - asin((hpoint->y - sp->center.y) / sp->radius) / PI;
    scale = 60;
    x = floor(u * scale);
    y = floor(v * scale);
    if ((x + y) % 2 == 0)
        return (t_color){0, 0, 0, 0};
    else
        return (t_color){255, 255, 255, 0};
}

t_color pl_checkerboard(t_vec3d *hpoint, t_pl *pl)
{
    t_vec3d (up), (right), (up_dir), (corss);
    double (u), (v);
    up = (t_vec3d){0, 1, 0, 0};
    right = v_cross(pl->normal, up);
    if (v_magnitude(right) < 0.01)
    {
        up = (t_vec3d){0, 0, 1, 0};
        right = v_cross(pl->normal, up);
    }
    right = v_normalize(right);
    corss = v_cross(right, pl->normal);
    up_dir = v_normalize(corss);
    u = fmod(v_dot(*hpoint, right) * 0.1, 1.0);
    v = fmod(v_dot(*hpoint, up_dir) * 0.1, 1.0);
    if (u < 0)
        u += 1.0;
    if (v < 0)
        v += 1.0;
    if ((int)(v + u) % 2 == 0)
        return (t_color){0, 0, 0, 0};
    else
        return (t_color){255, 255, 255, 0};
}

t_color cy_checkerboard(t_vec3d *hpoint, t_cy *cy)
{
	double (u), (v), (scale);
    int (x),(y);
    u = 0.5 + atan2(hpoint->z - cy->point.z, \
        hpoint->x - cy->point.x) / (2 * PI);
    v = fabs((hpoint->y - cy->point.y) / cy->len);
    scale = 60;
    x = floor(u * scale);
    y = floor(v * scale);
    if ((x + y) % 2 == 0)
        return (t_color){0, 0, 0, 0};
    else
        return (t_color){255, 255, 255, 0};
}
t_color co_checkerboard(t_vec3d *hpoint, t_co *co)
{
	double (u), (v), (scale);
    int (x),(y);

    u = 0.5 + atan2(hpoint->z - co->point.z, hpoint->x - co->point.x) / (2 * PI);
    v = fabs((hpoint->y - co->point.y) / co->height);
    scale = 20;
    x = floor(u * scale);
    y = floor(v * scale);
    if ((x + y) % 2 == 0)
        return (t_color){0, 0, 0, 0};
    else
        return (t_color){255, 255, 255, 0};
}