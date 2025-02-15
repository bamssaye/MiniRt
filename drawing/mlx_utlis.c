/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 03:16:52 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/15 12:49:31 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void	ft_init_win(t_minirt *mrt)
{
	mrt->mlx.mlx = mlx_init();
	mrt->mlx.win = mlx_new_window(mrt->mlx.mlx, W_WIDTH, W_HEIGHT, P_NAME);
	mrt->mlx.img.img = mlx_new_image(mrt->mlx.mlx, W_WIDTH, W_HEIGHT);
	mrt->mlx.img.addr = mlx_get_data_addr(mrt->mlx.img.img,
			&mrt->mlx.img.bpp,
			&mrt->mlx.img.width,
			&mrt->mlx.img.endian);
}
t_object *selected_object(t_list *obj, int id)
{
	t_list *tmp;
	t_object *objt;
	tmp = obj;
	while(tmp)
	{
		objt = (t_object *)tmp->content;
		if (objt->id == id)
			return (objt);
		tmp = tmp->next;
	}
	return (NULL);
}

int	key_hook(int keycode, t_minirt *mrt)
{
	if (keycode == 65307)
		ft_clear_all(mrt);
	
	return (0);
}



int mouse_ha(int keycode, int x, int y, t_minirt *prog)
{
	t_in_pa param;
	t_ray ray = ray_gen(prog->camera, x, y);
	prog->selected.slected = NULL;
	ft_memset(&param, 0, sizeof(t_in_pa));
	if(!prog->amc[A])
		prog->am_light.al_rgb = (t_color){0, 0, 0, 0};
	param.ray = &ray;
	param.closest.dista = INFINITY;
	param.inters.dista = INFINITY;
	param.iobj_id = -1;
	trace_rtobj(prog->object, &param, prog);
    if (param.hit_clos)
    {
		prog->selected.id_obj = param.iobj_id;
		prog->selected.slected = selected_object(prog->object, param.iobj_id);
    }
	(void)keycode;
	return 0;
}

int key_press(int button, t_minirt *mrt)
{
	(void)mrt;
	if (button == 124){
		mrt->obj_c = 0;
		printf("key_press{%d} \n",mrt->obj_c);
	}
	
	return (0);
}

int key_relase(int button, t_minirt *mrt)
{
	(void)mrt;
	if (button == 7)
		mrt->obj_c = 1;
	return 0;
}
void	ft_hooks_fun(t_minirt *mrt)
{
	t_mlx	*t;

	t = &mrt->mlx;
	mlx_hook(t->win, 17, 0, ft_clear_all, mrt);
	mlx_mouse_hook(t->win, mouse_ha, mrt);
	mlx_hook(t->win, 2, 1L<<0, key_press, mrt);
	mlx_hook(t->win, 3, 1L<<1, key_relase, mrt);
	mlx_key_hook(t->win, key_hook, mrt);
	mlx_loop(t->mlx);
}

void	mlx_putpixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->width + x * (data->bpp >> 3));
	*(unsigned int *)dst = color;
}

int	ft_clear_all(t_minirt *mrt)
{
	mlx_destroy_image(mrt->mlx.mlx, mrt->mlx.img.img);
	mlx_destroy_window(mrt->mlx.mlx, mrt->mlx.win);
	// mlx_destroy_display(mrt->mlx.mlx);
	free_cmd(mrt->object);
	free(mrt->mlx.mlx);
	exit(0);
	return (0);
}
