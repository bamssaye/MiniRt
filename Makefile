# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 01:39:23 by bamssaye          #+#    #+#              #
#    Updated: 2025/01/22 15:17:38 by bamssaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################
NAME =  aa
OBGDIR = MInirt_OBJ
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -rf
LIBFT = ./libft/libft.a
MLX_DIR = minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
#################################
SRC = main.c \
	utils/ft_atod.c utils/ft_atoii.c\
	pars/check_input.c pars/valid_input.c pars/read_file.c\
	utils/clean_memory.c pars/set_element.c\
	pars/set_object.c utils/utils.c pars/template_ob.c\
	drawing/canvas.c tuples/help5.c tuples/transformations.c\
	tuples/help1.c tuples/material.c rendering/raytrace.c\
##################################
#utils/test_print_object.c utils/test_print_object.c 
    #   src/ambient_light_p.c src/camera_2.c src/my_math.c 
    #   src/camera.c src/object.c src/p_plane.c 
    #   src/p_sphere.c src/prog2.c src/prog.c 
    #   src/vector_2.c src/vector_3.c src/vector_basic.c 
    #   src/color.c src/a_raytrace.c src/rerender.c 
    #   src/ft_strtod.c src/mlx_util.c src/a_raytrace_2.c 
    #   utils/get_next_line.c 
    #utils/get_next_line_utils.c 
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
$(OBGDIR)/%.o:pars/%.c
	@mkdir -p $(OBGDIR)
	$(CC) $(CFLAGS)  -c $< -o $@
$(OBGDIR)/%.o:drawing/%.c
	@mkdir -p $(OBGDIR)
	$(CC) $(CFLAGS)  -c $< -o $@
$(OBGDIR)/%.o:tuples/%.c
	@mkdir -p $(OBGDIR)
	$(CC) $(CFLAGS)  -c $< -o $@
$(OBGDIR)/%.o:rendering/%.c
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
	@$(MAKE) --no-print-directory -C ./libft fclean

re : fclean all