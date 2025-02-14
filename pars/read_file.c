/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:10:57 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/14 11:06:57 by bamssaye         ###   ########.fr       */
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
	if(str[0] == '#')
		return (0);
	if (check_lis(str))
		return (0);
	line = ft_split(str, ' ');
	if (!*line)
		return (arry_c(line), 0);
	if (valid_line(line, mrt))
		return (arry_c(line), 1);
	return (arry_c(line), 0);
}

void	ft_init(t_minirt *mrt)
{
	ft_memset(mrt->amc, 0, sizeof(mrt->amc));
	mrt->objs = (t_obj){.cy = NULL, .pl = NULL, .sp = NULL};
	mrt->x = 0;
	mrt->y = 0;
	mrt->count_t = 0;
	mrt->object = NULL;
	mrt->obj_c = 0;
}
int  free_line_error(char *line, t_list *obj, int *fd, char *buf)
{
	free(line);
	free(buf);
	free_cmd(obj);
	close(*fd);
	return (print_err(MSG_3, "LINE 1"));
}
int	ft_readfile(char *path, t_minirt *mrt)
{
	static char	*buffer;

	char *(line);
	int (fd);
	ft_init(mrt);
	if (check_filename(path))
		return (print_err(MSG_2 , "LINE 3"));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (print_err(MSG_2, "LINE 5"));
	while (1)
	{
		line = get_next_line(fd, &buffer);
		if (!line)
			break ;
		else if (tospaces(line, mrt))
			return (free_line_error(line, mrt->object, &fd, buffer));
		free(line);
	}
	close(fd);
	return (0);
}
