#include "../headers/minirt.h"

int	vec3d_minus(t_vec3d *res, t_vec3d *a, t_vec3d *b)
{
	if (a == NULL || b == NULL || res == NULL)
	{
		// vec3d_minus: a or b is NULL
		return (1);
	}
	res->x = a->x - b->x;
	res->y = a->y - b->y;
	res->z = a->z - b->z;
	return (0);
}

int	vec3d_cross(t_vec3d *res, t_vec3d *a, t_vec3d *b)
{
	if (res == NULL)
		return (1);
	res->x = a->y * b->z - a->z * b->y;
	res->y = a->z * b->x - a->x * b->z;
	res->z = a->x * b->y - a->y * b->x;
	return (0);
}

double	vec3d_length(t_vec3d *a)
{
	if (a == NULL)
		return (1);
	return (sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
}

int	vec3d_normalize(t_vec3d *a)
{
	double	length;

	if (a == NULL)
		return (1);
	length = vec3d_length(a);
	a->x /= length;
	a->y /= length;
	a->z /= length;
	return (0);
}

void	print_vec3d(t_vec3d *a, char *message)
{
	printf("vec3d %s [%.3f, %.3f, %.3f]\n", message, a->x, a->y, a->z);
}