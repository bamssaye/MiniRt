/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:03:03 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/17 06:11:38 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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

////////////////////

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

typedef struct s_mx4
{
    float mx[4][4];
} t_mx4;
//////////////////
typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		isv;
}			t_rgb;

typedef struct s_xyz// Coordinates x, y, z
{
	double		x;
	double		y;
	double		z;
	int		isv;	
}	t_xyz;
////////
typedef struct s_ray// Coordinates x, y, z
{
	t_xyz		ori; // origin
	t_xyz		dir; // direcation
}	t_ray;

typedef struct s_a_light// Ambient lightning
{
	t_rgb		al_rgb;
	double		al;
}			t_a_light;

typedef struct s_camera // Camera
{
	t_xyz		c_xyz; // view coordina
	t_xyz		vec_xyz; // normalize or vector
	int			fov; // horizontal fov
	//////////
	t_mx4		v_mx;
	t_mx4		p_mx;
	///////////
	// t_xyz		w_up;
	// t_xyz		look_at;
	// t_xyz		u;
	// t_xyz		v;
	// t_xyz		top_left;
}			t_camera;
//t_xyz		normalize[1];
typedef struct s_light // Light
{
	t_rgb		light_rgb;
	t_xyz		light_xyz;
	double		light_bri;
	char		l;

}			t_light;

typedef struct s_sphere // Sphere
{
	t_xyz		sph_xyz[1];
	t_rgb		sph_rgb[1];
	double		sph_dia[1];
}			t_sphere;

typedef struct s_plane // Plane
{
	t_xyz		pl_xyz[1];
	t_xyz		vec_xyz[1];
	t_rgb		pl_rgb[1];
}			t_plane;

typedef struct s_cylinder // Cylinder
{
	t_xyz		cy_xyz[1];
	t_xyz		vec_xyz[1];
	t_rgb		sy_rgb[1];
	double		c_dia[1];
	double		c_hei[1];
}			t_cylinder;

typedef struct s_objects
{
	t_list		*object;
	char		type[2];

}			t_objects;

typedef struct s_minirt //  capital letter can only be declared once
{
	t_objects	objects[3];
	t_a_light	am_light;
	t_camera	camera;
	t_light		light;
	t_mlx		mlx;
	int			amc[3];      // check if light, camera, Ambient set many time
	int			count_ob[3]; // count object for every element , sphere ...
	char		buffer[BUFFER_SIZE];
	int			x;
	int			y;
}			t_minirt;

#endif
