/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:38:18 by stanaka           #+#    #+#             */
/*   Updated: 2019/10/31 16:21:39 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//t_dot	*make_dot_info(char **split, int layer)
//{
//	int		i;
//	t_dot	*dot;
//	t_dot	*tmp;
//
//	tmp = NULL;
//	while (split[i] != NULL)
//	{
//		dot = init_dot();
//		if (tmp != NULL)
//			tmp->next = dot;
//		iso_calc(dot, split[i], i, layer);
//		//split[i] for Z, i for ?, layer for ?
//		tmp = dot;
//		i++;
//	}
//	return (dot); //dot is the last one...
//}

//struct s_calc move[2] = {
//	{0, *iso_calc},
//	{1, *parallel_calc}
//};

void	parallel_calc(t_dot *dot, char *num, int i, int layer)
{
	dot->x += 20 * i;
	dot->y += 20 * sin(1.0497) * layer - 15 * ft_atoi(num) * sin(0.5248775);

	dot->int_x = (int)dot->x;
	dot->int_y = (int)dot->y;
}

void	iso_calc(t_dot *dot, char *num, int i, int layer)
{

	dot->x += 20 * cos(0.5248775) * i;
	dot->y += 20 * sin(0.5248775) * i;
	dot->x -= 20 * cos(0.5248775) * layer;
	dot->y += 20 * sin(0.5248775) * layer;
	dot->y -= 20 * ft_atoi(num);

	dot->int_x = (int)dot->x;
	dot->int_y = (int)dot->y;
}

t_dot	*init_dot(int layer, char *num)
{
	t_dot	*dot;

	dot = malloc(sizeof(t_dot));
	if (dot == NULL)
		return(NULL);
	dot->x = 300;
	dot->y = 300;
	dot->next = NULL;
	dot->layer = layer;
	dot->max_height = ft_atoi(num);
	return (dot);
}


void	change_height(t_dot **info)
{
	keep_max();
}

t_dot	*make_new_dot(char *num, int i, int n, int layer)
{
	t_dot	*dot;
	int		calc_way;

	dot = init_dot(layer, num);
	//move[calc_way].calc(dot, num, i, n);
	iso_calc(dot, num, i, n);
	//parallel_calc(dot,num, i, n);
	
	return (dot);
}

void	connect_dot(t_dot *info, t_dot *new)
{
	t_dot	*tmp;

	tmp = info;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next= new;
}

t_dot	*make_each_line_info(char *line, int n, int layer)
{
	t_dot	*info; //should point top of thi link list
	char	**split;
	int		i;
	t_dot	*new;

	info = NULL;
	split = ft_strsplit(line, ' ');
	i = 0;
	while (split[i] != NULL)
	{
		new = make_new_dot(split[i], i, n, layer);
		if (info == NULL)
			info = new;
		else
			connect_dot(info, new);		
		i++;
	}
	return (info);
}

int		count_line(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		i++;
	}
	return (i);
}

t_dot	**make_info(int fd, int i)
{
	t_dot	**info;
	char	*line;
	int		n;

	info = malloc(sizeof(t_dot *) * (i + 1));
	if (info == NULL)
		return (NULL);
	info[i] = NULL;
	n = 0;
	while (get_next_line(fd, &line) > 0)
	{
		info[n] = make_each_line_info(line, n, i);
		n++;
	}
	change_height(info);
	return (info);
}

t_dot	**get_num_info(char *file)
{
	int		fd;
	int		i;
	t_dot	**info;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = count_line(fd);
	if (close(fd) < 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	info = make_info(fd, i);
	if (close(fd) < 0)
		return (NULL);
	return (info);
}

//void    get_num_info(char *file)
//{
//	int		fd;
//	char	*line;
//	int		i;
//	t_dot	*new;
//	t_dot	*old;
//
//	fd = open(file, O_RDONLY);
//	if (fd < 0)
//		return ;
//	//dot = init_dot();
//	i = 0;
//	while (get_next_line(fd, &line)> 0)
//	{
//		new = change_info(line, &i);
//		add_dot_info(old, new); //add the next layer to the last layer
//	}
//}
