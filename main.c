/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:30 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/24 12:41:35 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"

int	main(int ac, char **av)
{
	t_minirt	minirt;

	if (ac != 2)
		return (print_err(MSG, MSG_1));
	ft_memset(&minirt, 0, sizeof(minirt));
	minirt.bouns = 0;
	if (ft_readfile(av[1], &minirt))
		return (1);
	ft_init_win(&minirt);
	render_image(&minirt);
	ft_hooks_fun(&minirt);
	return (0);
}
