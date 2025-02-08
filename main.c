/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:30 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/08 07:24:51 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"

void	ft_init(t_minirt *mrt)
{
	ft_memset(mrt->amc, 0, sizeof(mrt->amc));
	mrt->x = 0;
	mrt->y = 0;
	mrt->object = NULL;
	mrt->obj_count = 0;
}
t_tex    load_texture(void *mlx, char *path){

	t_tex   tex;
 	// char *path = "./1.xpm";
	if (!access(path, R_OK))
		printf("yes");
    tex.img = mlx_xpm_file_to_image(mlx, path, &tex.width, &tex.height);
    if (!tex.img)
		exit(1);
    tex.addr = mlx_get_data_addr(tex.img, &tex.bpp,
        &tex.line_length, &tex.endian);
    return (tex);
}
int	main(int ac, char **av)
{
	t_minirt	minirt;

	if (ac != 2)
		return (1);
	ft_init(&minirt);
	if (ft_readfile(av[1], &minirt))
		return (printf("Error\n"), 1);
	
	t_object *oj = 	(t_object*)minirt.object->next->next->content;
	// t_object *ob1 = (t_object*)minirt.object->next->next->next->content;
	t_sphere *sp = (t_sphere*)oj->object;
	// t_plane *pl = (t_plane*)ob1->object;
	// t_object *ob2 = (t_object*)minirt.object->next->next->next->next->content;
	// t_sphere *sp1 = (t_sphere*)ob2->object;
	fprintf(stderr,"sss%s", sp->tex.path);
	ft_init_win(&minirt);
	sp->tex = load_texture(minirt.mlx.mlx, sp->tex.path);
	// sp1->tex = load_texture(minirt.mlx.mlx, "1.xpm");
	// pl->tex = load_texture(minirt.mlx.mlx, "2.xpm");
	render_image(&minirt);
	ft_hooks_fun(&minirt);
	return (0);
}
