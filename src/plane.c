#include "../headers/minirt.h"

void	clean_plane(void *pl)
{
	t_plane	*plane;

	plane = (t_plane *)pl;
	free(plane);
}

int	check_plane_intersection(void *object, t_inters_params *param)
{
	t_plane		*plane;
	t_object	*obj;

	obj = (t_object *)object;
	plane = (t_plane *)obj->object;
	return (calculate_plane_intersection(plane, param));
}

int	calculate_plane_intersection(t_plane *plane, t_inters_params *param)
{
	double	dist;
	t_vec3d	*ray;

	ray = &param->ray->direction;
	dist = calculate_plane_ray_intersection_distance(param->ray, plane, &param->is_closest_hit, param);
	if (dist > 0)
	{
		param->closest_color = plane->color;
		param->closest_distance = dist;
		param->closest_point.x = param->ray->origin.x + dist * ray->x;
		param->closest_point.y = param->ray->origin.y + dist * ray->y;
		param->closest_point.z = param->ray->origin.z + dist * ray->z;
		ft_memcpy(&param->closest_normal, &plane->normal, sizeof(t_vec3d));
		param->is_closest_hit = 1;
	}
	return (param->is_closest_hit);
}

int	setup_plane_from_input(char **str, t_prog *prog)
{
	t_plane		*plane;
	t_object	*object;

	plane = malloc(sizeof(t_plane));
	if (plane == NULL)
		return (1);
	initialize_vector_from_string(str[1], &plane->point);
	initialize_vector_from_string(str[2], &plane->normal);
	color_collect_string(str[3], &plane->color);
	object = create_object_plane(plane);
	if (object == NULL)
		return (1);
	prog->object_count++;
	object->id = prog->object_count;
	ft_lstadd_back(&prog->obj, ft_lstnew(object));
	return (0);
}

t_object	*create_object_plane(t_plane *plane)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	if (object == NULL)
		return (0);
	object->type = PLANE;
	object->object = plane;
	object->clean = clean_plane;
	object->test_intersection = check_plane_intersection;
	return (object);
}
