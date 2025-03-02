/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:03:03 by bamssaye          #+#    #+#             */
/*   Updated: 2025/03/02 23:44:08 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

///////////////////////////////////////////
////////////////////////// MLX STRUCT
typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				width;
	int				endian;
}					t_image;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	t_image			img;
}					t_mlx;
///////////////////////////////////////////
////////////////////////// ATOI && ATOF
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_atof
{
	double			num;
	int				isv;
	int				i;
	int				sign;
}					t_atof;

typedef struct s_atoi
{
	int				num;
	int				isv;
}					t_atoi;
///////////////////////////////////////////
////////////////////////// color && XYZ
typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	int				isv;
}					t_color;

typedef struct s_xyz
{
	double			x;
	double			y;
	double			z;
	int				isv;
}					t_vec3d;

typedef struct s_tbitan
{
	t_vec3d			tan;
	t_vec3d			bitan;
	t_vec3d			normal;
}					t_tbitan;
///////////////////////////////////////////
////////////////////////// RAY
typedef struct s_ray
{
	t_vec3d			origin;
	t_vec3d			direction;
}					t_ray;
///////////////////////////////////////////
////////////////////////// OBJECT : SPHERE, PLANE, CYLINDER

typedef struct s_tex
{
	void			*img;
	char			*addr;
	int				bpp;
	int				width;
	int				endian;
	int				height;
	int				line_length;
	char			*path;
	int				check_valid;
}					t_tex;

typedef struct s_sphere
{
	t_vec3d			center;
	t_color			color;
	double			radius;
}					t_sp;

typedef struct s_plane
{
	t_vec3d			point;
	t_vec3d			normal;
	t_color			color;
}					t_pl;

typedef struct s_cylinder
{
	t_vec3d			point;
	t_vec3d			normal;
	t_color			color;
	double			radius;
	double			len;
}					t_cy;
/////////////////////////////////////////
///////////////////////////////// cone
typedef struct s_cone
{
	t_vec3d			point;
	t_vec3d			normal;
	double			radius;
	double			height;
	t_color			color;
}					t_co;

typedef struct s_cone_inter
{
	double			dn;
	double			on;
	double			k;
	double			k_sq;
	double			a;
	double			b;
	double			c;
}					t_cone_inter;

typedef struct s_cone_dist
{
	double			t1;
	double			t2;
	double			min_t;
	double			h;
	int				i;
	double			roots[2];
	t_vec3d			hit;
	t_vec3d			ori;
}					t_cone_dist;

typedef struct s_cone_hit
{
	double			t;
	t_vec3d			a2h;
	double			proj;
	double			k_sq;
}					t_cone_hit;
///////////////////////////////////////////
////////////////////////// ENV : CAMERA, LIGHT, EMBIENT LIGHT
typedef struct s_camera
{
	t_vec3d			position;
	t_vec3d			normal;
	int				fov;
	t_vec3d			world_up;
	t_vec3d			look_at;
	t_vec3d			u;
	t_vec3d			v;
	t_vec3d			top_left;
}					t_camera;

typedef struct s_a_light
{
	t_color			al_color;
	double			al;
}					t_a_light;

typedef struct s_light
{
	t_vec3d			position;
	double			intensity;
	t_color			color;
}					t_light;
///////////////////////////////////////////
////////////////////////// INTERSECTION
typedef struct s_npc
{
	t_vec3d			normal;
	t_vec3d			point;
	t_color			color;
	double			dista;
}					t_npc;

typedef struct s_inters_params
{
	t_ray			*ray;
	int				hit;
	int				hit_clos;
	int				iobj_id;
	t_npc			closest;
	t_npc			inters;
	t_color			final_color;
}					t_hit;
///////////////////////////////////////////
////////////////////////// OBJECT LIGHT

typedef struct s_obslight
{
	t_ray			ray;
	t_vec3d			light_dire;
	double			m_dis;
	int				stuck;
	t_color			c;
	t_color			spc;
	// t_slight		light;
}					t_obslight;

///////////////////////////////////////////
////////////////////////// object
typedef struct s_bump
{
	t_tex			img;
	t_tex			bump;
}					t_bump;

typedef struct s_objects
{
	void			*object;
	int				type;
	int				id;
	char			*path;
	t_bump			bum_tex;
	int				style[3];
	int				t;
}					t_object;

///////////////////////////////////////////
////////////////////////// Trace light intersaction

typedef struct s_trace_light
{
	t_obslight		l_pa;
	t_npc			inters;
	t_list			*lst;
	t_object		*objt;
	t_color			f_c;
	t_color			col;
	t_color			ambient_color;
	double			angle;
}					t_trace_light;

///////////////////////////////////////////
////////////////////////// MAIN
typedef struct s_obj
{
	t_sp			*sp;
	t_pl			*pl;
	t_cy			*cy;
	t_co			*co;
	t_object		*obj;
}					t_obj;

typedef struct t_rota
{
	int				id_obj;
	t_object		*slected;
}					t_rota;

typedef struct s_key
{
	int				rot;
	int				tra;
	int				left;
	int				right;
	int				up;
	int				down;
	int				z_i;
	int				z_o;
}					t_keys;

typedef struct s_point_normal
{
	t_vec3d			point;
	t_vec3d			normal;
}					t_point_normal;

typedef struct s_minirt
{
	t_list			*object;
	t_a_light		am_light;
	t_camera		cam;
	t_light			light;
	t_mlx			mlx;
	t_rota			selected;
	t_keys			key;
	int				obj_count;
	int				count_t;
	int				bouns;
	int				amc[3];
	char			buffer[BUFFER_SIZE];
	int				x;
	int				y;
}					t_minirt;
///////////////////////////////////////////
#endif
