/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:20:54 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/14 14:22:25 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

/*
	ex : d_dn => dot(direction, normal)
	a = d_dd - (d_dn)^2
	b = 2 * (d_do - (d_dn)*(d_on))
	c = d_xx - (d_on)^2 - r*r
*/
double	cy_ray_dista(t_ray ray, t_cy cy)
{
	t_vec3d	ori;

	double (a), (b), (c), (d_dn), (d_on);
	ori = vec3d_minus(&ray.origin, &cy.point);
	d_on = vec3d_dot(&ori, &cy.normal);
	d_dn = vec3d_dot(&ray.direction, &cy.normal);
	a = vec3d_dot(&ray.direction, &ray.direction) - (d_dn * d_dn);
	b = 2.0 * (vec3d_dot(&ori, &ray.direction) - d_dn * d_on);
	c = vec3d_dot(&ori, &ori) - (d_on * d_on) - (cy.radius * cy.radius);
	return (quad_equa(a, b, c));
}

void	cy_caps(t_pl *pl, t_cy *cy)
{
	t_vec3d		offset;
	t_vec3d		cap_ce;

	offset = v_scale(cy->len / 2.0, &cy->normal);
	cap_ce = vec3d_plus(&cy->point, &offset);
	offset.isv = 0;
	pl[0] = copy_pl(&cap_ce, &cy->normal, &cy->color, &offset);
	offset = v_scale(-cy->len / 2.0, &cy->normal);
	cap_ce = vec3d_plus(&cy->point, &offset);
	offset.isv = 1;
	pl[1] = copy_pl(&cap_ce, &cy->normal, &cy->color, &offset);
}

int	check_cylinder_hit(t_cy *cy, t_in_pa *p)
{
	double	dist;
	t_vec3d	point_to_center;

	dist = cy_ray_dista(*p->ray, *cy);
	if (dist > 0.0)
	{
		p->closest.point = v_scale(dist, &p->ray->direction);
		p->closest.point = vec3d_plus(&p->ray->origin, &p->closest.point);
		p->closest.normal = vec3d_minus(&p->closest.point, &cy->point);
		p->closest.normal = vec3d_normalize(&p->closest.normal);
		point_to_center = vec3d_minus(&p->closest.point, &cy->point);
		if (fabs(vec3d_dot(&point_to_center, &cy->normal)) < cy->len / 2.0)
		{
			p->closest.dista = dist;
			p->hit_clos = 1;
			p->closest.color = cpy_color(&cy->color);
			return (1);
		}
	}
	return (0);
}
int	plane_interss(t_pl *plane, t_ray *ray, t_npc *closet)
{
	double	dist;
	dist = pl_ray_dista(*ray, *plane, closet);
	if (dist > 0)
	{
		*closet = pl_closest(ray->direction, *plane, dist, ray->origin);
	}
	return (dist);
}

int	check_cylinder_caps_intersection(t_cy *cy, t_in_pa *intersection)
{
	t_vec3d	point_to_center;
	t_pl	pl[2];
	int		i;

	i = 0;
	cy_caps(pl, cy);
	while (i < 2)
	{
		if (plane_interss(&pl[i], intersection->ray, &intersection->closest))
		{
			point_to_center = vec3d_minus(&intersection->closest.point,
					&pl[i].point);
			if (vec3d_magnitude(&point_to_center) < cy->radius)
				return (1);
		}
		i++;
	}
	return (0);
}


void	cy_inter(t_cy *cy, t_in_pa *f_inter)
{
	t_in_pa	tmp_inter;


	if (check_cylinder_hit(cy, f_inter))
		return ;
	tmp_inter = cpy_tmp_inter(f_inter);
	if (check_cylinder_caps_intersection(cy, &tmp_inter))
	{
		f_inter->hit_clos = 1;
		f_inter->closest = cpy_npc(&tmp_inter.closest);
		return ;
	}
}
	