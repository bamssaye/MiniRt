/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 05:47:14 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/17 09:12:02 by bamssaye         ###   ########.fr       */
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

char *check_path(char *str, int bouns)
{
	if (!bouns)
		return (NULL);
	if (ft_strncmp(str, "texture:", 8))
		return (NULL);
	// return (ft_strdup(str+8));
	return(str+8);
}

int	set_sp(char **s, t_minirt *aml)
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
	path = check_path(s[3], aml->bouns);
	if (path)
		aml->count_t++;
	sphere = sphere_ob(xyz, rgb, dia, path);
	if (!sphere || xyz.isv || (rgb.isv && !path)|| !++(aml->obj_c))
		return (free(path), free_obj(sphere), 1);
	sphere->id = aml->obj_c;
	ft_lstadd_back(&aml->object, ft_lstnew(sphere));
	return (0);
}

int	set_pl(char **s, t_minirt *aml)
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
	path = check_path(s[3], aml->bouns);
	if (path)
		aml->count_t++;
	plane = plane_ob(pxyz, vxyz, rgb, path);
	if (vxyz.isv || pxyz.isv || (rgb.isv && !path) || !++(aml->obj_c))
		return (free(path), free_obj(plane), 1);
	plane->id = aml->obj_c;
	ft_lstadd_back(&aml->object, ft_lstnew(plane));
	return (0);
}

int	set_cy(char **s, t_minirt *aml)
{
	t_object	*cylinder;
	t_color		rgb;
	t_vec3d		vxyz;
	t_vec3d		cxyz;
	double		v[2];
	char		*path;

	if (check_str(s, 6) || ft_atof(s[3]).isv || ft_atof(s[4]).isv)
		return (1);
	vxyz = check_xyz(s[2], -1, 1);
	cxyz = check_xyz(s[1], -IN_MIN, IN_MAX);
	rgb = check_color(s[5]);
	v[0] = ft_atof(s[3]).num;
	v[1] = ft_atof(s[4]).num;
	path = check_path(s[5], aml->bouns);
	if (path)
		aml->count_t++;
	cylinder = cylinder_ob(cxyz, vxyz, v, rgb);
	if (!cylinder || vxyz.isv || cxyz.isv || (rgb.isv && !path) || !++(aml->obj_c))
		return (free(path), free_obj(cylinder), 1);
	cylinder->id = aml->obj_c;
	ft_lstadd_back(&aml->object, ft_lstnew(cylinder));
	return (0);
}
