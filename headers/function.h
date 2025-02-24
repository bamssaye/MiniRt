/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:13:45 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/24 11:10:51 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H


///////////////////////////////////////////
t_color co_texture(t_tex *tex, t_vec3d *hpoint, t_co *co);
t_vec3d co_nomap(t_tex *n_map, t_co *co, t_npc *closest, t_ray *ray);
t_color co_checkerboard(t_vec3d *hpoint, t_co *co);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void load_texture(t_minirt *rt, t_list *lst);
t_vec3d cy_nomap(t_tex *n_map, t_cy *cy, t_npc *closest, t_ray *ray);
t_vec3d pl_nomap(t_tex *n_map, t_pl *pl, t_npc *closest, t_ray *ray);
t_vec3d sp_nomap(t_tex *n_map, t_npc *closest, t_ray *ray, t_sp *sp);
void p_c(t_color a);
int print_err(char *str, char *s);
t_vec3d color_map(t_color color);
t_color pl_texture(t_tex *tex, t_vec3d *hpoint, t_pl *pl);
t_color sp_texture(t_tex *tex, t_vec3d *hpoint, t_sp *sp);
t_color cy_texture(t_tex *tex, t_vec3d *hpoint, t_cy *cy);
void rotate_z(t_object *obj, double angle);
void rotate_x(t_object *obj, double angle);
void rotate_y(t_object *obj, double angle);
void transle_x(t_object *obj, double x);
void transle_y(t_object *obj, double y);
void transle_z(t_object *obj, double z);
void transle_x(t_object *obj, double x);
void transle_y(t_object *obj, double y);
void transle_z(t_object *obj, double z);
t_color pl_checkerboard(t_vec3d *hpoint, t_pl *pl);
t_color sp_checkerboard(t_vec3d *hpoint, t_sp *sp);
t_color cy_checkerboard(t_vec3d *hpoint, t_cy *cy);
/////////////////////////////// PARSINING
t_color		check_color(char *str);
t_vec3d		check_xyz(char *str, double min, double max);
char		**tospace(char *str);
void		arry_c(char **str);
void		free_cmd(t_list *cmd);
int			ft_readfile(char *path, t_minirt *mrt);
int			set_ambient(char **s, t_minirt *rt);
int			set_camera(char **s, t_minirt *rt);
int			set_light(char **s, t_minirt *rt);
int			set_sp(char **s, t_minirt *rt);
int			set_pl(char **s, t_minirt *rt);
int			set_cy(char **s, t_minirt *rt);
int			check_str(char **s, int size);
int			valid_line(char **s, t_minirt *mrt);
int			ft_isspace(int c);
int			ft_range(t_atoi n, double min, double max);
int			ft_ranges(t_atof n, double min, double max);
int			check_li(char *str);
///////////////////////////////////////////
/////////////////////////////// Camera
t_vec3d		c_look_at(t_camera *camera);
t_vec3d		c_topleft(t_camera *cam);
t_vec3d		c_up_v(t_camera *camera);
t_vec3d		c_r_v(t_camera *camera);
int			is_parallel(t_vec3d v1, t_vec3d v2);
///////////////////////////////////////////
/////////////////////////////// Math Utils
double		quad_equa(double a, double b, double c);
///////////////////////////////////////////
////////////////////////// Color Utils
t_color		c_scale(double scale, t_color a);
int			min(int a, int min);
t_color		c_plus(t_color a, t_color b);
int			ctoi(t_color color);
t_color color_a(t_color a, t_color b);
///////////////////////////////////////////
////////////////////////// SPHER
double		sp_ray_dista(t_ray ray, t_sp sp);
t_npc		c_sp_inter(t_ray ray, double dist, t_sp sp);
// void		sp_inter(t_sp *sp, t_hit *intersection);
void	sp_inter(t_sp *sp, t_hit *intersection, t_bump *bump, int *style);
// t_object	*sphere_ob(t_vec3d xyz, t_color color, double dia, char *path);
t_object	*sphere_ob(t_vec3d point, t_color color, double dia, char *path);
t_object	*plane_ob(t_point_normal *p_n, t_color color, char *path);
// t_object	*cylinder_ob(t_point_normal *p_n, double *d_h, t_color color);
t_object	*cylinder_ob(t_point_normal *p_n, double *d_h, t_color color, char *path);

// t_object	*cone_ob(t_point_normal *p_n, double *d_h, t_color color);
///////////////////////////////////////////
////////////////////////// PLANE
double		pl_ray_dista(t_ray ray, t_pl pl, t_npc *closest);
t_npc		pl_closest(t_vec3d ray, t_pl pl, double dist, t_vec3d origin);
int			plane_inter(t_pl *plane, t_hit *param, t_bump *bump, int *style);
// t_object	*plane_ob(t_vec3d p_xyz, t_vec3d v_xyz, t_color color, char *path);

///////////////////////////////////////////
////////////////////////// CYLINDER
double		cy_ray_dista(t_ray ray, t_cy cy);
t_pl		copy_pl(t_vec3d po, t_vec3d no, t_color col, t_vec3d offset);
// void		cy_caps(t_pl *pl, t_cy *cy);
void		cy_caps(t_pl *pl, t_cy *cy, int is_top);
int			check_cylinder_hit(t_cy *cy, t_hit *p);
int			check_cylinder_caps_intersection(t_cy *cy,
				t_hit *intersection);
void		cy_inter(t_cy *cy, t_hit *f_inter, t_bump *bump, int *style);
// t_object	*cylinder_ob(t_vec3d cxyz, t_vec3d vxyz, double *d_h, t_color color);

///////////////////////////////////////////
////////////////////////// VECTOR
t_vec3d		v_scale(double scale, t_vec3d a);
double		v_magnitude(t_vec3d a);
t_vec3d		v_cross(t_vec3d a, t_vec3d b);
t_vec3d		v_plus(t_vec3d a, t_vec3d b);
t_vec3d		v_minus(t_vec3d a, t_vec3d b);
t_vec3d		v_normalize(t_vec3d a);
double		v_dot(t_vec3d a, t_vec3d b);
///////////////////////////////////////////
////////////////////////// RAY TRACING
t_color	specular_light(t_trace_light *t_li, t_vec3d position);
t_ray		ray_gen(t_camera cam, int x, int y);
void		inter_wobject(t_object *obj, t_hit *param, t_minirt *rt);
void		trace_ray(t_hit *pa, int *stuck, double mx_dist, t_minirt *rt);
void		trace_rtobj(t_hit *pa, t_minirt *rt);
t_obslight	initlight_inter(t_light l_param, t_hit *pa);
void		trace_light_at_intersection(t_minirt *prog, t_hit *param);
int			calculate_pixel_color(t_ray *ray, t_minirt *prog);
double		lig_scale(t_vec3d a, t_vec3d b);
///////////////////////////////////////////
////////////////////////// INIT MLX
void		ft_init_win(t_minirt *mrt);
void		ft_hooks_fun(t_minirt *mrt);
int			ft_clear_all(t_minirt *mrt);
void		mlx_putpixel(t_image *data, int x, int y, int color);
int			render_image(t_minirt *prog);
///////////////////////////////////////////
////////////////////////// UTILS
t_color 	cpy_color(t_color co);
t_atof		ft_atof(char *nptr);
t_atoi		ft_atoii(const char *nptr);
int	    	ft_isalnum(int c);
char		*ft_strchr(const char *s, int c);
int	    	ft_strncmp(const char *s1, const char *s2, size_t len);
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memset(void *s, int c, size_t n);
char		**ft_split(char const *s, char c);
char		*get_next_line(int fd, char **buffer);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(void *content);
///////////////////////////////////////////
////////////////////////// TEST
void		vec_print(t_vec3d a);
void		color_prints(t_color a);
void		free_obj(t_object *obj);

////////////////////////////////////////////
/////////////////////////// CONE

// int cone_caps(t_pl *pl, t_co *cone, t_cone_utils *co);
double cone_ray_dista(t_ray ray, t_co cone);
int check_cone_hit(t_co *cone, t_hit *p);
int check_cone_caps_intersection(t_co *cone, t_hit *intersection);
void co_inter(t_co *cone, t_hit *f_inter, t_bump *bump, int *style);
// t_object *cone_ob(t_vec3d point, t_vec3d normal, double *d_h, t_color color);
t_object	*cone_ob(t_point_normal *p_n, double *d_h, t_color color, char *path);
int set_co(char **s, t_minirt *rt);
void 	set_style_pl(t_bump *bump, int *style, t_hit *inter, t_pl *pl);
void 	set_style_cy(t_bump *bump, int *style, t_hit *inter, t_cy *cy);
void 	set_style_co(t_bump *bump, int *style, t_hit *inter, t_co *co);
void 	set_style_sp(t_bump *bump, int *style, t_hit *inter, t_sp *sp);

#endif
