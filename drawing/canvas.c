/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 03:30:18 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/24 15:02:50 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"


int	render_image(t_minirt *prog)
{
	t_ray	ray;
	int		color;
	void	*img;

	prog->x = 0;
	while (prog->x < W_WIDTH)
	{
		prog->y = 0;
		while (prog->y < W_HEIGHT)
		{
			printf("\rRendering: %d%%", (prog->x * 100 / W_WIDTH) + 1);
			ray = ray_gen(prog->cam, prog->x, prog->y);
			color = calculate_pixel_color(&ray, prog);
			mlx_putpixel(&prog->mlx.img, prog->x, prog->y, color);
			prog->y++;
		}
		prog->x++;
	}
	img = prog->mlx.img.img;
	mlx_put_image_to_window(prog->mlx.mlx, prog->mlx.win, img, 0, 0);
	return (0);
}
