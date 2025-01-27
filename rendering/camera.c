/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 01:17:52 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/27 00:00:10 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vec3d	c_look_at(t_camera *camera)
{
	t_vec3d	look_at;

	look_at = vec3d_plus(camera->position, camera->normal);
	look_at = vec3d_minus(look_at, camera->position);
    look_at = vec3d_normalize(look_at);
    return (look_at);
}
t_vec3d	c_r_v(t_camera *camera)
{
	t_vec3d v;
    
    v = vec3d_cross(camera->look_at, camera->u);
	if (vec3d_normalize(v).isv == -6)
		exit(1);
    return (v);
}

t_vec3d	c_topleft(t_camera *cam)
{
	t_vec3d	dir_v;
	t_vec3d	s_u_v;
	t_vec3d	s_v_v;
	double	view_d;
    t_vec3d tp_left;

	view_d = W_WIDTH / 2;
	view_d = view_d / (2.0 * tan((double)cam->fov * (PI / 180.0) / 2.0));
	ft_memcpy(&dir_v, &cam->look_at, sizeof(t_vec3d));
	dir_v = vec3d_normalize(dir_v);
	dir_v = vec3d_scale(view_d, dir_v);
	s_u_v = vec3d_scale(W_WIDTH / 2, cam->u);
	s_v_v = vec3d_scale(W_HEIGHT / 2, cam->v);
	tp_left = vec3d_minus(dir_v, s_u_v);
	tp_left = vec3d_minus(tp_left, s_v_v);
    return (tp_left);
}
int	is_parallel(t_vec3d v1, t_vec3d v2)
{
	double	dot;
	double	len1;
	double	len2;

	dot = vec3d_dot(v1, v2);
	len1 = vec3d_length(v1);
	len2 = vec3d_length(v2);
	if (dot == len1 * len2)
		return (1);
	else
		return (0);
}
t_vec3d	c_up_v(t_camera *camera)
{
	t_vec3d	world_up;
    t_vec3d u;

	world_up = (t_vec3d){0, 1, 0, 0};
	if (is_parallel(camera->look_at, world_up))
		world_up = (t_vec3d){0, 0, -1, 0};
	u = vec3d_cross(camera->look_at, world_up);
	if (vec3d_normalize(camera->u).isv == -6)
		exit(1);
    return (u);
}
