/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:04 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/17 13:26:20 by iel-koub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	cy_ray_dista(t_ray ray, t_cylinder cy)
{
	t_vec3d	ori;

	double(a), (b), (c), (po), (bb), (cc);
	ori = vec3d_minus(ray.origin, cy.point);
	po = vec3d_dot(ray.direction, cy.normal);
	a = vec3d_dot(ray.direction, ray.direction) - pow(po, 2);
	bb = vec3d_dot(ray.direction, cy.normal);
	cc = vec3d_dot(ori, cy.normal);
	b = 2.0 * (vec3d_dot(ori, ray.direction) - bb * cc);
	c = vec3d_dot(ori, ori) - pow(cc, 2) - (cy.radius * cy.radius);
	return (quad_equa(a, b, c));
}

void cy_caps(t_plane *pl, t_cylinder *cy, int is_top)
{
    t_vec3d offset;
    t_vec3d cap_ce;

    if (is_top)
    {
        offset = vec3d_scale(cy->len / 2.0, cy->normal);
        cap_ce = vec3d_plus(cy->point, offset);
		offset.isv = 1;
    }
    else
    {
        offset = vec3d_scale(-cy->len / 2.0, cy->normal);
        cap_ce = vec3d_plus(cy->point, offset);
		offset.isv = 0;
    }
    *pl = copy_pl(cap_ce, cy->normal, cy->color, offset);
}

int	check_cylinder_hit(t_cylinder *cy, t_in_pa *p)
{
	double	dist;
	t_vec3d	point_to_center;

	dist = cy_ray_dista(*p->ray, *cy);
	// printf("|  %f |", dist);
    if (dist > 0.0)
    {
		// printf("|  %f |", dist);
	    p->closest.point = vec3d_plus(p->ray->origin, vec3d_scale(dist, p->ray->direction));
		// printf("  Point: (%.2f, %.2f, %.2f)", p->closest.point.x, p->closest.point.y, p->closest.point.z);
	    p->closest.normal = vec3d_normalize(vec3d_minus(p->closest.point, cy->point));
	    point_to_center = vec3d_minus(p->closest.point, cy->point);
	    if (fabs(vec3d_dot(point_to_center, cy->normal)) < cy->len / 2.0)
	    {
		    p->closest.dista = dist;
		    p->hit_clos = 1;
		    p->closest.color = cpy_color(cy->color);
		    return (1);
	    }
	   
    } 
    return (0);
}

int check_top_cap_intersection(t_cylinder *cy, t_in_pa *inter)
{
    t_vec3d point_to_center;
    t_plane top_cap;

    cy_caps(&top_cap, cy, 1);
    if (plane_inter(&top_cap, inter))
    {
        point_to_center = vec3d_minus(inter->closest.point, top_cap.point);
        if (vec3d_length(point_to_center) < cy->radius)
        {
            // printf("  Top Cap Intersection: (%.2f, %.2f, %.2f)\n", 
            //         inter->closest.point.x, 
            //         inter->closest.point.y, 
            //         inter->closest.point.z);
			// printf("  Top Cap Intersection: (%.2f)\n", 
			// 	inter->closest.dista);
            if (vec3d_dot(inter->ray->direction, top_cap.normal) > 0)
                inter->closest.normal = vec3d_scale(-1, top_cap.normal);
            else
                inter->closest.normal = top_cap.normal;
			inter->closest.dista = inter->closest.dista;
            inter->hit_clos = 1;
            inter->closest.color = cpy_color(cy->color);
            return (1);
        }
    }
    return (0);
}

int check_bottom_cap_intersection(t_cylinder *cy, t_in_pa *inter)
{
    t_vec3d point_to_center;
    t_plane bottom_cap;

    cy_caps(&bottom_cap, cy, 0);
    if (plane_inter(&bottom_cap, inter))
    {
        point_to_center = vec3d_minus(inter->closest.point, bottom_cap.point);
        if (vec3d_length(point_to_center) < cy->radius)
        {
            // printf("  Bottom Cap Intersection: (%.2f, %.2f, %.2f)\n", 
            //         inter->closest.point.x, 
            //         inter->closest.point.y, 
            //         inter->closest.point.z);

			// printf("  Bottom Cap Intersection: (%.2f)\n", 
			// 	inter->closest.dista);
			if (vec3d_dot(inter->ray->direction, bottom_cap.normal) > 0)
					inter->closest.normal = vec3d_scale(-1, bottom_cap.normal);
			else
					inter->closest.normal = bottom_cap.normal;
			inter->closest.dista = inter->closest.dista;
            inter->hit_clos = 1;
            inter->closest.color = cpy_color(cy->color);
            return (1);
        }
    }
    return (0);
}

int check_cylinder_caps_intersection(t_cylinder *cy, t_in_pa *inter)
{
    t_in_pa top_inter;
    t_in_pa bottom_inter;

    int hit_top;
    int hit_bottom;
    
    top_inter = *inter;
    bottom_inter = *inter;
    hit_top = check_top_cap_intersection(cy, &top_inter);
    hit_bottom = check_bottom_cap_intersection(cy, &bottom_inter);
    if (hit_top && hit_bottom) 
    {
        if (top_inter.closest.dista < bottom_inter.closest.dista)
        {
            *inter = top_inter;
        }
        else
        {
            *inter = bottom_inter;
        }
        return 1;
    }
    if (hit_top)
    {
        *inter = top_inter;
        return 1;
    }
    if (hit_bottom)
    {
        *inter = bottom_inter;
        return 1;
    }
    return 0;
}

void cy_inter(t_cylinder *cy, t_in_pa *f_inter)
{
    t_in_pa tmp_body = *f_inter;
    t_in_pa tmp_caps = *f_inter;


    tmp_body = *f_inter;
    if (check_cylinder_hit(cy, &tmp_body))
    {
        *f_inter = tmp_body;
    }
    tmp_caps = *f_inter;
    if (check_cylinder_caps_intersection(cy, &tmp_caps))
    {
        if (tmp_caps.closest.dista < f_inter->closest.dista)
        {
            *f_inter = tmp_caps;
        }
    }
}