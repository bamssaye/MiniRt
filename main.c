/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:30 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/12 05:21:03 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"

void	ft_init(t_minirt *mrt)
{
	ft_memset(mrt->amc, 0, sizeof(mrt->amc));
	mrt->x = 0;
	mrt->y = 0;
	mrt->count_t = 0;
	mrt->object = NULL;
	mrt->obj_count = 0;
}
t_tex    load_img(void *mlx, char *path){

	t_tex   tex;
	// if (!access(path, R_OK))
	// 	exit(1);
	tex.path = path;
	printf("%s\n", path+8);
    tex.img = mlx_xpm_file_to_image(mlx, path+8, &tex.width, &tex.height);
	if (!tex.img)
		exit(1);
    tex.addr = mlx_get_data_addr(tex.img, &tex.bpp,
        &tex.line_length, &tex.endian);
    return (tex);
}
void load_texture(t_minirt *rt, t_list *lst)
{
	t_list *tmp;
	t_object *obj;
	t_sphere	*sp;
	t_plane		*pl;
	
	tmp = lst;
	while (tmp)
	{
		obj = (t_object*)tmp->content;
		if (obj->type == SPHERE && obj->t)
		{
			sp = (t_sphere*)obj->object;
			sp->tex = load_img(rt->mlx.mlx, sp->tex.path);
			sp->no_map = load_img(rt->mlx.mlx, "texture:./texture/check2.xpm");
		}
		if (obj->type == PLANE && obj->t)
		{
			pl = (t_plane*)obj->object;
			pl->tex = load_img(rt->mlx.mlx, pl->tex.path);
		}
		// if (obj->type == SPHERE)
		// {
		// 	sp = (t_sphere*)obj->object;
		// 	sp->tex = load_img(rt->mlx.mlx, sp->tex.path);
		// }
		tmp = tmp->next;
	}
}
int	main(int ac, char **av)
{
	t_minirt	minirt;

	if (ac != 2)
		return (1);
	ft_init(&minirt);
	if (ft_readfile(av[1], &minirt))
		return (printf("Error\n"), 1);
	ft_init_win(&minirt);
	if (minirt.count_t)
		load_texture(&minirt, minirt.object);
	render_image(&minirt);
	ft_hooks_fun(&minirt);
	return (0);
}
