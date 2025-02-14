/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bumpping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:30:53 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/14 14:42:25 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vec3d map_normal(t_object *obj, t_vec3d *point);
t_vec3d normal_map(t_object *obj, t_npc *closest, t_ray *ray);
t_color pl_texture(t_tex *tex, t_vec3d *hpoint, t_pl *pl);
t_color sp_texture(t_tex *tex, t_vec3d *hpoint, t_sp *sp);
t_color cy_texture(t_tex *tex, t_vec3d *hpoint, t_cy *cy);

t_vec3d map_normal(t_object *obj, t_vec3d *point)
{
    t_color bmp;

    if (obj->type == SPHERE)
        bmp = sp_texture(&((t_sp*)obj->object)->n_map, point, \
        (t_sp*)obj->object);
    else if (obj->type == SPHERE)
        bmp = pl_texture(&((t_pl*)obj->object)->n_map, point, \
        (t_pl*)obj->object);
    else if (obj->type == SPHERE)
        bmp = cy_texture(&((t_cy*)obj->object)->n_map, point, \
        (t_cy*)obj->object);
    // else if (obj->type == SPHERE)
    //     bmp = cy_texture(&((t_cy*)obj->object)->n_map, point,
    //     (t_cy*)obj->object);
    return ((t_vec3d){
        (bmp.r / 255.0) * 2.0 - 1.0, 
        (bmp.g / 255.0) * 2.0 - 1.0,
        (bmp.b / 255.0) * 2.0 - 1.0,
        0
    });
}
t_vec3d normal_map(t_object *obj, t_npc *closest, t_ray *ray)
{
    t_vec3d (normal), (u), (v), (no_map), (sca_no_x), (sca_no_y), (sca_nm_z);
    normal = closest->normal;
    u = vec3d_cross(&closest->normal, &ray->direction);
    if (vec3d_magnitude(&u) > EPSILON)
    {
        t_vec3d v_vec = vec3d_cross(&closest->normal, &u);
        no_map = map_normal(obj, &closest->point);
        sca_no_x = v_scale(no_map.x, &u);
        sca_no_y = v_scale(no_map.y, &v_vec);
        sca_nm_z = v_scale(no_map.z, &closest->normal);
        normal = vec3d_plus(&sca_no_x, &sca_no_y);
        normal = vec3d_plus(&normal, &sca_nm_z);
        normal = vec3d_normalize(&normal);
    }
    return normal;
}
