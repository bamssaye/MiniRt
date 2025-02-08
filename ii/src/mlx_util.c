#include "../headers/minirt.h"

int	close_window(void)
{
	exit(0);
}

void	prog_mlx_loop(t_prog *prog)
{
	t_mlx_confix	*vars;

	vars = &(prog->mlx_config);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_loop(vars->mlx);
}

void	mlx_my_putpixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->width + x * (data->bpp >> 3));
	*(unsigned int *) dst = color;
}
