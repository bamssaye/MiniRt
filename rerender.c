#include "minirt.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
	{
		return (0);
	}
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

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

int	re_render(t_prog *prog)
{
	t_mlx_confix	*vars;

	render_image(prog);
	vars = &(prog->mlx_config);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
