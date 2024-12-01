/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_c_am_li.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:11:59 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/01 05:42:42 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int set_ambient(char **s, t_minirt *aml)
{
	t_rgb rgb;
	double al;
	
	if (aml->amc[0])
		return (printf("ERROT EXITS.. \n"), exit(1), 1);
	al = ft_atof(s[1]);
	if (!ft_range(al, 0.0, 1.0))
		return (printf("ERROR\n"), exit(1), 1);
	rgb = check_color(s[2]);
	aml->amc[0] = 1;
    aml->am_light.al = al;
    aml->am_light.al_rgb = rgb;
	return(0);
}

int set_camera(char **s, t_minirt *aml)
{
	t_xyz c_xyz;
	t_xyz vec_xyz;	
	int fov;
	
	if (aml->amc[1])
		return (printf("ERROT EXITS.. \n"), exit(1), 1);
	fov = ft_atoii(s[3]);
	if (!ft_range(fov, 0, 180))
		return (printf("ERROR\n"), exit(1), 1);
	c_xyz = check_xyz(s[1], -IN_MIN, IN_MAX);
	vec_xyz = check_xyz(s[2], -1.0, 1.0);
	aml->amc[1] = 1;
	aml->camera.c_xyz = c_xyz;
	aml->camera.vec_xyz = vec_xyz;
	aml->camera.fov = fov;
	return(0);
}

int set_light(char **s, t_minirt *aml)
{
	t_xyz	light_xyz;
	double	light_bri;
	t_rgb   light_rgb;
	
	if (aml->amc[2])
		return (printf("ERROT EXITS.. \n"), exit(1), 1);
	light_bri = ft_atof(s[2]);
	if (!ft_range(light_bri, 0.0, 1.0))
		return (printf("ERROR\n"), exit(1), 1);
	light_rgb = check_color(s[3]);
	light_xyz = check_xyz(s[1], -IN_MIN, IN_MAX);
	aml->amc[2] = 1;
	aml->light.light_bri = light_bri;
	aml->light.light_rgb = light_rgb;
	aml->light.light_xyz = light_xyz;
	return(0);
}
