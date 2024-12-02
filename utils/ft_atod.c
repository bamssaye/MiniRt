/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:36:00 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/01 22:46:14 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void	list_available(void)
{
	ft_putstr_fd("\n\t#  The parameter is invalid. #\n", 2);
}

static int	err(char *str, int i, int c, int *sign)
{
	if (c == 0)
	{
		while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
			i++;
		if (str[i] == '-')
			*sign *= -1;
		if (str[i] == '+' || str[i] == '-')
			i++;
	}
	if (c == 1 && !ft_isdigit(str[i]))
		list_available();
	if (c == 2 && str[i] != '.' && str[i])
		list_available();
	if (c == 3 && str[i] != '\0')
		list_available();
	return (i);
}

double	ft_atof(char *nptr)
{
	double	v;
	double	p;
	int		i;
	int		sign;

	if (!nptr)
		return (ft_putstr_fd("ERROR\n", 2), exit(1), 1);
	i = 0;
	sign = 1;
	v = 0;
	p = 1.0;
	i = err(nptr, i, 0, &sign);
	err(nptr, i, 1, &sign);
	while (ft_isdigit(nptr[i]))
		v = 10 * v + nptr[i++] - '0';
	err(nptr, i, 2, &sign);
	if (nptr[i] == '.' && nptr[i + 1] != '\0')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		v = 10.0 * v + (nptr[i++] - '0');
		p *= 10;
	}
	err(nptr, i, 3, &sign);
	return (sign * v / p);
}
