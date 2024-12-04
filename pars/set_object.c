/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 05:47:14 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/04 01:31:12 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

/*
∗identifier: sp
∗x,y,z coordinates of the sphere center: 0.0,0.0,20.6
∗the sphere diameter: 12.6
∗R,G,B colors in range [0-255]: 10, 0, 255
typedef struct s_sphere // Sphere
{
    char    sp[2];
    t_xyz   sph_xyz;
    double  sph_dia;
    t_rgb   sph_rgb;
} t_sphere;
sp     0.0,0.0,20.6     12.6      10,0,255
*/
t_sphere *sphere_ob(t_xyz xyz, t_rgb rgb, double dia)
{
    t_sphere    *obj;

    obj = malloc(sizeof(t_sphere));
    if (!obj)
        return (NULL);
    obj->sph_dia[0] = dia;
    obj->sph_rgb[0] = rgb;
    obj->sph_xyz[0] = xyz;
    return (obj);
}

int     set_sphere(char **s, t_minirt *aml)
{
    t_sphere    *obj;
    double      dia;
    t_xyz       xyz;
    t_rgb       rgb;

    if (!s[1] || !s[2] || !s[3] || s[4])
		return (printf("ERROT EXITS.. \n"), arry_c(s),  exit(1), 1);
    xyz = check_xyz(s[1], -IN_MIN, IN_MAX, s);
    dia = ft_atof(s[2]);
    rgb = check_color(s[3], s);
    obj = sphere_ob(xyz, rgb, dia);
    if (!obj || !++(aml->count_ob[0]))
        return (1);
    ft_lstadd_back(&aml->objects[0].object, ft_lstnew(obj));
    return (0);
}
/*

pl 0.0,0.0,-10.0  0.0,1.0,0.0  0,0,225
∗identifier: pl
∗x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
∗3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
∗R,G,B colors in range [0-255]: 0,0,225

typedef struct s_plane // Plane
{
    char    pl[2];
    t_xyz   pl_xyz;
    t_xyz   vec_xyz;
    t_rgb   pl_rgb;   
}   t_plane;

*/
t_plane *plane_ob(t_xyz p_xyz, t_xyz v_xyz, t_rgb rgb)
{
    t_plane    *obj;

    obj = malloc(sizeof(t_plane));
    if (!obj)
        return (NULL);   
    obj->pl_rgb[0] = rgb;   
    obj->pl_xyz[0] = p_xyz;
    obj->vec_xyz[0] = v_xyz;
    return (obj);
}
int     set_plane(char **s, t_minirt *aml)
{
    t_xyz   (pxyz), (vxyz);
    t_rgb   rgb;
    t_plane *plane;
    
    if (!s[1] || !s[2] || !s[3] || s[4])
		return (printf("ERROT EXITS.. \n"), exit(1), 1);
    vxyz = check_xyz(s[2], -1, 1, s);
    pxyz = check_xyz(s[1], -IN_MIN, IN_MAX, s);
    rgb = check_color(s[3], s);
    plane = plane_ob(pxyz, vxyz, rgb);
    if (!plane || !++(aml->count_ob[1]))
        return (1);
    ft_lstadd_back(&aml->objects[1].object, ft_lstnew(plane));
    return (0);
}

/*

cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
∗identifier: cy
∗x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
∗3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
∗the cylinder diameter: 14.2
∗the cylinder height: 21.42
∗R,G,B colors in range [0,255]: 10, 0, 255

typedef struct s_cylinder // Cylinder
{
    char    cy[2];
    t_xyz   cy_xyz;
    t_xyz   vec_xyz;
    double  c_dia;
    double  c_hei;
    t_rgb   sy_rgb;
}   t_cylinder;
double dia, double hei
*/
// t_cylinder *plane_ob(t_xyz cxyz, t_xyz vxyz, double *d_h, t_rgb rgb)
// {
//     t_cylinder    *obj;

//     obj = malloc(sizeof(t_cylinder));
//     if (!obj)
//         return (NULL);   
//     obj->c_dia[0] = d_h[0];
//     obj->c_hei[0] = d_h[1];
//     obj->cy_xyz[0] = cxyz;
//     obj->sy_rgb[0] = rgb;
//     obj->vec_xyz[0] = vxyz;
//     return (obj);
// }
int     set_cylinder(char **s, t_minirt *aml)
{
    (void) s;
    (void) aml;
    return (0);
}
