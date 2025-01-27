# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 01:39:23 by bamssaye          #+#    #+#              #
#    Updated: 2025/01/27 21:33:12 by bamssaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################
NAME =  miniRT
OBGDIR = obj
CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
RM = rm -rf
LIBFT = ./libft/libft.a
MLX_DIR = minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
#################################
VPATH = utils:pars:drawing:tuples:rendering
SRC = main.c check_input.c read_file.c set_element.c set_object.c
SRC += template_ob.c valid_input.c plane.c raytrace.c spher.c mlx_utlis.c
SRC += camera.c color.c cylinder.c intersection.c math.c vector_utils.c
SRC += clean_memory.c ft_atod.c ft_atoii.c pars_utils.c canvas.c
OBJ =  $(addprefix $(OBGDIR)/,  $(notdir $(SRC:.c=.o)))

$(OBGDIR)/%.o:%.c
	@mkdir -p $(OBGDIR)
	$(CC) $(CFLAGS)  -c $< -o $@
	
all: $(NAME)

$(LIBFT):
	$(MAKE) --no-print-directory -C ./libft
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBGDIR)

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) --no-print-directory -C ./libft fclean

re : fclean all