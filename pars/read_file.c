/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:10:57 by bamssaye          #+#    #+#             */
/*   Updated: 2025/03/01 20:53:37 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

static int	check_filename(char *s)
{
	char	*type;

	type = ft_strchr(s, '.');
	if (!type || ft_strncmp(type, ".rt", ft_strlen(type)))
		return (1);
	return (0);
}

static int	line_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isspace(str[i]))
			return (1);
	return (0);
}

static int	tospaces(char *str, t_minirt *mrt)
{
	char	**line;
	int		i;

	i = -1;
	while (str[++i])
		if (ft_isspace(str[i]))
			str[i] = ' ';
	if (str[0] == '#')
		return (0);
	if (line_space(str))
		return (0);
	line = ft_split(str, ' ');
	if (!*line)
		return (arry_c(line), 0);
	if (valid_line(line, mrt))
		return (arry_c(line), 1);
	return (arry_c(line), 0);
}

static int	free_line_error(char *line, t_minirt *mrt, int *fd, char *buf)
{
	free(line);
	free(buf);
	free_cmd(mrt->object, mrt, 0);
	close(*fd);
	return (1);
}

int	ft_readfile(char *path, t_minirt *mrt)
{
	static char	*buffer;

	char *(line);
	int (fd);
	if (check_filename(path))
		return (print_err(MSG, MSG_2));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (print_err(MSG, MSG_2));
	while (1)
	{
		line = get_next_line(fd, &buffer);
		if (!line)
			break ;
		else if (tospaces(line, mrt))
			return (free_line_error(line, mrt, &fd, buffer));
		free(line);
	}
	close(fd);
	return (0);
}
