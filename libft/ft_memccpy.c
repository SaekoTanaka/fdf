/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:57:17 by stanaka           #+#    #+#             */
/*   Updated: 2019/03/08 12:07:31 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	cc;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	cc = (unsigned char)c;
	while (0 < len--)
	{
		*d++ = *s++;
		if (*(s - 1) == cc)
		{
			return (d);
		}
	}
	return (NULL);
}
