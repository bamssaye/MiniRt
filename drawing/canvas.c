/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 03:30:18 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/23 14:01:16 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_ray ray_gen(t_minirt *prog, int x, int y) //generate_ray
{
	t_ray ray;
	t_camera cam;

	cam = prog->camera;
	ray.direction.x = x * cam.u.x + y * cam.v.x + cam.top_left.x;
	ray.direction.x = x * cam.u.y + y * cam.v.y + cam.top_left.y;
	ray.direction.x = x * cam.u.z + y * cam.v.z + cam.top_left.z;
	ray.direction = vec3d_normalize(ray.direction);
	ft_memcpy(&ray.origin, &cam.position, sizeof(t_vec3d));
	return (ray);
}

int	render_image(t_minirt *prog)
{
	t_ray	ray;
	int		color;

	prog->x = 0;
	while (prog->x < W_WIDTH)
	{
		prog->y = 0;
		while (prog->y < W_HEIGHT)
		{
			// printf("\rRendering: %d%%", (prog->x * 100 / W_WIDTH) + 1 );
			ray = ray_gen(prog, prog->x, prog->y);
			color = calculate_pixel_color(&ray, prog);
			// mlx_my_putpixel(&prog->mlx_config.img, prog->x, prog->y, color);
			prog->y++;
		}
		prog->x++;
	}
	return (0);
}
