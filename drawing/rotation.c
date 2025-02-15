/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 06:13:09 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/15 10:11:33 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"


void rotate_z(t_object *obj, double angle);
void rotate_x(t_object *obj, double angle);
void rotate_y(t_object *obj, double angle);

void rotate_x(t_object *obj, double angle)
{
    t_obj objs;
    
    double (cos_x), (sin_x), (y), (z);
    cos_x = cos(angle * (PI / 180));
    sin_x = sin(angle * (PI / 180));
    if (obj->type == PLANE)
    {
        objs.sp = (t_sp*)obj->object;
        y = objs.sp->center.y;
        z = objs.sp->center.z;
        objs.sp->center.y = (y * cos_x) - (z * sin_x);
        objs.sp->center.z = (y * sin_x) + (z * cos_x);
    }
    if (obj->type == CYLINDER)
    {
        objs.cy = (t_cy*)obj->object;
        y = objs.cy->normal.y;
        z = objs.cy->normal.z;
        objs.cy->normal.y = (y * cos_x) - (z * sin_x);
        objs.cy->normal.z = (y * sin_x) + (z * cos_x);
        objs.cy->normal = vec3d_normalize(&objs.cy->normal);
    }
}


void rotate_y(t_object *obj, double angle)
{
    t_obj objs;
    
    double (cos_y), (sin_y), (x), (z);
    cos_y = cos(angle * (PI / 180));
    sin_y = sin(angle * (PI / 180));
    if (obj->type == PLANE)
    {
        objs.pl = (t_pl*)obj->object;
        x = objs.pl->normal.x;
        z = objs.pl->normal.z;
        objs.pl->normal.x = (x * cos_y) + (z * sin_y);
        objs.pl->normal.z = -(x * sin_y) + (z * cos_y);
        objs.pl->normal = vec3d_normalize(&objs.pl->normal);
    }
    if (obj->type == CYLINDER)
    {
        objs.cy = (t_cy*)obj->object;
        x = objs.cy->normal.x;
        z = objs.cy->normal.z;
        objs.cy->normal.x = (x * cos_y) + (z * sin_y);
        objs.cy->normal.z = -(x * sin_y) + (z * cos_y);
        objs.cy->normal = vec3d_normalize(&objs.cy->normal);
    }
}


void rotate_z(t_object *obj, double angle)
{
    t_obj objs;
    
    double (cos_z), (sin_z), (y), (x);
    cos_z = cos(angle * (PI / 180));
    sin_z = sin(angle * (PI / 180));
    if (obj->type == PLANE)
    {
        objs.pl = (t_pl*)obj->object;
        x = objs.pl->normal.x;
        y = objs.pl->normal.y;
        objs.pl->normal.x = (x * cos_z) - (y * sin_z);
        objs.pl->normal.y = (x * sin_z) + (y * cos_z);
        objs.pl->normal = vec3d_normalize(&objs.pl->normal);
    }
    if (obj->type == CYLINDER)
    {
        objs.cy = (t_cy*)obj->object;
        x = objs.cy->normal.x;
        y = objs.cy->normal.y;
        objs.cy->normal.x = (x * cos_z) - (y * sin_z);
        objs.cy->normal.y = (x * sin_z) + (y * cos_z);
        objs.cy->normal = vec3d_normalize(&objs.cy->normal);
    }
}
