/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:13:45 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/17 13:27:34 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H


///////////////////////////////////////////
void p_c(t_color a);
/////////////////////////////// PARSINING
t_color		check_color(char *str);
t_vec3d		check_xyz(char *str, double min, double max);
char		**tospace(char *str);
void		arry_c(char **str);
void		free_cmd(t_list *cmd);
int			ft_readfile(char *path, t_minirt *mrt);
int			set_ambient(char **s, t_minirt *aml);
int			set_camera(char **s, t_minirt *aml);
int			set_light(char **s, t_minirt *aml);
int			set_sphere(char **s, t_minirt *aml);
int			set_plane(char **s, t_minirt *aml);
int			set_cylinder(char **s, t_minirt *aml);
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
t_color		color_scale(double scale, t_color a);
int			min(int a, int min);
t_color		color_plus(t_color a, t_color b);
int			ctoi(t_color color);
t_color color_a(t_color a, t_color b);
///////////////////////////////////////////
////////////////////////// SPHER
double		sp_ray_dista(t_ray ray, t_sphere sp);
t_npc		c_sp_inter(t_ray ray, double dist, t_sphere sp);
void		sp_inter(t_sphere *sp, t_in_pa *intersection);
t_object	*sphere_ob(t_vec3d xyz, t_color rgb, double dia, char *path);

///////////////////////////////////////////
////////////////////////// PLANE
double		pl_ray_dista(t_ray ray, t_plane pl, t_npc *closest);
t_npc		pl_closest(t_vec3d ray, t_plane pl, double dist, t_vec3d origin);
int			plane_inter(t_plane *plane, t_in_pa *param);
t_object	*plane_ob(t_vec3d p_xyz, t_vec3d v_xyz, t_color rgb, char *path);

///////////////////////////////////////////
////////////////////////// CYLINDER
double		cy_ray_dista(t_ray ray, t_cylinder cy);
t_plane		copy_pl(t_vec3d po, t_vec3d no, t_color col, t_vec3d offset);
// void		cy_caps(t_plane *pl, t_cylinder *cy);
void		cy_caps(t_plane *pl, t_cylinder *cy, int is_top);
int			check_cylinder_hit(t_cylinder *cy, t_in_pa *p);
int			check_cylinder_caps_intersection(t_cylinder *cy,
				t_in_pa *intersection);
void		cy_inter(t_cylinder *cy, t_in_pa *f_inter);
t_object	*cylinder_ob(t_vec3d cxyz, t_vec3d vxyz, double *d_h, t_color rgb);

///////////////////////////////////////////
////////////////////////// VECTOR
t_vec3d		vec3d_scale(double scale, t_vec3d a);
double		vec3d_length(t_vec3d a);
t_vec3d		vec3d_cross(t_vec3d a, t_vec3d b);
t_vec3d		vec3d_plus(t_vec3d a, t_vec3d b);
t_vec3d		vec3d_minus(t_vec3d a, t_vec3d b);
t_vec3d		vec3d_normalize(t_vec3d a);
double		vec3d_dot(t_vec3d a, t_vec3d b);
///////////////////////////////////////////
////////////////////////// RAY TRACING
t_ray		ray_gen(t_camera cam, int x, int y);
void		inter_wobject(t_object *obj, t_in_pa *param, t_minirt *aml);
void		trace_ray(t_list *obj, t_in_pa *pa, int *stuck, double mx_dist, t_minirt *aml);
void		trace_rtobj(t_list *obj, t_in_pa *pa, t_minirt *aml);
t_obslight	initlight_inter(t_light l_param, t_in_pa *pa);
void		trace_light_at_intersection(t_minirt *prog, t_in_pa *param);
int			calculate_pixel_color(t_ray *ray, t_minirt *prog);
double		c_light_scale(t_vec3d a, t_vec3d b);
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

void cone_caps(t_plane *pl, t_cone *cone);
double cone_ray_dista(t_ray ray, t_cone cone);
int check_cone_hit(t_cone *cone, t_in_pa *p);
int check_cone_caps_intersection(t_cone *cone, t_in_pa *intersection);
void co_inter(t_cone *cone, t_in_pa *f_inter);
t_object *cone_ob(t_vec3d point, t_vec3d normal, double *d_h, t_color color);
int set_cone(char **s, t_minirt *aml);

#endif
