/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template_ob.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:24:05 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/17 09:23:36 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	// if (!s1 || !s2)
	// 	return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

t_tex init_img(char *path, char *str)
{
	return ((t_tex){
		.img = NULL,
		.addr = NULL,
		.path = ft_strjoin(str, path)
	});
}

t_object	*sphere_ob(t_vec3d xyz, t_color rgb, double dia, char *path)
{
	t_sp	*obj;
	t_object	*obje;

	obje = malloc(sizeof(t_object));
	if (!obje)
		return (NULL);
	obj = malloc(sizeof(t_sp));
	if (!obj)
		return (free(obje), NULL);
	obj->radius = dia;
	obj->color = rgb;
	obj->center = xyz;
	if (path)
	{
		obj->tex = init_img(path, "");
		obj->n_map = init_img(path, "normal_");
	}
	else
		obj->tex.path = NULL;
	obje->t = 1;
	obje->type = SPHERE;
	obje->object = obj;
	return (obje);
}

t_object	*plane_ob(t_vec3d p_xyz, t_vec3d v_xyz, t_color rgb, char *path)
{
	t_pl		*obj;
	t_object	*obje;

	obje = malloc(sizeof(t_object));
	if (!obje)
		return (NULL);
	obj = malloc(sizeof(t_pl));
	if (!obj)
		return (free(obje), NULL);
	obj->color = rgb;
	obj->point = p_xyz;
	if (path){
	obj->tex = init_img(path, "");
	obj->n_map = init_img(path, "normal_");
	}
	else
		obj->tex.path = NULL;
	obj->normal = vec3d_normalize(&v_xyz);
	obje->type = PLANE;
	obje->object = obj;
	obje->t = 1;
	return (obje);
}

t_object	*cylinder_ob(t_vec3d cxyz, t_vec3d vxyz, double *d_h, t_color rgb)
{
	t_cy	*obj;
	t_object	*obje;

	obje = malloc(sizeof(t_object));
	if (!obje)
		return (NULL);
	obj = malloc(sizeof(t_cy));
	if (!obj)
		return (free(obje), NULL);
	obj->radius = d_h[0];
	obj->len = d_h[1];
	obj->point = cxyz;
	obj->color = rgb;
	obj->normal = vec3d_normalize(&vxyz);
	obje->type = CYLINDER;
	obje->object = obj;
	obje->t = 1;
	return (obje);
}
