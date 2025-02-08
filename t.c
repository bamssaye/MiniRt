#include "headers/minirt.h"

// typedef struct s_tex
// {
// 	void	*img;
// 	char	*addr;
// 	int		bpp;
// 	int		width;
// 	int		endian;
// 	int		height;
// 	int 	line_length;
// }			t_tex;
char *file_name(char *str)
{
	int i = -1;
	while(++str)
	{
		if(str[i] == ':')
			return (str+(i+1));
	}
	return (NULL);
}

t_tex    get_texture(void *mlx){

	t_tex   tex;
 	char *path = "texture:./1.xpm";

	if (!access(path+8, R_OK))
		printf("yes");
    tex.img = mlx_xpm_file_to_image(mlx, path+8, &tex.width, &tex.height);
    if (!tex.img)
		exit(8);
    tex.addr = mlx_get_data_addr(tex.img, &tex.bpp,
        &tex.line_length, &tex.endian);
    return (tex);
}

int	main(void)
{
	void	*mlx;
    void	*mlx_win;
    t_tex img;
	// void	*img;
	// char	*relative_path = "./1.xpm";
	// int		img_width;
	// int		img_height;
	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img = get_texture(mlx);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

}