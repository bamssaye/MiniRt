/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:30 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/27 21:32:11 by bamssaye         ###   ########.fr       */
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
	mrt->object = NULL;
	mrt->obj_count = 0;
}
int	close_window(void)
{
	exit(0);
}
int key_hook(int keycode)//, t_minirt *prog)
{
	if (keycode == 65307)
		close_window();
		// ft_clear_all(prog);
	return (0);	
}
void	prog_mlx_loop(t_minirt *prog)
{
	t_mlx	*vars;

	vars = &(prog->mlx);
	mlx_key_hook(vars->win, key_hook, prog);
	// mlx_hook(vars->win, 17, 0, ft_clear_all, fractol);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	t_minirt minirt;

	if (ac != 2)
		return (1);
	ft_init(&minirt);
	if (ft_readfile(av[1], &minirt))
		return (printf("ERROOR\n"), 1);
	ft_init_win(&minirt);
	render_image(&minirt);
	prog_mlx_loop(&minirt);
	//free_cmd(mrt->object)
	return (0);
}
