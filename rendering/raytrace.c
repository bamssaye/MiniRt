/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 06:01:45 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/07 05:53:27 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_ray	ray_gen(t_camera cam, int x, int y) //generate_ray
{
	t_ray	ray;

	ray.direction.x = x * cam.u.x + y * cam.v.x + cam.top_left.x;
	ray.direction.y = x * cam.u.y + y * cam.v.y + cam.top_left.y;
	ray.direction.z = x * cam.u.z + y * cam.v.z + cam.top_left.z;
	// ray.direction = vec3d_normalize(ray.direction);
	return ((t_ray){
		.direction = vec3d_normalize(ray.direction),
		.origin = cam.position});
}

void	trace_ray(t_list *obj, t_in_pa *pa, int *stuck, double mx_dist)
	//trace ray to light source
{
	t_list		*lst;
	t_object	*objt;

	*stuck = 0;
	lst = obj;
	while (lst && !*stuck)
	{
		pa->closest.dista = INFINITY;
		pa->closest.color = (t_color){0, 0, 0, 0};
		objt = (t_object *)lst->content;
		if (objt->id == pa->iobj_id)
		{
			lst = lst->next;
			continue ;
		}
		inter_wobject(objt, pa);
		lst = lst->next;
		if (pa->closest.dista <= mx_dist)
			*stuck = 1;
	}
}

void	trace_rtobj(t_list *obj, t_in_pa *pa) //trace_ray_to_objects
{
	t_list		*lst;
	t_object	*objt;

	lst = obj;
	while (lst)
	{
		pa->closest.dista = INFINITY;
		pa->closest.color = (t_color){0, 0, 0, 0};
		objt = (t_object *)lst->content;
		inter_wobject(objt, pa);
		if (pa->hit_clos)
		{
			if (pa->closest.dista < pa->inters.dista)
			{
				pa->inters.dista = pa->closest.dista;
				pa->inters = cpy_npc(pa->closest);
				pa->iobj_id = objt->id;
			}
		}
		lst = lst->next;
	}
}

void	trace_light_at_intersection(t_minirt *prog, t_in_pa *param)
	//trace_light_at_intersection
{
	t_obslight	l_param;
	t_npc		inters;
	t_slight	light;

	l_param = initlight_inter(prog->light, param);
	param->ray = &l_param.ray;
	trace_ray(prog->object, param, &l_param.stuck, l_param.max_dista);
	inters = param->inters;
	if (!l_param.stuck)
		l_param.angle_scale = c_light_scale(inters.normal, l_param.light_dire);
	light = l_param.light;
	if (prog->amc[L])
		light.light_color = color_scale(l_param.angle_scale, inters.color);
	light.ambient_color = color_a(prog->am_light.al_rgb, inters.color);
	param->final_color = color_plus(light.ambient_color, light.light_color);
}

int	calculate_pixel_color(t_ray *ray, t_minirt *prog)
{
	t_color		color;
	t_in_pa		param;

	ft_memset(&param, 0, sizeof(t_in_pa));
	if(!prog->amc[A])
		prog->am_light.al_rgb = (t_color){0, 0, 0, 0};
	param.ray = ray;
	param.closest.dista = INFINITY;
	param.inters.dista = INFINITY;
	param.iobj_id = -1;
	trace_rtobj(prog->object, &param);
	trace_light_at_intersection(prog, &param);
	color = cpy_color(param.final_color);
	return (ctoi(color));
}
