/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 05:47:14 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/17 13:27:17 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;
	int		i;

	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*check_path(char *str)
{
	if (ft_strncmp(str, "texture:./", 10))
		return (NULL);
	if (access(str + 8, R_OK))
		return (NULL);
	else
		return (ft_strdup(str));
	return (NULL);
}

int	set_sphere(char **s, t_minirt *aml)
{
	t_object	*sphere;
	double		dia;
	t_vec3d		xyz;
	t_color		rgb;
	char		*path;

	if (check_str(s, 4) || ft_atof(s[2]).isv)
		return (1);
	xyz = check_xyz(s[1], -IN_MIN, IN_MAX);
	dia = ft_atof(s[2]).num;
	rgb = check_color(s[3]);
	path = check_path(s[3]);
	if (path)
		aml->count_t++;
	sphere = sphere_ob(xyz, rgb, dia, path); // check  path leaks
	if (!sphere || xyz.isv || (rgb.isv && !path) || !++(aml->obj_count))
		return (free_obj(sphere), 1);
	sphere->id = aml->obj_count;
	ft_lstadd_back(&aml->object, ft_lstnew(sphere));
	return (0);
}

int	set_plane(char **s, t_minirt *aml)
{
	t_color		rgb;
	t_object	*plane;
	t_vec3d		pxyz;
	t_vec3d		vxyz;
	char		*path;

	path = NULL;
	if (check_str(s, 4))
		return (1);
	vxyz = check_xyz(s[2], -1, 1);
	pxyz = check_xyz(s[1], -IN_MIN, IN_MAX);
	rgb = check_color(s[3]);
	path = check_path(s[3]);
	plane = plane_ob(pxyz, vxyz, rgb, path);
	if (vxyz.isv || pxyz.isv || (rgb.isv && !path) || !++(aml->obj_count))
		return (free_obj(plane), 1);
	plane->id = aml->obj_count;
	ft_lstadd_back(&aml->object, ft_lstnew(plane));
	return (0);
}

int	set_cylinder(char **s, t_minirt *aml)
{
	t_object	*cylinder;
	t_color		rgb;
	t_vec3d		vxyz;
	t_vec3d		cxyz;
	double		v[2];

	if (check_str(s, 6) || ft_atof(s[3]).isv || ft_atof(s[4]).isv)
		return (1);
	vxyz = check_xyz(s[2], -1, 1);
	cxyz = check_xyz(s[1], -IN_MIN, IN_MAX);
	rgb = check_color(s[5]);
	v[0] = ft_atof(s[3]).num;
	v[1] = ft_atof(s[4]).num;
	cylinder = cylinder_ob(cxyz, vxyz, v, rgb);
	if (!cylinder || vxyz.isv || cxyz.isv || rgb.isv || !++(aml->obj_count))
		return (free_obj(cylinder), 1);
	cylinder->id = aml->obj_count;
	ft_lstadd_back(&aml->object, ft_lstnew(cylinder));
	return (0);
}

t_object	*cone_ob(t_vec3d point, t_vec3d normal, double *d_h, t_color color)
{
	t_object	*obje;
	t_cone		*obj;

	obje = malloc(sizeof(t_object));
	if (!obje)
		return (NULL);
	obj = malloc(sizeof(t_cone));
	if (!obj)
		return (NULL);
	obj->point = point;
	obj->normal = vec3d_normalize(normal);
	obj->radius = (d_h[0] / 2);
	obj->height = d_h[1];
	obj->color = color;
	obje->type = CONE;
	obje->object = obj;
	return (obje);
}

int	set_cone(char **s, t_minirt *aml)
{
	t_object	*cone;
	t_vec3d		point;
	t_vec3d		normal;
	double		v[2];
	t_color		color;

	if (check_str(s, 6) || ft_atof(s[3]).isv || ft_atof(s[4]).isv)
		return (1);
	point = check_xyz(s[1], -IN_MIN, IN_MAX);
	normal = check_xyz(s[2], -1, 1);
	v[0] = ft_atof(s[3]).num;
	v[1] = ft_atof(s[4]).num;
	color = check_color(s[5]);
	cone = cone_ob(point, normal, v, color);
	if (!cone || point.isv || normal.isv || color.isv || !++(aml->obj_count))
		return (free_obj(cone), 1);
	cone->id = aml->obj_count;
	ft_lstadd_back(&aml->object, ft_lstnew(cone));
	return (0);
}
