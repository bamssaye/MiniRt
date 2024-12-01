/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:30 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/01 05:39:46 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"



void ft_init(t_minirt *mrt)
{
	ft_memset(mrt->amc, 0, sizeof(mrt->amc));
}
int	main(int ac, char **av)
{
	//t_prog			prog;
	t_minirt minirt;

	(void) ac;
	//ft_init(&minirt);
	ft_readfile(av[1], &minirt);
	printf("Ambient : {%f}, [%d,%d,%d]\n", minirt.am_light.al, minirt.am_light.al_rgb.r, minirt.am_light.al_rgb.g, minirt.am_light.al_rgb.b);
	printf("Camera : {%d}, c_xyz[%f,%f,%f], c_xyz[%f,%f,%f]\n", minirt.camera.fov,minirt.camera.c_xyz.x,minirt.camera.c_xyz.y,minirt.camera.c_xyz.z, minirt.camera.vec_xyz.x, minirt.camera.vec_xyz.y, minirt.camera.vec_xyz.z);
	printf("Light : {%f}, light_xyz[%f,%f,%f], light_rgb[%d,%d,%d]\n", minirt.light.light_bri,minirt.light.light_xyz.x, minirt.light.light_xyz.y,minirt.light.light_xyz.z,minirt.light.light_rgb.r,minirt.light.light_rgb.g,minirt.light.light_rgb.b);

	return (0);
}
