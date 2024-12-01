#include "../headers/minirt.h"

int	almost_equal(double a, double b)
{
	return (fabs(a - b) < EPSILON);
}

double	calculate_plane_ray_intersection_distance(t_ray *ray, t_plane *pl, int *hit, t_inters_params *param)
{
	double		dist;
	double		dot;
	t_vec3d		inters_point;

	(void)hit;
	dist = -1;
	dot = vec3d_dot(&pl->normal, &ray->direction);
	if (almost_equal(dot, 0))
		return (0);
	vec3d_minus(&inters_point, &pl->point, &ray->origin);
	dist = vec3d_dot(&inters_point, &pl->normal) / dot;
	if (dist <= 0)
		return (0);
	ft_memcpy(&param->closest_normal, &pl->normal, sizeof(t_vec3d));
	if (dot > 0)
	{
		param->closest_normal.x = -param->closest_normal.x;
		param->closest_normal.y = -param->closest_normal.y;
		param->closest_normal.z = -param->closest_normal.z;
	}
	return (dist);
}

int	calculate_sphere_intersection_point(t_vec3d *inters, t_ray *ray, double dist)
{
	vec3d_scale(inters, dist, &ray->direction);
	vec3d_plus(inters, &ray->origin, inters);
	if (vec3d_length(inters) == 0.0)
	{
		// sphere intersection_point: inters is zero vector
		return (1);
	}
	return (0);
}

double	calculate_sphere_ray_distance(t_ray *ray, t_sphere *sp)
{
	double	a;
	double	b;
	double	c;
	t_vec3d	origin_to_center;

	vec3d_minus(&origin_to_center, &ray->origin, &sp->center);
	a = vec3d_dot(&ray->direction, &ray->direction);
	b = 2.0 * vec3d_dot(&origin_to_center, &ray->direction);
	c = vec3d_dot(&origin_to_center, &origin_to_center) - (sp->radius * sp->radius);
	return (solve_quadratic_equation(a, b, c));
}
