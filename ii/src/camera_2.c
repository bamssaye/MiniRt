#include "../headers/minirt.h"

void	camera_right_vector(t_camera *camera)
{
	vec3d_cross(&camera->v, &camera->look_at, &camera->u);
	if (vec3d_normalize(&camera->v))
	{
		// normalize world_up failed: init_camera
		exit(1);
	}
}

// void print_camera_info(t_camera *camera)///
// {
//     print_vec3d(&camera->position,"Camera Position: ");
//     print_vec3d(&camera->normal, "Camera Normal: ");
//     print_vec3d(&camera->look_at, "Look At:");
//     print_vec3d(&camera->u, "Up Vector: ");
//     print_vec3d(&camera->v, "Right Vector: ");
//     printf("FOV: %f\n", camera->fov);
// 	print_vec3d(&camera->top_left, "top_left");
// }

int	setup_camera_from_input(char **splited_line, t_prog *prog)
{
	t_camera	*camera;

	if (prog->has_camera == 1)
	{
		// Only one camera is allowed
		exit(1);
	}
	prog->has_camera = 1;
	camera = &prog->camera;
	initialize_vector_from_string(splited_line[1], &camera->position);
	initialize_vector_from_string(splited_line[2], &camera->normal);
	ft_strtod(splited_line[3], &camera->fov);
	init_camera(camera);
	// print_camera_info(camera);
	return (0);
}

void	*initialize_vector_from_string(char *str_vector, void *memory_in)
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
	// ft_free(splited_vector);
	return (memory_in);
}
