/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:04 by iel-koub          #+#    #+#             */
/*   Updated: 2025/02/20 13:30:14 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double	cy_ray_dista(t_ray ray, t_cy cy)
{
	t_vec3d	ori;

	double (a), (b), (c), (d_dn), (d_on);
	ori = v_minus(ray.origin, cy.point);
	d_on = v_dot(ori, cy.normal);
	d_dn = v_dot(ray.direction, cy.normal);
	a = v_dot(ray.direction, ray.direction) - (d_dn * d_dn);
	b = 2.0 * (v_dot(ori, ray.direction) - d_dn * d_on);
	c = v_dot(ori, ori) - (d_on * d_on) - (cy.radius * cy.radius);
	return (quad_equa(a, b, c));
}

void cy_caps(t_pl *pl, t_cy *cy, int is_top)
{
    t_vec3d offset;
    t_vec3d cap_ce;

    if (is_top)
    {
        offset = v_scale(cy->len / 2.0, cy->normal);
        cap_ce = v_plus(cy->point, offset);
		offset.isv = 1;
    }
    else
    {
        offset = v_scale(-cy->len / 2.0, cy->normal);
        cap_ce = v_plus(cy->point, offset);
		offset.isv = 0;
    }
    *pl = copy_pl(cap_ce, cy->normal, cy->color, offset);
}

int	check_cylinder_hit(t_cy *cy, t_hit *p)
{
	double	dist;
	t_vec3d	point_to_center;

	dist = cy_ray_dista(*p->ray, *cy);
    if (dist > 0.0)
    {
	    p->closest.point = v_plus(p->ray->origin, v_scale(dist, p->ray->direction));
	    p->closest.normal = v_normalize(v_minus(p->closest.point, cy->point));
	    point_to_center = v_minus(p->closest.point, cy->point);
	    if (fabs(v_dot(point_to_center, cy->normal)) < cy->len / 2.0)
	    {
		    p->closest.dista = dist;
		    p->hit_clos = 1;
		    p->closest.color = cpy_color(cy->color);
		    return (1);
	    }
	   
    } 
    return (0);
}

int check_top_cap_intersection(t_cy *cy, t_hit *inter)
{
    t_vec3d point_to_center;
    t_pl top_cap;

    cy_caps(&top_cap, cy, 1);
    if (plane_inter(&top_cap, inter, NULL, NULL))
    {
        point_to_center = v_minus(inter->closest.point, top_cap.point);
        if (v_magnitude(point_to_center) < cy->radius)
        {
            if (v_dot(inter->ray->direction, top_cap.normal) > 0)
                inter->closest.normal = v_scale(-1, top_cap.normal);
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

int check_bottom_cap_intersection(t_cy *cy, t_hit *inter)
{
    t_vec3d point_to_center;
    t_pl bottom_cap;

    cy_caps(&bottom_cap, cy, 0);
    if (plane_inter(&bottom_cap, inter, NULL, NULL))
    {
        point_to_center = v_minus(inter->closest.point, bottom_cap.point);
        if (v_magnitude(point_to_center) < cy->radius)
        {
			if (v_dot(inter->ray->direction, bottom_cap.normal) > 0)
					inter->closest.normal = v_scale(-1, bottom_cap.normal);
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

int check_cylinder_caps_intersection(t_cy *cy, t_hit *inter)
{
    t_hit (bottom_inter), (top_inter);
    int (hit_bottom), (hit_top);
    top_inter = *inter;
    bottom_inter = *inter;
    hit_top = check_top_cap_intersection(cy, &top_inter);
    hit_bottom = check_bottom_cap_intersection(cy, &bottom_inter);
    if (hit_top && hit_bottom) 
    {
        if (top_inter.closest.dista < bottom_inter.closest.dista)
            *inter = top_inter;
        else
            *inter = bottom_inter;
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


void cy_inter(t_cy *cy, t_hit *f_inter, t_bump *bump, int *style)
{
    t_hit (tmp_body), (tmp_caps);
    tmp_body = *f_inter;
    if (check_cylinder_hit(cy, &tmp_body))
    {
        *f_inter = tmp_body;
        if (style[COLOR] != 1)
			set_style_cy(bump, style, f_inter, cy);
    }
    tmp_caps = *f_inter;
    if (check_cylinder_caps_intersection(cy, &tmp_caps))
    {
        if (tmp_caps.closest.dista < f_inter->closest.dista)
        {
            *f_inter = tmp_caps;
            if (style[COLOR] != 1)
			    set_style_cy(bump, style, f_inter, cy);
        }
    }
}

