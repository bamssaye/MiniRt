/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:20:34 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/08 05:42:18 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	pl_ray_dista(t_ray ray, t_plane pl, t_npc *closest)
{
	t_vec3d		inter_p;

	double (dist), (dot);
	dist = -1;
	dot = vec3d_dot(pl.normal, ray.direction);
	inter_p = vec3d_minus(pl.point, ray.origin);
	dist = vec3d_dot(inter_p, pl.normal) / dot;
	if ((dist <= 0) || (fabs(dot - 0) < EPSILON))
		return (0);
	closest->normal = cpy_vec(pl.normal);
	if (dot > 0)
		closest->normal = multi_(closest->normal);
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
t_color get_plane_texture_color(t_tex tex, t_vec3d hit_point, t_plane plane)
{
    double u, v;
    int x, y;
    char *pixel;
    t_vec3d up = {0, 1, 0,0};  // Default up vector
    t_vec3d right;
    // Calculate texture coordinates
    right = vec3d_cross(plane.normal, up);
    if (vec3d_length(right) < 0.01)  // If normal is parallel to up
    {
        up = (t_vec3d){0, 0, 1,0};  // Use different up vector
        right = vec3d_cross(plane.normal, up);
    }
    right = vec3d_normalize(right);
    up = vec3d_normalize(vec3d_cross(right, plane.normal));
    // Project hit point onto plane coordinate system
    u = vec3d_dot(hit_point, right);
    v = vec3d_dot(hit_point, up);
    // Scale and wrap coordinates
    double scale = 0.1;  // Adjust this to change texture scale
    u = fmod(u * scale, 1.0);
    v = fmod(v * scale, 1.0);
    // Convert to positive values
    if (u < 0) u += 1.0;
    if (v < 0) v += 1.0;
    // Convert to texture coordinates
    x = (int)(u * tex.width) % tex.width;
    y = (int)(v * tex.height) % tex.height;
    // Get pixel color from texture
    pixel = tex.addr + (y * tex.line_length + x * (tex.bpp / 8));
    return ((t_color){
        (unsigned char)pixel[2],  // Red
        (unsigned char)pixel[1],  // Green
        (unsigned char)pixel[0],  // Blue
        0
    });
}

int	plane_inter(t_plane *plane, t_in_pa *param)
{
	double	dist;
	t_vec3d	*ray;

	ray = &param->ray->direction;
	dist = pl_ray_dista(*(param->ray), *plane, &param->closest);
	if (dist > 0)
	{
		param->closest = pl_closest(*ray, *plane, dist, param->ray->origin);
		param->hit_clos = 1;
		param->closest.color = get_plane_texture_color(plane->tex,
			param->closest.point, *plane);
	}
	return (dist);
}

t_plane	copy_pl(t_vec3d po, t_vec3d no, t_color col, t_vec3d offset)
{
	if (offset.isv)
	{
		offset = vec3d_scale(-1, no);
		return ((t_plane){
			.color = cpy_color(col),
			.normal = offset,
			.point = po});
	}
	return ((t_plane){
		.color = cpy_color(col),
		.normal = no,
		.point = po});
}
