/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:03:03 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/15 06:38:04 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

///////////////////////////////////////////
////////////////////////// MLX STRUCT
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
///////////////////////////////////////////
////////////////////////// ATOI && ATOF
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

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
///////////////////////////////////////////
////////////////////////// RGB && XYZ
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
	int			isv;	
}	t_vec3d;
///////////////////////////////////////////
////////////////////////// RAY 
typedef struct s_ray
{
	t_vec3d		origin;
	t_vec3d		direction;
}	t_ray;
///////////////////////////////////////////
////////////////////////// OBJECT : SPHERE, PLANE, CYLINDER
typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		endian;
	int		height;
	int 	line_length;
	char	*path;
	int		check_valid;
}			t_tex;
typedef struct s_sphere
{
	t_vec3d		center;
	t_color		color;
	double		radius;
	t_tex		tex;
	t_tex		n_map;

}			t_sp;
typedef struct s_plane
{
	t_vec3d		point;
	t_vec3d		normal;
	t_color		color;
	t_tex		tex;
	t_tex		n_map;

}			t_pl;
typedef struct s_cylinder
{
	t_vec3d		point;
	t_vec3d		normal;
	t_color		color;
	double		radius;
	double		len;
	t_tex		tex;
	t_tex		n_map;
}			t_cy;
///////////////////////////////////////////
////////////////////////// ENV : CAMERA, LIGHT, EMBIENT LIGHT
typedef struct s_camera
{
	t_vec3d		position;
	// t_vec3d		normal;
	double			fov;
	t_vec3d		world_up;
	t_vec3d		look_at;
	t_vec3d		u;
	t_vec3d		v;
	t_vec3d		top_left;
}			t_camera;
typedef struct s_a_light
{
	t_color		al_rgb;
	double		al;
}			t_a_light;
typedef struct s_light
{
	t_vec3d		position;
	double		intensity;
	t_color		color;
}			t_light;
///////////////////////////////////////////
////////////////////////// INTERSECTION 
typedef struct s_npc
{
	t_vec3d		normal;
	t_vec3d		point;
	t_color		color;
	double		dista;
}				t_npc;
typedef struct s_inters_params
{
	t_ray		*ray;
	int			hit;
	int			hit_clos;
	int			iobj_id;
	t_npc		closest;
	t_npc		inters;
	t_color		final_color;
}				t_in_pa;
///////////////////////////////////////////
////////////////////////// OBJECT LIGHT
typedef struct s_slight
{
	t_color		light_color;
	t_color		ambient_color;
}			t_slight;

typedef struct s_obslight
{
	t_ray		ray;
	t_vec3d		light_dire;
	double		max_dista;
	int			stuck;
	t_slight	light;
}				t_obslight;
///////////////////////////////////////////
////////////////////////// object
typedef struct s_objects
{
	void		*object;
	int			type;
	int			id;
	int			t;
}			t_object;
///////////////////////////////////////////
////////////////////////// Trace light intersaction

typedef struct s_trace_light
{
	t_obslight	l_pa;
	t_npc		inters;
	t_list		*lst;
	t_object	*objt;
	t_color		final_c;
	t_color		color;
	t_color		ambient_color;
	double		angle_scale;
} t_trace_light;

///////////////////////////////////////////
////////////////////////// MAIN
typedef struct s_obj
{
	t_sp		*sp;
	t_pl		*pl;
	t_cy		*cy;
	t_object	*obj;
} t_obj;

typedef struct t_rota
{
	int		id_obj;
	t_object	*slected;
} t_rota;
typedef struct s_minirt
{
	t_list		*object;
	t_obj		objs;
	t_a_light	am_light;
	t_camera	camera;
	t_light		light;
	t_mlx		mlx;
	t_rota		selected;
	int			obj_c;
	int			count_t;
	int			amc[3];
	char		buffer[BUFFER_SIZE];
	int			x;
	int			y;
	int			bouns;
}			t_minirt;
///////////////////////////////////////////
#endif
