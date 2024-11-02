NAME =  miniRT

SRC = main.c ambient_light_p.c \
      camera_2.c my_math.c camera.c \
      object.c \
      p_plane.c p_sphere.c \
      prog2.c prog.c \
      vector_2.c vector_3.c vector_basic.c color.c a_raytrace.c\
      mlx_util.c a_raytrace_2.c\
      rerender.c ft_strtod.c get_next_line.c get_next_line_utils.c 

OBJ = $(SRC:.c=.o)

MLX_DIR = /home/iel-koub/minilibx-linux

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR =  /home/iel-koub/minirt/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

