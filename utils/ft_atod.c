/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:36:00 by bamssaye          #+#    #+#             */
/*   Updated: 2025/01/27 23:41:40 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

static int	err(char *str, int c, t_atof *a)
{
	if (c == 0)
	{
		while ((str[a->i] >= 9 && str[a->i] <= 13) || (str[a->i] == 32))
			a->i++;
		if (str[a->i] == '-')
			a->sign *= -1;
		if (str[a->i] == '+' || str[a->i] == '-')
			a->i++;
	}
	if (c == 1 && !ft_isdigit(str[a->i]))
		a->isv = 1;
	else if (c == 2 && str[a->i] != '.' && str[a->i])
		a->isv = 1;
	else if (c == 3 && str[a->i] != '\0')
		a->isv = 1;
	return (a->i);
}

t_atof	ft_atof(char *nptr)
{
	t_atof	num[1];

	double (v), (p);
	if (!nptr)
		return ((t_atof){0, 1, 0, 0});
	num[0] = (t_atof){0, 0, 0, 1};
	v = 0;
	p = 1.0;
	num[0].i = err(nptr, 0, num);
	err(nptr, 1, num);
	while (ft_isdigit(nptr[num[0].i]))
		v = 10 * v + nptr[num[0].i++] - '0';
	err(nptr, 2, num);
	if (nptr[num[0].i] == '.' && nptr[num[0].i + 1] != '\0')
		num[0].i++;
	while (ft_isdigit(nptr[num[0].i]))
	{
		v = 10.0 * v + (nptr[num[0].i++] - '0');
		p *= 10;
	}
	err(nptr, 3, num);
	num[0].num = num[0].sign * v / p;
	return (num[0]);
}
