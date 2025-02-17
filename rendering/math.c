/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:24 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/17 13:26:38 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double quad_equa(double a, double b, double c)
{
	 double discriminant;
	 double t1;
	 double t2;
	 double sqrtdiscriminant;

	 if (a == 0.0)
		 return -1;
	 discriminant = b * b - 4.0 * a * c;
	 if (discriminant < 0.0)
		 return (-1);
	 sqrtdiscriminant = sqrt(discriminant);
	 t1 = (-b + sqrtdiscriminant) / (2.0 * a);
	 t2 = (-b - sqrtdiscriminant) / (2.0 * a);
	 if (discriminant == 0)
		 return (t1);
	 if (discriminant > 0.0)
	 {
		if (t1 < 0.0 && t2 < 0.0)
			return (-1);
		else if (t1 < 0.0)
			return t2;
		else if (t2 < 0.0)
			return t1;
		else
			return fmin(t1, t2);
	 }
	 return (-1);
}

double	vec3d_dot(t_vec3d a, t_vec3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	vec3d_length(t_vec3d a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

double c_light_scale(t_vec3d a, t_vec3d b) // Lambertian diffuse
{
    double cosine;

	cosine = vec3d_dot(a, b);
	return fmax(cosine, 0.0);
}
