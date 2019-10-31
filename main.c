/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:54:55 by stanaka           #+#    #+#             */
/*   Updated: 2019/10/31 16:16:29 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//int main()
//{
//    void    *mlx_ptr;
//    void    *win_ptr;
//    t_xy    *xy;
//
//    mlx_ptr = mlx_init();
//    win_ptr = mlx_new_window(mlx_ptr, 1200, 1200, "test");
//    xy = init_xy();
//    draw_line(xy, mlx_ptr, win_ptr);
//    mlx_loop(mlx_ptr);
//    mlx_clear_window(mlx_ptr, win_ptr);
//    return (0);
//}

int	deal_key(int key, void **param)
{
	if (key == 53)
	{
		mlx_destroy_window(param[0], param[1]);
		exit(0);
	}
	return (0);
}

void	line(t_dot	**info, char *file)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	**param;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1500, 1500, file);
	param = malloc(sizeof(void *) * 2);
	param[0] = mlx_ptr;
	param[1] = win_ptr;
	draw__line(info, mlx_ptr, win_ptr);
	mlx_key_hook(win_ptr, deal_key, param);
	mlx_loop(mlx_ptr);
    mlx_clear_window(mlx_ptr, win_ptr);
}

void    draw(char *file)
{
	t_dot   **info;

	info = get_num_info(file); //open file twice and make linklist array
	if (info != NULL)
		line(info, file); //use ex main
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	else
		draw(av[1]);
	return (0);    
}