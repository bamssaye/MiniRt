/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spher.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:55:45 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/23 12:18:10 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vec3d	cal_spi_point(t_ray *ray, double dist) //calculate_sphere_intersection_point
{
	t_vec3d inters;
    
    inters = vec3d_scale(dist, ray->direction);
	inters = vec3d_plus(ray->origin, inters);
	if (vec3d_length(inters) == 0.0)
        return ((t_vec3d){1,1,1,-1});
	return (inters);
}
double	quadratic_eq(double a, double b, double c) //solve_quadratic_equation
{
	double	discriminant;
	double	t1;
	double	t2;
	double	sqrtDiscriminant;

	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0.0)
		return (-1);
	sqrtDiscriminant = sqrt(discriminant);
	if (discriminant > 0.0)
	{
		t1 = (-b + sqrtDiscriminant) / (2.0 * a);
		t2 = (-b - sqrtDiscriminant) / (2.0 * a);
		if (t1 < 0.0 || t2 < 0.0)
			return (-1);
		if (t1 < t2)
			return (t1);
		else
			return (t2);
	}
	return (-1);
}

double	cal_sray_dist(t_ray *ray, t_sphere *sp) //calculate_sphere_ray_distance
{
	double	a;
	double	b;
	double	c;
	t_vec3d	origin_to_center;

	origin_to_center = vec3d_minus(ray->origin, sp->center);
	a = vec3d_dot(ray->direction, ray->direction);
	b = 2.0 * vec3d_dot(origin_to_center, ray->direction);
	c = vec3d_dot(origin_to_center, origin_to_center) - (sp->radius * sp->radius);
	return (quadratic_eq(a, b, c));
}

t_vec3d	cal_spi_normal(t_vec3d inters, t_vec3d center) //calculate_sphere_intersection_normal
{
	t_vec3d normal;
    
    normal = vec3d_minus(inters, center);
    normal = vec3d_normalize(normal);
    // if (normal.isv)
    //     return ((t_vec3d){1,1,1,-1});
	return (normal);
}

int	sp_inter(void *object, t_inter_p *intersection)
{
	double		dist;
	t_sphere	*sp;
	t_object	*obj;

	obj = (t_object *)object;
	sp = (t_sphere *)obj->object;
	dist = cal_sray_dist(intersection->ray, sp);
	if (dist > 0.0)
	{
		intersection->closest_distance = dist;
		intersection->is_closest_hit = 1;
        intersection->closest_point = cal_spi_point(intersection->ray, dist);
		intersection->closest_normal = cal_spi_normal(intersection->closest_point, sp->center);
		ft_memcpy(&intersection->closest_color, &sp->color, sizeof(t_color));
	}
	return (intersection->is_closest_hit);
}