/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:48:24 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/05 04:53:34 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"


void sphere(t_sphere *sph){
	fprintf(stderr, "{%f, %f, %f} -- %f -- [%d, %d, %d]\n",
		sph->sph_xyz[0].x, sph->sph_xyz[0].y, sph->sph_xyz[0].z,
        sph->sph_dia[0],
		sph->sph_rgb[0].r, sph->sph_rgb[0].g, sph->sph_rgb[0].b);
}
void plane(t_plane *sph){
	fprintf(stderr, " pl {%f, %f, %f} -- vec ; {%f, %f, %f} -- [%d, %d, %d]\n",
		sph->pl_xyz[0].x, sph->pl_xyz[0].y, sph->pl_xyz[0].z,
        sph->vec_xyz[0].x, sph->vec_xyz[0].y, sph->vec_xyz[0].z,
		sph->pl_rgb[0].r, sph->pl_rgb[0].g, sph->pl_rgb[0].b);
}
void cylinder(t_cylinder *sph){
	fprintf(stderr, "cyl{%f, %f, %f}--vec{%f, %f, %f}--{%f},{%f}--[%d, %d, %d]\n",
		sph->cy_xyz[0].x, sph->cy_xyz[0].y, sph->cy_xyz[0].z,
		sph->vec_xyz[0].x, sph->vec_xyz[0].y, sph->vec_xyz[0].z,
        sph->c_dia[0], sph->c_hei[0],
		sph->sy_rgb[0].r, sph->sy_rgb[0].g, sph->sy_rgb[0].b);
}
// void fprintcla(t_minirt *minirt){
//     printf("Ambient : {%f}, [%d,%d,%d]\n", minirt->am_light.al, minirt->am_light.al_rgb.r, minirt->am_light.al_rgb.g, minirt->am_light.al_rgb.b);
// 	printf("Camera : {%d}, c_xyz[%f,%f,%f], c_xyz[%f,%f,%f]\n", minirt->camera.fov,minirt->camera.c_xyz.x,minirt->camera.c_xyz.y,minirt->camera.c_xyz.z, minirt->camera.vec_xyz.x, minirt->camera.vec_xyz.y, minirt->camera.vec_xyz.z);
// 	printf("Light : {%f}, light_xyz[%f,%f,%f], light_rgb[%d,%d,%d]\n", minirt->light.light_bri,minirt->light.light_xyz.x, minirt->light.light_xyz.y,minirt->light.light_xyz.z,minirt->light.light_rgb.r,minirt->am_light->light_rgb.g,minirt->light.light_rgb.b);
// }