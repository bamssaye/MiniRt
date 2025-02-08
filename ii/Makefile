# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-koub <iel-koub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 01:39:23 by bamssaye          #+#    #+#              #
#    Updated: 2025/02/02 20:45:31 by iel-koub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################

NAME =  miniRT
OBGDIR = MInirt_OBJ
CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
RM = rm -rf
LIBFT = ./libft/libft.a
MLX_DIR = minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

#################################

SRC = main.c \
      src/ambient_light_parse.c src/camera_2.c src/my_math.c \
      src/camera.c src/object.c src/plane.c src/color_2.c \
      src/sphere.c src/cylinder_3.c src/prog_util.c \
      src/vector_2.c src/vector_3.c src/cylinder.c \
      src/color.c src/a_raytrace.c src/cylinder_2.c \
      src/ft_strtod.c src/mlx_util.c src/a_raytrace_2.c \
      src/a_raytrace_3.c utils/get_next_line.c \
      utils/get_next_line_utils.c \
	      
##################################

OBJ =  $(addprefix $(OBGDIR)/,  $(notdir $(SRC:.c=.o)))

$(OBGDIR)/%.o:%.c
	@mkdir -p $(OBGDIR)
	$(CC) $(CFLAGS)  -c $< -o $@
$(OBGDIR)/%.o:utils/%.c
	@mkdir -p $(OBGDIR)
	$(CC) $(CFLAGS)  -c $< -o $@
$(OBGDIR)/%.o:src/%.c
	@mkdir -p $(OBGDIR)
	$(CC) $(CFLAGS)  -c $< -o $@

all: $(NAME)

$(LIBFT):
	$(MAKE) --no-print-directory -C ./libft
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBGDIR)
	@$(MAKE) --no-print-directory -C ./libft clean

fclean: clean
	$(RM) $(NAME)

re: fclean all