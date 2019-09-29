/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:30:38 by stanaka           #+#    #+#             */
/*   Updated: 2019/03/07 12:29:16 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	n;

	if (*s2 == '\0')
	{
		return ((char*)s1);
	}
	i = 0;
	while (s1[i] != '\0' && i + ft_strlen(s2) <= len)
	{
		n = 0;
		while (s1[i + n] == s2[n])
		{
			n++;
			if (s2[n] == '\0')
				return (&((char*)s1)[i]);
		}
		i++;
	}
	return (NULL);
}
