/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:36:20 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/26 14:20:28 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

t_atoi	ft_atoii(const char *nptr)
{
	t_atoi	num[1];
	long	n;

	int (i), (p);
	i = 0;
	p = 1;
	n = 0;
	num[0] = (t_atoi){0, 0};
	if (nptr[i] == '-')
		p *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		n = 10 * n + nptr[i] - 48;
		if ((n > 2147483647 && p == 1) || (n > 2147483648 && p == -1))
			return ((t_atoi){0, 1});
		i++;
	}
	if (nptr[i] != '\0')
		return ((t_atoi){0, 1});
	num[0].num = n * p;
	return (num[0]);
}
