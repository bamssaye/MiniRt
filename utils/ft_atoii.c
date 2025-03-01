/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:36:20 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/26 22:23:48 by bamssaye         ###   ########.fr       */
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
	int		i;

	i = 0;
	n = 0;
	num[0] = (t_atoi){0, 0};
	if (nptr[i] == '+' || nptr[i] == '-')
		return ((t_atoi){0, 1});
	while (ft_isdigit(nptr[i]))
	{
		n = 10 * n + nptr[i] - 48;
		if (n > 2147483647)
			return ((t_atoi){0, 1});
		i++;
	}
	if (nptr[i] != '\0')
		return ((t_atoi){0, 1});
	num[0].num = n;
	return (num[0]);
}
