/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:39:39 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/23 11:18:40 by bamssaye         ###   ########.fr       */
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
#include "../mlxx/mlx.h"
# include <fcntl.h>
# include "struct.h"
# include "function.h"
# define P_NAME "miniRT"
# define W_WIDTH 800
# define W_HEIGHT 800
# define IN_MAX 2147483647
# define IN_MIN 2147483648
# define PI 3.14159265358979323846f
# define SPHERE 0
# define PLANE 1
# define CYLINDER 2
# define LIGHT 3
# define CONE 4
// # define EPSILON 0.00001
# define EPSILON 1e-6
# define SIZE 4
# define L 2
# define C 1
# define A 0
#define K_UP 126
#define K_DOWN 125
#define K_LEFT 123
#define K_RIGHT 124
#define K_Z_IN 24
#define K_Z_OUT 27
#define K_R 15
#define K_T 17
#define YES 1
#define NO 0
#define CHECKBORAD 2
#define TEXTURE 1
#define COLOR 0
#define MSG "Error"
# define MSG_1 "<./miniRt> <scene/*.rt>\n {* : file name}"
# define MSG_2 "File not found... !\n *file name must be .rt"
# define MSG_3 "Check line..., "
# define MSG_4 "<sp> <0,0,0> <10> 255,0,0\n[SP] [X,Y,Z] [R] [COLOR]"
# define MSG_5 "<pl> <0,0,0> <1,1,1> 255,255,255" 
# define MSG_6 "<cy> <0,0,0> <1,1,1>  10 40 255,255,255" 
# define MSG_7 "<co> <0,0,0> <1,1,1>  10 40 255,255,255" 
// # define MSG_1 ""
// # define MSG_1 ""
// # define MSG_1 ""
// # define MSG_1 ""
#endif
