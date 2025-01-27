/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:20:54 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/27 23:54:26 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	cy_ray_dista(t_ray ray, t_cylinder cy)
{
	t_vec3d	ori;

	double (a), (b), (c), (po), (bb), (cc);
	ori = vec3d_minus(ray.origin, cy.point);
	po = vec3d_dot(ray.direction, cy.normal);
	a = vec3d_dot(ray.direction, ray.direction) - pow(po, 2);
	bb = vec3d_dot(ray.direction, cy.normal);
	cc = vec3d_dot(ori, cy.normal);
	b = 2.0 * (vec3d_dot(ori, ray.direction) - bb * cc);
	c = vec3d_dot(ori, ori) - pow(cc, 2) - (cy.radius * cy.radius);
	return (quad_equa(a, b, c));
}

void	cy_caps(t_plane *pl, t_cylinder *cy)
{
	t_vec3d		offset;
	t_vec3d		cap_ce;

	offset = vec3d_scale(cy->len / 2.0, cy->normal);
	cap_ce = vec3d_plus(cy->point, offset);
	offset.isv = 0;
	pl[0] = copy_pl(cap_ce, cy->normal, cy->color, offset);
	offset.isv = 1;
	offset = vec3d_scale(-cy->len / 2.0, cy->normal);
	cap_ce = vec3d_plus(cy->point, offset);
	pl[1] = copy_pl(cap_ce, cy->normal, cy->color, offset);
}

int	check_cylinder_hit(t_cylinder *cy, t_in_pa *p)
{
	double	dist;
	t_vec3d	point_to_center;

	dist = cy_ray_dista(*p->ray, *cy);
	if (dist > 0.0)
	{
		p->closest.point = vec3d_scale(dist, p->ray->direction);
		p->closest.point = vec3d_plus(p->ray->origin, p->closest.point);
		p->closest.normal = vec3d_minus(p->closest.normal, cy->point);
		p->closest.normal = vec3d_normalize(p->closest.normal);
		point_to_center = vec3d_minus(p->closest.point, cy->point);
		if (fabs(vec3d_dot(point_to_center, cy->normal)) < cy->len / 2.0)
		{
			p->closest.dista = dist;
			p->hit_clos = 1;
			ft_memcpy(&p->closest.color, &cy->color, sizeof(t_color));
			return (1);
		}
	}
	return (0);
}

int	check_cylinder_caps_intersection(t_cylinder *cy, t_in_pa *intersection)
{
	t_vec3d	point_to_center;
	t_plane	pl[2];
	int		i;

	i = 0;
	cy_caps(pl, cy);
	while (i < 2)
	{
		if (plane_inter(&pl[i], intersection))
		{
			point_to_center = vec3d_minus(intersection->closest.point,
					pl[i].point);
			if (vec3d_length(point_to_center) < cy->radius)
			{
				intersection->closest.dista = intersection->closest.dista;
				intersection->hit_clos = 1;
				ft_memcpy(&intersection->closest.color, &cy->color,
					sizeof(t_color));
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	cy_inter(t_cylinder *cy, t_in_pa *f_inter)
{
	int		i;
	t_in_pa	tmp_inter[3];

	i = -1;
	while (++i < 3)
		ft_memcpy(&tmp_inter[i], f_inter, sizeof(t_in_pa));
	if (check_cylinder_hit(cy, &tmp_inter[0]))
	{
		f_inter->hit_clos = tmp_inter[0].hit_clos;
		ft_memcpy(&f_inter->closest, &tmp_inter[0].closest, sizeof(t_npc));
		return ;
	}
	if (check_cylinder_caps_intersection(cy, &tmp_inter[1]))
	{
		f_inter->hit_clos = tmp_inter[1].hit_clos;
		ft_memcpy(&f_inter->closest, &tmp_inter[1].closest, sizeof(t_npc));
		return ;
	}
}
