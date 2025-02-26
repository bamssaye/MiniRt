/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 06:13:09 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/26 14:11:31 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void	rotate_z(t_object *obj, double angle);
void	rotate_x(t_object *obj, double angle);
void	rotate_y(t_object *obj, double angle);

t_vec3d	rotat_e(double a, double b, double angle, int sign)
{
	double (t_cos), (t_sin);
	t_cos = cos(angle * (PI / 180));
	t_sin = sin(angle * (PI / 180));
	return ((t_vec3d){
		.x = (a * t_cos) - (sign * (b * t_sin)),
		.y = (sign * (a * t_sin)) + (b * t_cos)});
}

void	rotate_x(t_object *obj, double angle)
{
	t_vec3d (rot);
	t_vec3d (*rot_x);
	if (obj->type == PLANE)
	{
		rot_x = &(((t_sp *)obj->object)->center);
		rot = rotat_e(rot_x->y, rot_x->z, angle, 1);
		rot_x->y = rot.x;
		rot_x->z = rot.y;
	}
	if (obj->type == CYLINDER)
	{
		rot_x = &(((t_cy *)obj->object)->normal);
		rot = rotat_e(rot_x->y, rot_x->z, angle, 1);
		rot_x->y = rot.x;
		rot_x->z = rot.y;
		*rot_x = v_normalize(*rot_x);
	}
	if (obj->type == CONE)
	{
		rot_x = &(((t_co *)obj->object)->normal);
		rot = rotat_e(rot_x->y, rot_x->z, angle, 1);
		rot_x->y = rot.x;
		rot_x->z = rot.y;
		*rot_x = v_normalize(*rot_x);
	}
}

void	rotate_y(t_object *obj, double angle)
{
	t_vec3d (rot);
	t_vec3d (*rot_y);
	if (obj->type == PLANE)
	{
		rot_y = &(((t_sp *)obj->object)->center);
		rot = rotat_e(rot_y->x, rot_y->z, angle, -1);
		rot_y->x = rot.x;
		rot_y->z = rot.y;
	}
	if (obj->type == CYLINDER)
	{
		rot_y = &(((t_cy *)obj->object)->normal);
		rot = rotat_e(rot_y->x, rot_y->z, angle, -1);
		rot_y->x = rot.x;
		rot_y->z = rot.y;
		*rot_y = v_normalize(*rot_x);
	}
	if (obj->type == CONE)
	{
		rot_y = &(((t_co *)obj->object)->normal);
		rot = rotat_e(rot_y->x, rot_y->z, angle, -1);
		rot_y->x = rot.x;
		rot_y->z = rot.y;
		*rot_y = v_normalize(*rot_y);
	}
}

void	rotate_z(t_object *obj, double angle)
{
	t_vec3d (rot);
	t_vec3d (*rot_z);
	if (obj->type == PLANE)
	{
		rot_z = &(((t_sp *)obj->object)->center);
		rot = rotat_e(rot_z->x, rot_z->y, angle, 1);
		rot_z->x = rot.x;
		rot_z->y = rot.y;
	}
	if (obj->type == CYLINDER)
	{
		rot_z = &(((t_cy *)obj->object)->normal);
		rot = rotat_e(rot_z->x, rot_z->y, angle, 1);
		rot_z->x = rot.x;
		rot_z->y = rot.y;
		*rot_z = v_normalize(*rot_z);
	}
	if (obj->type == CONE)
	{
		rot_z = &(((t_co *)obj->object)->normal);
		rot = rotat_e(rot_z->x, rot_z->y, angle, 1);
		rot_z->x = rot.x;
		rot_z->y = rot.y;
		*rot_z = v_normalize(*rot_z);
	}
}
