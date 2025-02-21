/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:30 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/20 14:02:28 by bamssaye         ###   ########.fr       */
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

int print_err(char *str, char *s)
{
	return (printf("%s : %s\n", str, s), 1);
}


int	main(int ac, char **av)
{
	t_minirt	minirt;

	if (ac != 2)
		return (print_err(MSG, MSG_1));
	minirt.bouns = 0;
	ft_init(&minirt);
	if (ft_readfile(av[1], &minirt))
		return (1);
	fprintf(stderr, "dsdsd\n");
	ft_init_win(&minirt);
	// if (minirt.count_t)
	// 	load_texture(&minirt, minirt.object);
	render_image(&minirt);
	ft_hooks_fun(&minirt);
	return (0);
}
