/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:54:55 by stanaka           #+#    #+#             */
/*   Updated: 2019/09/29 18:00:02 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main()
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_xy    *xy;
    //int     i;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1200, 1200, "test");
    xy = init_xy();
    draw_line(xy, mlx_ptr, win_ptr);
    //i = 100;
    //while (i < 200)
    //{
    //    mlx_pixel_put(mlx_ptr, win_ptr, i, i, 0xFFFFFF);
    //    i++;
    //}
    mlx_loop(mlx_ptr);
    mlx_clear_window(mlx_ptr, win_ptr);
    return (0);
}