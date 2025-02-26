# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 01:39:23 by bamssaye          #+#    #+#              #
#    Updated: 2025/02/26 00:04:15 by bamssaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################
NAME =  miniRT
NAME_B = miniRT_B
OBGDIR = obj
CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
RM = rm -rf
# LIBFT = ./libft/libft.a
MLX_DIR = minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
# MLX_DIR = mlxx
# MLX_FLAGS = -L$(MLX_DIR) -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

#################################
VPATH = utils:pars:drawing:tuples:rendering
SRC = check_input.c read_file.c set_element.c set_object.c set_style.c
SRC += template_ob.c valid_input.c plane.c raytrace.c spher.c mlx_utlis.c key_utils.c
SRC += camera.c color.c cylinder.c intersection.c math.c vector_utils.c cone.c cone2.c
SRC += clean_memory.c ft_atod.c ft_atoii.c pars_utils.c canvas.c new_vec.c select_object.c
SRC += libft_utils.c get_line.c ft_split.c lst_addback.c load_texture.c ray_distance.c
SRC += bumpping.c checkborad.c rotation.c texture.c translation.c ft_strjoin.c ft_strdup.c
MAN += main.c $(SRC)
BON += main_bouns.c $(SRC)
OBJ =  $(addprefix $(OBGDIR)/,  $(notdir $(MAN:.c=.o)))
OBJ_B =  $(addprefix $(OBGDIR)/,  $(notdir $(BON:.c=.o)))

$(OBGDIR)/%.o:%.c
	@mkdir -p $(OBGDIR)
	$(CC) $(CFLAGS)  -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

bonus : $(NAME_B)

$(NAME_B): $(OBJ_B)
	@$(CC) $(CFLAGS) $(OBJ_B) $(MLX_FLAGS) -o $(NAME_B)

clean:
	$(RM) $(OBGDIR)

fclean: clean
	$(RM) $(NAME) $(NAME_B)

re : fclean all