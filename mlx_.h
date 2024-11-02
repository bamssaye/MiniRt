#ifndef MLX__H
# define MLX__H
# include "minirt.h"

typedef struct s_prog	t_prog;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		endian;
}				t_image;

typedef struct s_mlx_confix
{
	void	*mlx;
	void	*win;
	t_image	img;
	int		is_initmlx;
	int		is_init_image;
	int		is_initwin;
}				t_mlx_confix;

void	mlx_my_putpixel(t_image *data, int x, int y, int color);
void	mlx_my_init(t_mlx_confix *vars);
void	fill_image_color(t_mlx_confix *vars);
#endif