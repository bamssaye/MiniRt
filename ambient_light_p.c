#include "minirt.h"

int	collect_ambient(char **split_line, t_prog *prog)
{
	double	intensity;

	ft_strtod(split_line[1], &intensity);
	color_collect_string(split_line[2], &prog->ambient_color);
	color_scale(&prog->ambient_color, intensity, &prog->ambient_color);
	prog->ambient_intensity = intensity;
	return (0);
}

