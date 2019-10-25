/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams_line_algorithm.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:38:51 by stanaka           #+#    #+#             */
/*   Updated: 2019/10/25 09:02:55 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

     #include "fdf.h"

int     compare_y(double s_y, double l_y)
{
    double  av_y;
    int     small_y;
    int     large_y;

    av_y = (s_y + l_y) / 2;
    small_y = (int)av_y;
    large_y = (int)av_y + 1;
    if (av_y - small_y < large_y - av_y)
        return (small_y);
    else
        return (large_y);
}

int     get_y(t_xy *xy, int c_x)
{
    int     y;
    double  s_y;
    double  l_y;

    s_y = xy->t * (c_x - xy->x0) + xy->y0;
    l_y = s_y + xy->t;
    y = compare_y(s_y, l_y);
    return (y);
}

t_xy    *init_xy(void)
{
    t_xy    *xy;

    xy = malloc(sizeof(t_xy));
    xy->t = 0;
    xy->x0 = 100.5555;
    xy->x1 = 100.5555;
    xy->y0 = 200;
    xy->y1 = 400;
    return (xy);
}

void    special_pixel_put(void *mlx_ptr, void *win_ptr, t_xy *xy)
{
    int i;
    int y;

    i = xy->y0 > xy->y1 ? xy->y0 : xy->y1;
    // i is the large one
    y = xy->y0 > xy->y1 ? xy->y1 : xy->y0;
    // y is the small one
    while (i >= y)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, xy->x0, y, 0xFFFFFF);
        y++;
    }
}


void    draw_line(t_xy  *xy, void *mlx_ptr, void *win_ptr)
{
    int s_x;//start
    int t_x;//end
    int c_x;
    int c_y;

    s_x = (int)xy->x0;
    t_x = (int)xy->x1;
    if (xy->x0 - xy->x1 != 0)
        xy->t = (xy->y0 - xy->y1)/(xy->x0 - xy->x1);
    else
        special_pixel_put(mlx_ptr, win_ptr, xy);       
    c_x = s_x;
    while (c_x <= t_x)//
    // the case that c_x < t_x or c_x > t_x 
    {
        c_y = get_y(xy, c_x);
        mlx_pixel_put(mlx_ptr, win_ptr, c_x, c_y, 0xFFFFFFF);//mlx_pixel_put (int) (int)
       // printf("(%d,%d)\n", c_x, c_y);
        c_x++;
    }
}