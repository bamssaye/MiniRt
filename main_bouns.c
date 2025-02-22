/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bouns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:56:45 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/22 11:39:04 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"


void	ft_init(t_minirt *mrt)
{
	ft_memset(mrt->amc, 0, sizeof(mrt->amc));
	mrt->x = 0;
	mrt->y = 0;
	mrt->count_t = 0;
	mrt->object = NULL;
	mrt->obj_count = 0;
}

int	main(int ac, char **av)
{
	t_minirt	minirt;

	if (ac != 2)
		return (1);
	ft_init(&minirt);
	minirt.bouns = 1;
	if (ft_readfile(av[1], &minirt))
		return (printf("Error\n"), 1);
	ft_init_win(&minirt);
	if (minirt.count_t)
		load_texture(&minirt, minirt.object);
	render_image(&minirt);
	ft_hooks_fun(&minirt);
	return (0);
}