/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:33:08 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/19 21:38:57 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"


t_color pl_texture(t_tex *tex, t_vec3d *hpoint, t_pl *pl);
t_color sp_texture(t_tex *tex, t_vec3d *hpoint, t_sp *sp);
t_color cy_texture(t_tex *tex, t_vec3d *hpoint, t_cy *cy);

t_color sp_texture(t_tex *tex, t_vec3d *hpoint, t_sp *sp)
{	
	char *pixel;
    
    double (u), (v);
    int (x), (y);
	u = 0.5 + atan2(hpoint->z - sp->center.z, \
        hpoint->x - sp->center.x) / (2 * PI);
    v = 0.5 - asin((hpoint->y - sp->center.y) / sp->radius) / PI;
    x = (int)(u * tex->width) % tex->width;
    y = (int)(v * tex->height) % tex->height;
    pixel = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
    return ((t_color){
        (unsigned char)pixel[2],
        (unsigned char)pixel[1],
        (unsigned char)pixel[0],
        0
    });
}

t_color pl_texture(t_tex *tex, t_vec3d *hpoint, t_pl *pl)
{
    char *pixel;

    t_vec3d (up), (right), (up_dir), (corss);
    double (u), (v);
    up = (t_vec3d){0, 1, 0, 0};
    right = v_cross(pl->normal, up);
    if (v_magnitude(right) < 0.01)
    {
        up = (t_vec3d){0, 0, 1, 0};
        right = v_cross(pl->normal, up);
    }
    right = v_normalize(right);
    corss = v_cross(right, pl->normal);
    up_dir = v_normalize(corss);
    u = fmod(v_dot(*hpoint, right) * 0.1, 1.0);
    v = fmod(v_dot(*hpoint, up_dir) * 0.1, 1.0);
    if (u < 0)
        u += 1.0;
    if (v < 0)
        v += 1.0;
    pixel = tex->addr + ((int)(v * tex->height) % tex->height) * \
     tex->line_length + ((int)(u * tex->width) % tex->width) * (tex->bpp / 8);
    return ((t_color){(unsigned char)pixel[2], (unsigned char)pixel[1], \
        (unsigned char)pixel[0], 0});
}

t_color cy_texture(t_tex *tex, t_vec3d *hpoint, t_cy *cy)
{
	char *pixel;

    double (u), (v);
    int (x),(y);
    u = 0.5 + atan2(hpoint->z - cy->point.z, hpoint->x - cy->point.x) / (2 * PI);
    v = fabs((hpoint->y - cy->point.y) / cy->len);
    x = (int)(u * tex->width);
    y = (int)(v * tex->height);
    pixel = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
    return ((t_color){
        (unsigned char)pixel[2],
        (unsigned char)pixel[1],
        (unsigned char)pixel[0],
        0
    });
}
