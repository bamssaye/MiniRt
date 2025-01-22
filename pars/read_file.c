/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:10:57 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/22 14:49:26 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int check_filename(char *s)
{
	char *type;
	
	type = ft_strchr(s, '.');
	if(!type || ft_strncmp(type, ".rt", ft_strlen(type)))
		return (1);
	return (0);
}

int	ft_readfile(char *path, t_minirt *mrt)
{
	static char	*buffer;

	char *(line), **(check_line);
	int (fd);
	if (check_filename(path))
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd, &buffer);
		if (!line)
			break ;
		check_line = tospace(line);
		if (valid_line(check_line, mrt))
			return (arry_c(check_line), free(line), free(buffer), 1);
		///////
		arry_c(check_line);
		free(line);
	}
	// free_cmd(mrt->objects[PLANE].object);
	close(fd);
	return (0);
}
