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
# define EPSILON 1e-21f

# define SPHERE 0
# define PLANE 1
# define CYLINDER 2

typedef struct s_inters_params	t_inters_params ;

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
	int		(*test_intersection)(void *object, t_inters_params *param);
}			t_object;

typedef struct s_camera
{
	t_vec3d		position;
	t_vec3d		normal;
	double		fov;	
	t_vec3d		world_up;
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
}				t_inters_params;

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
	int					has_ambient;
	int					has_light;
	t_camera			camera; ///
	t_light				light;
	t_color				ambient_color;
	double				ambient_intensity;
	int					x;
	int					y;
	int					object_count;
}						t_prog;

typedef struct s_slight
{
	t_color		light_color;
	t_color		ambient_color;
}			t_slight;

typedef struct s_cylinder
{
	t_vec3d		point;
	double		radius;
	double		len;
	t_vec3d		normal;
	t_color		color;
}				t_cylinder;

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

int			prog_constructor(t_prog *prog);
int			read_rt_file(char *filepath, t_prog *prog);
int			check_line(char *line, t_prog *prog);
int			check_line_type(char **splited_lint, t_prog *prog);
int			setup_camera_from_input(char **splited_line, t_prog *prog);
int			setup_ambient_from_input(char **split_line, t_prog *prog);
int			setup_light_from_input(char **splited_line, t_prog *prog);
int			setup_sphere_from_input(char **splited_line, t_prog *prog);
int			setup_plane_from_input(char **str, t_prog *prog);
int			calculate_sphere_intersection_normal(t_vec3d *normal, \
	t_vec3d *inters, t_vec3d *center);
int			calculate_sphere_intersection_point(t_vec3d *inters, t_ray *ray, double dist);
void		clean_plane(void *pl);
int			check_plane_intersection(void *obj, t_inters_params *param);
int			calculate_plane_intersection(t_plane *plane, t_inters_params *param);
void		clean_cylinder(void *object);
t_object	*create_cylinder_object(t_cylinder *cylinder);
int			setup_cylinder_from_input(char **str, t_prog *prog);
int			check_cylinder_intersection(void *object, t_inters_params *p);
void		clean_sphere(void *sphere);
int			check_sphere_intersection(void *object, t_inters_params *p);
int			color_plus(t_color *res, t_color *a, t_color *b);
int			convert_color_to_int(t_color *color);
int			rgb_to_int(int r, int g, int b);
int			color_collect_string(char *color_string, t_color *color);
int			color_scale(t_color *res, double scale, t_color *a);
void		set_default_color(t_color *color);
void		init_camera(t_camera *cam);
t_object	*create_object_sphere(t_sphere *sp);
t_object	*create_object_plane(t_plane *plane);
void		generate_ray(t_ray *ray, t_prog *prog, int x, int y);
int			trace_ray_to_objects(t_prog *prog, t_inters_params *param);
double		solve_quadratic_equation(double a, double b, double c);
void		prog_init_mlx(t_prog *prog);
int			render_image(t_prog *prog);
void		prog_mlx_loop(t_prog *prog);
int			reset_intersection_focus(t_inters_params *param);
int			init_intersection_param(t_prog *prog, \
	t_ray *ray, t_inters_params *param);
int			set_intersection_info(t_inters_params *param, \
	t_object *focus_obj);
void		initialize_light_parameters(t_prog *prog, t_inters_params *param, \
	t_obslight *light_param);
int			calculate_light_intensity_scale(t_obslight *l_param, t_inters_params *p);
int			almost_equal(double a, double b);
int			render_image(t_prog *prog);
void		generate_ray(t_ray *ray, t_prog *prog, int x, int y);
int			calculate_pixel_color(t_ray *ray, t_prog *prog);
int			trace_ray_to_light_source(t_prog *prog, \
	t_inters_params *param, t_obslight *light_param);
void		trace_light_at_intersection(t_prog *prog, t_inters_params *param);
int			check_cylinder_intersection(void *object, t_inters_params *p);
double		calculate_cylinder_distance(t_ray *ray, t_cylinder *cy);
int			calculate_cylinder_intersection_normal(t_vec3d *normal, \
	t_vec3d *inters, t_vec3d *center);
int			cy_intersection_point(t_vec3d *inters, t_ray *ray, double dist);
int			create_cylinder_caps_planes(t_plane *pl, t_cylinder *cy);
void		create_tempIntersection_inters(t_ray *ray, \
	t_inters_params *tempIntersection, t_inters_params *p);
void		print_inters_param(t_inters_params *p);
int			set_inters_from_tempIntersection(t_inters_params *p, t_inters_params *tempIntersection);
int			check_cylinder_hit(t_cylinder *cy, t_inters_params *p);
int			check_cylinder_caps_intersection(t_cylinder *cy, t_inters_params *p);
int			color_plus(t_color *res, t_color *a, t_color *b);
int			convert_color_to_int(t_color *color);
void		camera_look_at(t_camera *camera);
void		camera_right_vector(t_camera *camera);
void		camera_up_vector(t_camera *camera);
void		camera_top_left_vector(t_camera *camera);
double		calculate_plane_ray_intersection_distance(t_ray *ray, t_plane *pl, \
	int *hit, t_inters_params *param);
double		calculate_sphere_ray_distance(t_ray *ray, t_sphere *sp);
int			calculate_sphere_intersection_normal(t_vec3d *normal, \
	t_vec3d *inters, t_vec3d *center);
int			check_intersection_with_object(t_object *obj, t_inters_params *param);
void		init_light(t_light *l);
void		print_vec3d(t_vec3d *a, char *message);
int			vec3d_init(t_vec3d *a, double x, double y, double z);
int			copy_vec3d(t_vec3d *to, t_vec3d *from);
int			vec3d_plus(t_vec3d *res, t_vec3d *a, t_vec3d *b);
int			vec3d_minus(t_vec3d *res, t_vec3d *a, t_vec3d *b);
int			vec3d_cross(t_vec3d *res, t_vec3d *a, t_vec3d *b);
int			vec3d_normalize(t_vec3d *a);
int			vec3d_scale(t_vec3d *res, double scale, t_vec3d *a);
double		vec3d_length(t_vec3d *a);
double		vec3d_dot(t_vec3d *a, t_vec3d *b);
int			ft_strtod(char *str, double *result_ptr);
void		*initialize_vector_from_string(char *str_vector, void *memory_in);
void		print_vec3d(t_vec3d *a, char *message);


#endif
