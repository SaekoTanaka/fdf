/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:07:09 by stanaka           #+#    #+#             */
/*   Updated: 2019/03/07 15:04:47 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	cc;

	cs = (unsigned char*)s;
	cc = (unsigned char)c;
	while (0 < n--)
	{
		if (*cs == cc)
		{
			return (cs);
		}
		cs++;
	}
	return (NULL);
}
