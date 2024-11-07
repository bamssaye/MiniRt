/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:48:19 by bamssaye          #+#    #+#             */
/*   Updated: 2024/11/07 01:48:20 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	color_plus(t_color *res, t_color *a, t_color *b)
{
	res->r = a->r + b->r;
	if (res->r > 255)
		res->r = 255;
	res->g = a->g + b->g;
	if (res->g > 255)
		res->g = 255;
	res->b = a->b + b->b;
	if (res->b > 255)
		res->b = 255;
	return (0);
}

int	color_rgb2int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	color_copy(t_color *dst, t_color *src)
{
	dst->r = src->r;
	dst->g = src->g;
	dst->b = src->b;
	return (0);
}
t_color	int2color(int color)
{
	t_color	res;

	res.r = (color >> 16) & 0xFF;
	res.g = (color >> 8) & 0xFF;
	res.b = color & 0xFF;
	return (res);
}

void	color_set_defval(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

int	color_dot(t_color *res, t_color *c1, t_color *intensity)
{
	res->r = (double)c1->r * (double)intensity->r;
	res->g = (double)c1->g * (double)intensity->g;
	res->b = (double)c1->b * (double)intensity->b;
	return (0);
}
