/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:12:40 by stanaka           #+#    #+#             */
/*   Updated: 2019/03/17 12:11:20 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	char	*p;

	new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new == NULL)
	{
		return (NULL);
	}
	p = new;
	while (*s != '\0')
	{
		*new = *s;
		new++;
		s++;
	}
	*new = '\0';
	return (p);
}
