/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 03:16:52 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/15 17:46:27 by bamssaye         ###   ########.fr       */
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
		fprintf(stderr,"[object selected]\n");
	}
	(void)keycode;
	return 0;
}
void rotation_translation(t_minirt *mrt)
{
	if (mrt->key.rot)
	{
		if(mrt->key.right)
			rotate_x(mrt->selected.slected, 45.0);
		else if(mrt->key.up)
			rotate_y(mrt->selected.slected, 45.0);
		else if(mrt->key.down)
			rotate_z(mrt->selected.slected, 45.0);
	}
	else if (mrt->key.tra)
	{
		if(mrt->key.right)
			transle_x(mrt->selected.slected, 5);
		else if(mrt->key.left)
			transle_x(mrt->selected.slected, -5);
		else if(mrt->key.up)
			transle_y(mrt->selected.slected, 5);
		else if(mrt->key.down)
			transle_y(mrt->selected.slected, -5);
		else if(mrt->key.z_out)
			transle_z(mrt->selected.slected, -5);
		else if(mrt->key.z_in)
			transle_z(mrt->selected.slected, 5);
	}
}
#define K_UP 126
#define K_DOWN 125
#define K_LEFT 123
#define K_RIGHT 124
#define K_Z_IN 24
#define K_Z_OUT 27
#define K_R 15
#define K_T 17

int key_press(int button, t_minirt *mrt)
{
	if (button == K_R)
		mrt->key.rot = YES;
	else if (button == K_T)
		mrt->key.tra = YES;
	else if (button == K_RIGHT)
		mrt->key.right = YES;
	else if (button == K_LEFT)
		mrt->key.left = YES;
	else if (button == K_UP)
		mrt->key.up = YES;
	else if (button == K_DOWN)
		mrt->key.down = YES;
	else if (button == K_Z_OUT)
		mrt->key.z_out = YES;
	else if (button == K_Z_IN)
		mrt->key.z_in = YES;
	rotation_translation(mrt);
	// fprintf(stderr,"[randering %d]\n", mrt->selected.slected->t);
	if (mrt->selected.slected->t == 2)
	{
		mrt->selected.slected->t = 1;
		render_image(mrt);
	}
		
	return (0);
}

int key_relase(int button, t_minirt *mrt)
{
	if (button == K_R)
		mrt->key.rot = NO;
	else if (button == K_T)
		mrt->key.tra = NO;
	else if (button == K_RIGHT)
		mrt->key.right = NO;
	else if (button == K_LEFT)
		mrt->key.left = NO;
	else if (button == K_UP)
		mrt->key.up = NO;
	else if (button == K_DOWN)
		mrt->key.down = NO;
	else if (button == K_Z_OUT)
		mrt->key.z_out = NO;
	else if (button == K_Z_IN)
		mrt->key.z_in = NO;
	return 0;
}
void	ft_hooks_fun(t_minirt *mrt)
{
	t_mlx	*t;

	t = &mrt->mlx;
	// mrt->key.tra = 0;
	// mrt->key.rot = 0;
	// mrt->key.down = 0;
	// mrt->key.left = 0;
	// mrt->key.up = 0;
	// mrt->key.rot = 0;
	ft_memset(&mrt->key, 0, sizeof(t_keys));
	mlx_hook(t->win, 17, 0, ft_clear_all, mrt);
	mlx_mouse_hook(t->win, mouse_ha, mrt);
	mlx_hook(t->win, 2, 1L<<0, key_press, mrt);
	mlx_hook(t->win, 3, 1L<<1, key_relase, mrt);
	// mlx_key_hook(t->win, key_hook, mrt);
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
