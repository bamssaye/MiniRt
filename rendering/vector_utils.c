/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:27:12 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/09 04:26:49 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

// double	vec3d_length(t_xyz *a)
// {
// 	if (a == NULL)
// 		return (1);
// 	return (sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
// }

t_xyz	vec3d_normalize(t_xyz a)
{
	double	length;
    t_xyz   norm;

	length = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	// norm.x = a.x / length;
	// norm.y = a.y / length;
	// norm.z = a.z / length;
    // norm.isv = a.isv;
    if (fabs(length - 1) < 0.00001)
        return ((t_xyz){0,0,0,1});
	return (norm);
}
