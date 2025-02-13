/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:20:34 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/13 08:51:13 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	pl_ray_dista(t_ray ray, t_plane pl, t_npc *closest)
{
	t_vec3d		inter_p;

	double (dist), (dot);
	dist = -1;
	dot = vec3d_dot(&pl.normal, &ray.direction);
	inter_p = vec3d_minus(&pl.point, &ray.origin);
	dist = vec3d_dot(&inter_p, &pl.normal) / dot;
	if ((dist <= 0) || (fabs(dot - 0) < EPSILON))
		return (0);
	closest->normal = cpy_vec(&pl.normal);
	if (dot > 0)
		closest->normal = multi_(&closest->normal);
	return (dist);
}

t_npc	pl_closest(t_vec3d ray, t_plane pl, double dist, t_vec3d origin)
{
	return ((t_npc){
		.color = pl.color,
		.dista = dist,
		.normal = pl.normal,
		.point = (t_vec3d){
		.x = origin.x + dist * ray.x,
		.y = origin.y + dist * ray.y,
		.z = origin.z + dist * ray.z,
	}});
}
// t_color pl_texture_col(t_tex tex, t_vec3d hit_point, t_plane plane)
// {
//     char *pixel;

// 	double (u), (v);
// 	t_vec3d (up), (right);
// 	up = (t_vec3d){0, 1, 0, 0};
//     right = vec3d_cross(plane.normal, up);
//     if (vec3d_length(right) < 0.01)
//     {
//         up = (t_vec3d){0, 0, 1, 0};
//         right = vec3d_cross(plane.normal, up);
//     }
//     u = vec3d_dot(hit_point, vec3d_normalize(right));
//     v = vec3d_dot(hit_point, vec3d_normalize(vec3d_cross(right, plane.normal)));
//     u = fmod(u * 0.1, 1.0);
//     v = fmod(v * 0.1, 1.0);
//     if (u < 0)
// 		u += 1.0;
//     if (v < 0)
// 		v += 1.0;
//     pixel = tex.addr + ((int)(v * tex.height) % tex.height) * tex.line_length 
//                           + ((int)(u * tex.width) % tex.width) * (tex.bpp / 8);
//     return (t_color){pixel[2], pixel[1], pixel[0], 0};
// }

int	plane_inter(t_plane *plane, t_in_pa *param)
{
	double	dist;
	t_vec3d	*ray;

	ray = &param->ray->direction;
	dist = pl_ray_dista(*(param->ray), *plane, &param->closest);
	if (dist > 0)
	{
		// fprintf(stderr, "helllll \n");
		param->closest = pl_closest(*ray, *plane, dist, param->ray->origin);
		param->hit_clos = 1;
		// if (plane->tex.img)
		// 	param->closest.color = pl_texture_col(plane->tex, param->closest.point, *plane);
	}
	(void)ray;
	return (dist);
}

t_plane	copy_pl(t_vec3d *po, t_vec3d *no, t_color *col, t_vec3d *offset)
{
	if (offset->isv)
	{
		*offset = vec3d_scale(-1, no);
		return ((t_plane){
			.color = cpy_color(col),
			.normal = *offset,
			.point = *po});
	}
	return ((t_plane){
		.color = cpy_color(col),
		.normal = *no,
		.point = *po});
}
