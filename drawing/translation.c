/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:35:12 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/15 17:17:36 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void transle_x(t_object *obj, double x);
void transle_y(t_object *obj, double y);
void transle_z(t_object *obj, double z);


void transle_x(t_object *obj, double x)
{
    t_obj objs;
    
    if (obj->type == PLANE && obj->t++)
    {
        objs.sp = (t_sp*)obj->object;
        objs.sp->center.x += x;
    }
    else if (obj->type == PLANE && obj->t++)
    {
        objs.sp = (t_sp*)obj->object;
        objs.cy->point.x += x;
    }
    else if (obj->type == CYLINDER && obj->t++)
    {
        objs.cy = (t_cy*)obj->object;
        objs.cy->point.x += x;
    }
}

void transle_y(t_object *obj, double y)
{
    t_obj objs;
    
    if (obj->type == PLANE && obj->t++)
    {
        objs.sp = (t_sp*)obj->object;
        objs.sp->center.y += y;
    }
    else if (obj->type == PLANE && obj->t++)
    {
        objs.pl = (t_pl*)obj->object;
        objs.pl->point.y += y;
    }
    else if (obj->type == CYLINDER && obj->t++)
    {
        objs.cy = (t_cy*)obj->object;
        objs.cy->point.y += y;
    }	
}

void transle_z(t_object *obj, double z)
{
	t_obj objs;
    
    if (obj->type == SPHERE && obj->t++)
    {
        objs.sp = (t_sp*)obj->object;
        objs.sp->center.z +=z;
    }
    else if (obj->type == PLANE && obj->t++)
    {
        objs.pl = (t_pl*)obj->object;
        objs.pl->point.z +=z;
    }
    else if (obj->type == CYLINDER && obj->t++)
    {
        objs.cy = (t_cy*)obj->object;
        objs.cy->point.z +=z;
    }	
}
