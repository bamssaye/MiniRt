/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 05:25:14 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/21 11:30:47 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

// t_tex	get_texture(void *mlx, *path)
// {
// 	t_tex	tex;

// 	// char *path = "./1.xpm";
// 	if (!access(path, R_OK))
// 		printf("yes");
// 	tex.img = mlx_xpm_file_to_image(mlx, path, &tex.width, &tex.height);
// 	if (!tex.img)
// 		exit(1);
// 	tex.addr = mlx_get_data_addr(tex.img, &tex.bpp, &tex.line_length,
// 			&tex.endian);
// 	return (tex);
// }
