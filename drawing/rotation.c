/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 06:13:09 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/24 15:38:54 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"


void rotate_z(t_object *obj, double angle);
void rotate_x(t_object *obj, double angle);
void rotate_y(t_object *obj, double angle);

t_vec3d rotat_e(double a, double b, double angle, int sign)
{
    double t_cos, t_sin;
    
    t_cos = cos(angle * (PI / 180));
    t_sin = sin(angle * (PI / 180));
    return ((t_vec3d){
        .x = (a * t_cos) - (sign * (b * t_sin)),
        .y = (sign * (a * t_sin)) + (b * t_cos)
    });
}

void rotate_x(t_object *obj, double angle)
{
    t_vec3d (rot), (*rot_x);
    if (obj->type == PLANE)
    {
        rot_x = &(((t_sp*)obj->object)->center);
        rot = rotat_e(rot_x->y, rot_x->z, angle, 1);
        rot_x->y = rot.x;
        rot_x->z = rot.y;
    }
    if (obj->type == CYLINDER)
    {
        rot_x = &(((t_cy*)obj->object)->normal);
        rot = rotat_e(rot_x->y, rot_x->z, angle, 1);
        rot_x->y = rot.x;
        rot_x->z = rot.y;
        *rot_x = v_normalize(*rot_x);
    }
    if (obj->type == CONE)
    {
        rot_x = &(((t_co*)obj->object)->normal);
        rot = rotat_e(rot_x->y, rot_x->z, angle, 1);
        rot_x->y = rot.x;
        rot_x->z = rot.y;
        *rot_x = v_normalize(*rot_x);
    }
}

void rotate_y(t_object *obj, double angle)
{
    t_vec3d (rot), (*rot_x);
    if (obj->type == PLANE)
    {
        rot_x = &(((t_sp*)obj->object)->center);
        rot = rotat_e(rot_x->x, rot_x->z, angle, -1);
        rot_x->x = rot.x;
        rot_x->z = rot.y;
    }
    if (obj->type == CYLINDER)
    {
        rot_x = &(((t_cy*)obj->object)->normal);
        rot = rotat_e(rot_x->x, rot_x->z, angle, -1);
        rot_x->x = rot.x;
        rot_x->z = rot.y;
        *rot_x = v_normalize(*rot_x);
    }
    if (obj->type == CONE)
    {
        rot_x = &(((t_co*)obj->object)->normal);
        rot = rotat_e(rot_x->x, rot_x->z, angle, -1);
        // rot_x->y = 1.0;
        rot_x->x = rot.x;
        rot_x->z = rot.y;
        *rot_x = v_normalize(*rot_x);
    }
}

void rotate_z(t_object *obj, double angle)
{
    t_vec3d (rot), (*rot_x);
    if (obj->type == PLANE)
    {
        rot_x = &(((t_sp*)obj->object)->center);
        rot = rotat_e(rot_x->x, rot_x->y, angle, 1);
        rot_x->x = rot.x;
        rot_x->y = rot.y;
    }
    if (obj->type == CYLINDER)
    {
        rot_x = &(((t_cy*)obj->object)->normal);
        rot = rotat_e(rot_x->x, rot_x->y, angle, 1);
        rot_x->x = rot.x;
        rot_x->y = rot.y;
        *rot_x = v_normalize(*rot_x);
    }
    if (obj->type == CONE)
    {
        rot_x = &(((t_co*)obj->object)->normal);
        rot = rotat_e(rot_x->x, rot_x->y, angle, 1);
        rot_x->x = rot.x;
        rot_x->y = rot.y;
        *rot_x = v_normalize(*rot_x);
    }
}
