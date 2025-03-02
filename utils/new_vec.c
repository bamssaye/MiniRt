/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 02:05:33 by bamssaye          #+#    #+#             */
/*   Updated: 2025/03/01 18:57:28 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_color	cpy_color(t_color co)
{
	return ((t_color){
		.isv = co.isv,
		.r = min(co.r, 255),
		.g = min(co.g, 255),
		.b = min(co.b, 255)});
}

t_vec3d	color_map(t_color color)
{
	return ((t_vec3d){
		.x = (color.r / 255.0) * 2.0 - 1.0,
		.y = (color.g / 255.0) * 2.0 - 1.0,
		.z = (color.b / 255.0) * 2.0 - 1.0,
		.isv = 0
	});
}

t_vec3d	normal_sp(t_vec3d no, t_tbitan tbn)
{
	t_vec3d		x;
	t_vec3d		y;
	t_vec3d		z;

	x = v_scale(no.x, tbn.tan);
	y = v_scale(no.y, tbn.bitan);
	z = v_scale(no.z, tbn.normal);
	return (v_plus(v_plus(x, y), z));
}

int	print_err(char *str, char *s)
{
	return (printf("%s : %s\n", str, s), 1);
}
