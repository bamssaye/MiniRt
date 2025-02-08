/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:39:39 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/07 23:46:18 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
// # include <mlx.h>
#include "../minilibx/mlx.h"
# include <fcntl.h>
// # include "../libft/libft.h"
# include "struct.h"
# include "function.h"
# define P_NAME "miniRT"
# define W_WIDTH 1000
# define W_HEIGHT 700
# define IN_MAX 2147483647
# define IN_MIN 2147483648
# define PI 3.14159265358979323846f
# define SPHERE 0
# define PLANE 1
# define CYLINDER 2
# define LIGHT 3
# define EPSILON 0.00001
# define SIZE 4
# define L 2
# define C 1
# define A 0

#endif
