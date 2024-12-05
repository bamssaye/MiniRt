/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:10:57 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/05 06:06:58 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	ft_readfile(char *path, t_minirt *mrt)
{
	static char	*buffer;

	char *(line), **(check_line);
	int (fd);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror("open"), 1);
	while (1)
	{
		line = get_next_line(fd, &buffer);
		if (!line)
			break ;
		check_line = tospace(line);
		if (valid_line(check_line, mrt))
			return (arry_c(check_line), free(line), free(buffer), 1);
		arry_c(check_line);
		free(line);
	}
	close(fd);
	return (0);
}
