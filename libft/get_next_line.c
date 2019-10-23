/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:29:40 by stanaka           #+#    #+#             */
/*   Updated: 2019/10/22 15:42:27 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_line(int fd, char **line, char **s)
{
	char	*tmp;
	int		i;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	*line = ft_strsub(s[fd], 0, i);
	if (*line == NULL)
		return (-1);
	if (s[fd][i + 1] == '\0')
	{
		free(s[fd]);
		s[fd] = NULL;
		return (1);
	}
	tmp = ft_strdup(&s[fd][i + 1]);
	free(s[fd]);
	s[fd] = tmp;
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char		*s[1024];
	int				ret;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || fd > 1024 || !line || (read(fd, buff, 0)) < 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (s[fd] == NULL)
		return (0);
	return (set_line(fd, line, s));
}
