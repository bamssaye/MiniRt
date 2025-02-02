#include "../headers/minirt.h"

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
		// vec3d_dot: a or b is NULL
		return (1);
	}
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

int	vec3d_init(t_vec3d *a, double x, double y, double z)
{
	if (a == NULL)
	{
		// vec3d_init: a is NULL
		return (1);
	}
	a->x = x;
	a->y = y;
	a->z = z;
	return (0);
}

int	copy_vec3d(t_vec3d *to, t_vec3d *from)
{
	if (to == NULL || from == NULL)
	{
		// copy_vec3d: to or from is NULL
		return (1);
	}
	ft_memcpy(to, from, sizeof(t_vec3d));
	return (0);
}

int	vec3d_plus(t_vec3d *res, t_vec3d *a, t_vec3d *b)
{
	if (a == NULL || b == NULL)
	{
		// vec3d_plus: a or b is NULL
		return (1);
	}
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->z = a->z + b->z;
	return (0);
}