/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:30 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/04 01:00:23 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minirt.h"



void ft_init(t_minirt *mrt)
{
	int	i;
	
	i = -1;
	ft_memset(mrt->amc, 0, sizeof(mrt->amc));
	ft_memset(mrt->count_ob, 0, sizeof(mrt->amc));
	while (++i < 3)
		mrt->objects[i].object = NULL;
	// mrt->objects[0]
	//mrt->objects = (t_objects*)malloc(sizeof(t_objects) * 3);
	//mrt->objects[2] = NULL;
}
void fprintd(t_sphere *sph){

	fprintf(stderr, "{%f, %f, %f} -- %f -- [%d, %d, %d]\n",
		sph->sph_xyz[0].x, sph->sph_xyz[0].y, sph->sph_xyz[0].z,
        sph->sph_dia[0],
		sph->sph_rgb[0].r, sph->sph_rgb[0].g, sph->sph_rgb[0].b);
}
void	free_cmd(t_list *cmd)
{
	t_list	*tmp;

	if (!cmd)
		return ;
	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		free(tmp->content);
		free(tmp);
		tmp = NULL;
	}
}
int	main(int ac, char **av)
{
	//t_prog			prog;
	t_minirt minirt;

	(void) ac;
	ft_init(&minirt);
	ft_readfile(av[1], &minirt);
	// printf("Ambient : {%f}, [%d,%d,%d]\n", minirt.am_light.al, minirt.am_light.al_rgb.r, minirt.am_light.al_rgb.g, minirt.am_light.al_rgb.b);
	// printf("Camera : {%d}, c_xyz[%f,%f,%f], c_xyz[%f,%f,%f]\n", minirt.camera.fov,minirt.camera.c_xyz.x,minirt.camera.c_xyz.y,minirt.camera.c_xyz.z, minirt.camera.vec_xyz.x, minirt.camera.vec_xyz.y, minirt.camera.vec_xyz.z);
	// printf("Light : {%f}, light_xyz[%f,%f,%f], light_rgb[%d,%d,%d]\n", minirt.light.light_bri,minirt.light.light_xyz.x, minirt.light.light_xyz.y,minirt.light.light_xyz.z,minirt.light.light_rgb.r,minirt.light.light_rgb.g,minirt.light.light_rgb.b);
	// printf("%s", (t_sphere*)minirt.objects->object_t->content);
	// t_list	*objc;
	
	// objc = minirt.objects[0].object;
	// //printf("----{%c}\n", minirt.objects[0].type[0]);
	// //printf("@22\n",objc);
	// while (objc){
	// 	printf("sp--------\n");
	// 	fprintd((t_sphere*)objc->content);
	// 	objc = objc->next;
	// 	printf("sp--------\n");
	// }
	// printf("count OBJECT: %d\n", minirt.count_ob[0]);
	free_cmd(minirt.objects[0].object);
	// // free(minirt.objects[0].object->content);
	//t_sphere *ob;
	//ob = (t_sphere*)minirt.objects[0].object->content;
	// fprint(ob);
	//free(ob);
	//free(minirt.objects[0].object);
	return (0);
}
