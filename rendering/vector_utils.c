/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:27:12 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/22 18:23:17 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

// int	vec3d_scale(t_vec3d *res, double scale, t_vec3d *a);
// double	vec3d_dot(t_vec3d *a, t_vec3d *b);
// int	vec3d_init(t_vec3d *a, double x, double y, double z);
// int	copy_vec3d(t_vec3d *to, t_vec3d *from);
// int	vec3d_normalize(t_vec3d *a);
// int	vec3d_plus(t_vec3d *res, t_vec3d *a, t_vec3d *b);
// int	vec3d_minus(t_vec3d *res, t_vec3d *a, t_vec3d *b);
// int	vec3d_cross(t_vec3d *res, t_vec3d *a, t_vec3d *b);
// double	vec3d_length(t_vec3d *a);


// int	vec3d_scale(t_vec3d *res, double scale, t_vec3d *a)
// {
// 	if (res == NULL || a == NULL)
// 		return (1);
// 	res->x = a->x * scale;
// 	res->y = a->y * scale;
// 	res->z = a->z * scale;
// 	return (0);
// }
// double	vec3d_dot(t_vec3d *a, t_vec3d *b)
// {
// 	if (a == NULL || b == NULL)
// 		return (1);
// 	return (a->x * b->x + a->y * b->y + a->z * b->z);
// }
// int	vec3d_init(t_vec3d *a, double x, double y, double z)
// {
// 	if (a == NULL)
// 		return (1);
// 	a->x = x;
// 	a->y = y;
// 	a->z = z;
// 	return (0);
// }
// int	copy_vec3d(t_vec3d *to, t_vec3d *from)
// {
// 	if (to == NULL || from == NULL)
// 		return (1);
// 	ft_memcpy(to, from, sizeof(t_vec3d));
// 	return (0);
// }
// int	vec3d_plus(t_vec3d *res, t_vec3d *a, t_vec3d *b)
// {
// 	if (a == NULL || b == NULL)
// 		return (1);
// 	res->x = a->x + b->x;
// 	res->y = a->y + b->y;
// 	res->z = a->z + b->z;
// 	return (0);
// }
// int	vec3d_minus(t_vec3d *res, t_vec3d *a, t_vec3d *b)
// {
// 	if (a == NULL || b == NULL || res == NULL)
// 		return (1);
// 	res->x = a->x - b->x;
// 	res->y = a->y - b->y;
// 	res->z = a->z - b->z;
// 	return (0);
// }
// int	vec3d_cross(t_vec3d *res, t_vec3d *a, t_vec3d *b)
// {
// 	if (res == NULL)
// 		return (1);
// 	res->x = a->y * b->z - a->z * b->y;
// 	res->y = a->z * b->x - a->x * b->z;
// 	res->z = a->x * b->y - a->y * b->x;
// 	return (0);
// }
// double	vec3d_length(t_vec3d *a)
// {
// 	if (a == NULL)
// 		return (1);
// 	return (sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
// }
// int	vec3d_normalize(t_vec3d *a)
// {
// 	double	length;

// 	if (a == NULL)
// 		return (1);
// 	length = vec3d_length(a);
// 	a->x /= length;
// 	a->y /= length;
// 	a->z /= length;
// 	return (0);
// }

///////////////////////////////////////////////////


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