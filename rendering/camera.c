/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:18:52 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/27 19:09:35 by bamssaye         ###   ########.fr       */
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

	view_d = W_WIDTH / 2;
	view_d = view_d / (2.0 * tan((double)cam->fov * (PI / 180) / 2.0));
	dir_v = v_scale(view_d, cam->look_at);
	s_u_v = v_scale(W_WIDTH / 2, cam->u);
	s_v_v = v_scale(W_HEIGHT / 2, cam->v);
	tp_left = v_minus(dir_v, s_u_v);
	tp_left = v_minus(tp_left, s_v_v);
	return (tp_left);
}

int	is_parallel(t_vec3d v1, t_vec3d v2)
{
	double	dot;

	dot = v_dot(v2, v1);
	if (fabs(dot) > EPSILON)
		return (1);
	else
		return (0);
}

t_vec3d	c_r_v(t_camera *camera)
{
	t_vec3d	world_up;
	t_vec3d	u;

	world_up = (t_vec3d){0, 1, 0, 0};
	if (is_parallel(camera->look_at, world_up))
		world_up = (t_vec3d){0, 0, 1, 0};
	u = v_cross(camera->look_at, world_up);
	u = v_normalize(u);
	return (u);
}
