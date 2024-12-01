#include "../headers/minirt.h"

int	check_cylinder_hit(t_cylinder *cy, t_inters_params *p)
{
	double	dist;
	t_vec3d	point_to_center;

	dist = calculate_cylinder_distance(p->ray, cy);
	if (dist > 0.0)
	{
		cy_intersection_point(&p->closest_point, p->ray, dist);
		calculate_cylinder_intersection_normal(&p->closest_normal, &p->closest_point, &cy->point);
		vec3d_minus(&point_to_center, &p->closest_point, &cy->point);
		if (fabs(vec3d_dot(&point_to_center, &cy->normal)) < cy->len / 2.0)
		{
			p->closest_distance = dist;
			p->is_closest_hit = 1;
			ft_memcpy(&p->closest_color, &cy->color, sizeof(t_color));
			return (1);
		}
	}
	return (0);
}

int	set_inters_from_tempIntersection(t_inters_params *finalIntersection,\
	 t_inters_params *tempIntersection)
{
	finalIntersection->closest_distance = tempIntersection->closest_distance;
	finalIntersection->is_closest_hit = tempIntersection->is_closest_hit;
	ft_memcpy(&finalIntersection->closest_color, \
		&tempIntersection->closest_color, sizeof(t_color));
	ft_memcpy(&finalIntersection->closest_point, \
		&tempIntersection->closest_point, sizeof(t_vec3d));
	ft_memcpy(&finalIntersection->closest_normal, \
		&tempIntersection->closest_normal, sizeof(t_vec3d));
	return (0);
}

int	check_cylinder_caps_intersection(t_cylinder *cy, t_inters_params *intersection)
{
	t_vec3d	point_to_center;
	t_plane	pl[2];
	int		i;

	i = 0;
	create_cylinder_caps_planes(pl, cy);
	while (i < 2)
	{
		if (calculate_plane_intersection(&pl[i], intersection))
		{
			vec3d_minus(&point_to_center, &intersection->closest_point, &pl[i].point);
			if (vec3d_length(&point_to_center) < cy->radius)
			{
				intersection->closest_distance = intersection->closest_distance;
				intersection->is_closest_hit = 1;
				ft_memcpy(&intersection->closest_color, &cy->color, sizeof(t_color));
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	calculate_cylinder_intersection_normal(t_vec3d *norm, t_vec3d *inters, t_vec3d *cent)
{
	vec3d_minus(norm, inters, cent);
	if (vec3d_normalize(norm))
	{
		// cyhere intersection_normal: normal is zero vector
		return (1);
	}
	return (0);
}
