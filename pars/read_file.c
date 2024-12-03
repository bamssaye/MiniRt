/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:10:57 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/03 05:16:32 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

char **ft_readfile(char *path, t_minirt *mrt)
{
	int (fd);
	char *line;
	char **check_line;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror("open"), NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		if (check_li(line))
		{
			check_line =  _tospace(line);
			valid_line(check_line, mrt);
			arry_c(check_line);
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (NULL);
}
