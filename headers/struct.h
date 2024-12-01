/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:03:03 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/01 05:20:00 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STRUCT_H
# define STRUCT_H


typedef struct s_color // Colors RGB
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_xyz // Coordinates x, y, z
{
	double			x;
	double			y;
	double			z;
}				t_xyz;
////////
typedef struct s_a_light // Ambient lightning
{
    char a;
    double al;
    t_rgb   al_rgb;
}   t_a_light;

typedef struct s_camera // Camera
{
    char    c;
    t_xyz   c_xyz;
    t_xyz   vec_xyz;
    int     fov;
} t_camera;

typedef struct s_light // Light
{
    char    l;
    t_xyz   light_xyz;
    double  light_bri;
    t_rgb   light_rgb;
}   t_light;

typedef struct s_sphere // Sphere
{
    char    sp[2];
    t_xyz   sph_xyz;
    double  sph_dia;
    t_rgb   sph_rgb;
} t_sphere;

typedef struct s_plane // Plane
{
    char    pl[2];
    t_xyz   pl_xyz;
    t_xyz   vec_xyz;
    t_rgb   pl_rgb;   
}   t_plane;

typedef struct s_cylinder // Cylinder
{
    char    cy[2];
    t_xyz   cy_xyz;
    t_xyz   vec_xyz;
    double  c_dia;
    double  c_hei;
    t_rgb   sy_rgb;
}   t_cylinder;

typedef struct s_minirt //  capital letter can only be declared once
{
    t_a_light   am_light;
    t_camera    camera;
    t_light     light; 
    int         amc[3];  
}   t_minirt;





# endif