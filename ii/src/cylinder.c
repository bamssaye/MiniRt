#include "../headers/minirt.h"

void	clean_cylinder(void *object)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)object;
	free(cylinder);
}

int	check_cylinder_intersection(void *object, t_inters_params *finalIntersection)
{
	t_cylinder		*cy;
	t_object		*obj;
	t_ray			ray[3];
	t_inters_params	tempIntersection[3];

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

void	create_tempIntersection_inters(t_ray *ray, t_inters_params *tempIntersection,\
		t_inters_params *finalIntersection)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		ft_memcpy(&tempIntersection[i], finalIntersection, sizeof(t_inters_params));
		ft_memcpy(&ray[i], finalIntersection->ray, sizeof(t_ray));
		tempIntersection[i].ray = &ray[i];
		i++;
	}
}

int	setup_cylinder_from_input(char **str, t_prog *prog)
{
	t_cylinder	*cylinder;
	t_object	*object;

	cylinder = malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
		return (1);
	initialize_vector_from_string(str[1], &cylinder->point);
	initialize_vector_from_string(str[2], &cylinder->normal);
	ft_strtod(str[3], &cylinder->radius);
	ft_strtod(str[4], &cylinder->len);
	color_collect_string(str[5], &cylinder->color);
	object = create_cylinder_object(cylinder);
	if (object == NULL)
		return (1);
	prog->object_count++;
	object->id = prog->object_count;
	ft_lstadd_back(&prog->obj, ft_lstnew(object));
	return (0);
}

int	cylinder_intersection(void *obj, t_inters_params *param)
{
	(void)obj;
	(void)param;
	printf("this oject has no cylinder_intersection function\n");
	exit(1);
}

t_object	*create_cylinder_object(t_cylinder *cylinder)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	if (object == NULL)
		return (0);
	object->type = CYLINDER;
	object->object = cylinder;
	object->clean = clean_cylinder;
	object->test_intersection = cylinder_intersection;
	return (object);
}
