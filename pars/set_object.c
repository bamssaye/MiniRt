/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 05:47:14 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/24 17:40:49 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

char *check_path(char *str, int bouns)
{
	if (!bouns)
		return (NULL);
	if (!ft_strncmp(str, "texture:", 8))
		return (str);
	if (!ft_strncmp(str, "checkborad", 11))
		return (str);
	return(NULL);
}


int	set_sp(char **s, t_minirt *rt)
{
	t_object	*sphere;
	double		dia;
	t_vec3d		point;
	t_color		color;
	char		*path;

	if (check_str(s, 4) || ft_atof(s[2]).isv)
		return (print_err("\t{SPHER}", MSG_4));
	point = check_xyz(s[1], -IN_MIN, IN_MAX);
	dia = ft_atof(s[2]).num;
	color = check_color(s[3]);
	path = check_path(s[3], rt->bouns);
	if (path)
		rt->count_t++;
	sphere = sphere_ob(point, color, dia, path);
	if (!sphere || point.isv || (color.isv && !path) || !++(rt->obj_count))
		return (free(path), free_obj(sphere), print_err("\t{SPHER}", MSG_4));
	sphere->id = rt->obj_count;
	ft_lstadd_back(&rt->object, ft_lstnew(sphere));
	return (0);
}

int	set_pl(char **s, t_minirt *rt)
{
	t_color			color;
	t_object		*plane;
	t_point_normal	p_n;
	char			*path;

	path = NULL;
	if (check_str(s, 4))
		return (print_err("\t{PLANE}", MSG_5));
	p_n.normal = check_xyz(s[2], -1, 1);
	p_n.point = check_xyz(s[1], -IN_MIN, IN_MAX);
	color = check_color(s[3]);
	path = check_path(s[3], rt->bouns);
	plane = plane_ob(&p_n, color, path);
	if (path)
		rt->count_t++;
	if (p_n.normal.isv || p_n.point.isv || (color.isv && !path) || !++(rt->obj_count))
		return (free(path), free_obj(plane), print_err("\t{PLANE}", MSG_5));
	plane->id = rt->obj_count;
	ft_lstadd_back(&rt->object, ft_lstnew(plane));
	return (0);
}

int	set_cy(char **s, t_minirt *rt)
{
	t_object		*cylinder;
	t_color			color;
	t_point_normal	p_n;
	char 			*path;
	double			v[2];

	if (check_str(s, 6) || ft_atof(s[3]).isv || ft_atof(s[4]).isv)
		return (print_err("\t{CYLINDER}", MSG_6));
	p_n.normal = check_xyz(s[2], -1, 1);
	p_n.point = check_xyz(s[1], -IN_MIN, IN_MAX);
	color = check_color(s[5]);
	path = check_path(s[5], rt->bouns);
	v[0] = ft_atof(s[3]).num;
	v[1] = ft_atof(s[4]).num;
	if (path)
		rt->count_t++;
	cylinder = cylinder_ob(&p_n, v, color, path);
	if (!cylinder || p_n.normal.isv || p_n.point.isv || (color.isv && !path) || !++(rt->obj_count))
		return (free(path), free_obj(cylinder), print_err("\t{CYLINDER}", MSG_6));
	cylinder->id = rt->obj_count;
	ft_lstadd_back(&rt->object, ft_lstnew(cylinder));
	return (0);
}

int	set_co(char **s, t_minirt *rt)
{
	t_object		*cone;
	t_point_normal	p_n;
	char			*path;
	double			v[2];
	t_color			color;

	if (check_str(s, 6) || ft_atof(s[3]).isv || ft_atof(s[4]).isv)
		return (print_err("\t{CONE}", MSG_7));
	p_n.point = check_xyz(s[1], -IN_MIN, IN_MAX);
	p_n.normal = check_xyz(s[2], -1, 1);
	v[0] = ft_atof(s[3]).num;
	v[1] = ft_atof(s[4]).num;
	color = check_color(s[5]);
	path = check_path(s[5], rt->bouns);
	if (path)
		rt->count_t++;
	cone = cone_ob(&p_n, v, color, path);
	if (!cone || p_n.point.isv || p_n.normal.isv || (color.isv && !path) || !++(rt->obj_count))
		return (free(path), free_obj(cone), print_err("\t{CONE}", MSG_7));
	cone->id = rt->obj_count;
	ft_lstadd_back(&rt->object, ft_lstnew(cone));
	return (0);
}
