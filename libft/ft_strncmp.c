/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:32:57 by stanaka           #+#    #+#             */
/*   Updated: 2019/03/09 10:11:21 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	if (len == 0)
		return (0);
	i = 0;
	while (c1[i] == c2[i] && c1[i] != '\0' && c2[i] != '\0')
	{
		i++;
		if (i == len)
			return (0);
	}
	return (c1[i] - c2[i]);
}
