/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:24 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/28 20:00:34 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	quad_equa(double a, double b, double c)
{
	double (x1), (x2), (delta), (sq_delta);
	delta = (b * b) - (4.0 * a * c);
	if (a == 0.0 || delta < 0.0)
		return (-1);
	sq_delta = sqrt(delta);
	x1 = (-b + sq_delta) / (2.0 * a);
	x2 = (-b - sq_delta) / (2.0 * a);
	if (delta == 0.0)
		return (x1);
	if (x1 < 0.0 && x2 < 0.0)
		return (-1);
	else if (x1 < 0.0)
		return (x2);
	else if (x2 < 0.0)
		return (x1);
	else
		return (fmin(x1, x2));
	return (-1);
}

double	v_dot(t_vec3d a, t_vec3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	v_magnitude(t_vec3d a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

// Lambertian diffuse / light scale
double	lig_scale(t_vec3d a, t_vec3d b)
{
	double	cosine;

	cosine = v_dot(a, b);
	return (fmax(cosine, 0.0));
}
t_vec3d v_perpendicular(t_vec3d v)
{
    t_vec3d perp;
    
    if (fabs(v.x) <= fabs(v.y) && fabs(v.x) <= fabs(v.z))
        perp = v_cross(v, (t_vec3d){1, 0, 0, 0});
    else if (fabs(v.y) <= fabs(v.z))
        perp = v_cross(v, (t_vec3d){0, 1, 0, 0});
    else
        perp = v_cross(v, (t_vec3d){0, 0, 1, 0});
    return (v_normalize(perp));
}
t_vec3d	tan_bitan_n(t_vec3d normal, t_vec3d no_map)
{
	t_tbitan	tbn;

	tbn.tan =  v_perpendicular(normal);
	tbn.bitan = v_normalize(v_cross(normal, tbn.tan));
	return ((t_vec3d){
		.x = v_dot(no_map, tbn.tan),
		.y = v_dot(no_map, tbn.bitan),
		.z = v_dot(no_map, normal)
	});
}
