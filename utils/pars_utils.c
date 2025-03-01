/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:15:14 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/26 14:19:38 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	check_str(char **s, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (!s[i])
			return (1);
	if (s[size])
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == '\n');
}

int	ft_range(t_atoi n, double min, double max)
{
	if (n.isv)
		return (0);
	return (n.num >= min && n.num <= max);
}

int	ft_ranges(t_atof n, double min, double max)
{
	if (n.isv)
		return (0);
	return (n.num >= min && n.num <= max);
}

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
