/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 01:17:52 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/17 10:29:33 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vec3d	c_topleft(t_camera *cam)
{
	t_vec3d	dir_v;
	t_vec3d	s_u_v;
	t_vec3d	s_v_v;
	double	view_d;
	t_vec3d	tp_left;
	
	view_d = (W_WIDTH / 2) / (tan((cam->fov * PI) / 180.0));
	dir_v = v_scale(view_d, &cam->look_at);
	s_u_v = v_scale(W_WIDTH / 2, &cam->u);
	s_v_v = v_scale(W_HEIGHT / 2, &cam->v);
	tp_left = vec3d_minus(&dir_v, &s_u_v);
	tp_left = vec3d_minus(&tp_left, &s_v_v);
	return (tp_left);
}

int	is_parallel(t_vec3d v1, t_vec3d v2)
{
	double	dot;
	dot = vec3d_dot(&v2, &v1);
	if (fabs(dot) > EPSILON)
		return (1);
	else
		return (0);
}
t_vec3d	c_r_v(t_camera *camera)
{
	t_vec3d	v;

	v = vec3d_cross(&camera->look_at, &camera->u);
	v = vec3d_normalize(&v);
	return (v);
}

t_vec3d	c_up_v(t_camera *camera)
{
	t_vec3d	world_up;
	t_vec3d	u;

	world_up = (t_vec3d){0, 1, 0, 0};
	if (is_parallel(camera->look_at, world_up))
		world_up = (t_vec3d){0, 0, -1, 0};
	u = vec3d_cross(&camera->look_at, &world_up);
	u = vec3d_normalize(&u);
	return (u);
}
