/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:39:45 by bamssaye          #+#    #+#             */
/*   Updated: 2024/11/07 01:39:46 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX__H
# define MLX__H
# include "minirt.h"

typedef struct s_prog	t_prog;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		endian;
}				t_image;

typedef struct s_mlx_confix
{
	void	*mlx;
	void	*win;
	t_image	img;
}				t_mlx_confix;

void	mlx_my_putpixel(t_image *data, int x, int y, int color);
void	mlx_my_init(t_mlx_confix *vars);
#endif