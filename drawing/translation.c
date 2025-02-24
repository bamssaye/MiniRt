/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:35:12 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/24 13:18:34 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void transle_x(t_object *obj, double x);
void transle_y(t_object *obj, double y);
void transle_z(t_object *obj, double z);

void transle_x(t_object *obj, double x)
{
    t_obj objs;
    
    if (obj->type == SPHERE)
    {
        objs.sp = (t_sp*)obj->object;
        objs.sp->center.x += x;
    }
    else if (obj->type == PLANE)
    {
        objs.sp = (t_sp*)obj->object;
        objs.cy->point.x += x;
    }
    else if (obj->type == CYLINDER)
    {
        objs.cy = (t_cy*)obj->object;
        objs.cy->point.x += x;
    }
    else if (obj->type == CONE)
    {
        objs.co = (t_co*)obj->object;
        objs.co->point.x += x;
    }
}

void transle_y(t_object *obj, double y)
{
    t_obj objs;
    
    if (obj->type == SPHERE)
    {
        objs.sp = (t_sp*)obj->object;
        objs.sp->center.y += y;
    }
    else if (obj->type == PLANE)
    {
        objs.pl = (t_pl*)obj->object;
        objs.pl->point.y += y;
    }
    else if (obj->type == CYLINDER)
    {
        objs.cy = (t_cy*)obj->object;
        objs.cy->point.y += y;
    }
    else if (obj->type == CONE)
    {
        objs.co = (t_co*)obj->object;
        objs.co->point.y += y;
    }
}

void transle_z(t_object *obj, double z)
{
	t_obj objs;
    
    if (obj->type == SPHERE)
    {
        objs.sp = (t_sp*)obj->object;
        objs.sp->center.z +=z;
    }
    else if (obj->type == PLANE)
    {
        objs.pl = (t_pl*)obj->object;
        objs.pl->point.z +=z;
    }
    else if (obj->type == CYLINDER)
    {
        objs.cy = (t_cy*)obj->object;
        objs.cy->point.z +=z;
    }
    else if (obj->type == CONE)
    {
        objs.co = (t_co*)obj->object;
        objs.co->point.z += z;
    }
}
