/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bumpping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:30:53 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/25 20:38:41 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"


t_vec3d color_map(t_color color)
{
    return ((t_vec3d){
        (color.r / 255.0) * 2.0 - 1.0,
        (color.g / 255.0) * 2.0 - 1.0,
        (color.b / 255.0) * 2.0 - 1.0,
        0
    });
}

t_vec3d sp_nomap(t_tex *n_map, t_npc *closest, t_ray *ray, t_sp *sp)
{
    t_vec3d (normal), (u), (no_map), (v_vec);
    t_vec3d (sca_no_x), (sca_no_y), (sca_nm_z);
    normal = closest->normal;
    u = v_cross(closest->normal, ray->direction);
    if (v_magnitude(u) > EPSILON)
    {
        v_vec = v_cross(closest->normal, u);
        no_map = color_map(sp_texture(n_map, &closest->point, sp));
        sca_no_x = v_scale(no_map.x, u);
        sca_no_y = v_scale(no_map.y, v_vec);
        sca_nm_z = v_scale(no_map.z, closest->normal);
        normal = v_plus(sca_no_x, sca_no_y);
        normal = v_plus(normal, sca_nm_z);
        normal = v_normalize(normal);
    }
    return normal;
}
// t_vec3d tangent_world(t_vec3d tang_normal, t_vec3d world, t_vec3d normal)
// {
//     return ((t_vec3d){
//         .x = ,
//         .y = ,
//         .z = 
//     });
// }

t_vec3d pl_nomap(t_tex *n_map, t_pl *pl, t_npc *closest, t_ray *ray)
{
    t_vec3d (normal), (u), (no_map), (v_vec);
    t_vec3d (sca_no_x), (sca_no_y), (sca_nm_z);
    // normal = pl_normal_map(n_map, &closest->point, pl);
    normal = closest->normal;
    u = v_cross(closest->normal, ray->direction);
    if (v_magnitude(u) > EPSILON)
    {
        v_vec = v_cross(closest->normal, u);
        no_map = color_map(pl_texture(n_map, &closest->point, pl));
        sca_no_x = v_scale(no_map.x, u);
        sca_no_y = v_scale(no_map.y, v_vec);
        sca_nm_z = v_scale(no_map.z, closest->normal);
        normal = v_plus(sca_no_x, sca_no_y);
        normal = v_plus(normal, sca_nm_z);
        normal = v_normalize(normal);
    }
    return normal;
}
t_vec3d cy_nomap(t_tex *n_map, t_cy *cy, t_npc *closest, t_ray *ray)
{
    t_vec3d (normal), (u), (no_map), (v_vec);
    t_vec3d (sca_no_x), (sca_no_y), (sca_nm_z);
    normal = closest->normal;
    u = v_cross(closest->normal, ray->direction);
    if (v_magnitude(u) > EPSILON)
    {
        v_vec = v_cross(closest->normal, u);
        no_map = color_map(cy_texture(n_map, &closest->point, cy));
        sca_no_x = v_scale(no_map.x, u);
        sca_no_y = v_scale(no_map.y, v_vec);
        sca_nm_z = v_scale(no_map.z, closest->normal);
        normal = v_plus(sca_no_x, sca_no_y);
        normal = v_plus(normal, sca_nm_z);
        normal = v_normalize(normal);
    }
    return normal;
}

t_vec3d co_nomap(t_tex *n_map, t_co *co, t_npc *closest, t_ray *ray)
{
    t_vec3d (normal), (u), (no_map), (v_vec);
    t_vec3d (sca_no_x), (sca_no_y), (sca_nm_z);
    normal = closest->normal;
    u = v_cross(closest->normal, ray->direction);
    if (v_magnitude(u) > EPSILON)
    {
        v_vec = v_cross(closest->normal, u);
        no_map = color_map(co_texture(n_map, &closest->point, co));
        sca_no_x = v_scale(no_map.x, u);
        sca_no_y = v_scale(no_map.y, v_vec);
        sca_nm_z = v_scale(no_map.z, closest->normal);
        normal = v_plus(sca_no_x, sca_no_y);
        normal = v_plus(normal, sca_nm_z);
        normal = v_normalize(normal);
    }
    return normal;
}
