/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:30 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/24 11:16:33 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"

int	main(int ac, char **av)
{
	t_minirt	minirt;

	if (ac != 2)
		return (print_err(MSG, MSG_1));
	ft_memset(&minirt, 0, sizeof(minirt));
	minirt.bouns = 1;
	if (ft_readfile(av[1], &minirt))
		return (1);
	ft_init_win(&minirt);
	if (minirt.count_t)
		load_texture(&minirt, minirt.object);
	render_image(&minirt);
	ft_hooks_fun(&minirt);
	return (0);
}
