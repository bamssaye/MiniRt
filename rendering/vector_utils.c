/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:27:12 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/23 12:15:14 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vec3d	vec3d_scale(double scale, t_vec3d a);
double	vec3d_length(t_vec3d a);
t_vec3d	vec3d_cross(t_vec3d a, t_vec3d b);
t_vec3d	vec3d_plus(t_vec3d a, t_vec3d b);
t_vec3d	vec3d_minus(t_vec3d a, t_vec3d b);
t_vec3d	vec3d_normalize(t_vec3d a);

t_vec3d	vec3d_scale(double scale, t_vec3d a)
{
	return ((t_vec3d){
		.x = a.x * scale,
		.y = a.y * scale,
		.z = a.z * scale,
	});
}
double	vec3d_length(t_vec3d a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}
t_vec3d	vec3d_cross(t_vec3d a, t_vec3d b)
{
	return ((t_vec3d){
		.x = a.y * b.z - a.z * b.y,
		.y = a.z * b.x - a.x * b.z,
		.z = a.x * b.y - a.y * b.x,
	});
}
t_vec3d	vec3d_plus(t_vec3d a, t_vec3d b)
{
    return ((t_vec3d){
		.x = a.x + b.x,
		.y = a.y + b.y,
		.z = a.z + b.z,
	});
}
t_vec3d	vec3d_minus(t_vec3d a, t_vec3d b)
{
	return ((t_vec3d){
		.x = a.x - b.x,
		.y = a.y - b.y,
		.z = a.z - b.z,
	});
}
t_vec3d	vec3d_normalize(t_vec3d a)
{
	double	length;

	length = vec3d_length(a);
	return ((t_vec3d){
		.x = a.x / length,
		.y = a.y / length,
		.z = a.z / length,
	});
}
double	vec3d_dot(t_vec3d a, t_vec3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
