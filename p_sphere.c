#include "minirt.h"

int	collect_sphere(char **splited_str, t_prog *prog)
{
	t_sphere	*sphere;
	t_object	*object;

	sphere = malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return (1);
	convert_3d(splited_str[1], &sphere->center);
	ft_strtod(splited_str[2], &sphere->radius);
	color_collect_string(splited_str[3], &sphere->color);
	object = create_object_sphere(sphere);
	if (object == NULL)
		return (1);
	prog->item_count++;
	object->id = prog->item_count;
	ft_lstadd_back(&prog->obj, ft_lstnew(object));
	return (0);
}

t_object	*create_object_sphere(t_sphere *sp)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	if (object == NULL)
		return (0);
	object->type = SPHERE;
	object->object = sp;
	object->clean = clean_sphere;
	object->test_intersection = sp_test_intersection;
	return (object);
}

void	clean_sphere(void *sph)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)sph;
	free(sphere);
}

int	sp_test_intersection(void *object, t_interparam *p)
{
	double		dist;
	t_sphere	*sp;
	t_object	*obj;

	obj = (t_object *)object;
	sp = (t_sphere *)obj->object;
	dist = sp_cale_dist(p->ray, sp);
	if (dist > 0.0)
	{
		p->f_dist = dist;
		p->f_ishit = 1;
		sp_intersection_point(&p->f_point, p->ray, dist);
		sp_intersection_normal(&p->f_normal, &p->f_point, &sp->center);
		ft_memcpy(&p->f_color, &sp->color, sizeof(t_color));
	}
	return (p->f_ishit);
}

int	sp_intersection_normal(t_vec3d *normal, \
	t_vec3d *inters, t_vec3d *center)
{
	vec3d_minus(normal, inters, center);
	if (vec3d_normalize(normal))
	{
		//sphere intersection_normal: normal is zero vector
		return (1);
	}
	return (0);
}