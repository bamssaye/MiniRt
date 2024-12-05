/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 05:47:14 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/05 04:46:30 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"


int     set_sphere(char **s, t_minirt *aml)
{
    t_sphere    *obj;
    double      dia;
    t_xyz       xyz;
    t_rgb       rgb;

    if (check_str(s, 4) || ft_atof(s[2]).isv)
		return (1);
    xyz = check_xyz(s[1], -IN_MIN, IN_MAX);
    dia = ft_atof(s[2]).num;
    rgb = check_color(s[3]);
    obj = sphere_ob(xyz, rgb, dia);
    if (!obj || xyz.isv || rgb.isv || !++(aml->count_ob[0]))
        return (1);
    ft_lstadd_back(&aml->objects[0].object, ft_lstnew(obj));
    return (0);
}

int     set_plane(char **s, t_minirt *aml)
{
    t_xyz   (pxyz), (vxyz);
    t_rgb   rgb;
    t_plane *plane;
    
    if (check_str(s, 4))
		return (1);
    vxyz = check_xyz(s[2], -1, 1);
    pxyz = check_xyz(s[1], -IN_MIN, IN_MAX);
    rgb = check_color(s[3]);
    plane = plane_ob(pxyz, vxyz, rgb);
    if (!plane || vxyz.isv || pxyz.isv || rgb.isv || !++(aml->count_ob[1]))
        return (1);
    ft_lstadd_back(&aml->objects[1].object, ft_lstnew(plane));
    return (0);
}

int     set_cylinder(char **s, t_minirt *aml)
{
    t_cylinder  *cylinder;
    t_xyz       (cxyz), (vxyz);
    t_rgb       rgb;
    double      v[2];
    
    if (check_str(s, 6) || ft_atof(s[3]).isv || ft_atof(s[4]).isv)
		return (1);
    vxyz = check_xyz(s[2], -1, 1);
    cxyz = check_xyz(s[1], -IN_MIN, IN_MAX);
    rgb  = check_color(s[5]);
    v[0] = ft_atof(s[3]).num;
    v[1] = ft_atof(s[4]).num;
    cylinder = cylinder_ob(cxyz, vxyz, v, rgb);
    if (!cylinder || vxyz.isv || cxyz.isv || rgb.isv || !++(aml->count_ob[2]))
        return (1);
    ft_lstadd_back(&aml->objects[2].object, ft_lstnew(cylinder));
    return (0);
}
