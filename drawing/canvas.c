/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 03:30:18 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/22 14:42:26 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

// int	render_image(t_prog *prog)
// {
// 	t_ray	ray;
// 	int		color;

// 	prog->x = 0;
// 	while (prog->x < WINDOW_WIDTH)
// 	{
// 		prog->y = 0;
// 		while (prog->y < WINDOW_HEIGHT)
// 		{
// 			printf("\rRendering: %d%%", (prog->x * 100 / WINDOW_WIDTH) + 1 );
// 			generate_ray(&ray, prog, prog->x, prog->y);
// 			color = calculate_pixel_color(&ray, prog);
// 			mlx_my_putpixel(&prog->mlx_config.img, prog->x, prog->y, color);
// 			prog->y++;
// 		}
// 		prog->x++;
// 	}
// 	// ft_putstr_fd("\rRendring : 100%", STDOUT_FILENO);
// 	return (0);
// }
