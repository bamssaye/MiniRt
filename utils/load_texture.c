/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:52:32 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/21 12:53:48 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

static void    load_img(void *mlx, t_tex *img, char *path, char *str)
{
    char    name[40];
    int i;
    
	i = -1;
	while (str[++i]){
        name[i] = str[i];}
    int j =-1;
    while (path[++j] && i < 30)
        name[i++] = path[j];
    name[i] = '\0';
    img->img = mlx_xpm_file_to_image(mlx, name, &img->width, &img->height);
	if (!img->img)
	{
		img->check_valid = 1;
		return ;
	}	
    img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, \
		&img->endian);
}
static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s2);
	return (str);
}

void load_texture(t_minirt *rt, t_list *lst)
{
	t_list *tmp;
	t_object *obj;
	
	tmp = lst;
	while (tmp)
	{
		obj = (t_object*)tmp->content;
		if (obj->style[TEXTURE] == 1)
		{
			load_img(rt->mlx.mlx, &obj->bum_tex.img , obj->path, "./texture/");
			obj->path = ft_strjoin("normal_", obj->path);
			load_img(rt->mlx.mlx, &obj->bum_tex.bump, obj->path,"./texture/");
		}
		tmp = tmp->next;
	}
}
