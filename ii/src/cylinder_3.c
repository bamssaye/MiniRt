#include "../headers/minirt.h"

double	calculate_cylinder_distance(t_ray *ray, t_cylinder *cy)
{
	double	a;
	double	b;
	double	c;
	t_vec3d	cam2obj;

	vec3d_minus(&cam2obj, &ray->origin, &cy->point);
	a = vec3d_dot(&ray->direction, &ray->direction) - \
		pow(vec3d_dot(&ray->direction, &cy->normal), 2);
	b = 2.0 * (vec3d_dot(&cam2obj, &ray->direction) - \
		vec3d_dot(&ray->direction, &cy->normal) * \
		vec3d_dot(&cam2obj, &cy->normal));
	c = vec3d_dot(&cam2obj, &cam2obj) - \
	pow(vec3d_dot(&cam2obj, &cy->normal), 2) - (cy->radius * cy->radius);
	return (solve_quadratic_equation(a, b, c));
}

int	create_cylinder_caps_planes(t_plane *pl, t_cylinder *cy)
{
	t_vec3d		offset;
	t_vec3d		cap_center;

	// Create top cap plane
	vec3d_scale(&offset, cy->len / 2.0, &cy->normal);
	vec3d_plus(&cap_center, &cy->point, &offset);
	ft_memcpy(&pl[0].color, &cy->color, sizeof(t_color));
	ft_memcpy(&pl[0].point, &cap_center, sizeof(t_vec3d));
	ft_memcpy(&pl[0].normal, &cy->normal, sizeof(t_vec3d));
	// Create bottom cap plane
	vec3d_scale(&offset, -cy->len / 2.0, &cy->normal);
	vec3d_plus(&cap_center, &cy->point, &offset);
	ft_memcpy(&pl[1].color, &cy->color, sizeof(t_color));
	ft_memcpy(&pl[1].point, &cap_center, sizeof(t_vec3d));
	// Invert normal for the bottom cap
	vec3d_scale(&offset, -1, &cy->normal);
	ft_memcpy(&pl[1].normal, &offset, sizeof(t_vec3d));
	return (0);
}

int	cy_intersection_point(t_vec3d *inters, t_ray *ray, double dist)
{
	vec3d_scale(inters, dist, &ray->direction);
	vec3d_plus(inters, &ray->origin, inters);
	if (vec3d_length(inters) == 0.0)
	{
		// cy here intersection_point: inters is zero vector
		return (1);
	}
	return (0);
}
