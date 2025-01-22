/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:30 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/22 14:49:14 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"

void ft_init(t_minirt *mrt)
{
	int	i;
	
	i = -1;
	ft_memset(mrt->amc, 0, sizeof(mrt->amc));
	mrt->x = 0;
	mrt->y = 0;
	mrt->objects.object = NULL;
	mrt->objects.obj_count = 0;
}
int	close_window(void)
{
	exit(0);
}

void	prog_mlx_loop(t_minirt *prog)
{
	t_mlx	*vars;

	vars = &(prog->mlx);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	t_minirt minirt;
	// t_mx4 a;//b,c,r;
	// (void) ac;
	if (ac != 2)
		return (1);
	ft_init(&minirt);
	if (ft_readfile(av[1], &minirt))
		return (printf("ERROOR\n"), 1);
	exit(1);
	// t_vec3d p = {0.6,0.4,0.9,1};
	// a =  rotation_mx(p);
	// for (int i = 0; i < 4; i++)
	// {
	// 	for (int j = 0; j < 4;j++)
	// 		printf("%.5f ", a.mx[i][j]);
	// 	printf("\n");
	// }
	// render_image(&minirt);
	
	//////Randring
	// ft_init_win(&minirt);
	// render_image(&minirt);
	// mlx_put_image_to_window(minirt.mlx.mlx, minirt.mlx.win, minirt.mlx.img.img, 0, 0);
	// prog_mlx_loop(&minirt);
	return (0);
}
