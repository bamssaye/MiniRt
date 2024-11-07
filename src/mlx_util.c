/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:48:30 by bamssaye          #+#    #+#             */
/*   Updated: 2024/11/07 01:48:31 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void	mlx_my_init(t_mlx_confix *vars)
{
	vars->mlx = mlx_init();
	vars->is_initmlx = 1;
	vars->win = mlx_new_window(vars->mlx, \
		WINDOW_WIDTH, WINDOW_HEIGHT, PROGRAM_NAME);
	vars->is_initwin = 1;
	vars->img.img = mlx_new_image(vars->mlx, \
		WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
		&vars->img.bpp, &vars->img.width, &vars->img.endian);
	fill_image_color(vars);
	vars->is_init_image = 1;
}

int	close_window(void)
{
	exit(0);
}

void	prog_mlx_loop(t_prog *prog)
{
	t_mlx_confix	*vars;

	prog->selected_obj = &prog->camera;
	vars = &(prog->mlx_config);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_loop(vars->mlx);
}

void	mlx_my_putpixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->width + x * (data->bpp >> 3));
	*(unsigned int *) dst = color;
}

void	fill_image_color(t_mlx_confix *vars)
{
	int	win_x;
	int	win_y;
	int	color;

	win_y = 0;
	while (win_y < WINDOW_HEIGHT)
	{
		win_x = 0;
		while (win_x < WINDOW_WIDTH)
		{
			color = color_rgb2int(0, 0, 0);
			mlx_my_putpixel(&(vars->img), win_x, win_y, color);
			win_x++;
		}
		win_y++;
	}
}

void	prog_init_mlx(t_prog *prog)
{
	t_mlx_confix	*mlx_config;

	mlx_config = &(prog->mlx_config);
	mlx_my_init(mlx_config);
}