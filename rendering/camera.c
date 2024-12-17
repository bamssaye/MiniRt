/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 01:17:52 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/17 07:18:22 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

float dot_p(t_xyz vec, t_xyz p)
{
   return (vec.x * p.x + vec.y * p.y + vec.z * p.z);
}
void fill_mx(float *row, t_xyz v, int n)
{
    if (!(n & 1))
    {
        row[0] = v.x * -1;
        row[1] = v.y * -1;
        row[2] = v.z * -1;
        row[3] = 0;
        return ;
    }
    row[0] = v.x;
    row[1] = v.y;
    row[2] = v.z;
    row[3] = 0;
    
}

void view_mx(t_mx4 *vmx, t_camera *cm, t_xyz *up, t_xyz *tg)
{
    t_xyz (der), (ri), (cros);
    der = (t_xyz){tg->x - cm->c_xyz.x, tg->y - cm->c_xyz.y, 
            tg->z - cm->c_xyz.z, 1};
    der = vc3d_normalize(der);
    ri = (t_xyz){((der.y * up->z) - (der.z * up->y)),
        ((der.z * up->x) - (der.x * up->z)),
        ((der.x * up->y) - (der.y * up->x)), 1};
    ri = vc3d_normalize(ri);
    cros = (t_xyz){((ri.y * der.z) - (ri.z * der.y)),
        ((ri.z * der.x) - (ri.x * der.z)),
        ((der.x * der.y) - (ri.y * der.x)), 1};
    cros = vc3d_normalize(cros);
    ft_memset (vmx, 0, sizeof(t_mx4));
    fill_mx(vmx->mx[0], ri, 0);
    fill_mx(vmx->mx[1], *up, 0);
    fill_mx(vmx->mx[2], (der), 1);
    vmx->mx[3][0] = -dot_p(ri, cm->c_xyz);
    vmx->mx[3][1] = -dot_p(*up, cm->c_xyz);
    vmx->mx[3][2] = dot_p(der, cm->c_xyz);
    vmx->mx[3][3] = 1.0;
}

void proj_mx(t_mx4 *p_mx, t_camera *cm)
{
    float h_fov;
    
    h_fov = tan(((cm->fov * PI) / 180.0) / 2.0);
    ft_memset(p_mx->mx, 0, sizeof(float) * 16);
    p_mx->mx[0][0] = 1.0f / ((float)(W_WIDTH / W_HEIGHT) * h_fov);
    p_mx->mx[1][1] = 1.0f / h_fov;
    p_mx->mx[2][2] = -(100.0 + 0.1) / (100 - 0.1);
    p_mx->mx[2][3] = -1.0;
    p_mx->mx[3][2] = -(2.0 * 100.0 * 0.1) / (100 - 0.1);

}
void camera_init(t_camera *cm)
{
    t_xyz (up), (tg);
    up = (t_xyz){0, 1, 0, 1};
    tg = (t_xyz){cm->c_xyz.x + cm->vec_xyz.x, 
                cm->c_xyz.y + cm->vec_xyz.y, 
                cm->c_xyz.z + cm->vec_xyz.z, 1};
    view_mx(&cm->v_mx, cm, &up, &tg);
    proj_mx(&cm->p_mx, cm);
}
