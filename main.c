/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:30 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/09 09:07:31 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"

int	ft_clear_all(t_minirt *mrt)
{
	// mlx_destroy_image(mrt->mlx.mlx, mrt->mlx.img.img);
	// mlx_destroy_window(mrt->mlx.mlx, mrt->mlx.win);
	// mlx_destroy_display(mrt->mlx.mlx);
	//free(mrt->mlx.mlx);
	(void)mrt;
	exit(0);
	return (0);
}

void ft_init(t_minirt *mrt)
{
	int	i;
	
	i = -1;
	ft_memset(mrt->amc, 0, sizeof(mrt->amc));
	ft_memset(mrt->count_ob, 0, sizeof(mrt->amc));
	mrt->x = 0;
	mrt->y = 0;
	while (++i < 3)
		mrt->objects[i].object = NULL;
}
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
int	main(int ac, char **av)
{
	t_minirt minirt;

	(void) ac;
	ft_init(&minirt);
	if (ft_readfile(av[1], &minirt))
		return (printf("ERROOR\n"), 1);
	ft_init_win(&minirt);
	//render_image(&minirt);
	ft_hooks_fun(&minirt);
	t_mlx *t = &(minirt.mlx);
	mlx_loop(t->mlx);
	///print object
	//all_printf((t_cylinder*)minirt.objects[2].object, (t_plane*)minirt.objects[1].object, (t_sphere*)minirt.objects[0].object, &minirt);
	return (0);
}
