/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:36:20 by bamssaye          #+#    #+#             */
/*   Updated: 2024/11/30 23:38:33 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/minirt.h"

void	ft_error_all()
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_atoii(const char *nptr)
{
	int		i;
	int		p;
	long	n;

	i = 0;
	p = 1;
	n = 0;
	if (nptr[i] == '-')
		p *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		n = 10 * n + nptr[i] - 48;
		if ((n > 2147483647 && p == 1) || (n > 2147483648 && p == -1))
			return (ft_error_all(), 0);
		i++;
	}
	if (nptr[i] != '\0')
		return (ft_error_all(), 0);
	return (n * p);
}