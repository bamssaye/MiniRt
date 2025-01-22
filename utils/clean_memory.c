/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:07:59 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/05 07:54:39 by bamssaye         ###   ########.fr       */
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

	if (!cmd)
		return ;
	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		free(tmp->content);
		free(tmp);
		tmp = NULL;
	}
}
