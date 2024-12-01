/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:39:39 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/01 04:23:11 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "mlx_.h"
# include "function.h"

# define PROGRAM_NAME "miniRT"
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 500
# define IN_MAX 2147483647
# define IN_MIN 2147483648
# define PI 3.14159265358979323846f

# define SPHERE 0
# define PLANE 1

// typedef struct s_interparam	t_interparam ;

// typedef struct s_color
// {
// 	int			r;
// 	int			g;
// 	int			b;
// }				t_color;

// typedef struct s_vec3d
// {
// 	double		x;
// 	double		y;
// 	double		z;
// }		t_vec3d;

// typedef struct s_object
// {
// 	int		type;
// 	void	*object;
// 	int		id;
// 	void	(*clean)(void *object);
// 	int		(*test_intersection)(void *object, t_interparam *param);
// }			t_object;

// typedef struct s_camera
// {
// 	t_vec3d		position;
// 	t_vec3d		normal;
// 	double		fov;
// 	double		len;
// 	double		aspect_ratio;
// 	t_vec3d		look_at;
// 	t_vec3d		u;
// 	t_vec3d		v;
// 	t_vec3d		top_left;
// }				t_camera;

// typedef struct s_light
// {
// 	t_vec3d		position;
// 	t_color		color;
// 	double		intensity;
// }				t_light;

// typedef struct s_ray
// {
// 	t_vec3d		origin;
// 	t_vec3d		direction;
// }				t_ray;

// typedef struct s_plane
// {
// 	t_vec3d		point;
// 	t_vec3d		normal;
// 	t_color		color;
// }				t_plane;

// typedef struct s_interparam
// {
// 	t_ray		*ray;
// 	int			hit;
// 	double		f_dist;
// 	int			f_ishit;
// 	t_vec3d		f_normal;
// 	t_vec3d		f_point;
// 	t_color		f_color;
// 	double		inters_dist;
// 	int			inters_obj_id;
// 	t_vec3d		inters_point;
// 	t_vec3d		inters_normal;
// 	t_color		inters_color;
// 	int			d_inters_obj_type;
// 	t_color		final_color;
// }				t_interparam;

// typedef struct s_sphere
// {
// 	t_vec3d		center;
// 	double		radius;
// 	t_color		color;
// }				t_sphere;
// ////////////////////////////////////////////////////////////////////////////////////


// typedef struct s_prog
// {
// 	t_list				*obj;
// 	t_mlx_confix		mlx_config;
// 	int					has_camera;
// 	t_camera			camera;
// 	t_light				light;
// 	t_color				ambient_color;
// 	double				ambient_intensity;
// 	void				*selected_obj;
// 	int					x;
// 	int					y;
// 	int					item_count;
// }						t_prog;



// typedef struct s_minirt //  capital letter can only be declared once
// {
//     t_light   am_light;
//     t_camera    camera;
//     t_light     light; 
//     int         amc[3];  
// }   t_minirt;

// /////////////////////////////////////////////////////////////////////////////////
// typedef struct s_slight
// {
// 	t_color		light_color;
// 	t_color		ambient_color;
// }			t_slight;

// typedef struct s_obslight
// {
// 	t_ray		ray;
// 	t_vec3d		light_dir;
// 	double		max_dist;
// 	t_slight	light;
// }				t_obslight;

//////////////

///////////////////


#endif
