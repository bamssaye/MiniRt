/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:03:03 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/22 16:41:59 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

//////////////////////////////////////////////////////////////////////////////////
///////////////// MLX Struct
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		endian;
}			t_image;
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_image	img;
}			t_mlx;
//////////////////////////////////////////////////////////////////////////////////
//////////////////// Atoi && Atof
typedef struct s_atof
{
	double	num;
	int		isv;
	int		i;
	int		sign;
}			t_atof;

typedef struct s_atoi
{
	int		num;
	int		isv;
}			t_atoi;
//////////////////////////////////////////////////////////////////////////////////
//////////////////// ARG && XYZ
typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		isv;
}			t_color;

typedef struct s_xyz
{
	double		x;
	double		y;
	double		z;
	int		isv;	
}	t_vec3d;
//////////////////////////////////////////////////////////////////////////////////
typedef struct s_ray
{
	t_vec3d		origin;
	t_vec3d		direction;
}	t_ray;
//////////////////////////////////////////////////////////////////////////////////
///////////////// OBJCT
typedef struct s_sphere
{
	t_vec3d		center;
	t_color		color;
	double		radius;
}			t_sphere;

typedef struct s_plane
{
	t_vec3d		point;
	t_vec3d		normal;
	t_color		color;
}			t_plane;

typedef struct s_cylinder
{
	t_vec3d		point;
	t_vec3d		normal;
	t_color		color;
	double		radius;
	double		len;
}			t_cylinder;
/////////////// Red
//////////// camra lighting amb
typedef struct s_camera // Camera
{
	t_vec3d		position; // view coordina
	t_vec3d		normal; // normalize or vector
	int			fov; // horizontal fov
	t_vec3d		world_up;
	t_vec3d		look_at;
	t_vec3d		u;
	t_vec3d		v;
	t_vec3d		top_left;
}			t_camera;

typedef struct s_a_light// Ambient lightning
{
	t_color		al_rgb;
	double		al;
}			t_a_light;

typedef struct s_light // Light
{
	t_vec3d		position;
	double		intensity;
	t_color		color;
	char		l;

}			t_light;

//////////////////////
typedef struct s_object
{
	int		type;
	void	*object;
	int		id;
	void	(*clean)(void *object);
	int		(*test_intersection)(void *object, t_inter_p *param);
}			t_object;

typedef struct s_inters_params
{
	t_ray		*ray;
	int			hit;
	double		closest_distance;
	int			is_closest_hit;
	t_object	*f_obj;
	t_vec3d		closest_normal;
	t_vec3d		closest_point;
	t_color		closest_color;
	double		inters_dist;
	int			inters_object_id;
	t_vec3d		inters_point;
	t_vec3d		inters_normal;
	t_color		inters_color;
	t_color		final_color;
}				t_inter_p;
//////////////////////////////
typedef struct s_slight
{
	t_color		light_color;
	t_color		ambient_color;
}			t_slight;

typedef struct s_obslight
{
	t_ray		ray;
	t_vec3d		light_direction;
	double		angle;
	double		max_distance;
	double		angle_scale;
	int			stuck;
	t_slight	light;
}				t_obslight;
//////////////////////////////////
typedef struct s_objects
{
	t_list		*object;
	int			obj_count;
}			t_objects;

typedef struct s_minirt //  capital letter can only be declared once
{
	t_objects	objects;
	t_a_light	am_light;
	t_camera	camera;
	t_light		light;
	t_mlx		mlx;
	int			amc[3];
	char		buffer[BUFFER_SIZE];
	int			x;
	int			y;
}			t_minirt;

// typedef struct s_prog
// {
// 	t_list				*obj;
// 	t_mlx_confix		mlx_config;
// 	int					has_camera;
// 	int					has_ambient;
// 	int					has_light;
// 	t_camera			camera; ///
// 	t_light				light;
// 	t_color				ambient_color;
// 	double				ambient_intensity;
// 	int					x;
// 	int					y;
// 	int					object_count;
// }						t_prog;














































//////////////////////////////
typedef struct s_mx4
{
    double mx[4][4];
	int		size;
} t_mx4;
typedef struct s_discriminant 
{
	double  a;
	double  b;
	double  c;
	double  disc;
	double	t1;
	double	t2;
}			t_discriminant;
typedef struct s_material 
{
	t_color	color;
	double  ambient;
	double  diffuse;
	double  specular;
	double  shininess;
}			t_material;
#endif
