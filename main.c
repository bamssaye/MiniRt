#include "minirt.h"

int	main(int argc, char **argv)
{
	t_prog			prog;
	t_mlx_confix	*vars;

	vars = &(prog.mlx_config);
	prog_constructor(&prog);
	(void)argc;
	(void)argv;
	read_rt_file(argv[1], &prog);
	prog_init_mlx(&prog);
	render_image(&prog);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	prog_mlx_loop(&prog);
	return (0);
}
