/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:38:18 by stanaka           #+#    #+#             */
/*   Updated: 2019/10/23 12:04:34 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	*make_dot_info(char **split, int layer)
{
	int		i;
	t_dot	*dot;
	t_dot	*tmp;

	tmp = NULL;
	while (split[i] != NULL)
	{
		dot = init_dot();
		if (tmp != NULL)
			tmp->next = dot;
		iso_calc(dot, split[i], i, layer);
		//split[i] for Z, i for ?, layer for ?
		tmp = dot;
		i++;
	}
	return (dot); //dot is the last one...
}

void	iso_calc(t_dot *dot, char *num, int i, int layer)
{

	dot->x += 50 * cos(3.149265 / 6) * i;
	dot->y += 50 * sin(3.149265 / 6) * i;
	dot->x -= 50 * cos(3.149265 / 6) * layer;
	dot->y += 50 * sin(3.149265 / 6) * layer;
	dot->y -= 20 * ft_atoi(num);
}

t_dot	*init_dot()
{
	t_dot	*dot;

	dot = malloc(sizeof(t_dot));
	if (dot == NULL)
		return(NULL);
	dot->x = 100;
	dot->y = 100;
	dot->next = NULL;
	dot->next_layer = NULL;
	return (dot);
}


t_dot	*change_info(char *line, int *i)
{
	char 	**split;
	t_dot	*new;
	split = ft_strsplit(line , ' ');
	new = make_dot_info(split, *i);
	*i++; //how many layers they have
	return (new);
}

void	add_dot_info()
{
	
}
void    get_num_info(char **av)
{
	int		fd;
	char	*line;
	int		i;
	t_dot	*new;
	t_dot	*old;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return ;
	//dot = init_dot();
	i = 0;
	while (get_next_line(fd, &line)> 0)
	{
		new = change_info(line, &i);
		add_dot_info(old, new); //add the next layer to the last layer
	}
}