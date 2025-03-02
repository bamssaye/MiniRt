/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:18:37 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/27 23:52:20 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

static t_object	*selected_object(t_list *obj, int id)
{
	t_list		*tmp;
	t_object	*objt;

	tmp = obj;
	while (tmp)
	{
		objt = (t_object *)tmp->content;
		if (objt->id == id)
			return (objt);
		tmp = tmp->next;
	}
	return (NULL);
}

int	select_object(int keycode, int x, int y, t_minirt *prog)
{
	t_hit	param;
	t_ray	ray;

	ray = ray_gen(prog->cam, x, y);
	prog->selected.slected = NULL;
	ft_memset(&param, 0, sizeof(t_hit));
	if (!prog->amc[A])
		prog->am_light.al_color = (t_color){0, 0, 0, 0};
	param.ray = &ray;
	param.closest.dista = INFINITY;
	param.inters.dista = INFINITY;
	param.iobj_id = -1;
	trace_rtobj(&param, prog);
	if (param.hit_clos)
	{
		prog->selected.slected = selected_object(prog->object, param.iobj_id);
		printf("\n[object selected]\n");
	}
	prog->selected.id_obj = param.iobj_id;
	(void)keycode;
	return (0);
}

int	rotation_translation(t_minirt *mrt)
{
	if (mrt->key.rot)
	{
		if (mrt->key.right)
			return (rotate_x(mrt->selected.slected, 45.0), 1);
		else if (mrt->key.up)
			return (rotate_y(mrt->selected.slected, 45.0), 1);
		else if (mrt->key.down)
			return (rotate_z(mrt->selected.slected, 45.0), 1);
	}
	else if (mrt->key.tra)
	{
		if (mrt->key.right)
			return (transle_x(mrt->selected.slected, 3), 1);
		else if (mrt->key.left)
			return (transle_x(mrt->selected.slected, -3), 1);
		else if (mrt->key.up)
			return (transle_y(mrt->selected.slected, 3), 1);
		else if (mrt->key.down)
			return (transle_y(mrt->selected.slected, -3), 1);
		else if (mrt->key.z_o)
			return (transle_z(mrt->selected.slected, -3), 1);
		else if (mrt->key.z_i)
			return (transle_z(mrt->selected.slected, 3), 1);
	}
	return (0);
}

static void	o_zoom(t_object *obj, double x)
{
	t_obj	objs;

	if (obj->type == SPHERE && obj->t++)
	{
		objs.sp = (t_sp *)obj->object;
		objs.sp->radius *= x;
	}
	else if (obj->type == CYLINDER && obj->t++)
	{
		objs.cy = (t_cy *)obj->object;
		objs.cy->radius *= x;
		objs.cy->len *= x;
	}
	else if (obj->type == CONE && obj->t++)
	{
		objs.co = (t_co *)obj->object;
		objs.co->radius *= x;
		objs.co->height *= x;
	}
}

int	obj_zoom(int button, t_minirt *mrt)
{
	if (button == K_OUT)
		return (o_zoom(mrt->selected.slected, 0.72), 1);
	else if (button == K_IN)
		return (o_zoom(mrt->selected.slected, 1.27), 1);
	return (0);
}
