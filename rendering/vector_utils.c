/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:20:01 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/19 21:19:50 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vec3d	v_scale(double scale, t_vec3d a)
{
	return ((t_vec3d){
		.x = a.x * scale,
		.y = a.y * scale,
		.z = a.z * scale,
	});
}

t_vec3d	v_cross(t_vec3d a, t_vec3d b)
{
	return ((t_vec3d){
		.x = a.y * b.z - a.z * b.y,
		.y = a.z * b.x - a.x * b.z,
		.z = a.x * b.y - a.y * b.x,
	});
}

t_vec3d	v_plus(t_vec3d a, t_vec3d b)
{
	return ((t_vec3d){
		.x = a.x + b.x,
		.y = a.y + b.y,
		.z = a.z + b.z,
	});
}

t_vec3d	v_minus(t_vec3d a, t_vec3d b)
{
	return ((t_vec3d){
		.x = a.x - b.x,
		.y = a.y - b.y,
		.z = a.z - b.z,
	});
}

t_vec3d	v_normalize(t_vec3d a)
{
	double	length;

	length = v_magnitude(a);
	return ((t_vec3d){
		.x = a.x / length,
		.y = a.y / length,
		.z = a.z / length,
	});
}
