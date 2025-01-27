/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:07:59 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/27 19:50:32 by bamssaye         ###   ########.fr       */
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

void	free_cmd(t_list *cmd)
{
	t_list	*tmp;
	t_object *t;

	if (!cmd)
		return ;
	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		t = (t_object*)tmp->content;
		free(t->object);
		free(t);
		free(tmp);
		tmp = NULL;
	}
}

void free_obj(t_object *obj)
{
	if (!obj)
		return ;
	free(obj->object);
	free(obj);
	obj = NULL;
}