/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:55:12 by stanaka           #+#    #+#             */
/*   Updated: 2019/10/31 16:16:09 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include "fdf_minilibx_macos/mlx.h"

typedef struct  s_xy
{
    int      x0;//start x
   // double      x1;//end x
    double      y0;//start y
   // double      y1;//end y
    double      t; //(y0 - y1)/(x0 - x1)
    int         x;
}               t_xy;

void    draw_line(t_xy  *xy, void *mlx_ptr, void *win_ptr);
t_xy    *init_xy(void);

typedef struct      s_dot
{
    double			x;
    double			y;
    struct s_dot    *next;
    int             int_x;
    int             int_y;
    int             layer;
    int             max_height;
}                   t_dot;

typedef void    t_cal(t_dot *dot, char *num, int i, int layer);
typedef struct  s_calc
{
    t_cal  *calc;
}               t_calc;

void	draw__line(t_dot **info, void *mlx_ptr, void *win_ptr);
t_dot	**get_num_info(char *file);
# endif