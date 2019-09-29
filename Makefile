NAME = fdf

FLAGS = -Wall -Wextra -Wall

INCLUDES = -I fdf.h -I libft/libft.h -I minilibx_macos/mlx.h
LIBRARY = -L libft/ -lft -L minilibx_macos/ -lmlx

FRAMEWORKS = -framework OpenGL -framework AppKit

SRC = 

OBJ = 

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos/
	gcc $(FLAGS) $(INCLUDES) $(FRAMEWORKS) $(LIBRARY) $(OBJ) -o $(NAME)

clean:
	make -C libft/ clean
	make -C minilibx_macos/ clean

fclean: clean
	make -C libft/ fclean
	make -C minilibx_macos/ fclean

re: fclean all
