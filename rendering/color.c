/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:18:57 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/24 12:26:49 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	min(int a, int min)
{
	if (a > min)
		return (min);
	return (a);
}

t_color	c_plus(t_color a, t_color b)
{
	return ((t_color){
		.isv = 0,
		.r = min(a.r + b.r, 255),
		.g = min(a.g + b.g, 255),
		.b = min(a.b + b.b, 255)
	});
}

int	ctoi(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

t_color	c_scale(double scale, t_color a)
{
	return ((t_color){
		.isv = 0,
		.r = (scale * (double)a.r),
		.g = (scale * (double)a.g),
		.b = (scale * (double)a.b)
	});
}

t_color	color_a(t_color a, t_color b)
{
	return ((t_color){
		.isv = 0,
		.r = (a.r * b.r) / 255,
		.g = (a.g * b.g) / 255,
		.b = (a.b * b.b) / 255
	});
}
