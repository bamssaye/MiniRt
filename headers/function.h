/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:13:45 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/05 04:42:18 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "struct.h"

//////////////////////// PARSINING
t_plane     *plane_ob(t_xyz p_xyz, t_xyz v_xyz, t_rgb rgb);
t_sphere    *sphere_ob(t_xyz xyz, t_rgb rgb, double dia);
t_cylinder  *cylinder_ob(t_xyz cxyz, t_xyz vxyz, double *d_h, t_rgb rgb);
t_rgb       check_color(char *str);
t_xyz       check_xyz(char *str, double min, double max);
t_atof      ft_atof(char *nptr);
t_atoi      ft_atoii(const char *nptr);
char        **tospace(char *str);
void        arry_c(char **str);
int        ft_readfile(char *path, t_minirt *mrt);
int         set_ambient(char **s, t_minirt *aml);
int         set_camera(char **s, t_minirt *aml);
int         set_light(char **s, t_minirt *aml);
int         set_sphere(char **s, t_minirt *aml);
int         set_plane(char **s, t_minirt *aml);
int         set_cylinder(char **s, t_minirt *aml);
int         check_str(char **s, int size);
int         valid_line(char **s, t_minirt *mrt);
int         ft_isspace(int c);
int         ft_range(t_atoi n, double min, double max);
int         ft_ranges(t_atof n, double min, double max);
int         check_li(char *str);

///////////////////////////////////////////////
// int			strreplace_space(char *str);
// int			read_rt_file(char *filepath, t_prog *prog);
// int			check_line(char *line, t_prog *prog);
// int			check_line_type(char **splited_lint, t_prog *prog);
// int			collect_camera(char **splited_line, t_prog *prog);
// int			collect_ambient(char **split_line, t_prog *prog);
// int			collect_sphere(char **splited_line, t_prog *prog);
// int			collect_plane(char **str, t_prog *prog);
// int			sp_intersection_normal(t_vec3d *normal, t_vec3d *inters, t_vec3d *center);
// double		cale_camera_len(t_camera *camera);
// void		clean_plane(void *pl);
// int			pl_test_intersection(void *obj, t_interparam *param);
// int			pl_sub_intersect(t_plane *plane, t_interparam *param);
// void		clean_sphere(void *sphere);
// int			sp_test_intersection(void *object, t_interparam *p);
// int			color_rgb2int(int r, int g, int b);
// int			color_collect_string(char *color_string, t_color *color);
// void		color_set_defval(t_color *color);
// void		init_camera(t_camera *cam);
// t_object	*create_object_sphere(t_sphere *sp);
// t_object	*create_object_plane(t_plane *plane);
// int			trace_ray_to_obj(t_prog *prog, t_interparam *param);
// double		solve_quadratic(double a, double b, double c);
// void		prog_init_mlx(t_prog *prog);
// int			render_image(t_prog *prog);
// void		prog_mlx_loop(t_prog *prog);
// int			reset_inters_focus(t_interparam *param);
// int			init_intersection_param(t_prog *prog, t_ray *ray, t_interparam *param);
// int			gather_inters_info(t_interparam *param, t_object *focus_obj);
// void		init_inters_light_param(t_prog *prog, t_interparam *param, t_obslight *light_param);
// void		generate_ray(t_ray *ray, t_prog *prog, int x, int y);
// int			ray_color(t_ray *ray, t_prog *prog);
// void		trace_light(t_prog *prog, t_interparam *param);
// int			color_plus(t_color *res, t_color *a, t_color *b);
// int			color_struct2int(t_color *color);
// int			color_scale(t_color *res, double scale, t_color *a);
// void		camera_look_at(t_camera *camera);
// void		camera_right_vector(t_camera *camera);
// void		camera_up_vector(t_camera *camera);
// void		camera_top_left_vector(t_camera *camera);
// double		pl_cale_dist(t_ray *ray, t_plane *pl, int *hit, t_interparam *param);
// double		sp_cale_dist(t_ray *ray, t_sphere *sp);
// int			sp_intersection_point(t_vec3d *inters, t_ray *ray, double dist);
// int			re_render(t_prog *prog);
// int			select_camera(t_prog *prog);
// int			camera_translate_add(t_prog *prog);
// int			camera_translate_minus(t_prog *prog);
// void		init_light(t_light *l);
// int			prog_constructor(t_prog *prog);
// int		vec3d_init(t_vec3d *a, double x, double y, double z);
// int		vec3d_assign(t_vec3d *to, t_vec3d *from);
// int		vec3d_add(t_vec3d *to, t_vec3d *from);
// int		vec3d_plus(t_vec3d *res, t_vec3d *a, t_vec3d *b);
// int		vec3d_minus(t_vec3d *res, t_vec3d *a, t_vec3d *b);
// int		vec3d_cross(t_vec3d *res, t_vec3d *a, t_vec3d *b);
// int		vec3d_normalize(t_vec3d *a);
// int		vec3d_scale(t_vec3d *res, double scale, t_vec3d *a);
// double	vec3d_length(t_vec3d *a);
// double	vec3d_dot(t_vec3d *a, t_vec3d *b);
// void	print_vec3d(t_vec3d *a, char *message);
// void	*convert_3d(char *str_vector, void *memory_in);
// int		ft_strtod(char *str, double *result_ptr);



#endif
