#include "../headers/minirt.h"

int	setup_ambient_from_input(char **split_line, t_prog *prog)
{
	double	intensity;

	if (prog->has_ambient == 1)
	{
		// Only one ambient light is allowed
		return (1);
	}
	prog->has_ambient = 1;
	ft_strtod(split_line[1], &intensity);
	color_collect_string(split_line[2], &prog->ambient_color);
	color_scale(&prog->ambient_color, intensity, &prog->ambient_color);
	prog->ambient_intensity = intensity;
	return (0);
}

int	setup_light_from_input(char **splited_line, t_prog *prog)
{
	t_light	*light;

	if (prog->has_light == 1)
	{
		// Only one light is allowed
		return (1);
	}
	prog->has_light = 1;
	light = &prog->light;
	initialize_vector_from_string(splited_line[1], &light->position);
	ft_strtod(splited_line[2], &light->intensity);
	return (0);
}
