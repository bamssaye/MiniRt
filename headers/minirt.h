/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:39:39 by bamssaye          #+#    #+#             */
/*   Updated: 2024/11/07 01:41:43 by bamssaye         ###   ########.fr       */
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
# include "get_next_line.h"

# define PROGRAM_NAME "miniRT"
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 500
# define PI 3.14159265358979323846f

# define SPHERE 0
# define PLANE 1

typedef struct s_interparam	t_interparam ;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_vec3d
{
	double		x;
	double		y;
	double		z;
}		t_vec3d;

typedef struct s_object
{
	int		type;
	void	*object;
	int		id;
	void	(*clean)(void *object);
	int		(*test_intersection)(void *object, t_interparam *param);
}			t_object;

typedef struct s_camera
{
	t_vec3d		position;
	t_vec3d		normal;
	double		fov;
	double		len;
	double		aspect_ratio;
	t_vec3d		look_at;
	t_vec3d		u;
	t_vec3d		v;
	t_vec3d		top_left;
}				t_camera;

typedef struct s_light
{
	t_vec3d		position;
	t_color		color;
	double		intensity;
}				t_light;

typedef struct s_ray
{
	t_vec3d		origin;
	t_vec3d		direction;
}				t_ray;

typedef struct s_plane
{
	t_vec3d		point;
	t_vec3d		normal;
	t_color		color;
}				t_plane;

typedef struct s_interparam
{
	t_ray		*ray;
	int			hit;
	double		f_dist;
	int			f_ishit;
	t_vec3d		f_normal;
	t_vec3d		f_point;
	t_color		f_color;
	double		inters_dist;
	int			inters_obj_id;
	t_vec3d		inters_point;
	t_vec3d		inters_normal;
	t_color		inters_color;
	int			d_inters_obj_type;
	t_color		final_color;
}				t_interparam;

typedef struct s_sphere
{
	t_vec3d		center;
	double		radius;
	t_color		color;
}				t_sphere;

typedef struct s_prog
{
	t_list				*obj;
	t_mlx_confix		mlx_config;
	int					has_camera;
	t_camera			camera;
	t_light				light;
	t_color				ambient_color;
	double				ambient_intensity;
	void				*selected_obj;
	int					x;
	int					y;
	int					item_count;
}						t_prog;

typedef struct s_slight
{
	t_color		light_color;
	t_color		ambient_color;
}			t_slight;

typedef struct s_obslight
{
	t_ray		ray;
	t_vec3d		light_dir;
	double		max_dist;
	t_slight	light;
}				t_obslight;


int			strreplace_space(char *str);
int			read_rt_file(char *filepath, t_prog *prog);
int			check_line(char *line, t_prog *prog);
int			check_line_type(char **splited_lint, t_prog *prog);
int			collect_camera(char **splited_line, t_prog *prog);
int			collect_ambient(char **split_line, t_prog *prog);
int			collect_sphere(char **splited_line, t_prog *prog);
int			collect_plane(char **str, t_prog *prog);
int			sp_intersection_normal(t_vec3d *normal, \
	t_vec3d *inters, t_vec3d *center);
double		cale_camera_len(t_camera *camera);
void		clean_plane(void *pl);
int			pl_test_intersection(void *obj, t_interparam *param);
int			pl_sub_intersect(t_plane *plane, t_interparam *param);
void		clean_sphere(void *sphere);
int			sp_test_intersection(void *object, t_interparam *p);
int			color_rgb2int(int r, int g, int b);
int			color_collect_string(char *color_string, t_color *color);
void		color_set_defval(t_color *color);
void		init_camera(t_camera *cam);
t_object	*create_object_sphere(t_sphere *sp);
t_object	*create_object_plane(t_plane *plane);
int			trace_ray_to_obj(t_prog *prog, t_interparam *param);
double		solve_quadratic(double a, double b, double c);
void		prog_init_mlx(t_prog *prog);
int			render_image(t_prog *prog);
void		prog_mlx_loop(t_prog *prog);
int			reset_inters_focus(t_interparam *param);
int			init_intersection_param(t_prog *prog, \
	t_ray *ray, t_interparam *param);
int			gather_inters_info(t_interparam *param, \
	t_object *focus_obj);
void		init_inters_light_param(t_prog *prog, t_interparam *param, \
	t_obslight *light_param);
void		generate_ray(t_ray *ray, t_prog *prog, int x, int y);
int			ray_color(t_ray *ray, t_prog *prog);
void		trace_light(t_prog *prog, t_interparam *param);
int			color_plus(t_color *res, t_color *a, t_color *b);
int			color_struct2int(t_color *color);
int			color_scale(t_color *res, double scale, t_color *a);
void		camera_look_at(t_camera *camera);
void		camera_right_vector(t_camera *camera);
void		camera_up_vector(t_camera *camera);
void		camera_top_left_vector(t_camera *camera);
double		pl_cale_dist(t_ray *ray, t_plane *pl, \
	int *hit, t_interparam *param);
double		sp_cale_dist(t_ray *ray, t_sphere *sp);
int			sp_intersection_point(t_vec3d *inters, \
	t_ray *ray, double dist);
int			re_render(t_prog *prog);
int			select_camera(t_prog *prog);
int			camera_translate_add(t_prog *prog);
int			camera_translate_minus(t_prog *prog);
void		init_light(t_light *l);
int			prog_constructor(t_prog *prog);
int		vec3d_init(t_vec3d *a, double x, double y, double z);
int		vec3d_assign(t_vec3d *to, t_vec3d *from);
int		vec3d_add(t_vec3d *to, t_vec3d *from);
int		vec3d_plus(t_vec3d *res, t_vec3d *a, t_vec3d *b);
int		vec3d_minus(t_vec3d *res, t_vec3d *a, t_vec3d *b);
int		vec3d_cross(t_vec3d *res, t_vec3d *a, t_vec3d *b);
int		vec3d_normalize(t_vec3d *a);
int		vec3d_scale(t_vec3d *res, double scale, t_vec3d *a);
double	vec3d_length(t_vec3d *a);
double	vec3d_dot(t_vec3d *a, t_vec3d *b);
void	print_vec3d(t_vec3d *a, char *message);
void	*convert_3d(char *str_vector, void *memory_in);
int		ft_strtod(char *str, double *result_ptr);
#endif
