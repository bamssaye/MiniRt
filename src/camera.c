#include "../headers/minirt.h"

int	is_parallel(t_vec3d *v1, t_vec3d *v2)
{
	double	dot;
	double	len1;
	double	len2;

	dot = vec3d_dot(v1, v2);
	len1 = vec3d_length(v1);
	len2 = vec3d_length(v2);
	if (dot == len1 * len2)
		return (1);
	else
		return (0);
}

void	init_camera(t_camera *camera)
{
	camera_look_at(camera);
	camera_up_vector(camera);
	camera_right_vector(camera);
	camera_top_left_vector(camera);
}

void	camera_look_at(t_camera *camera)
{
	t_vec3d	look_at;

	vec3d_plus(&look_at, &camera->position, &camera->normal);
	vec3d_minus(&camera->look_at, &look_at, &camera->position);
	if (vec3d_normalize(&camera->look_at))
	{
		print_vec3d(&camera->look_at, "look_at");
		// normalize look_at failed: init_camera
	}
}

void	camera_top_left_vector(t_camera *cam)
{
	t_vec3d	direction_vector;
	t_vec3d	scaled_u_vector;
	t_vec3d	scaled_v_vector;
	double	view_distance;

	// Calculate view distance based on FOV and window width
	view_distance = WINDOW_WIDTH / 2;
	view_distance = view_distance / (2.0 * tan(cam->fov * (PI / 180.0) / 2.0));
	// Normalize the camera's look_at direction and scale it
	ft_memcpy(&direction_vector, &cam->look_at, sizeof(t_vec3d));
	vec3d_normalize(&direction_vector);
	vec3d_scale(&direction_vector, view_distance, &direction_vector);
	// Scale the u and v vectors
	vec3d_scale(&scaled_u_vector, WINDOW_WIDTH / 2, &cam->u);
	vec3d_scale(&scaled_v_vector, WINDOW_HEIGHT / 2, &cam->v);
	// Calculate the top-left corner vector
	vec3d_minus(&cam->top_left, &direction_vector, &scaled_u_vector);
	// vec3d_plus(&cam->top_left, &direction_vector, &scaled_u_vector);
	vec3d_minus(&cam->top_left, &cam->top_left, &scaled_v_vector);
}

void	camera_up_vector(t_camera *camera)
{
	t_vec3d	world_up;

	world_up = (t_vec3d){0, 1, 0};
	if (is_parallel(&camera->look_at, &world_up))
	{
		world_up = (t_vec3d){0, 0, -1};
		// camera look_at is parallel to world_up
	}
	vec3d_cross(&camera->u, &camera->look_at, &world_up);
	if (vec3d_normalize(&camera->u))
	{
		// normalize u failed: init_camera
		exit(1);
	}
}
