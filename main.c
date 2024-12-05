/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:30 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/05 04:53:57 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"

void ft_init(t_minirt *mrt)
{
	int	i;
	
	i = -1;
	ft_memset(mrt->amc, 0, sizeof(mrt->amc));
	ft_memset(mrt->count_ob, 0, sizeof(mrt->amc));
	while (++i < 3)
		mrt->objects[i].object = NULL;
	// mrt->objects[0]
	//mrt->objects = (t_objects*)malloc(sizeof(t_objects) * 3);
	//mrt->objects[2] = NULL;
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
int	main(int ac, char **av)
{
	t_minirt minirt;

	(void) ac;
	ft_init(&minirt);
	if (ft_readfile(av[1], &minirt))
		return (printf("ERROOR\n"), 1);
	t_list	*objc;
	
	objc = minirt.objects[2].object;
	while (objc){
		printf("sp--------\n");
		fprintd((t_cylinder*)objc->content);
		objc = objc->next;
		printf("sp--------\n");
	}
	printf("count OBJECT: %d\n", minirt.count_ob[2]);
	free_cmd(minirt.objects[0].object);
	free_cmd(minirt.objects[1].object);
	free_cmd(minirt.objects[2].object);

	return (0);
}
