/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bumpping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:30:53 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/26 14:04:32 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vec3d	color_map(t_color color)
{
	return ((t_vec3d){
		(color.r / 255.0) * 2.0 - 1.0,
		(color.g / 255.0) * 2.0 - 1.0,
		(color.b / 255.0) * 2.0 - 1.0,
		0});
}

t_vec3d	sp_nomap(t_tex *n_map, t_npc *closest, t_ray *ray, t_sp *sp)
{
	t_normal_map	norm_mp;

	norm_mp.normal = closest->normal;
	norm_mp.u = v_cross(closest->normal, ray->direction);
	if (v_magnitude(norm_mp.u) > EPSILON)
	{
		norm_mp.v_vec = v_cross(closest->normal, norm_mp.u);
		norm_mp.no_map = color_map(sp_texture(n_map, &closest->point, sp));
		norm_mp.sca_no_x = v_scale(norm_mp.no_map.x, norm_mp.u);
		norm_mp.sca_no_y = v_scale(norm_mp.no_map.y, norm_mp.v_vec);
		norm_mp.sca_nm_z = v_scale(norm_mp.no_map.z, closest->normal);
		norm_mp.normal = v_plus(norm_mp.sca_no_x, norm_mp.sca_no_y);
		norm_mp.normal = v_plus(norm_mp.normal, norm_mp.sca_nm_z);
		norm_mp.normal = v_normalize(norm_mp.normal);
	}
	return (norm_mp.normal);
}

t_vec3d	pl_nomap(t_tex *n_map, t_pl *pl, t_npc *closest, t_ray *ray)
{
	t_normal_map	norm_mp;

	norm_mp.normal = closest->normal;
	norm_mp.u = v_cross(closest->normal, ray->direction);
	if (v_magnitude(norm_mp.u) > EPSILON)
	{
		norm_mp.v_vec = v_cross(closest->normal, norm_mp.u);
		norm_mp.no_map = color_map(pl_texture(n_map, &closest->point, pl));
		norm_mp.sca_no_x = v_scale(norm_mp.no_map.x, norm_mp.u);
		norm_mp.sca_no_y = v_scale(norm_mp.no_map.y, norm_mp.v_vec);
		norm_mp.sca_nm_z = v_scale(norm_mp.no_map.z, closest->normal);
		norm_mp.normal = v_plus(norm_mp.sca_no_x, norm_mp.sca_no_y);
		norm_mp.normal = v_plus(norm_mp.normal, norm_mp.sca_nm_z);
		norm_mp.normal = v_normalize(norm_mp.normal);
	}
	return (norm_mp.normal);
}

t_vec3d	cy_nomap(t_tex *n_map, t_cy *cy, t_npc *closest, t_ray *ray)
{
	t_normal_map	norm_mp;

	norm_mp.normal = closest->normal;
	norm_mp.u = v_cross(closest->normal, ray->direction);
	if (v_magnitude(norm_mp.u) > EPSILON)
	{
		norm_mp.v_vec = v_cross(closest->normal, norm_mp.u);
		norm_mp.no_map = color_map(cy_texture(n_map, &closest->point, cy));
		norm_mp.sca_no_x = v_scale(norm_mp.no_map.x, norm_mp.u);
		norm_mp.sca_no_y = v_scale(norm_mp.no_map.y, norm_mp.v_vec);
		norm_mp.sca_nm_z = v_scale(norm_mp.no_map.z, closest->normal);
		norm_mp.normal = v_plus(norm_mp.sca_no_x, norm_mp.sca_no_y);
		norm_mp.normal = v_plus(norm_mp.normal, norm_mp.sca_nm_z);
		norm_mp.normal = v_normalize(norm_mp.normal);
	}
	return (norm_mp.normal);
}

t_vec3d	co_nomap(t_tex *n_map, t_co *co, t_npc *closest, t_ray *ray)
{
	t_normal_map	norm_mp;

	norm_mp.normal = closest->normal;
	norm_mp.u = v_cross(closest->normal, ray->direction);
	if (v_magnitude(norm_mp.u) > EPSILON)
	{
		norm_mp.v_vec = v_cross(closest->normal, norm_mp.u);
		norm_mp.no_map = color_map(co_texture(n_map, &closest->point, co));
		norm_mp.sca_no_x = v_scale(norm_mp.no_map.x, norm_mp.u);
		norm_mp.sca_no_y = v_scale(norm_mp.no_map.y, norm_mp.v_vec);
		norm_mp.sca_nm_z = v_scale(norm_mp.no_map.z, closest->normal);
		norm_mp.normal = v_plus(norm_mp.sca_no_x, norm_mp.sca_no_y);
		norm_mp.normal = v_plus(norm_mp.normal, norm_mp.sca_nm_z);
		norm_mp.normal = v_normalize(norm_mp.normal);
	}
	return (norm_mp.normal);
}
