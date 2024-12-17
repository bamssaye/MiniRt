/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:27:12 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/17 01:50:10 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	vc3d_length(t_xyz a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_xyz	vc3d_normalize(t_xyz a)
{
	double	length;
    t_xyz   norm;

	length = vec3d_length(a);
	if (length == 0)
        return ((t_xyz){0,0,0,1});
	norm.x = a.x / length;
	norm.y = a.y / length;
	norm.z = a.z / length;
    norm.isv = a.isv;
	return (norm);
}
