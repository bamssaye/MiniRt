#include "minirt.h"

int	render_image(t_prog *prog)
{
	t_ray	ray;
	int		color;

	prog->x = 0;
	while (prog->x < WINDOW_WIDTH)
	{
		prog->y = 0;
		while (prog->y < WINDOW_HEIGHT)
		{
			generate_ray(&ray, prog, prog->x, prog->y);
			color = ray_color(&ray, prog);
			mlx_my_putpixel(&prog->mlx_config.img, prog->x, prog->y, color);
			prog->y++;
		}
		prog->x++;
	}
	return (0);
}

void	generate_ray(t_ray *ray, t_prog *prog, int x, int y)
{
	t_camera	*cam;

	cam = (t_camera *)&prog->camera;
	ray->direction.x = x * cam->u.x + y * cam->v.x + cam->top_left.x;
	ray->direction.y = x * cam->u.y + y * cam->v.y + cam->top_left.y;
	ray->direction.z = x * cam->u.z + y * cam->v.z + cam->top_left.z;
	vec3d_normalize(&ray->direction);
	vec3d_assign(&ray->origin, &cam->position);
}

int	ray_color(t_ray *ray, t_prog *prog)
{
	t_color			color;
	t_interparam	param;
	int				hit;

	color = (t_color){0, 0, 0};
	param.ray = ray;
	init_intersection_param(prog, ray, &param);
	hit = trace_ray_to_obj(prog, &param);
	if (hit)
		trace_light(prog, &param);
	ft_memcpy(&color, &param.final_color, sizeof(t_color));
	return (color_struct2int(&color));
}

int	gather_inters_info(t_interparam *param, t_object *focus_obj)
{
	param->inters_dist = param->f_dist;
	ft_memcpy(&param->inters_point, &param->f_point, sizeof(t_vec3d));
	ft_memcpy(&param->inters_normal, &param->f_normal, sizeof(t_vec3d));
	ft_memcpy(&param->inters_color, &param->f_color, sizeof(t_color));
	param->inters_obj_id = focus_obj->id;
	param->d_inters_obj_type = focus_obj->type;
	return (0);
}

int	init_intersection_param(t_prog *prog, t_ray *ray, t_interparam *param)
{
	(void)prog;
	(void)ray;
	reset_inters_focus(param);
	vec3d_init(&param->inters_normal, 0, 0, 0);
	vec3d_init(&param->inters_point, 0, 0, 0);
	param->inters_dist = INFINITY;
	param->f_ishit = 0;
	param->inters_obj_id = -1;
	param->inters_color = (t_color){0, 0, 0};
	param->hit = 1;
	param->f_ishit = 0;
	return (0);
}

int	reset_inters_focus(t_interparam *param)
{
	param->f_dist = INFINITY;
	param->f_ishit = 0;
	param->f_color = (t_color){0, 0, 0};
	return (0);
}