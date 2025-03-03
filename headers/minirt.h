/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:39:39 by bamssaye          #+#    #+#             */
/*   Updated: 2025/03/01 04:47:01 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include "struct.h"
# include "function.h"
# include <fcntl.h>
# define P_NAME "miniRT"
# define W_WIDTH 1000
# define W_HEIGHT 1000
# define IN_MAX 2147483647
# define IN_MIN 2147483648
# define PI 3.14159265358979323846f
# define SPHERE 0
# define PLANE 1
# define CYLINDER 2
# define LIGHT 3
# define CONE 4
# define EPSILON 1e-6
# define SIZE 4
# define L 2
# define C 1
# define A 0
# define K_R 114
# define K_T 116
# define K_ESC 65307
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_UP 65362
# define K_DOWN 65364
# define K_Z_I 105 
# define K_Z_O 111
# define K_IN 65451  
# define K_OUT 65453 
# define YES 1
# define NO 0
# define CHECKBORAD 2
# define TEXTURE 1
# define COLOR 0
# define MSG "Error"
# define MSG_1 "<./miniRt> <scene/*.rt>\n {* : file name}"
# define MSG_2 "File not found... !\n *file name must be .rt"
# define MSG_3 "Check line..., "
# define MSG_4 "<sp> <0,0,0> <10> 255,0,0\n[SP] [X,Y,Z] [R] [COLOR]"
# define MSG_5 "<pl> <0,0,0> <1,1,1> 255,255,255"
# define MSG_6 "<cy> <0,0,0> <1,1,1>  10 40 255,255,255"
# define MSG_7 "<co> <0,0,0> <1,1,1>  10 40 255,255,255"
# define MSG_8 "texture / normal map not found"
#endif
