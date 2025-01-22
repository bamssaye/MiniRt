/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 03:16:52 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/22 14:41:25 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"


void	ft_init_win(t_minirt *mrt)
{
	mrt->mlx.mlx = mlx_init();
	mrt->mlx.win = mlx_new_window(mrt->mlx.mlx, W_WIDTH, W_HEIGHT, P_NAME);
	mrt->mlx.img.img = mlx_new_image(mrt->mlx.mlx, W_WIDTH, W_HEIGHT);
	mrt->mlx.img.addr = mlx_get_data_addr(mrt->mlx.img.img, 
			&mrt->mlx.img.bpp, &mrt->mlx.img.width, &mrt->mlx.img.endian);
}

void	ft_hooks_fun(t_minirt *mrt)
{
	t_mlx *t;
	t = &mrt->mlx;
	mlx_hook(t->win, 17, 0, ft_clear_all, mrt);
}
void	mlx_putpixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->width + x * (data->bpp >> 3));
	*(unsigned int *) dst = color;
}
int	ft_clear_all(t_minirt *mrt)
{
	mlx_destroy_image(mrt->mlx.mlx, mrt->mlx.img.img);
	mlx_destroy_window(mrt->mlx.mlx, mrt->mlx.win);
	mlx_destroy_display(mrt->mlx.mlx);
	free(mrt->mlx.mlx);
	// (void)mrt;
	exit(0);
	return (0);
}