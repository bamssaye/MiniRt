/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:48:49 by bamssaye          #+#    #+#             */
/*   Updated: 2024/11/07 01:48:50 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	prog_constructor(t_prog *prog)
{
	prog->obj = NULL;
	prog->has_camera = 0;
	prog->item_count = 0;
	init_light(&prog->light);
	return (0);
}

void	init_light(t_light *l)
{
	t_color	color;

	color = (t_color){0, 0, 0};
	ft_memcpy(&l->color, &color, sizeof(t_color));
	l->intensity = 0;
}

int	read_rt_file(char *filepath, t_prog *prog)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(filepath, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		strreplace_space(line);
		if (!line)
			break ;
		check_line(line, prog);
		free(line);
	}
	close(fd);
	return (0);
}

