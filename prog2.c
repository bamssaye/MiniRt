#include "minirt.h"

int	check_line_type(char **spl, t_prog *prog)
{
	if (ft_strncmp(spl[0], "C", ft_strlen(spl[0])) == 0)
		collect_camera(spl, prog);
	if (ft_strncmp(spl[0], "A", ft_strlen(spl[0])) == 0)
		collect_ambient(spl, prog);
	if (ft_strncmp(spl[0], "sp", ft_strlen(spl[0])) == 0)
		collect_sphere(spl, prog);
	if (ft_strncmp(spl[0], "pl", ft_strlen(spl[0])) == 0)
		collect_plane(spl, prog);
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
		check_line_type(split_out, prog);
	}
	free(line);
	return (0);
}

