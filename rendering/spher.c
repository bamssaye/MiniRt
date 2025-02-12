/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spher.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:52 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/12 06:30:36 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	sp_ray_dista(t_ray ray, t_sphere sp) // calculate_sphere_ray_dista
{
	t_vec3d		ori;

	double (a), (b), (c);
	ori = vec3d_minus(ray.origin, sp.center);
	a = vec3d_dot(ray.direction, ray.direction);
	b = 2.0 * vec3d_dot(ori, ray.direction);
	c = vec3d_dot(ori, ori) - (sp.radius * sp.radius);
	return (quad_equa(a, b, c));
}

t_npc	c_sp_inter(t_ray ray, double dist, t_sphere sp)
{
	t_vec3d	point;
	t_vec3d	normal;

	point = vec3d_scale(dist, ray.direction);
	point = vec3d_plus(ray.origin, point);
	normal = vec3d_minus(point, sp.center);
	normal = vec3d_normalize(normal);
	// p_c(sp.color);
	return ((t_npc){
		.shininess = 0,
		.color = sp.color,
		.dista = dist,
		.normal = normal,
		.point = point});
}

t_color spher_texture_color(t_tex tex, t_vec3d hit_point, t_sphere sp)
{
    // char *pixel;
	
	double (u), (v);
    int (x), (y);
    (void)tex;
	u = 0.5 + atan2(hit_point.z - sp.center.z, hit_point.x - sp.center.x) / (2 * PI);
    v = 0.5 - asin((hit_point.y - sp.center.y) / sp.radius) / PI;
    x = floor(u * 16);
	y = floor(v * 16);
	if ((y + x) % 2 == 0)
		return (t_color){0,0,0,0};
	else
		return (t_color){255, 255, 255,0};

}


void	sp_inter(t_sphere *sp, t_in_pa *intersection)
{
	double	dist;

	dist = sp_ray_dista(*(intersection->ray), *sp);
	if (dist > 0.0)
	{
		intersection->closest = c_sp_inter(*intersection->ray, dist, *sp);
		intersection->inters.shininess = 1.5;
		intersection->hit_clos = 1;
        intersection->closest.color = spher_texture_color(sp->tex, intersection->closest.point, *sp);
		// if (sp->tex.img)
		// 	intersection->closest.color = spher_texture_color(sp->tex, intersection->closest.point, *sp);
		
	}
}
