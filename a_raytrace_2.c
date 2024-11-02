#include "minirt.h"

void	trace_light(t_prog *prog, t_interparam *param)
{
	t_obslight	l_param;

	init_inters_light_param(prog, param, &l_param);
	if (param == NULL)
	{
		printf("trace_light: param is NULL\n");
		exit(0);
	}
	color_scale(&l_param.light.ambient_color, \
		prog->ambient_intensity, &param->inters_color);
	color_plus(&param->final_color, \
		&l_param.light.ambient_color, &l_param.light.light_color);
}

void	init_inters_light_param(t_prog *prog, \
	t_interparam *param, t_obslight *light_param)
{
	color_set_defval(&light_param->light.light_color);
	color_set_defval(&light_param->light.ambient_color);
	vec3d_minus(&light_param->light_dir, \
		&prog->light.position, &param->inters_point);
	light_param->max_dist = vec3d_length(&light_param->light_dir);
	vec3d_normalize(&light_param->light_dir);
	vec3d_assign(&light_param->ray.origin, &param->inters_point);
	vec3d_assign(&light_param->ray.direction, &light_param->light_dir);
	param->ray = &light_param->ray;
}

int	trace_ray_to_obj(t_prog *prog, t_interparam *param)
{
	t_list		*lst;
	t_object	*focus_obj;
	int			f_hit;

	lst = prog->obj;
	while (lst)
	{
		reset_inters_focus(param);
		focus_obj = (t_object *)lst->content;
		if (focus_obj->type == SPHERE)
			f_hit = sp_test_intersection(focus_obj, param);
		else if (focus_obj->type == PLANE)
			f_hit = pl_test_intersection(focus_obj, param);
		if (param->f_ishit == 1)
			if (param->f_dist < param->inters_dist)
				gather_inters_info(param, focus_obj);
		lst = lst->next;
	}
	(void)f_hit;
	return (param->hit);
}
