/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:18:36 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/23 11:56:02 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	sp_inter(void *object, t_inter_p *inter);
int	pl_inter(void *object, t_inter_p *param);
int	cy_inter(void *object, t_inter_p *param);
void	clean_plane(void *pl);
void	clean_sphere(void *sph);
void	clean_cylinder(void *object);

void	clean_plane(void *pl)
{
	t_plane	*plane;

	plane = (t_plane *)pl;
	free(plane);
}
void	clean_sphere(void *sph)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)sph;
	free(sphere);
}
void	clean_cylinder(void *object)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)object;
	free(cylinder);
}

int	sp_inter(void *object, t_inter_p *intersection)
{
	double		dist;
	t_sphere	*sp;
	t_object	*obj;

	obj = (t_object *)object;
	sp = (t_sphere *)obj->object;
	dist = calculate_sphere_ray_distance(intersection->ray, sp);
	if (dist > 0.0)
	{
		intersection->closest_distance = dist;
		intersection->is_closest_hit = 1;
		calculate_sphere_intersection_point(&intersection->closest_point, \
			intersection->ray, dist);
		calculate_sphere_intersection_normal(&intersection->closest_normal, \
			&intersection->closest_point, &sp->center);
		ft_memcpy(&intersection->closest_color, &sp->color, sizeof(t_color));
	}
	return (intersection->is_closest_hit);
}

int	pl_inter(void *object, t_inter_p *param)
{
	t_plane		*plane;
	t_object	*obj;

	obj = (t_object *)object;
	plane = (t_plane *)obj->object;
	return (calculate_plane_intersection(plane, param));
}
int	cy_inter(void *object, t_inter_p *finalIntersection)
{
	t_cylinder		*cy;
	t_object		*obj;
	t_ray			ray[3];
	t_inter_p	tempIntersection[3];

	obj = (t_object *)object;
	cy = (t_cylinder *)obj->object;
	create_tempIntersection_inters(ray, tempIntersection, finalIntersection);
	if (check_cylinder_hit(cy, &tempIntersection[0]))
	{
		set_inters_from_tempIntersection(finalIntersection, &tempIntersection[0]);
		return (1);
	}
	if (check_cylinder_caps_intersection(cy, &tempIntersection[1]))
	{
		set_inters_from_tempIntersection(finalIntersection, &tempIntersection[1]);
		return (1);
	}
	return (0);
}