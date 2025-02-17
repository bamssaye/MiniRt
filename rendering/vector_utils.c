/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:20:01 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/17 01:04:56 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vec3d	vec3d_scale(double scale, t_vec3d a)
{
	return ((t_vec3d){
		.x = a.x * scale,
		.y = a.y * scale,
		.z = a.z * scale,
	});
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
