/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:30 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/02 20:57:11 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"

void	mlx_my_init(t_mlx_confix *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, \
		WINDOW_WIDTH, WINDOW_HEIGHT, PROGRAM_NAME);
	vars->img.img = mlx_new_image(vars->mlx, \
		WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, 
		&vars->img.bpp, &vars->img.width, &vars->img.endian);
}

void	prog_init_mlx(t_prog *prog)
{
	t_mlx_confix	*mlx_config;

	mlx_config = &(prog->mlx_config);
	mlx_my_init(mlx_config);
}

void	init_light(t_light *l)
{
	t_color	color;

	color = (t_color){0, 0, 0};
	ft_memcpy(&l->color, &color, sizeof(t_color));
	l->intensity = 0;
}

int	prog_constructor(t_prog *prog)
{
	prog->has_camera = 0;
	prog->has_ambient = 0;
	prog->has_light = 0;
	prog->object_count = 0;
	prog->obj = NULL;
	init_light(&prog->light);
	return (0);
}
void progcheck(t_prog *p)
{
	if (!p->has_ambient)
	{
		p->ambient_color = (t_color){0,0,0};
	}
}
int	main(int argc, char **argv)
{
	t_prog			prog;
	t_mlx_confix	*vars;

	vars = &(prog.mlx_config);
	prog_constructor(&prog);
	(void)argc;
	(void)argv;
	read_rt_file(argv[1], &prog);
	prog_init_mlx(&prog);
	// progcheck(&prog);
	render_image(&prog);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	prog_mlx_loop(&prog);
	return (0);
}
