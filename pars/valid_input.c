/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:09:49 by bamssaye          #+#    #+#             */
/*   Updated: 2025/03/01 21:31:33 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	valid_line(char **s, t_minirt *mrt)
{
	size_t	len;

	len = ft_strlen(s[0]);
	if (!ft_strncmp(s[0], "A", len))
		return (set_ambient(s, mrt));
	if (!ft_strncmp(s[0], "C", len))
		return (set_camera(s, mrt));
	if (!ft_strncmp(s[0], "L", len))
		return (set_light(s, mrt));
	if (!ft_strncmp(s[0], "sp", len))
		return (set_sp(s, mrt));
	if (!ft_strncmp(s[0], "pl", len))
		return (set_pl(s, mrt));
	if (!ft_strncmp(s[0], "cy", len))
		return (set_cy(s, mrt));
	if (!ft_strncmp(s[0], "co", len))
	{
		if (!mrt->bouns)
			return (print_err("\t{CONE}", "Bouns part"));
		else
			return (set_co(s, mrt));
	}
	return (1);
}
