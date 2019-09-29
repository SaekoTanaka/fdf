NAME = fdf

FLAGS = -Wall -Wextra -Wall

INCLUDES = -I fdf.h -I libft/libft.h -I minilibx_macos/mlx.h
LIBRARY = -L libft/ -lft -L minilibx_macos/ -lmlx

FRAMEWORKS = -framework OpenGL -framework AppKit

all: $(NAME)


