#include "../headers/minirt.h"

int	set_intersection_info(t_inters_params *param, t_object *focus_obj)
{
	param->inters_dist = param->closest_distance;
	ft_memcpy(&param->inters_point, &param->closest_point, sizeof(t_vec3d));
	ft_memcpy(&param->inters_normal, &param->closest_normal, sizeof(t_vec3d));
	fprintf(stderr, "{%d,%d,%d} \n",param->closest_color.r, param->closest_color.g, param->closest_color.b);
	ft_memcpy(&param->inters_color, &param->closest_color, sizeof(t_color));
	fprintf(stderr, "{%d,%d,%d} \n",param->inters_color.r, param->inters_color.g, param->inters_color.b);
	param->inters_object_id = focus_obj->id;
	return (0);
}

int	init_intersection_param(t_prog *prog, t_ray *ray, t_inters_params *param)
{
	(void)prog;
	(void)ray;
	reset_intersection_focus(param);
	vec3d_init(&param->inters_normal, 0, 0, 0);
	vec3d_init(&param->inters_point, 0, 0, 0);
	param->inters_dist = INFINITY;
	param->is_closest_hit = 0;
	param->inters_object_id = -1;
	param->inters_color = (t_color){0, 0, 0};
	return (0);
}

int	reset_intersection_focus(t_inters_params *param)
{
	param->closest_distance = INFINITY;
	param->closest_color = (t_color){0, 0, 0};
	return (0);
}
