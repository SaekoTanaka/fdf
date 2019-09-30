/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:55:12 by stanaka           #+#    #+#             */
/*   Updated: 2019/09/29 18:08:53 by stanaka          ###   ########.fr       */
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
    double      x0;
    double      x1;
    double      y0;
    double      y1;
    double      t; //(y0 - y1)/(x0 - x1)
}               t_xy;

void    draw_line(t_xy  *xy, void *mlx_ptr, void *win_ptr);
t_xy    *init_xy(void);

# endif