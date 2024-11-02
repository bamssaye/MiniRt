#include "minirt.h"

int	vec3d_scale(t_vec3d *res, double scale, t_vec3d *a)
{
	if (res == NULL || a == NULL)
		return (1);
	res->x = a->x * scale;
	res->y = a->y * scale;
	res->z = a->z * scale;
	return (0);
}

double	vec3d_dot(t_vec3d *a, t_vec3d *b)
{
	if (a == NULL || b == NULL)
	{
		printf("vec3d_dot: a or b is NULL\n");
		return (1);
	}
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

void	print_vec3d(t_vec3d *a, char *message)
{
	printf("vec3d %s [ %.3f %.3f %.3f ]\n", message, a->x, a->y, a->z);
}

