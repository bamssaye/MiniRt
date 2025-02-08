#include "../headers/minirt.h"

void	clean_sphere(void *sph)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)sph;
	free(sphere);
}

int	check_sphere_intersection(void *object, t_inters_params *intersection)
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

int	calculate_sphere_intersection_normal(t_vec3d *normal, \
	t_vec3d *inters, t_vec3d *center)
{
	vec3d_minus(normal, inters, center);
	if (vec3d_normalize(normal))
	{
		// sphere intersection_normal: normal is zero vector
		return (1);
	}
	return (0);
}

int	setup_sphere_from_input(char **splited_str, t_prog *prog)
{
	t_sphere	*sphere;
	t_object	*object;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (1);
	initialize_vector_from_string(splited_str[1], &sphere->center);
	ft_strtod(splited_str[2], &sphere->radius);
	color_collect_string(splited_str[3], &sphere->color);
	object = create_object_sphere(sphere);
	if (!object)
		return (1);
	prog->object_count++;
	object->id = prog->object_count;
	ft_lstadd_back(&prog->obj, ft_lstnew(object));
	return (0);
}

t_object	*create_object_sphere(t_sphere *sp)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	if (!object)
		return (0);
	object->type = SPHERE;
	object->object = sp;
	object->clean = clean_sphere;
	object->test_intersection = check_sphere_intersection;
	return (object);
}
