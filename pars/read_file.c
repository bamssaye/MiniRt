/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:10:57 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/04 04:50:13 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

char **ft_readfile(char *path, t_minirt *mrt)
{
	int (fd);
	char (*line), (**check_line);
	static char *buffer;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror("open"), NULL);
	while (1)
	{
		line = get_next_line(fd, &buffer);
		if (!line)
			break;
		if (check_li(line))
		{
			check_line =  _tospace(line);
			valid_line(check_line, mrt);
			arry_c(check_line);
			free(line);
			free(buffer);
			break;
		}
		free(line);
	}
	close (fd);
	return (NULL);
}
/*
, arry_c(s), exit(1), 
*/