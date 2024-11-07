/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_plane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:48:42 by bamssaye          #+#    #+#             */
/*   Updated: 2024/11/07 01:48:43 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	collect_plane(char **str, t_prog *prog)
{
	t_plane		*plane;
	t_object	*object;

	plane = malloc(sizeof(t_plane));
	if (plane == NULL)
		return (1);
	convert_3d(str[1], &plane->point);
	convert_3d(str[2], &plane->normal);
	color_collect_string(str[3], &plane->color);
	object = create_object_plane(plane);
	if (object == NULL)
		return (1);
	prog->item_count++;
	object->id = prog->item_count;
	ft_lstadd_back(&prog->obj, ft_lstnew(object));
	return (0);
}

t_object	*create_object_plane(t_plane *plane)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	if (object == NULL)
		return (0);
	object->type = PLANE;
	object->object = plane;
	object->test_intersection = pl_test_intersection;
	return (object);
}

void	clean_plane(void *pl)
{
	t_plane	*plane;

	plane = (t_plane *)pl;
	free(plane);
}

int	pl_test_intersection(void *object, t_interparam *param)
{
	t_plane		*plane;
	t_object	*obj;

	obj = (t_object *)object;
	plane = (t_plane *)obj->object;
	return (pl_sub_intersect(plane, param));
}

int	pl_sub_intersect(t_plane *plane, t_interparam *param)
{
	double	dist;
	t_vec3d	*ray;

	ray = &param->ray->direction;
	dist = pl_cale_dist(param->ray, plane, &param->f_ishit, param);
	if (dist > 0)
	{
		param->f_color = plane->color;
		param->f_dist = dist;
		param->f_point.x = param->ray->origin.x + dist * ray->x;
		param->f_point.y = param->ray->origin.y + dist * ray->y;
		param->f_point.z = param->ray->origin.z + dist * ray->z;
		ft_memcpy(&param->f_normal, &plane->normal, sizeof(t_vec3d));
		param->f_ishit = 1;
	}
	return (param->f_ishit);
}