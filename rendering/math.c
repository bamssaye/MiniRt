/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:09:26 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/13 08:48:03 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	quad_equa(double a, double b, double c) //solve_quadratic_equation
{
	double	discriminant;
	double	t1;
	double	t2;
	double	sqrtdiscriminant;

	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0.0)
		return (-1);
	sqrtdiscriminant = sqrt(discriminant);
	if (discriminant > 0.0)
	{
		t1 = (-b + sqrtdiscriminant) / (2.0 * a);
		t2 = (-b - sqrtdiscriminant) / (2.0 * a);
		if (t1 < 0.0 || t2 < 0.0)
			return (-1);
		if (t1 < t2)
			return (t1);
		else
			return (t2);
	}
	return (-1);
}

double	vec3d_dot(t_vec3d *a, t_vec3d *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

double	vec3d_length(t_vec3d *a)
{
	return (sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
}

t_vec3d	multi_(t_vec3d *normal)
{
	return ((t_vec3d){
		.x = -normal->x,
		.y = -normal->y,
		.z = -normal->z,
	});
}

double	c_light_scale(t_vec3d *a, t_vec3d *b)
{
	double	angle;

	angle = acos(vec3d_dot(a, b));
	if (angle <= 1.570796)
		return (1.0 - (angle / 1.570796));
	return (0);
}
