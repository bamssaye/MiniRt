#include "../headers/minirt.h"

int	calculate_light_intensity_scale(t_obslight *l_param, t_inters_params *p)
{
	l_param->angle = acos(vec3d_dot(&p->inters_normal, &l_param->light_direction));
	if (l_param->angle <= 1.570796)
		l_param->angle_scale = (1.0 - (l_param->angle / 1.570796));
	else
		l_param->angle_scale = 0;
	return (0);
}

void	initialize_light_parameters(t_prog *prog, \
	t_inters_params *param, t_obslight *light_param)
{
	set_default_color(&light_param->light.light_color);
	set_default_color(&light_param->light.ambient_color);
	light_param->angle_scale = 0;
	light_param->angle = 0;
	vec3d_minus(&light_param->light_direction, \
		&prog->light.position, &param->inters_point);
	light_param->max_distance = vec3d_length(&light_param->light_direction);
	vec3d_normalize(&light_param->light_direction);
	light_param->stuck = 0;
	copy_vec3d(&light_param->ray.origin, &param->inters_point);
	copy_vec3d(&light_param->ray.direction, &light_param->light_direction);
	param->ray = &light_param->ray;
}

int	trace_ray_to_light_source(t_prog *prog, \
	t_inters_params *param, t_obslight *light_param)
{
	t_list		*lst;
	t_object	*obj;
	int			temp;

	lst = prog->obj;
	temp = 0;
	light_param->stuck = 0;
	while (lst && !light_param->stuck)
	{
		reset_intersection_focus(param);
		obj = (t_object *)lst->content;
		if (obj->id == param->inters_object_id)
		{
			lst = lst->next;
			continue ;
		}
		temp = check_intersection_with_object(obj, param);
		lst = lst->next;
		if (param->closest_distance <= light_param->max_distance)
			light_param->stuck = 1;
	}
	return (temp);
}

void	trace_light_at_intersection(t_prog *prog, t_inters_params *param)
{
	t_obslight	l_param;

	initialize_light_parameters(prog, param, &l_param);
	if (param == NULL)
	{
		// trace_light_at_intersection: param is NULL
		exit(0);
	}
	trace_ray_to_light_source(prog, param, &l_param);
	if (l_param.stuck == 0)
		calculate_light_intensity_scale(&l_param, param);
	if (prog->has_light)
		color_scale(&l_param.light.light_color, \
		l_param.angle_scale, &param->inters_color);
	color_scale(&l_param.light.ambient_color, \
		prog->ambient_intensity, &param->inters_color);
	color_plus(&param->final_color, \
		&l_param.light.ambient_color, &l_param.light.light_color);
}

int	check_intersection_with_object(t_object *obj, t_inters_params *param)
{
	int	temp;

	temp = 0;
	if (obj->type == SPHERE)
		temp = check_sphere_intersection(obj, param);
	else if (obj->type == PLANE)
		temp = check_plane_intersection(obj, param);
	else if (obj->type == CYLINDER)
		temp = check_cylinder_intersection(obj, param);
	return (temp);
}

int	trace_ray_to_objects(t_prog *prog, t_inters_params *param)
{
	t_list		*lst;
	t_object	*current_object;
	int			hit_detected;

	lst = prog->obj;
	while (lst)
	{
		reset_intersection_focus(param);
		current_object = (t_object *)lst->content;
		if (current_object->type == SPHERE)
			hit_detected = check_sphere_intersection(current_object, param);
		else if (current_object->type == PLANE)
			hit_detected = check_plane_intersection(current_object, param);
		else if (current_object->type == CYLINDER)
			hit_detected = check_cylinder_intersection(current_object, param);
		if (param->is_closest_hit == 1)
			if (param->closest_distance < param->inters_dist)
				set_intersection_info(param, current_object);
		lst = lst->next;
	}
	(void)hit_detected;
	return (1);
}
