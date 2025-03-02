/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_style.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:22:22 by bamssaye          #+#    #+#             */
/*   Updated: 2025/03/01 18:53:39 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void	set_style_co(t_bump *bump, int *style, t_hit *inter, t_co *co);
void	set_style_cy(t_bump *bump, int *style, t_hit *inter, t_cy *cy);
void	set_style_pl(t_bump *bump, int *style, t_hit *inter, t_pl *pl);
void	set_style_sp(t_bump *bump, int *style, t_hit *inter, t_sp *sp);

void	set_style_co(t_bump *bump, int *style, t_hit *inter, t_co *co)
{
	if (style[TEXTURE] == 1)
	{
		inter->closest.color = co_texture(&bump->img, \
		&inter->closest.point, co);
		inter->closest.normal = co_nomap(&bump->bump, co, &inter->closest);
	}
	else if (style[CHECKBORAD] == 1)
		inter->closest.color = co_checkerboard(&inter->closest.point, co);
}

void	set_style_cy(t_bump *bump, int *style, t_hit *inter, t_cy *cy)
{
	if (style[TEXTURE] == 1)
	{
		inter->closest.color = cy_texture(&bump->img, &inter->closest.point,
				cy);
		inter->closest.normal = cy_nomap(&bump->bump, cy, &inter->closest);
	}
	else if (style[CHECKBORAD] == 1)
		inter->closest.color = cy_checkerboard(&inter->closest.point, cy);
}

void	set_style_pl(t_bump *bump, int *style, t_hit *inter, t_pl *pl)
{
	if (style[TEXTURE] == 1)
	{
		inter->closest.color = pl_texture(&bump->img, &inter->closest.point,
				pl);
		inter->closest.normal = pl_nomap(&bump->bump, pl, &inter->closest);
	}
	else if (style[CHECKBORAD] == 1)
		inter->closest.color = pl_checkerboard(&inter->closest.point, pl);
}

void	set_style_sp(t_bump *bump, int *style, t_hit *inter, t_sp *sp)
{
	if (style[TEXTURE] == 1)
	{
		inter->closest.color = sp_texture(&bump->img, &inter->closest.point,
				sp);
		inter->closest.normal = sp_nomap(&bump->bump, sp, &inter->closest);
	}
	else if (style[CHECKBORAD] == 1)
		inter->closest.color = sp_checkerboard(&inter->closest.point, sp);
}
