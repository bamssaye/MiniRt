/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 06:13:09 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/15 06:56:33 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"

void rotate_x(t_object *obj, double angle)
{
    t_obj objs;
    
    double (cos_x), (sin_x), (y), (z);
    cos_x = cos(angle);
    sin_x = sin(angle);
    if (obj->type == SPHERE)
    {
        objs.sp = (t_sp*)obj->object;
        objs.sp->center.y = y;
        objs.sp->center.z = z;
        objs.sp->center.y = (y * cos_x) - (z * sin_x);
        objs.sp->center.z = (y * sin_x) + (z * cos_x);
    }
    if (obj->type == CYLINDER)
    {
        objs.cy = (t_cy*)obj->object;
        objs.cy->normal.y = y;
        objs.cy->normal.z = z;
        objs.cy->normal.y = (y * cos_x) - (z * sin_x);
        objs.cy->normal.z = (y * sin_x) + (z * cos_x);
        objs.cy->normal = vec3d_normalize(&objs.cy->normal);
    }
}


void rotate_y(t_object *obj, double angle)
{
    t_obj objs;
    
    double (cos_y), (sin_y), (x), (z);
    cos_y = cos(angle);
    sin_y = sin(angle);
    if (obj->type == SPHERE)
    {
        objs.sp = (t_sp*)obj->object;
        objs.sp->center.x = x;
        objs.sp->center.z = z;
        objs.sp->center.x = (x * cos_y) + (z * sin_y);
        objs.sp->center.z = -(x * sin_y) + (z * cos_y);
    }
    if (obj->type == CYLINDER)
    {
        objs.cy = (t_cy*)obj->object;
        objs.cy->normal.x = x;
        objs.cy->normal.z = z;
        objs.cy->normal.x = (x * cos_y) + (z * sin_y);
        objs.cy->normal.z = -(x * sin_y) + (z * cos_y);
        objs.cy->normal = vec3d_normalize(&objs.cy->normal);
    }
}


void rotate_z(t_object *obj, double angle)
{
    t_obj objs;
    
    double (cos_z), (sin_z), (y), (x);
    cos_z = cos(angle);
    sin_z = sin(angle);
    if (obj->type == PLANE)
    {
        objs.sp = (t_sp*)obj->object;
        objs.sp->center.x = x;
        objs.sp->center.y = y;
        objs.sp->center.x = (x * cos_z) - (y * sin_z);
        objs.sp->center.y = (x * sin_z) + (y * cos_z);
    }
    if (obj->type == CYLINDER)
    {
        objs.cy = (t_cy*)obj->object;
        objs.cy->normal.x = x;
        objs.cy->normal.y = y;
        objs.cy->normal.x = (x * cos_z) - (y * sin_z);
        objs.cy->normal.y = (x * sin_z) + (y * cos_z);
        objs.cy->normal = vec3d_normalize(&objs.cy->normal);
    }
}
