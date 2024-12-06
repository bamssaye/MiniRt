/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:30 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/06 04:24:24 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"

void ft_init(t_minirt *mrt)
{
	int	i;
	
	i = -1;
	ft_memset(mrt->amc, 0, sizeof(mrt->amc));
	ft_memset(mrt->count_ob, 0, sizeof(mrt->amc));
	while (++i < 3)
		mrt->objects[i].object = NULL;
	// mrt->objects[0]
	//mrt->objects = (t_objects*)malloc(sizeof(t_objects) * 3);
	//mrt->objects[2] = NULL;
}
void	ft_init_win(t_minirt *mrt)
{
	mrt->mlx.mlx = mlx_init();
	mrt->mlx.win = mlx_new_window(mrt->mlx.mlx, W_WIDTH, W_HEIGHT, P_NAME);
	mrt->mlx.img.img = mlx_new_image(mrt->mlx.mlx, W_WIDTH, W_HEIGHT);
	mrt->mlx.img.addr = mlx_get_data_addr(mrt->mlx.img.img, 
			&mrt->mlx.img.bpp, &mrt->mlx.img.width, &mrt->mlx.img.endian);
}

int	main(int ac, char **av)
{
	t_minirt minirt;

	(void) ac;
	ft_init(&minirt);
	if (ft_readfile(av[1], &minirt))
		return (printf("ERROOR\n"), 1);
	ft_init_win(&minirt);
	mlx_loop(minirt.mlx.mlx);
	///print object
	//all_printf((t_cylinder*)minirt.objects[2].object, (t_plane*)minirt.objects[1].object, (t_sphere*)minirt.objects[0].object, &minirt);
	return (0);
}
