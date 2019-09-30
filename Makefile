NAME = fdf

FLAGS = -Wall -Wextra -Wall

INCLUDES = -I fdf.h -I libft/libft.h -I minilibx_macos/mlx.h
LIBRARY = -L libft -lft -L fdf_minilibx_macos -lmlx

FRAMEWORKS = -framework OpenGL -framework AppKit

SRC = main.c bresenhams_line_algorithm.c

OBJ = main.o bresenhams_line_algorithm.o

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C fdf_minilibx_macos/
	gcc $(FLAGS) $(INCLUDES) $(FRAMEWORKS) $(LIBRARY) $(OBJ) -o $(NAME)

clean:
	make -C libft/ clean
	make -C fdf_minilibx_macos/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all
