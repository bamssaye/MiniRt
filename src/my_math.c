#include "../headers/minirt.h"

double	solve_quadratic_equation(double a, double b, double c)
{
	double	discriminant;
	double	t1;
	double	t2;
	double	sqrtDiscriminant;

	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0.0)
		return (-1);
	sqrtDiscriminant = sqrt(discriminant);
	if (discriminant > 0.0)
	{
		t1 = (-b + sqrtDiscriminant) / (2.0 * a);
		t2 = (-b - sqrtDiscriminant) / (2.0 * a);
		if (t1 < 0.0 || t2 < 0.0)
			return (-1);
		if (t1 < t2)
			return (t1);
		else
			return (t2);
	}
	return (-1);
}
