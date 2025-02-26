/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:33:08 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/25 23:47:13 by bamssaye         ###   ########.fr       */
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
    t_vec3d local;

    int (x), (y);
    double (u), (v);
    local = find_perpendicular(pl->normal, *hpoint, pl->point);
    double scale = 0.01;
    u = fmod(fabs(local.x * scale), 1.0);
    v = fmod(fabs(local.y * scale), 1.0);
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

t_color cy_texture(t_tex *tex, t_vec3d *hpoint, t_cy *cy)
{
	char *pixel;
    t_vec3d local;

    double (u), (v);
    int (x),(y);
    local = find_perpendicular(cy->normal, *hpoint, cy->point);
    u = 0.5 + atan2(local.x, local.y) / (2 * PI);
    v = fabs(local.z / cy->len);
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

t_color co_texture(t_tex *tex, t_vec3d *hpoint, t_co *co)
{
	char *pixel;

    double (u), (v);
    int (x),(y);
    u = 0.5 + atan2(hpoint->z - co->point.z, hpoint->x - co->point.x) / (2 * PI);
    v = fabs((hpoint->y - co->point.y) / co->height);
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
