/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 05:47:14 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/19 21:01:23 by bamssaye         ###   ########.fr       */
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

int	set_sp(char **s, t_minirt *rt)
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
		rt->count_t++;
	sphere = sphere_ob(xyz, rgb, dia, path); // check  path leaks
	if (!sphere || xyz.isv || (rgb.isv && !path) || !++(rt->obj_count))
		return (free_obj(sphere), 1);
	sphere->id = rt->obj_count;
	ft_lstadd_back(&rt->object, ft_lstnew(sphere));
	return (0);
}

int	set_pl(char **s, t_minirt *rt)
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
	if (vxyz.isv || pxyz.isv || (rgb.isv && !path) || !++(rt->obj_count))
		return (free_obj(plane), 1);
	plane->id = rt->obj_count;
	ft_lstadd_back(&rt->object, ft_lstnew(plane));
	return (0);
}

int	set_cy(char **s, t_minirt *rt)
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
	if (!cylinder || vxyz.isv || cxyz.isv || rgb.isv || !++(rt->obj_count))
		return (free_obj(cylinder), 1);
	cylinder->id = rt->obj_count;
	ft_lstadd_back(&rt->object, ft_lstnew(cylinder));
	return (0);
}

t_object	*cone_ob(t_vec3d point, t_vec3d normal, double *d_h, t_color color)
{
	t_object	*obje;
	t_co		*obj;

	obje = malloc(sizeof(t_object));
	if (!obje)
		return (NULL);
	obj = malloc(sizeof(t_co));
	if (!obj)
		return (NULL);
	obj->point = point;
	obj->normal = v_normalize(normal);
	obj->radius = (d_h[0] / 2);
	obj->height = d_h[1];
	obj->color = color;
	obje->type = CONE;
	obje->object = obj;
	return (obje);
}

int	set_co(char **s, t_minirt *rt)
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
	if (!cone || point.isv || normal.isv || color.isv || !++(rt->obj_count))
		return (free_obj(cone), 1);
	cone->id = rt->obj_count;
	ft_lstadd_back(&rt->object, ft_lstnew(cone));
	return (0);
}
