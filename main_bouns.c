/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bouns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:56:45 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/14 14:15:07 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"


t_tex    load_img(void *mlx, char *path, char *str){

	t_tex   tex;
    char    name[50];
    int i;
    
    i = -1;
    while (str[++i])
        name[i] = str[i];
    int j =-1;
    while (path[++j])
        name[i] = path[j];
    name[i] = '\0';
    printf("%s", name);
	tex.path = path;
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
	t_sp	*sp;
	// t_pl		*pl;
	
	tmp = lst;
	while (tmp)
	{
		obj = (t_object*)tmp->content;
		if (obj->type == SPHERE && obj->t)
		{
			sp = (t_sp*)obj->object;
			sp->tex = load_img(rt->mlx.mlx, sp->tex.path, "./texture/");
		}
		// if (obj->type == PLANE && obj->t)
		// {
		// 	sp = (t_sp*)obj->object;
		// 	sp->tex = load_img(rt->mlx.mlx, sp->tex.path);
		// }
		// if (obj->type == SPHERE)
		// {
		// 	sp = (t_sp*)obj->object;
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