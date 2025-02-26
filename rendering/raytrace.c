/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:46 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/26 00:12:06 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_ray	ray_gen(t_camera cam, int x, int y)
{
	t_ray	ray;

	ray.direction = v_normalize(v_plus(cam.top_left, v_plus(v_scale(x, cam.u),
					v_scale(y, cam.v))));
	return ((t_ray){.direction = ray.direction, .origin = cam.position});
}

// trace ray to light source
void	trace_ray(t_hit *pa, int *stuck, double mx_dist, t_minirt *rt)
{
	t_list		*lst;
	t_object	*objt;

	*stuck = 0;
	lst = rt->object;
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
		inter_wobject(objt, pa, rt);
		lst = lst->next;
		if (pa->closest.dista <= mx_dist)
		{
			*stuck = 1;
		}
	}
}

// trace_ray_to_objects
void	trace_rtobj(t_hit *pa, t_minirt *rt)
{
	t_list		*lst;
	t_object	*objt;

	lst = rt->object;
	while (lst)
	{
		pa->closest.dista = INFINITY;
		pa->closest.color = (t_color){0, 0, 0, 0};
		objt = (t_object *)lst->content;
		inter_wobject(objt, pa, rt);
		if (pa->hit_clos)
		{
			if (pa->closest.dista < pa->inters.dista)
			{
				pa->inters.dista = pa->closest.dista;
				pa->inters = pa->closest;
				pa->iobj_id = objt->id;
			}
		}
		lst = lst->next;
	}
}

// li_scale
void	trace_light_at_intersection(t_minirt *prog, t_hit *hit)
{
	t_trace_light	tr;

	tr.f_c = (t_color){0, 0, 0, 0};
	tr.lst = prog->object;
	while (tr.lst)
	{
		tr.objt = (t_object *)tr.lst->content;
		if (tr.objt->type == LIGHT)
		{
			tr.l_pa = initlight_inter(*((t_light *)tr.objt->object), hit);
			hit->ray = &tr.l_pa.ray;
			trace_ray(hit, &tr.l_pa.stuck, tr.l_pa.m_dis, prog);
			tr.inters = hit->inters;
			if (!tr.l_pa.stuck)
			{
				tr.angle = lig_scale(tr.inters.normal, tr.l_pa.light_dire);
				tr.color = c_scale(tr.angle, tr.inters.color);
				tr.l_pa.light.spc = specular_light(&tr, prog->cam.position);
				tr.f_c = c_plus(tr.f_c, c_plus(tr.color, tr.l_pa.light.spc));
			}
		}
		tr.lst = tr.lst->next;
	}
	tr.ambient_color = color_a(prog->am_light.al_color, tr.inters.color);
	hit->final_color = c_plus(tr.ambient_color, tr.f_c);
}

int	calculate_pixel_color(t_ray *ray, t_minirt *prog)
{
	t_color	color;
	t_hit	param;

	ft_memset(&param, 0, sizeof(t_hit));
	if (!prog->amc[A])
		prog->am_light.al_color = (t_color){0, 0, 0, 0};
	param.ray = ray;
	param.closest.dista = INFINITY;
	param.inters.dista = INFINITY;
	param.iobj_id = -1;
	trace_rtobj(&param, prog);
	trace_light_at_intersection(prog, &param);
	color = cpy_color(param.final_color);
	return (ctoi(color));
}
