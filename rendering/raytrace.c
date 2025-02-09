/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:46 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/08 14:19:48 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_ray	ray_gen(t_camera cam, int x, int y) //generate_ray
{
	t_ray	ray;

	ray.direction.x = x * cam.u.x + y * cam.v.x + cam.top_left.x;
	ray.direction.y = x * cam.u.y + y * cam.v.y + cam.top_left.y;
	ray.direction.z = x * cam.u.z + y * cam.v.z + cam.top_left.z;
	return ((t_ray){
		.direction = vec3d_normalize(ray.direction),
		.origin = cam.position});
}

void	trace_ray(t_list *obj, t_in_pa *pa, int *stuck, double mx_dist, t_minirt *aml)
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
		inter_wobject(objt, pa, aml);
		lst = lst->next;
		if (pa->closest.dista <= mx_dist)
			*stuck = 1;	
	}
}

void	trace_rtobj(t_list *obj, t_in_pa *pa, t_minirt *aml) //trace_ray_to_objects
{
	t_list		*lst;
	t_object	*objt;

	lst = obj;
	while (lst)
	{
		pa->closest.dista = INFINITY;
		pa->closest.color = (t_color){0, 0, 0, 0};
		objt = (t_object *)lst->content;
		inter_wobject(objt, pa, aml);
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

void trace_light_at_intersection(t_minirt *prog, t_in_pa *param)
{
    t_trace_light tr;
    t_vec3d reflect_dir, view_dir;
    
    tr.final_c = (t_color){0, 0, 0, 0};
    tr.lst = prog->object;
    while (tr.lst)
    {
        tr.objt = (t_object *)tr.lst->content;
        if (tr.objt->type == LIGHT)
        {
            tr.l_pa = initlight_inter(*((t_light*)tr.objt->object), param);
            param->ray = &tr.l_pa.ray;
            trace_ray(prog->object, param, &tr.l_pa.stuck, tr.l_pa.max_dista, prog);
            tr.inters = param->inters;
            if (!tr.l_pa.stuck)
            {
                tr.angle_scale = c_light_scale(tr.inters.normal, tr.l_pa.light_dire);
                tr.color = color_scale(tr.angle_scale, tr.inters.color);
                reflect_dir = vec3d_normalize(vec3d_minus(
                    vec3d_scale(2.0 * vec3d_dot(tr.inters.normal, tr.l_pa.light_dire), tr.inters.normal),
                    tr.l_pa.light_dire));
                view_dir = vec3d_normalize(vec3d_minus(prog->camera.position, tr.inters.point));
                tr.l_pa.light.specular_color = color_scale(
                    fmin(1.5 * pow(fmax(0.0, vec3d_dot(reflect_dir, view_dir)), 70.0), 1.0),
                    (t_color){255, 255, 255, 0});
                tr.final_c = color_plus(tr.final_c, color_plus(tr.color, tr.l_pa.light.specular_color));
            }
        }
        tr.lst = tr.lst->next;
    }
    tr.ambient_color = color_a(prog->am_light.al_rgb, tr.inters.color);
    param->final_color = color_plus(tr.ambient_color, tr.final_c);
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
	trace_rtobj(prog->object, &param, prog);
	trace_light_at_intersection(prog, &param);
	color = cpy_color(param.final_color);
	return (ctoi(color));
}
