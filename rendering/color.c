/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:10:02 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/27 23:48:58 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	min(int a, int min)
{
	if (a > min)
		return (min);
	return (a);
}

t_color	color_plus(t_color a, t_color b)
{
	return ((t_color){
		.r = min(a.r + b.r, 255),
		.g = min(a.g + b.g, 255),
		.b = min(a.b + b.b, 255)});
}

int	ctoi(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

t_color	color_scale(double scale, t_color a)
{
	return ((t_color){
		.r = (scale * (double)a.r),
		.g = (scale * (double)a.g),
		.b = (scale * (double)a.b)});
}
