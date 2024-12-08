/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 06:02:32 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/06 06:42:17 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

// void	generate_ray(t_ray *ray, t_prog *prog, int x, int y)
// {
// 	t_camera	*cam;

// 	cam = (t_camera *)&prog->camera;
// 	ray->direction.x = x * cam->u.x + y * cam->v.x + cam->top_left.x;
// 	ray->direction.y = x * cam->u.y + y * cam->v.y + cam->top_left.y;
// 	ray->direction.z = x * cam->u.z + y * cam->v.z + cam->top_left.z;
// 	vec3d_normalize(&ray->direction);
// 	copy_vec3d(&ray->origin, &cam->position);
// }



// int	calculate_pixel_color(t_ray *ray, t_prog *prog)
// {
// 	t_color			color;
// 	t_inters_params	param;
// 	int				hit;

// 	color = (t_color){0, 0, 0};
// 	param.ray = ray;
// 	init_intersection_param(prog, ray, &param);
// 	hit = trace_ray_to_objects(prog, &param);
// 	if (hit)
// 		trace_light_at_intersection(prog, &param);
// 	ft_memcpy(&color, &param.final_color, sizeof(t_color));
// 	return (convert_color_to_int(&color));
// }
int	render_image(t_minirt *mrt)
{
	t_ray	ray;
	int		color;

	mrt->x = 0;
	while (mrt->x < W_WIDTH)
	{
		mrt->y = 0;
		while (mrt->y < W_HEIGHT)
		{
			
			
			mrt->y++;
		}
		mrt->x++;
	}
	return (0);
}
/*
generate_ray(&ray, mrt, mrt->x, mrt->y);
color = calculate_pixel_color(&ray, prog);
mlx_my_putpixel(&prog->mlx_config.img, prog->x, prog->y, color);

*/