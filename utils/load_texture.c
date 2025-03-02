/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:52:32 by bamssaye          #+#    #+#             */
/*   Updated: 2025/03/01 19:26:52 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

static void	load_img(void *mlx, t_tex *img, char *path, char *str)
{
	char	name[40];
	int		i;
	int		j;

	i = -1;
	img->check_valid = 0;
	while (str[++i])
	{
		name[i] = str[i];
	}
	j = -1;
	while (path[++j] && i < 30)
		name[i++] = path[j];
	name[i] = '\0';
	img->img = mlx_xpm_file_to_image(mlx, name, &img->width, &img->height);
	if (!img->img)
	{
		img->check_valid = 1;
		return ;
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
}

int	load_texture(t_minirt *rt, t_list *lst)
{
	t_list		*tmp;
	t_object	*obj;

	tmp = lst;
	while (tmp)
	{
		obj = (t_object *)tmp->content;
		if (obj->style[TEXTURE] == 1)
		{
			load_img(rt->mlx.mlx, &obj->bum_tex.img, obj->path, "./texture/");
			obj->path = ft_strjoin("normal_", obj->path);
			load_img(rt->mlx.mlx, &obj->bum_tex.bump, obj->path, "./texture/");
			if (obj->bum_tex.img.check_valid || obj->bum_tex.bump.check_valid)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
