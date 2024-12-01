#include "../headers/minirt.h"

int	color_plus(t_color *res, t_color *a, t_color *b)
{
	res->r = a->r + b->r;
	if (res->r > 255)
		res->r = 255;
	res->g = a->g + b->g;
	if (res->g > 255)
		res->g = 255;
	res->b = a->b + b->b;
	if (res->b > 255)
		res->b = 255;
	return (0);
}

void	set_default_color(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

