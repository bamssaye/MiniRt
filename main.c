/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:30 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/17 10:07:43 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"

int print_err(char *str, char *s)
{
	return (printf("%s : %s\n", str, s), 1);
}
void    load_img(void *mlx, t_tex *img, char *str)
{
    char    name[40];
    int i;
    
	i = -1;
	while (str[++i]){
        name[i] = str[i];}
    int j =-1;
    while (img->path[++j] && i < 30)
        name[i++] = img->path[j];
    name[i] = '\0';
	if (img->path)
		free(img->path);
	img->path = name;
    img->img = mlx_xpm_file_to_image(mlx, name, &img->width, &img->height);
	if (!img->img){
		img->check_valid = 1;
		return ;
	}	
    img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, \
		&img->endian);
}
void load_texture(t_minirt *rt, t_list *lst)
{
	t_list *tmp;
	t_object *obj;
	
	tmp = lst;
	while (tmp)
	{
		obj = (t_object*)tmp->content;
		if (!obj->t)
		{
			tmp = tmp->next;
			continue;
		}
		if (obj->type == SPHERE)
		{
			load_img(rt->mlx.mlx, &((t_sp*)obj->object)->tex, "./texture/");
			load_img(rt->mlx.mlx, &((t_sp*)obj->object)->n_map, "./texture/");
		}
		else if (obj->type == PLANE){
			load_img(rt->mlx.mlx, &((t_pl*)obj->object)->tex, "./texture/");
			load_img(rt->mlx.mlx, &((t_pl*)obj->object)->n_map, "./texture/");
		}
		// else if (obj->type == CYLINDER && obj->t)
		// 	load_img(rt->mlx.mlx, &((t_cy*)obj->object)->tex, "./texture/");
		// else if (obj->type == CYLINDER && obj->t)
		// 	load_img(rt->mlx.mlx, &((t_*)obj->object)->tex, "./texture/");
		tmp = tmp->next;
	}
}
int	main(int ac, char **av)
{
	t_minirt	minirt;

	if (ac != 2)
		return (print_err(MSG_1, "LINE 4"));
	minirt.bouns = 1;
	if (ft_readfile(av[1], &minirt))
		return (1);
	ft_init_win(&minirt);
	if (minirt.count_t)
		load_texture(&minirt, minirt.object);
	render_image(&minirt);
	ft_hooks_fun(&minirt);
	return (0);
}
