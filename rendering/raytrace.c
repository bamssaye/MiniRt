/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 06:01:45 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/23 14:49:19 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

// void	generate_ray(t_ray *ray, t_minirt *prog, int x, int y)
// {
// 	t_camera	*cam;

// 	cam = (t_camera *)&prog->camera;
// 	ray->direction.x = x * cam->u.x + y * cam->v.x + cam->top_left.x;
// 	ray->direction.y = x * cam->u.y + y * cam->v.y + cam->top_left.y;
// 	ray->direction.z = x * cam->u.z + y * cam->v.z + cam->top_left.z;
// 	vec3d_normalize(&ray->direction);
// 	copy_vec3d(&ray->origin, &cam->position);
// }
// int	reset_intersection_focus(t_inter_p *param)
// {
// 	param->closest_distance = INFINITY;
// 	param->closest_color = (t_color){0, 0, 0};
// 	return (0);
// }
void	init_param(t_ray *ray, t_inter_p *param)
{
	param->ray = ray;
	param->closest_distance = INFINITY;
	param->closest_color = (t_color){0, 0, 0};
	param->inters_normal = (t_vec3d){0, 0, 0};
	param->inters_point  = (t_vec3d){0, 0, 0};
	param->inters_dist = INFINITY;
	param->is_closest_hit = 0;
	param->inters_object_id = -1;
	param->inters_color = (t_color){0, 0, 0};
}
int	ray_object(t_minirt *prog, t_inter_p *param) //trace_ray_to_objects
{
	t_list		*lst;
	t_object	*current_object;
	int			hit_detected;

	lst = prog->objects.object;
	while (lst)
	{
		reset_intersection_focus(param);
		current_object = (t_object *)lst->content;
		if (current_object->type == SPHERE)
			hit_detected = sp_inter(current_object, param);
		else if (current_object->type == PLANE)
			hit_detected = check_plane_intersection(current_object, param);
		else if (current_object->type == CYLINDER)
			hit_detected = check_cylinder_intersection(current_object, param);
		if(hit_detected)
			if (param->is_closest_hit == 1)
				if (param->closest_distance < param->inters_dist)
					set_intersection_info(param, current_object);
		lst = lst->next;
	}
	(void)hit_detected;
	return (1);
}

int	calculate_pixel_color(t_ray *ray, t_minirt *prog)
{
	t_color			color;
	t_inter_p	param;
	int				hit;

	color = (t_color){0, 0, 0};
	// param.ray = ray;
	init_param(ray, &param);
	
	// init_intersection_param(prog, ray, &param);
	hit = trace_ray_to_objects(prog, &param);
	if (hit)
		trace_light_at_intersection(prog, &param);
	ft_memcpy(&color, &param.final_color, sizeof(t_color));
	return (convert_color_to_int(&color));
}
int	set_intersection_info(t_inter_p *param, t_object *focus_obj)
{
	param->inters_dist = param->closest_distance;
	ft_memcpy(&param->inters_point, &param->closest_point, sizeof(t_vec3d));
	ft_memcpy(&param->inters_normal, &param->closest_normal, sizeof(t_vec3d));
	ft_memcpy(&param->inters_color, &param->closest_color, sizeof(t_color));
	param->inters_object_id = focus_obj->id;
	return (0);
}





int	calculate_light_intensity_scale(t_obslight *l_param, t_inter_p *p)
{
	l_param->angle = acos(vec3d_dot(p->inters_normal, l_param->light_direction));
	if (l_param->angle <= 1.570796)
		l_param->angle_scale = (1.0 - (l_param->angle / 1.570796));
	else
		l_param->angle_scale = 0;
	return (0);
}

void	initialize_light_parameters(t_minirt *prog, t_inter_p *param, t_obslight *light_param)
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

int	trace_ray_to_light_source(t_minirt *prog, t_inter_p *param, t_obslight *light_param)
{
	t_list		*lst;
	t_object	*obj;
	int			temp;

	lst = prog->objects.object;
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

void	trace_light_at_intersection(t_minirt *prog, t_inter_p *param)
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
	if (prog->amc[L])
		color_scale(&l_param.light.light_color, \
		l_param.angle_scale, &param->inters_color);
	color_scale(&l_param.light.ambient_color, \
		prog->am_light.al, &param->inters_color);
	color_plus(&param->final_color, \
		&l_param.light.ambient_color, &l_param.light.light_color);
}

int	check_intersection_with_object(t_object *obj, t_inter_p *param)
{
	int	temp;

	temp = 0;
	if (obj->type == SPHERE)
		temp = sp_inter(obj, param);
	else if (obj->type == PLANE)
		temp = check_plane_intersection(obj, param);
	else if (obj->type == CYLINDER)
		temp = check_cylinder_intersection(obj, param);
	return (temp);
}

