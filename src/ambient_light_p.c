/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:47:56 by bamssaye          #+#    #+#             */
/*   Updated: 2024/11/07 01:47:59 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	collect_ambient(char **split_line, t_prog *prog)
{
	double	intensity;

	ft_strtod(split_line[1], &intensity);
	color_collect_string(split_line[2], &prog->ambient_color);
	color_scale(&prog->ambient_color, intensity, &prog->ambient_color);
	prog->ambient_intensity = intensity;
	return (0);
}

