/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:33:08 by bamssaye          #+#    #+#             */
/*   Updated: 2025/03/01 03:30:49 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_color	pl_texture(t_tex *tex, t_vec3d *hpoint, t_pl *pl);
t_color	sp_texture(t_tex *tex, t_vec3d *hpoint, t_sp *sp);
t_color	cy_texture(t_tex *tex, t_vec3d *hpoint, t_cy *cy);

t_color	sp_texture(t_tex *tex, t_vec3d *hpoint, t_sp *sp)
{
	char	*pixel;
	t_vec3d local;

	double (u), (v);
	int (x), (y);
	local = v_minus(*hpoint, sp->center);
	u = (-(atan2(local.z, local.x)) + PI) / (2.0 * PI);
	v = acos(local.y / sp->radius) / PI;
	x = (int)(u * tex->width) % tex->width;
	y = (int)(v * tex->height) % tex->height;
	pixel = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
	return ((t_color){
		(unsigned char)pixel[2],
		(unsigned char)pixel[1],
		(unsigned char)pixel[0],
		0});
}
 
/*
right 
up 
*/
t_vec3d hight_right_up(t_vec3d normal, t_vec3d local, int pl, double height)
{
	t_vec3d right;
	t_vec3d up;

	double (hight), (x), (y);
    right = v_perpendicular(normal);
    up = v_cross(normal, right);
    x = v_dot(local, right);
    y = v_dot(local, up);
	hight = v_dot(local, normal);
	if (pl)
		return ((t_vec3d){.x = x, .y = y});
	return ((t_vec3d){
		.x = atan2(x , y),
		.y = hight,
		.z = v_dot(local, right)
	});
}


t_color	pl_texture(t_tex *tex, t_vec3d *hpoint, t_pl *pl)
{
	char	*pixel;
	t_vec3d	local;
	t_vec3d u_v;

	int (x), (y);
	double (u), (v);
	local = v_minus(*hpoint, pl->point);
	u_v = hight_right_up(pl->normal, local, 1, 1);
	
	u = fmod(fabs(u_v.x * 0.005), 1.0);
    v = fmod(fabs(u_v.y * 0.005) , 1.0);
	x = (int)(u * tex->width) % tex->width;
	y = (int)(v * tex->height) % tex->height;
	pixel = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
	return ((t_color){
		(unsigned char)pixel[2],
		(unsigned char)pixel[1],
		(unsigned char)pixel[0],
		0});
}

t_color	cy_texture(t_tex *tex, t_vec3d *hpoint, t_cy *cy)
{
	char	*pixel;
	t_vec3d	local;
	t_vec3d u_v;

	double (u), (v);
	int (x), (y);
	local = v_minus(*hpoint, cy->point);
	u_v = hight_right_up(cy->normal, local, 0, cy->len);
	u = 0.5 + u_v.x / (2 * PI);
    v = fmod(u_v.y / cy->len + 1.0, 1.0);
	x = (int)(u * tex->width);
	y = (int)(v * tex->height);
	pixel = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
	return ((t_color){
		(unsigned char)pixel[2],
		(unsigned char)pixel[1],
		(unsigned char)pixel[0],
		0});
}

t_color	co_texture(t_tex *tex, t_vec3d *hpoint, t_co *co)
{
	char	*pixel;
	t_vec3d	local, u_v;

	double (u), (v);
	int (x), (y);
	local = v_minus(*hpoint, co->point);
	u_v = hight_right_up(co->normal, local, 0, co->height);
	u = 0.5 + u_v.x / (2 * PI);
	v = fmod(u_v.y / co->height + 1, 1.0);
	x = (int)(u * tex->width);
	y = (int)(v * tex->height);
	pixel = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
	printf("[%d]\n", (unsigned char)pixel[2]);
	// exit(1);
	return ((t_color){
		(unsigned char)pixel[2],
		(unsigned char)pixel[1],
		(unsigned char)pixel[0],
		0});
}
