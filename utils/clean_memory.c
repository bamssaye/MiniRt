/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:07:59 by bamssaye          #+#    #+#             */
/*   Updated: 2025/03/01 18:39:27 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void	arry_c(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	free_cmd(t_list *cmd, t_minirt *rt, int f)
{
	t_list		*tmp;
	t_object	*t;

	(void)f;
	if (!cmd)
		return ;
	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		t = (t_object *)tmp->content;
		if (t->bum_tex.img.img)
			mlx_destroy_image(rt->mlx.mlx, t->bum_tex.img.img);
		if (t->bum_tex.bump.img)
			mlx_destroy_image(rt->mlx.mlx, t->bum_tex.bump.img);
		if (t->path)
			free(t->path);
		free(t->object);
		free(t);
		free(tmp);
		tmp = NULL;
	}
}

void	free_obj(t_object *obj) //
{
	if (!obj)
		return ;
	free(obj->object);
	free(obj);
	obj = NULL;
}
