#include "../headers/minirt.h"

int	strreplace_space(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r')
			str[i] = ' ';
		i++;
	}
	return (0);
}

int	read_rt_file(char *filepath, t_prog *prog)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(filepath, O_RDONLY);
	if(!fd)
		return(0);
	while (1)
	{
		line = get_next_line(fd);
		strreplace_space(line);
		if (!line)
			break ;
		check_line(line, prog);
		// free(line);
	}
	close(fd);
	return (0);
}

int	check_line_type(char **spl, t_prog *prog)
{
	if(!spl[0])
		return(0);
	if(ft_strncmp(spl[0], "C", ft_strlen(spl[0])) == 0)
		setup_camera_from_input(spl, prog);
	if (ft_strncmp(spl[0], "A", ft_strlen(spl[0])) == 0)
		setup_ambient_from_input(spl, prog);
	if (ft_strncmp(spl[0], "L", ft_strlen(spl[0])) == 0)
		setup_light_from_input(spl, prog);
	if (ft_strncmp(spl[0], "sp", ft_strlen(spl[0])) == 0)
		setup_sphere_from_input(spl, prog);
	if (ft_strncmp(spl[0], "pl", ft_strlen(spl[0])) == 0)
		setup_plane_from_input(spl, prog);
	if (ft_strncmp(spl[0], "cy", ft_strlen(spl[0])) == 0)
		setup_cylinder_from_input(spl, prog);
	return (0);
}

int	is_skip_line(char *line)
{
	if (line == NULL)
		return (1);
	if (ft_strlen(line) == 0)
		return (1);
	if (ft_strlen(line) == 1 && line[0] == '\n')
		return (1);
	if (ft_strncmp(line, "#", 1) == 0)
		return (1);
	return (0);
}



int	check_line(char *lint, t_prog *prog)
{
	char	**split_out;
	char	*line;
	int		skiped;

	line = ft_strtrim(lint, " \t\n");
	skiped = is_skip_line(line);
	if (!skiped)
	{
		split_out = ft_split(line, ' ');
		if(!split_out)
			return(0);
		check_line_type(split_out, prog);
	}
	// free(line);
	return (0);
}