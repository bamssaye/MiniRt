/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bumpping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:30:53 by bamssaye          #+#    #+#             */
/*   Updated: 2025/03/01 18:42:14 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vec3d	sp_nomap(t_tex *n_map, t_sp *sp, t_npc *closest)
{
	t_tbitan	tbn;
	t_vec3d		no_map;
	t_vec3d		normal;

	no_map = color_map(sp_texture(n_map, &closest->point, sp));
	tbn = tan_bitan_n(closest->normal, no_map);
	normal = normal_sp(no_map, tbn);
	return (v_normalize(normal));
}

t_vec3d	pl_nomap(t_tex *n_map, t_pl *pl, t_npc *closest)
{
	t_tbitan	tbn;
	t_vec3d		no_map;
	t_vec3d		normal;

	no_map = color_map(pl_texture(n_map, &closest->point, pl));
	tbn = tan_bitan_n(closest->normal, no_map);
	normal.x = v_dot(no_map, tbn.tan);
	normal.y = v_dot(no_map, tbn.bitan);
	normal.z = v_dot(no_map, tbn.normal);
	return (v_normalize(normal));
}

t_vec3d	cy_nomap(t_tex *n_map, t_cy *cy, t_npc *closest)
{
	t_tbitan	tbn;
	t_vec3d		no_map;
	t_vec3d		normal;

	no_map = color_map(cy_texture(n_map, &closest->point, cy));
	tbn = tan_bitan_n(closest->normal, no_map);
	normal.x = v_dot(no_map, tbn.tan);
	normal.y = v_dot(no_map, tbn.bitan);
	normal.z = v_dot(no_map, tbn.normal);
	return (v_normalize(normal));
}

t_vec3d	co_nomap(t_tex *n_map, t_co *co, t_npc *closest)
{
	t_tbitan	tbn;
	t_vec3d		no_map;
	t_vec3d		normal;

	no_map = color_map(co_texture(n_map, &closest->point, co));
	tbn = tan_bitan_n(closest->normal, no_map);
	normal.x = v_dot(no_map, tbn.tan);
	normal.y = v_dot(no_map, tbn.bitan);
	normal.z = v_dot(no_map, tbn.normal);
	return (v_normalize(normal));
}
