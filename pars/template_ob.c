/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template_ob.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:24:05 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/26 22:28:48 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void	check_type(char *str, int *style, t_object *obje)
{
	if (!ft_strncmp(str, "checkborad", 11))
		style[CHECKBORAD] = 1;
	else if (!ft_strncmp(str, "texture:", 8))
		style[TEXTURE] = 1;
	obje->path = ft_strdup(str + 8);
}

t_object	*sphere_ob(t_vec3d point, t_color color, double dia, char *path)
{
	t_sp		*obj;
	t_object	*obje;

	obje = malloc(sizeof(t_object));
	if (!obje)
		return (NULL);
	obj = malloc(sizeof(t_sp));
	ft_memset(obje->style, 0, sizeof(int *));
	if (!obj)
		return (free(obje), NULL);
	if (path)
		check_type(path, obje->style, obje);
	else
	{
		obje->path = NULL;
		obje->style[COLOR] = 1;
	}
	obj->radius = (dia / 2);
	obj->color = color;
	obj->center = point;
	obje->type = SPHERE;
	obje->object = obj;
	return (obje);
}

t_object	*plane_ob(t_point_normal *p_n, t_color color, char *path)
{
	t_pl		*obj;
	t_object	*obje;

	obje = malloc(sizeof(t_object));
	if (!obje)
		return (NULL);
	obj = malloc(sizeof(t_pl));
	if (!obj)
		return (free(obje), NULL);
	if (path)
		check_type(path, obje->style, obje);
	else
	{
		obje->path = NULL;
		obje->style[COLOR] = 1;
	}
	obj->color = color;
	obj->point = p_n->point;
	obj->normal = v_normalize(p_n->normal);
	obje->type = PLANE;
	obje->object = obj;
	return (obje);
}

t_object	*cylinder_ob(t_point_normal *p_n, double *d_h, t_color color,
		char *path)
{
	t_cy		*obj;
	t_object	*obje;

	obje = malloc(sizeof(t_object));
	if (!obje)
		return (NULL);
	obj = malloc(sizeof(t_cy));
	if (!obj)
		return (free(obje), NULL);
	if (path)
		check_type(path, obje->style, obje);
	else
	{
		obje->path = NULL;
		obje->style[COLOR] = 1;
	}
	obj->radius = (d_h[0] / 2);
	obj->len = d_h[1];
	obj->point = p_n->point;
	obj->color = color;
	obj->normal = v_normalize(p_n->normal);
	obje->type = CYLINDER;
	obje->object = obj;
	return (obje);
}

t_object	*cone_ob(t_point_normal *p_n, double *d_h, t_color color,
		char *path)
{
	t_object	*obje;
	t_co		*obj;

	obje = malloc(sizeof(t_object));
	if (!obje)
		return (NULL);
	obj = malloc(sizeof(t_co));
	if (!obj)
		return (NULL);
	if (path)
		check_type(path, obje->style, obje);
	else
	{
		obje->path = NULL;
		obje->style[COLOR] = 1;
	}
	obj->point = p_n->point;
	obj->normal = v_normalize(p_n->normal);
	obj->radius = (d_h[0] / 2);
	obj->height = d_h[1];
	obj->color = color;
	obje->type = CONE;
	obje->object = obj;
	return (obje);
}
