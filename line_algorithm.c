/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:22:10 by stanaka           #+#    #+#             */
/*   Updated: 2019/10/31 09:13:15 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//void	dots(int i, double t, t_dot *this)
//{
//	int	s_y;
//	int	t_y;
//
//	if (t > 0)
//	{
//		s_y = t * (i - (int)this->x) + this->y;
//		t_y = s_y + t + 1;
//	}
//	else
//	{
//		s_y = t * (i - (int)this->x) + this->y + 1;
//		t_y = s_y + t;
//	}
//	dot()
//}


int		compare_y(double s, double t)
{
	int	y;
	double yy;

	yy = (s + t) / 2;
	if (yy - (int)yy > 0.5)
		y = (int)yy + 1;
	else
		y = (int)yy;
	return (y);
}


void	each_x_dots(t_xy xy, void *mlx_ptr, void *win_ptr)
{
	double	s_y;
	double	t_y;
	int		ys;

	s_y = xy.t * (xy.x - xy.x0) + xy.y0;
	t_y = s_y + xy.t;
	if (xy.t > 0)
	{
		ys = s_y;
		while (ys <= (int)t_y + 1)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, xy.x, ys, 0xFF00FF);
			ys++;
		}
	}
	else
	{
		ys = s_y + 1;
		while ((int)t_y <= ys)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, xy.x, ys, 0xFFFFFF);
			ys--;
		}
	}
//	ys = compare_y(s_y, t_y);
//	mlx_pixel_put(mlx_ptr, win_ptr, ys, xy.x, 0xFFFFFF);
}


void	special_case(t_dot *this, t_dot *next, void *mlx_ptr, void *win_ptr)
{
	int	sy;
	int ty;

	sy = this->y > next->y ? this->y : next->y;
	ty = this->y < next->y ? this->y : next->y;
	if (sy < ty)
	{
		while (sy <= ty + 1)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, (int)this->x, sy, 0xFFFFFFF);
			sy++;
		}
	}
	else
	{
		while (sy + 1 >= ty)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, (int)this->x, sy, 0xFFFFFFF);
			sy--;
		}
	}
}

void    make_dots_next(t_dot *this, t_dot *next, void *mlx_ptr, void *win_ptr) //if we can get two t_dots 
{
	//this->x < next->x
	t_xy	xy;
	int i = 0;//

	if (this->x != next->x)
	{
		xy.t = (next->y - this->y) / (next->x - this->x);
		xy.x0 = (int)this->x;
		xy.y0 = this->y;
		xy.x = (int)this->x;
//		while (xy.x <= ((int)next->x) + 1)
		while (xy.x <= ((int)next->x))
		{
			each_x_dots(xy, mlx_ptr, win_ptr);
			xy.x++;
			i++;//
		}
		printf("dots:%d\n",i);
	}
	else
		special_case(this, next, mlx_ptr, win_ptr); //x are same only y direction    
}

void    make_dots_nextlayer(t_dot *this, t_dot *next, void  *mlx_ptr, void *win_ptr)
{
	//this->x > next->x
	make_dots_next(next, this, mlx_ptr, win_ptr);
}

void	dots_next(t_dot *layer, void *mlx_ptr, void *win_ptr)
{
	int i = 0;//
	while (layer->next)
	{
		make_dots_next(layer, layer->next, mlx_ptr, win_ptr);
		layer = layer->next;
		i++;//
	}
	printf("dot_next:%d\n", i);//
}

void	dots_next_layer(t_dot *first, t_dot *second, void *mlx_ptr, void *win_ptr)
{
	int i = 0;//
	while (first)
	{
		make_dots_nextlayer(first, second, mlx_ptr, win_ptr);
		first = first->next;
		second = second->next;
		i++;//
	}
	printf("dot_next_layer:%d\n", i);//
}

void	draw__line(t_dot **info, void *mlx_ptr, void *win_ptr)
{
	int	i;

	i = 0;
	while (info[i] != NULL)
	{
		dots_next(info[i], mlx_ptr, win_ptr);
		if (info[i + 1] != NULL)
			dots_next_layer(info[i], info[i + 1], mlx_ptr, win_ptr);
		i++;
	}
}