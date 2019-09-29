/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:23:56 by stanaka           #+#    #+#             */
/*   Updated: 2019/03/08 12:37:48 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dl;
	size_t	sl;
	size_t	i;

	i = 0;
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (size > dl + 1)
	{
		while (*dst)
		{
			dst++;
		}
		while (size > dl + 1 + i++ && *src)
		{
			*dst++ = *src++;
		}
		*dst = '\0';
		return (dl + sl);
	}
	else
	{
		return (size + sl);
	}
}
