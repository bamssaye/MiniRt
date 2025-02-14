/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:27:12 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/14 05:19:51 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vec3d	vec3d_scale(double scale, t_vec3d *a)
{
	return ((t_vec3d){
		.x = a->x * scale,
		.y = a->y * scale,
		.z = a->z * scale,
	});
}
/* vector cross product
s = s1 + s2 + s3 = a × b
S1 = a2*b3 - a3*b2 
S2 = a3*b1 - a1*b3
S3 = a1*b2 - a2*b1
*/
t_vec3d	vec3d_cross(t_vec3d *a, t_vec3d *b)
{
	return ((t_vec3d){
		.x = a->y * b->z - a->z * b->y,
		.y = a->z * b->x - a->x * b->z,
		.z = a->x * b->y - a->y * b->x,
	});
}

t_vec3d	vec3d_plus(t_vec3d *a, t_vec3d *b)
{
	return ((t_vec3d){
		.x = a->x + b->x,
		.y = a->y + b->y,
		.z = a->z + b->z,
	});
}

t_vec3d	vec3d_minus(t_vec3d *a, t_vec3d *b)
{
	return ((t_vec3d){
		.x = a->x - b->x,
		.y = a->y - b->y,
		.z = a->z - b->z,
	});
}
/* vector normalize :
	- m = magnitue |a|
	- |a| = |a| / m
*/
t_vec3d	vec3d_normalize(t_vec3d *a)
{
	double	magnitude;

	magnitude = vec3d_magnitude(a);
	return ((t_vec3d){
		.x = a->x / magnitude,
		.y = a->y / magnitude,
		.z = a->z / magnitude,
	});
}
