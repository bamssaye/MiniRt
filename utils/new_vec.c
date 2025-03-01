/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 02:05:33 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/26 14:19:55 by bamssaye         ###   ########.fr       */
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

int	print_err(char *str, char *s)
{
	return (printf("%s : %s\n", str, s), 1);
}
