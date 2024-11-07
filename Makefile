# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 01:39:23 by bamssaye          #+#    #+#              #
#    Updated: 2024/11/07 02:14:49 by bamssaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# SRC = main.c ambient_light_p.c \
#       camera_2.c my_math.c camera.c \
#       object.c \
#       p_plane.c p_sphere.c \
#       prog2.c prog.c \
#       vector_2.c vector_3.c vector_basic.c color.c a_raytrace.c\
#       mlx_util.c a_raytrace_2.c\
#       rerender.c ft_strtod.c get_next_line.c get_next_line_utils.c



# OBJ = $(SRC:.c=.o)

# MLX_DIR = minilibx

# MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# CFLAGS = -Wall -Wextra -Werror

# LIBFT_DIR =  libft
# LIBFT = $(LIBFT_DIR)/libft.a

# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(NAME) $(LIBFT)

# re: fclean all

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
      src/ambient_light_p.c src/camera_2.c src/my_math.c \
      src/camera.c src/object.c src/p_plane.c \
      src/p_sphere.c src/prog2.c src/prog.c \
      src/vector_2.c src/vector_3.c src/vector_basic.c \
      src/color.c src/a_raytrace.c src/rerender.c \
      src/ft_strtod.c src/mlx_util.c src/a_raytrace_2.c \
      utils/get_next_line.c \
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