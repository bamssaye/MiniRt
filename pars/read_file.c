/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:10:57 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/27 23:57:06 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	check_filename(char *s)
{
	char	*type;

	type = ft_strchr(s, '.');
	if (!type || ft_strncmp(type, ".rt", ft_strlen(type)))
		return (1);
	return (0);
}

int	check_lis(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isspace(str[i]))
			return (1);
	return (0);
}

int	tospaces(char *str, t_minirt *mrt)
{
	char	**line;
	int		i;

	i = -1;
	while (str[++i])
		if (ft_isspace(str[i]))
			str[i] = ' ';
	if (check_lis(str))
		return (0);
	line = ft_split(str, ' ');
	if (!*line)
		return (arry_c(line), 0);
	if (valid_line(line, mrt))
		return (arry_c(line), 1);
	return (arry_c(line), 0);
}

int	ft_readfile(char *path, t_minirt *mrt)
{
	static char	*buffer;

	char *(line);
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
		if (tospaces(line, mrt))
			return (free(line), free(buffer), free_cmd(mrt->object), close(fd),
				1);
		free(line);
	}
	close(fd);
	return (0);
}
