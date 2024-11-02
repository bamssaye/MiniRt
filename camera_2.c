#include "minirt.h"

void	camera_right_vector(t_camera *camera)
{
	vec3d_cross(&camera->v, &camera->look_at, &camera->u);
	if (vec3d_normalize(&camera->v))
	{
		// normalize world_up failed: init_camera
		exit(1);
	}
}

double	cale_camera_len(t_camera *camera)
{
	double	len;
	double	aux_cale;

	if (camera->fov > 180 || camera->fov < 0)
	{
		// fov must be between 0 and 180
		exit(1);
	}
	aux_cale = camera->fov / 2;
	aux_cale = aux_cale * PI / 180;
	aux_cale = tan(aux_cale);
	len = (WINDOW_WIDTH / (2 * aux_cale));
	return (len);
}

int	collect_camera(char **splited_line, t_prog *prog)
{
	t_camera	*camera;

	if (prog->has_camera == 1)
	{
		// Only one camera is allowed
		exit(1);
	}
	prog->has_camera = 1;
	camera = &prog->camera;
	convert_3d(splited_line[1], &camera->position);
	convert_3d(splited_line[2], &camera->normal);
	ft_strtod(splited_line[3], &camera->fov);
	init_camera(camera);
	return (0);
}

void	*convert_3d(char *str_vector, void *memory_in)
{
	char	**splited_vector;
	t_vec3d	*vector;

	vector = (t_vec3d *)memory_in;
	splited_vector = ft_split(str_vector, ',');
	if (vector == NULL)
		return (NULL);
	ft_strtod(splited_vector[0], &vector->x);
	ft_strtod(splited_vector[1], &vector->y);
	ft_strtod(splited_vector[2], &vector->z);
	return (memory_in);
}
