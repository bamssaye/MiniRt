/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 05:47:14 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/27 19:48:52 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	set_sphere(char **s, t_minirt *aml)
{
	t_object	*sphere;
	double		dia;
	t_vec3d		xyz;
	t_color		rgb;

	if (check_str(s, 4) || ft_atof(s[2]).isv)
		return (1);
	xyz = check_xyz(s[1], -IN_MIN, IN_MAX);
	dia = ft_atof(s[2]).num;
	rgb = check_color(s[3]);
	sphere = sphere_ob(xyz, rgb, dia);
	if (!sphere || xyz.isv || rgb.isv || !++(aml->obj_count))
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

	if (check_str(s, 4))
		return (1);
	vxyz = check_xyz(s[2], -1, 1);
	pxyz = check_xyz(s[1], -IN_MIN, IN_MAX);
	rgb = check_color(s[3]);
	if (vxyz.isv || pxyz.isv || rgb.isv || !++(aml->obj_count))
		return (1);
	plane = plane_ob(pxyz, vxyz, rgb);
	if (!plane)
		return (1);
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
