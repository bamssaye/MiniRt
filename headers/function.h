/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:13:45 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/17 06:14:35 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "struct.h"

//////////////////////// PARSINING
t_plane		*plane_ob(t_xyz p_xyz, t_xyz v_xyz, t_rgb rgb);
t_sphere	*sphere_ob(t_xyz xyz, t_rgb rgb, double dia);
t_cylinder	*cylinder_ob(t_xyz cxyz, t_xyz vxyz, double *d_h, t_rgb rgb);
t_rgb		check_color(char *str);
t_xyz		check_xyz(char *str, double min, double max);
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
///////Printf to test?/??
void		printf_sphere(t_sphere *sph);
void		printf_plane(t_plane *sph);
void		printf_cylinder(t_cylinder *sph);
void		all_printf(t_cylinder *cyl, t_plane *plane, t_sphere *sph,
				t_minirt *minirt);
//////////////////////////////
t_xyz	vc3d_normalize(t_xyz a);
void camera_init(t_camera *cm);
///////////////////////////////////////////////
#endif
