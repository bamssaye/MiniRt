/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 06:57:13 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/12 06:58:45 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_color pl_checkborad(t_vec3d hit_point, t_plane plane)
{
    double u, v;
    int x, y;

    t_vec3d up = {0, 1, 0, 0};
    t_vec3d right;
    right = vec3d_cross(plane.normal, up);
    if (vec3d_length(right) < 0.01)
    {
        up = (t_vec3d){0, 0, 1,0};
        right = vec3d_cross(plane.normal, up);
    }
    right = vec3d_normalize(right);
    up = vec3d_normalize(vec3d_cross(right, plane.normal));
    u = vec3d_dot(hit_point, right);
    v = vec3d_dot(hit_point, up);
	x = floor(u * 0.1);
    y = floor(v * 0.1); ;
	if ((y + x) & 1)
		return (t_color){0,0,0,0};
	else
		return (t_color){255, 255, 255,0};

}