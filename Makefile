NAME = fdf

CFLAGS = -Wall -Wextra -Wall

I = -I fdf.h -I libft/libft.h -I minilibx_macos/mlx.h
L = -L libft/ -lft -L minilibx_macos/ -lmlx



all: $(NAME)


