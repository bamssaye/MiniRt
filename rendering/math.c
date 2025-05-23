/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:24 by iel-koub          #+#    #+#             */
/*   Updated: 2025/03/01 06:18:23 by bamssaye         ###   ########.fr       */
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

double	lig_scale(t_vec3d a, t_vec3d b)
{
	double	cosine;

	cosine = v_dot(a, b);
	return (fmax(cosine, 0.0));
}

t_tbitan	tan_bitan_n(t_vec3d normal, t_vec3d no_map)
{
	t_tbitan	tbn;

	tbn.tan = v_perpendicular(normal);
	(void)no_map;
	tbn.bitan = v_normalize(v_cross(normal, tbn.tan));
	return ((t_tbitan){
		.tan = tbn.tan,
		.bitan = tbn.bitan,
		.normal = normal
	});
}
