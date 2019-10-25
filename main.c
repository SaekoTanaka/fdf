/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:54:55 by stanaka           #+#    #+#             */
/*   Updated: 2019/10/25 10:37:35 by stanaka          ###   ########.fr       */
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

void	line(t_dot	**info, char *file)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1500, 1500, file);
	draw__line(info, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
    mlx_clear_window(mlx_ptr, win_ptr);
}

void    draw(char *file)
{
	t_dot   **info;

	info = get_num_info(file); //open file twice and make linklist array
//printf("hello\n");
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