/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:13:45 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/23 12:22:43 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "struct.h"

//////////////////////// PARSINING
// t_plane		*plane_ob(t_vec3d p_xyz, t_vec3d v_xyz, t_color rgb);
// t_sphere	*sphere_ob(t_vec3d xyz, t_color rgb, double dia);
// t_cylinder	*cylinder_ob(t_vec3d cxyz, t_vec3d vxyz, double *d_h, t_color rgb);
t_color		check_color(char *str);
t_vec3d		check_xyz(char *str, double min, double max);
t_atof		ft_atof(char *nptr);
t_atoi		ft_atoii(const char *nptr);
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
///////////////////////
t_object	*sphere_ob(t_vec3d xyz, t_color rgb, double dia);
t_object	*plane_ob(t_vec3d p_xyz, t_vec3d v_xyz, t_color rgb);
t_object	*cylinder_ob(t_vec3d cxyz, t_vec3d vxyz, double *d_h, t_color rgb);
int	color_collect_string(char *color_string, t_color *color);
int	rgb_to_int(int r, int g, int b);
int	convert_color_to_int(t_color *color);
int	color_scale(t_color *res, double scale, t_color *a);
int	rgb_to_int(int r, int g, int b);
int	color_plus(t_color *res, t_color *a, t_color *b);
void	set_default_color(t_color *color);
t_vec3d	vec3d_scale(double scale, t_vec3d a);
double	vec3d_length(t_vec3d a);
t_vec3d	vec3d_cross(t_vec3d a, t_vec3d b);
t_vec3d	vec3d_plus(t_vec3d a, t_vec3d b);
t_vec3d	vec3d_minus(t_vec3d a, t_vec3d b);
t_vec3d	vec3d_normalize(t_vec3d a);
double	vec3d_dot(t_vec3d a, t_vec3d b);
int	sp_inter(void *object, t_inter_p *intersection);
int	is_parallel(t_vec3d v1, t_vec3d v2);
t_vec3d	c_look_at(t_camera *camera);
t_vec3d	c_topleft(t_camera *cam);
t_vec3d	c_up_v(t_camera *camera);
t_vec3d	c_r_v(t_camera *camera);
///////////////////////////////////////////
///////Printf to test?/??
void		printf_sphere(t_sphere *sph);
void		printf_plane(t_plane *sph);
void		printf_cylinder(t_cylinder *sph);
void		all_printf(t_cylinder *cyl, t_plane *plane, t_sphere *sph,
				t_minirt *minirt);
//////////////////////////////
t_vec3d	vc3d_normalize(t_vec3d a);
void camera_init(t_camera *cm);
///////////////////////////////////////////////Drawing
void	ft_init_win(t_minirt *mrt);
void	ft_hooks_fun(t_minirt *mrt);
int		ft_clear_all(t_minirt *mrt);
void	mlx_putpixel(t_image *data, int x, int y, int color);
/////////
// double minor(t_mx4 a, int rw, int cl);
// double det_2xa2(double mx[4][4]);
// t_mx4  identity_mx();
// t_mx4 submatrix(t_mx4 a, int rw, int col); 
// double cofactor(t_mx4 a, int rw, int cl);
// t_mx4 new_mx(double m[4][4] , int s);
// double determinant(t_mx4 a);
// t_mx4 inverse(t_mx4 a);
// t_mx4 multi_mx(t_mx4 a, t_mx4 b);
// int equal(double a, double b);
// int comparing_mtx(t_mx4 a, t_mx4 b);
// t_mx4 translation(double x, double y, double z);
// t_mx4 scaling(double x, double y, double z);
// t_mx4 rotation_x(double r);
// t_mx4 rotation_y(double r);
// t_mx4 rotation_z(double r);
// t_mx4 shearing(t_vec3d x, t_vec3d y, t_vec3d z);
///////////
// void tuple_type(t_vec3d *tuple, int type);
// t_vec3d adding(t_vec3d a, t_vec3d b);
// double dot_prod(t_vec3d a, t_vec3d b);
// t_vec3d corss_prod(t_vec3d a, t_vec3d b);
// t_vec3d subtracting(t_vec3d a, t_vec3d b);
// t_vec3d subtracting(t_vec3d a, t_vec3d b);
// t_vec3d negating(t_vec3d a);
// double magnitude(t_vec3d a) ;
// t_vec3d multiply(t_vec3d a, double b);
// t_vec3d divide(t_vec3d a, double b);
// t_vec3d position(t_ray r, double t);
// t_material material();
// t_ray g_ray(t_vec3d origin, t_vec3d direction);

////////////////
#endif
