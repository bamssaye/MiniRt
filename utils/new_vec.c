/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 02:05:33 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/13 08:42:42 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_color cpy_color(t_color *co)
{
	return((t_color){
		.isv = co->isv,
		.r = min(co->r, 255),
		.g = min(co->g, 255),
		.b = min(co->b, 255)
	});
}
t_vec3d cpy_vec(t_vec3d *ve)
{
	return((t_vec3d){
		.isv = ve->isv,
		.x = ve->x,
		.y = ve->y,
		.z = ve->z
	});
}
t_in_pa cpy_tmp_inter(t_in_pa *a)
{
	return ((t_in_pa){
		.closest = a->closest,
		.final_color = a->final_color,
		.hit = a->hit,
		.hit_clos = a->hit_clos,
		.inters = a->inters,
		.iobj_id  = a->iobj_id,
		.ray = a->ray,
	});
}

t_npc cpy_npc(t_npc *a)
{
	return ((t_npc){
		.color = a->color,
		.dista = a->dista,
		.normal = a->normal,
		.point = a->point
	});
}